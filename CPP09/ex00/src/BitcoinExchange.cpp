/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:35:45 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/23 11:25:56 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

using std::cout;
using std::cerr;
using std::endl;

typedef std::map<std::string, float> Database;
typedef std::pair<std::string, float> Data;

static void error(std::string message) {
    cerr << "Error: " << message << endl;
}

static float ft_stof(const std::string &str) {
    std::istringstream iss(str);
    float value;
    iss >> value;
    return (value);
}

static bool getData(Data &data, const std::string &line, const std::string sep) {
    struct tm tm;
    if (line.length() < 11 + sep.length() || line.find(sep) != 10
        || !strptime(line.c_str(), "%Y-%m-%d", &tm)
        || !line.compare(8, 2, "00")) {
        return (RETURN_FAILURE);
    }
    size_t i = 10 + sep.length();
    if (line[i] == '+' || line[i] == '-') {
        ++i;
    }
    bool period = false;
    for (; i < line.length(); ++i) {
        if (!std::isdigit(line[i])) {
            if (line[i] == '.' && period == false) {
                period = true;
                continue ;
            }
            return (RETURN_FAILURE);
        }
    }
    data.first = line.substr(0, 10);
    data.second = ft_stof(line.substr(10 + sep.length()));
    return (RETURN_SUCCESS);
}

static void readDatabase(Database &database) {
    std::ifstream in_file(DATABASE);
    if (in_file.is_open() == false) {
        throw std::runtime_error("could not open database file.");
    }
    std::string line;
    std::getline(in_file, line);
    if (line != "date,exchange_rate") {
        throw std::runtime_error("invalid database header.");
    }
    for (size_t i = 2; std::getline(in_file, line); ++i) {
        Data data;
        if (getData(data, line, ",") == RETURN_FAILURE) {
            std::ostringstream oss;
            oss << "invalid data in database! line: " << i;
            throw std::runtime_error(oss.str());
        }
        database[data.first] = data.second;
    }
    in_file.close();
}

static void runLine(Database &database, const std::string &line) {
    Data data;
    if (getData(data, line, " | ") == RETURN_FAILURE) {
        error("bad input => " + line);
        return ;
    } else if (data.second < 0) {
        error("not a positive number.");
        return ;
    } else if (data.second > 1000) {
        error("too large a number.");
        return ;
    }

    float result;
    Database::iterator it = database.find(data.first);
    if (it != database.end()) {
        result = it->second * data.second;
    } else if (data.first.compare(database.begin()->first) >= 0) {        
        result = (--database.lower_bound(data.first))->second * data.second;
    } else {
        error("date precedes lowest date in database => " + data.first);
        return ;
    }
    cout << data.first << " => " << data.second << " = " << result << endl;
}

void btc(const std::string input) {
    Database database;
    readDatabase(database);
    
    std::ifstream in_file(input.c_str());
    if (in_file.is_open() == false) {
        throw std::runtime_error("could not open input file.");
    }
    
    std::string line;
    std::getline(in_file, line);
    if (line != "date | value") {
        throw std::runtime_error("invalid input file header.");
    }
    while (std::getline(in_file, line)) {
        runLine(database, line);
    }
    in_file.close();
}
