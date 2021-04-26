#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace ariel
{
    class NumberWithUnits
    {
    private:
        // variables
        double number;
        string unit;

        // functions
        void throw_error(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        bool is_valid(const NumberWithUnits &unit_element_1);
        double unit_convert(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        void print_map();

    public:
        // constructor
        NumberWithUnits(double number, string unit){};
        // destructor
        ~NumberWithUnits(){};

        static void read_units(std::ifstream &file_name);

        // overloading the arithmetic operators
        // positive
        NumberWithUnits operator+(const NumberWithUnits &unit_element);
        NumberWithUnits operator+=(const NumberWithUnits &unit_element);
        NumberWithUnits operator+();
        // negative
        NumberWithUnits operator-(const NumberWithUnits &unit_element);
        NumberWithUnits operator-=(const NumberWithUnits &unit_element);
        NumberWithUnits operator-();

        // overloading equality operators
        bool operator>(const NumberWithUnits &unit_element);
        bool operator>=(const NumberWithUnits &unit_element);
        bool operator<(const NumberWithUnits &unit_element);
        bool operator<=(const NumberWithUnits &unit_element);
        bool operator==(const NumberWithUnits &unit_element);
        bool operator!=(const NumberWithUnits &unit_element);

        // overloading increment and decrement operators
        // prefix
        NumberWithUnits &operator++()
        {
            number++;
            return *this;
        }
        NumberWithUnits &operator--()
        {
            number--;
            return *this;
        }
        // postfix
        NumberWithUnits operator++(int)
        {
            NumberWithUnits original = *this;
            number++;
            return original;
        }
        NumberWithUnits operator--(int)
        {
            NumberWithUnits original = *this;
            number--;
            return original;
        }

        // overloading multiplication operator
        // direction: ->
        NumberWithUnits operator*(double num);
        // direction: <-
        friend NumberWithUnits operator*(double num, const NumberWithUnits &unit_element);

        // friend global overloading I/O operators
        friend std::istream &operator>>(istream &is, const NumberWithUnits &input_unit_element);
        friend std::ostream &operator<<(ostream &os, const NumberWithUnits &output_unit_element);
    };
}
