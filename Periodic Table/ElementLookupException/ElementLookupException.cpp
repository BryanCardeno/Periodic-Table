/*
* Author: Bryan Cardeno
* File : ElementLookupException.cpp
* Date : 5/11/2024
* Description: Implementation of ElementLookup header file.
*/

#include "ElementLookupException.h"

ElementLookupException::ElementLookupException() :message(DEFAULT_ERROR_MESSAGE){
}

const char *ElementLookupException::what() {
    return message.c_str();
}
