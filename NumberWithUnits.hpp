#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double number;
        string unit;

    public:
        // getters
        double get_number() const
        {
            return this->number;
        }

        string get_unit() const
        {
            return this->unit;
        }

        // setters
        void set_number(double new_number)
        {
            this->number = new_number;
        }

        // constructor
        NumberWithUnits(double number = 0, string unit = "none")
        {
            // this->number = number;
            // this->unit = unit;
        }
        // destructor
        ~NumberWithUnits(){};

        static void read_units(std::ifstream &file_name);

        // overloading the arithmetic operators
        // positive
        friend NumberWithUnits operator+(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend NumberWithUnits operator+=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend NumberWithUnits operator+(const NumberWithUnits &unit_element);
        // negative
        friend NumberWithUnits operator-(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend NumberWithUnits operator-=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend NumberWithUnits operator-(const NumberWithUnits &unit_element);

        // overloading equality operators
        friend bool operator>(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend bool operator>=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend bool operator<(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend bool operator<=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend bool operator==(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);
        friend bool operator!=(const NumberWithUnits &unit_element_1, const NumberWithUnits &unit_element_2);

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
        friend NumberWithUnits operator*(const NumberWithUnits &unit_element, double num);
        // NumberWithUnits operator*=(double num); // TODO: ?
        // direction: <-
        friend NumberWithUnits operator*(double num, const NumberWithUnits &unit_element);
        // friend NumberWithUnits operator*=(double num, const NumberWithUnits &unit_element); // TODO: ?

        // friend global overloading I/O operators
        friend std::istream &operator>>(istream &is, const NumberWithUnits &input_unit_element);
        friend std::ostream &operator<<(ostream &os, const NumberWithUnits &output_unit_element);
    };
}
