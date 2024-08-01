/*
* Author: Bryan Cardeno
* File : ElementLookup.cpp
* Date : 5/9/2024
* Description: Implementation of ElementLookup header file.
*/
#include "ElementLookup.h"

#include <fstream>

#include "../ElementLookupException/ElementLookupException.h"

//region CONSTRUCTORS
ElementLookup::ElementLookup() {
    initializeTree();
}
//endregion

//region MUTATORS
void ElementLookup::initializeTree() {
    std::fstream input_file(INPUT_FILE_PATH);
    std::string target_line;

    if(input_file.is_open()) {

        //skip first line or column HEADERS
        std::getline(input_file,target_line);

        while(std::getline(input_file,target_line)) {

            std::vector<string> parsed_data = parseString(target_line);

            Element local_element(parsed_data.at(0), parsed_data.at(1), std::stoi(parsed_data.at(2)), std::stod(parsed_data.at(3)));
            element_tree.insert(local_element);
        }
    }
}
//endregion

//region ACCESSORS
std::string ElementLookup::lookupByName() {
    std::string user_input;

    std::cout << "Please enter Element name" << std::endl;
    std::getline(std::cin, user_input);

    Element* element_ptr = element_tree.retrieveData(user_input);

    if(element_ptr == nullptr) {
        throw ElementLookupException();
    }

    return element_ptr->getInformation();
}

std::string ElementLookup::lookupByNumber() {
    int user_input;

    std::cout << "Please enter the Atomic Number" << std::endl;
    std::cin >> user_input;
    std::cin.get();

    Element* element_ptr = element_tree.retrieveData(user_input);

    if(element_ptr == nullptr) {
        throw ElementLookupException();
    }

    return element_ptr->getInformation();
}
//endregion

//region HELPERS
std::vector<string> ElementLookup::parseString(string& string_value) {
    std::vector<string> list;

    int numberOfCommasToParse = 4;
    int counter = 0;
    size_t current_index = 0;
    size_t comma_index = string_value.find(DELIMITER_CHAR);

    while(counter < numberOfCommasToParse) {
        std::string substring = string_value.substr(current_index, comma_index - current_index);
        list.push_back(trimWhiteSpace(substring));

        current_index = ++comma_index;
        comma_index = string_value.find(DELIMITER_CHAR, current_index);
        ++counter;
    }

    return list;
}

std::string ElementLookup::trimWhiteSpace(string &string_value) {
    size_t first_nonspace_index = string_value.find_first_not_of(' ');
    size_t last_nonspace_index = string_value.find_last_not_of(' ');

    return string_value.substr(first_nonspace_index, last_nonspace_index - first_nonspace_index + 1);
}

void ElementLookup::menu() {
    int user_input;
    string output;
    std::cout << "Lookup Element By:" << std::endl;
    std::cout << "1. Number" << std::endl;
    std::cout << "2. Name" << std::endl << std::endl;

    std::cout << "Please select input" << std::endl;
    std::cin >> user_input;
    std::cin.get();

    try {
        switch(user_input) {
            case 1:
                output = lookupByNumber();
                break;
            case 2:
                output = lookupByName();
                break;
            default:
                output = "Invalid option selected";
                break;
        }
    }
    catch(ElementLookupException& ex) {
        output = ex.what();
    }

    std::cout << output << std::endl;
}
//endregion












