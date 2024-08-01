/*
* Author: Bryan Cardeno
* File : Element.h
* Date : 5/9/2024
* Description: Header file for Eleemnt.cpp
*/

#pragma once

#include <string>

using std::string;

class Element {
private:
    string name;
    string symbol;
    int atomic_number;
    double atomic_weight;

public:
    //region CONSTRUCTORS
    /**
     * @brief Working constructor.
     * @param local_name name of the element
     * @param local_symbol symbol of the element
     * @param local_atom_num atomic number of the element
     * @param local_atom_weight atomic weight of the element
     */
    Element(string& local_name, string& local_symbol, int local_atom_num, double local_atom_weight);

    /**
     * @brief Constructor with Element parameter
     * @param local_element Element data type.
     */
    Element(Element& local_element);

    /**
     * @brief Default constructor. Utilizes working constructor passing default values.
     */
    Element();
    //endregion

    //region ACCESSORS
    /**
     * @brief Get the name property of the element.
     * @return name string value
     */
    string getName();

    /**
     * @brief Get the atomic number property of the element.
     * @return atomic number int value
     */
    int getAtomicNumber();

    /**
     * @brief Get the properties of the element. Name, symbol, atomic number, and atomic weight.
     * @return string value of all the properties.
     */
    string getInformation();
    //endregion

    //region HELPERS
    /**
     * @brief Overload less than operator. Compares name value of the elements.
     * @param other_element Secondary element to compare to.
     * @return true or false depending on the result.
     */
    bool operator<(Element& other_element);

    /**
     * @brief Overload greater than operator. Compares name value of the elements.
     * @param other_element Secondary element to compare to.
     * @return true or false depending on the result.
     */
    bool operator>(Element& other_element);

    /**
     * @brief Overload equal to operator. Compares the name value of the elements.
     * @param other_element Secondary element to compare to.
     * @return true or false depending on the result.
     */
    bool operator==(Element& other_element);

    /**
     * @brief Overload less than operator. Compares name value of the main operator to the string parameter.
     * @param element_name String value of the element to compare to.
     * @return true or false depending on the result.
     */
    bool operator<(std::string &element_name);

    /**
     * @brief Overload greater than operator. Compares name value of the main operator to the string parameter.
     * @param element_name String value of the element to compare to.
     * @return true or false depending on the result.
     */
    bool operator>(std::string &element_name);

    /**
     * @brief Overload equal to operator. Compares name value of the main operator to the string parameter.
     * @param element_name String value of the element to compare to.
     * @return true or false depending on the result.
     */
    bool operator==(std::string &element_name);

    /**
     * @brief Overload less than operator. Compares the atomic number of the element to the int parameter.
     * @param element_num int value of the element to compare to.
     * @return true or false depending on the result.
     */
    bool operator<(int &element_num);

    /**
     * @brief Overload greater than operator. Compares the atomic number of the element to the int parameter.
     * @param element_num int value of the element to compare to.
     * @return true or false depending on the result.
     */
    bool operator>(int &element_num);

    /**
     * @brief Overload equal to operator. Compares the atomic number of the element to the int parameter.
     * @param element_num int value of the element to compare to.
     * @return true or false depending on the result.
     */
    bool operator==(int &element_num);

    /**
     * @brief Converts passed string value to all upper case.
     * @param string_value string.
     * @return upper cased value of the string value.
     */
    std::string toUpper(std::string &string_value);
    //endregion
};


