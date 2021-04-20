// #include <iostream>
// #include <map>
#include "NumberWithUnits.hpp"
#include <map>
using namespace std;

namespace ariel
{
    //==============================================constructor=============================================
    map<string, map<string, double>> units;
    NumberWithUnits::NumberWithUnits(double number, string unit)
    {
        this->number = number;
        this->unit = unit;
    }

    //==========================================ultilize functions==========================================
    void throw_error(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        string a = unit_element_1.get_unit();
        string b = unit_element_2.get_unit();
        throw std::invalid_argument("Units do not match [" + a + "] cannot be converted to [" + b + "]");
    }

    bool unit_check(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2)
    {
        bool flag = false; // not equal

        if (unit_element_1.get_unit() == unit_element_2.get_unit())
        {
            flag = true;
        }

        else
        {
            for (unit_element : units)
            {
                if (unit_element) //TODO: have to add some code here
            }
        }

        if (!flag) // if not equal throw error
        {
            throw_error(unit_element_1, unit_element_2);
        }

        return flag;
    }

    //==========================================method operators============================================
    void read_units(ifstream &file_name)
    {
        // TODO: add some code here
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &unit_element)
    {
        if (unit_check(*this, unit_element)) // both elements have the same type
        {
            double sum = *this.get_number() + unit_element.get_number();
            NumberWithUnits temp = {sum, unit_element.get_unit()};
        }
        return temp;
    }

    NumberWithUnits &operator+=(const NumberWithUnits &unit_element)
    {
        if (unit_check(*this, unit_element)) // both elements have the same type
        {
            this.set_number(*this.get_number() + unit_element.get_number());
        }
        return *this;
    }

}
