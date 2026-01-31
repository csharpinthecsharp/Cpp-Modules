#include "ScalarConverter.hpp"
#include <limits>
#include <iomanip>

// START OF *
// ScalarConvert is not instantiable, so it will never be printed.
// I choose to still put them into it since the rules of CPP say,
// That all exos need to have canonical orthodox style. 
ScalarConverter::ScalarConverter() {
    std::cout << "Scalar constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter() { 
    std::cout << "Scalar destructor called" << std::endl;
}
ScalarConverter::ScalarConverter( const ScalarConverter& sr ) { 
    std::cout << "Scalar copy constructor called" << std::endl;
    *this = sr; 
}
ScalarConverter &ScalarConverter::operator=( const ScalarConverter& sr ) {
    std::cout << "Scalar copy assignement operator  called" << std::endl;
    return *this;
}
// END OF *

enum _return {
    _char,
    _int,
    _double,
    _float,
    _unknown,
};

static const std::string _special[6] = {
    "nan",
    "nanf",
    "+inf",
    "+inff",
    "-inf",
    "-inff"
};

static bool handle_special( const std::string &str ) {
    for (int i(0); i < 6; i++) {
        if (str.compare(_special[i]) == 0)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (i == 0 || i == 1) {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            }
            else if (i == 2 || i == 3) {
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
            }
            else if (i == 4 || i == 5) {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            }
            return true;
        }
    }
    return false;
}

static bool isIntOverflow( long value ) {
    if (value <= std::numeric_limits<int>::max() 
        && value >= std::numeric_limits<int>::lowest()) 
        return true;
    return false;
}

static bool isDoubleOverflow( long double value ) {
    if (value <= std::numeric_limits<double>::max() 
        && value >= std::numeric_limits<double>::lowest()) 
        return true;
    return false;
}

static bool isFloatOverflow( long double value ) {
    if (value <= std::numeric_limits<float>::max() 
        && value >= std::numeric_limits<float>::lowest()) 
        return true;
    return false;
}

static void checkPrintInt( long value ) {
    if (isIntOverflow(value))
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

static void checkPrintDouble( long double value ) {
    if (isDoubleOverflow(value)) {
        std::cout << "double: " << static_cast<double>(value);
        if ((value - static_cast<int>(value)) == 0)
            std::cout << ".0" << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}

static void checkPrintFloat( long double value ) {
    if (isFloatOverflow(value)) {
        std::cout << "float: " << static_cast<float>(value);
        if ((value - static_cast<int>(value)) == 0)
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
}

static void checkPrintChar( long value ) {
    if (!isascii(static_cast<int>(value)))
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
}

static void printChar( const std::string& str ) {
    checkPrintChar(static_cast<long>(str[0]));
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    return ;
}

static void printInt( const std::string& str ) {
    long value = strtol(str.c_str(), NULL, 10);
    checkPrintChar(value);
    checkPrintInt(value);
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    return ;
}

static void printDouble( const std::string& str ) {
    double value = strtod(str.c_str(), NULL);
    checkPrintChar(static_cast<long>(value));
    checkPrintInt(static_cast<long>(value));
    checkPrintFloat(value); 
    checkPrintDouble(value);
    return ;
}

static void printFloat( const std::string& str ) {
    double value = strtod(str.c_str(), NULL);
    checkPrintChar(static_cast<long>(value));
    checkPrintInt(static_cast<long>(value));
    checkPrintFloat(value);
    checkPrintDouble(value);
    return ;
}

static bool isChar( const std::string& str ) {
    if (str.length() != 1 || isdigit(str[0])) return false;
    return true;
}

static bool isInt( const std::string& str ) {
    if (str.length() == 1 && isdigit(str[0])) return true;
    for (int i(0); i < str.length(); i++) {
        while (str[i] == ' ' || str[i] == '-' || str[i] == '+')
            i++;
        if (!isdigit(str[i])) return false;
    }
    return true;
}

static bool isDouble(const std::string& str)
{
    if (str.length() == 1 && isdigit(str[0])) return true;
    for (int i(0), count(0); i < str.length(); i++) {
        while (str[i] == ' ' || str[i] == '-' || str[i] == '+')
            i++;
        if (!isdigit(str[i])) {
            if (str[i] == '.' && count == 0) count+=1;
            else return false;
        }
    }
    return true;
}

static bool isFloat(const std::string& str)
{
    if (str.length() == 1 && isdigit(str[0])) return true;
    for (int i(0), count(0); i < (str.length() - 1); i++) {
        while (str[i] == ' ' || str[i] == '-' || str[i] == '+')
            i++;
        if (!isdigit(str[i])) {
            if (str[i] == '.' && count == 0) count+=1;
            else return false;
        }
    }
    if (str[str.length() - 1] == 'f')
        return true;
    return false;
}

static _return getType( const std::string& str ) {
    if (isChar(str)) return _char;
    if (isInt(str)) return _int;
    if (isDouble(str)) return _double;
    if (isFloat(str)) return _float;
    return _unknown;
}

void ScalarConverter::convert( const std::string& str ) {
    if (handle_special(str))
        return ;
    _return type = getType(str);
    switch (type) {
        case _char:
            std::cout << "selected char." << std::endl;
            printChar(str);
            break;
        case _int:
            std::cout << "selected int." << std::endl;
            printInt(str);
            break;
        case _double:
            std::cout << "selected double." << std::endl;
            printDouble(str);
            break;
        case _float:
            std::cout << "selected float." << std::endl;
            printFloat(str);
            break;
        case _unknown:
            std::cout << "I don't recognize your input lil bro." << std::endl;
            break;
    }
}
