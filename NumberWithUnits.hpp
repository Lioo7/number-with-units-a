#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

namespace ariel
{
    class NumberWithUnits
    {
    private:
        // bool empty = true;
        map<double, string> units;

    public:
        //constructor
        NumberWithUnits(double number, string unit) {}
        //destructor
        ~NumberWithUnits(){}; 

        static void read_units(ifstream &file_name);

        // overloading the arithmetic operators
        // positive
        NumberWithUnits operator+(const NumberWithUnits &element);
        NumberWithUnits &operator+=(const NumberWithUnits &element);
        NumberWithUnits &operator+(); // TODO ?
        // negative
        NumberWithUnits operator-(const NumberWithUnits &element);
        NumberWithUnits &operator-=(const NumberWithUnits &element);
        NumberWithUnits &operator-(); // TODO input?

        // overloading equality operators 
        bool operator>(const NumberWithUnits &element); // TODO friends?
        bool operator>=(const NumberWithUnits &element);
        bool operator<(const NumberWithUnits &element);
        bool operator<=(const NumberWithUnits &element);
        bool operator==(const NumberWithUnits &element);
        bool operator!=(const NumberWithUnits &element);

        // overloading increment and decrement operators
        // prefix
        NumberWithUnits &operator++();
        NumberWithUnits &operator--();
        // postfix
        NumberWithUnits &operator++(int);
        NumberWithUnits &operator--(int);

        // overloading multiplication operator
        // direction: ->
        friend NumberWithUnits operator*(const NumberWithUnits &element, double num);
        friend NumberWithUnits operator*=(const NumberWithUnits &element, double num);
        // direction: <-
        friend NumberWithUnits operator*(double num, const NumberWithUnits &element);
        friend NumberWithUnits operator*=(double num, const NumberWithUnits &element);

        // friend global overloading I/O operators
        friend ostream &operator<<(ostream &os, const NumberWithUnits &input);
        friend ostream &operator>>(ostream &os, const NumberWithUnits &output);
    };
}
