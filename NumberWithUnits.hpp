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
        NumberWithUnits(double number, string unit)
        {
        }
        // destructor
        ~NumberWithUnits(){};

        static void read_units(ifstream &file_name);

        // overloading the arithmetic operators
        // positive
        NumberWithUnits operator+(const NumberWithUnits &unit_element);
        NumberWithUnits &operator+=(const NumberWithUnits &unit_element);
        NumberWithUnits &operator+(); // TODO ?
        // negative
        NumberWithUnits operator-(const NumberWithUnits &unit_element);
        NumberWithUnits &operator-=(const NumberWithUnits &unit_element);
        NumberWithUnits &operator-(); // TODO input?

        // overloading equality operators
        bool operator>(const NumberWithUnits &unit_element);
        bool operator>=(const NumberWithUnits &unit_element);
        bool operator<(const NumberWithUnits &unit_element);
        bool operator<=(const NumberWithUnits &unit_element);
        bool operator==(const NumberWithUnits &unit_element);
        bool operator!=(const NumberWithUnits &unit_element);

        // overloading increment and decrement operators
        // prefix
        NumberWithUnits &operator++();
        NumberWithUnits &operator--();
        // postfix
        NumberWithUnits &operator++(int);
        NumberWithUnits &operator--(int);

        // overloading multiplication operator
        // direction: ->
        NumberWithUnits operator*(double num);
        NumberWithUnits operator*=(double num);
        // direction: <-
        friend NumberWithUnits operator*(double num, const NumberWithUnits &unit_element);
        friend NumberWithUnits operator*=(double num, const NumberWithUnits &unit_element);

        // friend global overloading I/O operators
        friend std::istream &operator>>(istream &is, const NumberWithUnits &input_unit_element);
        friend std::ostream &operator<<(ostream &os, const NumberWithUnits &output_unit_element);
    };
}
