#include <iostream>
#include <map>
#include <cmath>
#include "NumberWithUnits.hpp"
using namespace std;
map<string, map<string, double>> units_map;
const double epsilon = 0.001;

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
    void NumberWithUnits::throw_error(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        string a = unit_element_1.unit;
        string b = unit_element_2.unit;
        throw std::invalid_argument("Units do not match [" + a + "] cannot be converted to [" + b + "]");
    }

    // This function check is the element is valid
    bool NumberWithUnits::is_valid(const NumberWithUnits &unit_element_1)
    {
        return (units_map.count(unit_element_1.unit) > 0);
    }

    // This function convert the unit if it's possible and necessary
    double NumberWithUnits::unit_convert(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        double ans = unit_element_2.number;
        // checks if both of the elements are valid
        if (!is_valid(unit_element_1) || !is_valid(unit_element_2))
        {
            throw_error;
        }
        // checks if both the elments have the same unit
        else if (unit_element_1.unit == unit_element_2.unit)
        {
            return ans;
        }
        // checks if is it possible to convert
        else if (units_map[unit_element_1.unit].count(unit_element_2.unit) < 1)
        {
            throw_error;
        }
        // returns the convert number(second number * ratio)
        else
        {
            double second_number = unit_element_2.number;
            double ratio = units_map[unit_element_1.unit][unit_element_2.unit];
            ans = second_number * ratio;
        }
        return ans;
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

            // finds transitive relations between the units in the map
            // iterates through the units_map
            for (auto itr = units_map.begin(); itr != units_map.end(); ++itr)
            {
                // takes the inner unit
                auto itr_in = itr->second.begin();
                // iterates through the units_map
                for (auto itr_out = units_map.begin(); itr_out != units_map.end(); ++itr_out)
                {
                    // checks if the inner unit equals to the outer unit
                    if (itr_in->first == itr_out->first)
                    {
                        // adds the first direction ->
                        units_map[itr_out->first][itr_in->first] = itr_in->second * itr_out->second; // TODO
                        // adds the opposite direction <-
                        units_map[itr_in->first][itr_out->first] = (1 / itr_in->second) / itr_out->second;
                    }
                }
            }
        }
    }

    // overloading the arithmetic operators
    // positive
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &unit_element)
    {
        double sum = unit_convert(*this, unit_element);
        return NumberWithUnits(this->number + sum, this->unit);
    }
    NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits &unit_element)
    {
        double sum = unit_convert(*this, unit_element);
        this->number += sum;
        return NumberWithUnits(*this);
    }

    NumberWithUnits NumberWithUnits::operator+()
    {
        double positive_value = std::abs(this->number);
        return NumberWithUnits{positive_value, this->unit};
    }
    // negative
    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &unit_element)
    {
        double sum = unit_convert(*this, unit_element);
        return NumberWithUnits(this->number - sum, this->unit);
    }
    NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits &unit_element)
    {
        double sum = unit_convert(*this, unit_element);
        this->number -= sum;
        return NumberWithUnits(*this);
    }
    NumberWithUnits NumberWithUnits::operator-()
    {
        double negatice_value = std::abs(this->number) * -1;
        return NumberWithUnits{negatice_value, this->unit};
    }

    // overloading equality operators
    bool NumberWithUnits::operator>(const NumberWithUnits &unit_element)
    {
        double num_1 = this->number;
        double num_2 = unit_convert(*this, unit_element);
        return (num_1 - num_2 > epsilon);
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &unit_element)
    {
        return (*this > unit_element || *this == unit_element);
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &unit_element)
    {
        double num_1 = this->number;
        double num_2 = unit_convert(*this, unit_element);
        return (num_1 - num_2 < epsilon);
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &unit_element)
    {
        return (*this < unit_element || *this == unit_element);
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &unit_element) // TODO: check for recursion
    {
        double num_1 = this->number;
        double num_2 = unit_convert(*this, unit_element);
        double sum = num_1 - num_2;
        return (sum >= 0 && sum <= epsilon);
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &unit_element)
    {
        return *this != unit_element;
    }

    // overloading multiplication operator
    // direction: ->
    NumberWithUnits NumberWithUnits::operator*(double num)
    {
        return NumberWithUnits{this->number * num, this->unit};
    }
    // direction: <-
    NumberWithUnits operator*(double num, const NumberWithUnits &unit_element)
    {
        return NumberWithUnits{unit_element.number * num, unit_element.unit};
    }

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
