/*
* Author: Bryan Cardeno
* File : Element.cpp
* Date : 5/9/2024
* Description: Implementation of Element header file.
*/

#include "Element.h"

#include <sstream>
#include <format>

//region CONSTRUCTORS
Element::Element(string& local_name, string& local_symbol, int local_atom_num, double local_atom_weight)
        :name(local_name), symbol(local_symbol), atomic_number(local_atom_num), atomic_weight(local_atom_weight) {
}

Element::Element(Element &local_element) {
    name = local_element.name;
    symbol = local_element.symbol;
    atomic_number = local_element.atomic_number;
    atomic_weight = local_element.atomic_weight;
}

Element::Element(): Element((string &) "", (string &) "", 0, 0) {
}
//endregion

//region ACCESSORS
string Element::getName() {
    return name;
}

int Element::getAtomicNumber() {
    return atomic_number;
}

string Element::getInformation() {
    return std::format("Atomic Number: {}, Symbol: {}, Name: {}, Atomic Weight: {}", atomic_number, symbol, name,atomic_weight);
}
//endregion

//region HELPERS
bool Element::operator<(Element &other_element) {
    return name < other_element.getName();
}

bool Element::operator>(Element &other_element) {
    return name > other_element.getName();
}
bool Element::operator==(Element &other_element) {
    return name == other_element.getName();
}

bool Element::operator<(std::string &element_name) {
    return toUpper(name) < toUpper(element_name);
}

bool Element::operator>(std::string &element_name) {
    return toUpper(name) > toUpper(element_name);
}

bool Element::operator==(std::string &element_name) {
    return toUpper(name) == toUpper(element_name);
}

bool Element::operator<(int &element_num) {
    return atomic_number < element_num;
}

bool Element::operator>(int &element_num) {
    return atomic_number > element_num;
}

bool Element::operator==(int &element_num) {
    return atomic_number == element_num;
}

std::string Element::toUpper(std::string &string_value) {
    std::stringstream return_value;

    for(char character:string_value) {
        return_value << std::toupper(character);
    }

    return return_value.str();
}
//endregion