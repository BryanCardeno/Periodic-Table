/*
* Author: Bryan Cardeno
* File : ElementLookup.h
* Date : 5/9/2024
* Description: Header file for ElementLookup.cpp
*/

#pragma once


#include <vector>

#include "../AVL Tree/AvlTree.h"
#include "../Element/Element.h"

class ElementLookup {
    const std::string INPUT_FILE_PATH = "..\\Files\\periodicTable.csv";
    const char DELIMITER_CHAR = ',';
    const std::string EXCEPTION_MESSAGE = "Element does not exist in the table";

private:
    AvlTree<Element> element_tree;

public:
    //region CONSTRUCTORS
    /**
     * @brief Default constructor. Initializes tree.
     */
    ElementLookup();
    //endregion

    //region MUTATORS
    /**
     * @brief Initializes element tree by parsing data from the input file.
     */
    void initializeTree();
    //endregion

    //region ACCESSORS
    /**
     * @brief Look up element in the element tree by inputting a valid element name.
     * @return string value information of the element.
     */
    std::string lookupByName();

    /**
     * @brief Look up element in the element tree by inputting a valid element atomic number.
     * @return string value information of the element.
     */
    std::string lookupByNumber();
    //endregion

    //region HELPERS
    /**
     * @brief Parses the passed line from the input file.
     * @param string_value line from the input file.
     * @return a vector of the required element properties from the parsed line.
     */
    std::vector<string> parseString(std::string& string_value);

    /**
     * @brief Remove leading and trailing white spaces.
     * @param string_value string type.
     * @return modified string value.
     */
    std::string trimWhiteSpace(std::string& string_value);

    /**
     * @brief Provides menu option and prompts the user to select from the options.
     */
    void menu();
    //endregion
};

