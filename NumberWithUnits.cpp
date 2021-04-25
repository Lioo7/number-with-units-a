#include <iostream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;
map<string, map<string, double>> units_map;
const double epsilon = 0.001; // TODO: 001 or 0001?

namespace ariel
{
    //==============================================constructor=============================================
    NumberWithUnits::NumberWithUnits(double number, string unit)
    {
        this->number = number;
        this->unit = unit;
    }

    //==========================================ultilize functions==========================================

    // This function throws an error when gets invalid input 
    void throw_error(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        string a = unit_element_1.get_unit();
        string b = unit_element_2.get_unit();
        throw std::invalid_argument("Units do not match [" + a + "] cannot be converted to [" + b + "]");
    }

    // This function check is both of the elements are valid
    bool unit_check(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
    }

    // This function convert the unit if it's possible
    void unit_convert(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
    }

    // This function print the units_map
    void print_map()
    {
        for (auto itr_out = units_map.begin(); itr_out != units_map.end(); ++itr_out)
        {
            cout << itr_out->first << ":(";
            for (auto itr_in = itr_out->second.begin(); itr_in != itr_out->second.end(); ++itr_in)
            {
                cout << itr_in->first << ':' << itr_in->second << ')' << '\n';
            }
        }
    }

    //==========================================method operators============================================
    
    void NumberWithUnits::read_units(ifstream &units_file)
    {
        ifstream units_file{"units.txt"};
        string line;

        // iterates through the lines of the file
        while (std::getline(units_file, line))
        {
            int count = 0;
            double num_1 = 0;
            double num_2 = 0;
            string unit_1 = "null";
            string unit_2 = "null";
            string temp = "";

            // iterates through the characters of the line
            for (int i = 0; i < line.length(); i++)
            {
                if (i == line.length() - 1) // last char
                {
                    count++;
                }
                if (line[i] == '=') // '='
                {
                    i++;
                    continue;
                }
                else if (line[i] == ' ') // space
                {
                    count++;
                }
                else
                {
                    temp += line[i]; // valid char
                }

                if (count == 1 && num_1 == 0) // first number
                {
                    num_1 = stod(temp); // convers the string to double
                    temp = "";
                }
                else if (count == 2 && unit_1 == "null") // first unit
                {
                    unit_1 = temp;
                    temp = "";
                }
                else if (count == 3 && num_2 == 0) // second number
                {
                    num_2 = stod(temp); // convers the string to double
                    temp = "";
                }
                else if (count == 4 && unit_2 == "null") // second unit
                {
                    unit_2 = temp;
                    temp = "";
                }
            }

            units_map[unit_1][unit_2] = num_2;         // adds the first direction ->
            units_map[unit_2][unit_1] = num_1 / num_2; // adds the opposite direction <-
        }
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
