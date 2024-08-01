/*
* Author: Bryan Cardeno
* File : ElementLookupException.h
* Date : 5/11/2024
* Description: Header file for ElementLookupException.cpp
*/

#pragma once

#include <exception>
#include <string>

class ElementLookupException: public std::exception {
    const std::string DEFAULT_ERROR_MESSAGE = "Element does not exist in the table";

private:
    std::string message;

public:
    /**
     * @brief Default Constructor. Assigns message with the DEFAULT ERROR MESSAGE.
     */
    ElementLookupException();

    /**
     * @brief provides error message
     * @return message
     */
    virtual const char* what();
};

