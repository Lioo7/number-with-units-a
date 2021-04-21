#include <iostream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{
    void NumberWithUnits::read_units(ifstream &units_file)
    {
    }

    // overloading the arithmetic operators
    // positive
    NumberWithUnits operator+(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return unit_element_1;
    }
    NumberWithUnits operator+=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return unit_element_1;
    }

    NumberWithUnits operator+(const NumberWithUnits &unit_element)
    {
        return unit_element;
    }
    // negative
    NumberWithUnits operator-(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return unit_element_1;
    }
    NumberWithUnits operator-=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return unit_element_1;
    }
    NumberWithUnits operator-(const NumberWithUnits &unit_element)
    {
        return unit_element;
    }

    // overloading equality operators
    bool operator>(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return true;
    }
    bool operator>=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return true;
    }
    bool operator<(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return true;
    }
    bool operator<=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return true;
    }
    bool operator==(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return true;
    }
    bool operator!=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        return true;
    }

    // overloading multiplication operator
    // direction: ->
    NumberWithUnits operator*(const NumberWithUnits &unit_element, double num)
    {
        return unit_element;
    }
    // NumberWithUnits operator*=(double num); // TODO: ?
    // direction: <-
    NumberWithUnits operator*(double num, const NumberWithUnits &unit_element)
    {
        return unit_element;
    }
    // friend NumberWithUnits operator*=(double num, const NumberWithUnits &unit_element); // TODO: ?

    // friend global overloading I/O operators
    std::istream &operator>>(istream &is, const NumberWithUnits &input_unit_element)
    {
        return is;
    }
    std::ostream &operator<<(ostream &os, const NumberWithUnits &output_unit_element)
    {
        return os;
    }

}
