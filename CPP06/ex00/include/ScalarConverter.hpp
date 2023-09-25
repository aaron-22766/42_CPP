/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:53:21 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/23 20:24:40 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <sstream>
# include <exception>
# include <limits>
# include <iomanip>

/* ************************************************************************** */
/*                                   USING                                    */
/* ************************************************************************** */

using std::cout;
using std::cerr;
using std::endl;

/* ************************************************************************** */
/*                                   ENUMS                                    */
/* ************************************************************************** */

enum e_types {
    T_INVALID,
    T_CHAR,
    T_NUM,
    T_SPECIAL
};

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class ScalarConverter {

public:

    typedef ScalarConverter SC;

    static void convert(const std::string input);
    
    class InvalidInputException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

private:

    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter(void);

    static void checkType(void);
    static void trimFloatExtension(void);
    static void readValue(void);
    static void printChar(void);
    static void printInt(void);
    static void printFloat(void);
    static void printDouble(void);

    static std::string _s;
    static int8_t _type;
    static double _value;

};

#endif