/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:53:21 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/16 17:13:54 by arabenst         ###   ########.fr       */
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

typedef enum e_types {
    T_INVALID,
    T_CHAR,
    T_NUM,
    T_SPECIAL
}   t_types;

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
    static t_types _type;
    static double _value;

};

#endif