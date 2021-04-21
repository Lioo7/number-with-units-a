/**
 * Unit tests.
 * AUTHORS: <Lioz Akirav>
 * Date: 2021-04
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <sstream>
using std::istringstream;
using std::string;
using namespace std;
using namespace ariel;
const string TRUE = "true";
const string FALSE = "false";
const ifstream units_file{"units.txt"};

NumberWithUnits a{1, "km"};     // 1km = 1,000m = 100,000cm
NumberWithUnits b{200, "m"};    // 0.2km = 200m = 20,000cm
NumberWithUnits c{30, "cm"};    // 0.0003km = 0.3m = 30cm
NumberWithUnits a_n{-1, "km"};  // -1km = -1,000m = -100,000cm
NumberWithUnits b_n{-200, "m"}; // -0.2km = -200m = -20,000cm
NumberWithUnits c_n{-30, "cm"}; // -0.0003km = -0.3m = -30cm

TEST_CASE("checks basic arithmetic operators on distance elements")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    // +
    CHECK(a + b == NumberWithUnits(1.2, "km"));
    CHECK(b + a == NumberWithUnits(1200, "m"));
    CHECK(a + c == NumberWithUnits(1.0003, "km"));
    CHECK(c + a == NumberWithUnits(100030, "cm"));
    CHECK(b + c == NumberWithUnits(200.3, "m"));
    CHECK(c + b == NumberWithUnits(20030, "cm"));
    // -
    CHECK(a - b == NumberWithUnits(0.8, "km"));
    CHECK(b - a == NumberWithUnits(-800, "m"));
    CHECK(a - c == NumberWithUnits(0.9997, "km"));
    CHECK(c - a == NumberWithUnits(-99970, "cm"));
    CHECK(b - c == NumberWithUnits(199.7, "m"));
    CHECK(c - b == NumberWithUnits(-19970, "cm"));
    // +=
    a += NumberWithUnits{2, "km"};
    CHECK(a == NumberWithUnits(3, "km"));
    b += NumberWithUnits{100, "m"};
    CHECK(b == NumberWithUnits(300, "m"));
    c += NumberWithUnits{20, "cm"};
    CHECK(c == NumberWithUnits(50, "cm"));
    // -=
    a -= NumberWithUnits{2, "km"};
    CHECK(a == NumberWithUnits(1, "km"));
    b -= NumberWithUnits{100, "m"};
    CHECK(b == NumberWithUnits(200, "m"));
    c -= NumberWithUnits{20, "cm"};
    CHECK(c == NumberWithUnits(30, "cm"));
}

TEST_CASE("checks basic arithmetic operators on mixed elements")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits d_a{1, "km"};
    NumberWithUnits d_b{200, "m"};
    NumberWithUnits d_c{30, "cm"};
    NumberWithUnits w_a{1, "ton"};
    NumberWithUnits w_b{200, "kg"};
    NumberWithUnits w_c{30, "g"};

    // +
    CHECK_THROWS(d_a + w_b);
    CHECK_THROWS(d_b + w_a);
    CHECK_THROWS(d_a + w_c);
    CHECK_THROWS(w_c + d_a);
    CHECK_THROWS(w_b + d_c);
    CHECK_THROWS(w_c + d_b);
    // -
    CHECK_THROWS(d_a - w_b);
    CHECK_THROWS(d_b - w_a);
    CHECK_THROWS(d_a - w_c);
    CHECK_THROWS(w_c - d_a);
    CHECK_THROWS(w_b - d_c);
    CHECK_THROWS(w_c - d_b);
    // +=
    CHECK_THROWS(d_a += w_a);
    CHECK_THROWS(d_b += w_b);
    CHECK_THROWS(d_c += w_c);
    // -=
    CHECK_THROWS(d_a -= w_a);
    CHECK_THROWS(d_b -= w_b);
    CHECK_THROWS(d_c -= w_c);
}

TEST_CASE("unary operators")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    // +
    CHECK((+a_n) == a);
    CHECK((+b_n) == b);
    CHECK((+c_n) == c);
    // -
    CHECK((-a) == a_n);
    CHECK((-b) == b_n);
    CHECK((-c) == c_n);
}

TEST_CASE("checks basic equality operators")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    string result;

    // true
    result = (a == a);
    CHECK(result == TRUE);
    result = (a != c);
    CHECK(result == TRUE);
    result = (a > b);
    CHECK(result == TRUE);
    result = (b > c);
    CHECK(result == TRUE);
    result = (c >= c);
    CHECK(result == TRUE);
    // false
    result = (a != a);
    CHECK(result == FALSE);
    result = (a == c);
    CHECK(result == FALSE);
    result = (a < b);
    CHECK(result == FALSE);
    result = (b <= c);
    CHECK(result == FALSE);
    result = (b == b_n);
    CHECK(result == FALSE);
    result = (c < c_n);
    CHECK(result == FALSE);
}

TEST_CASE("pre/post fix")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    // pre
    NumberWithUnits temp{1, "km"};
    temp = ++a;
    CHECK(temp == NumberWithUnits{2, "km"});
    temp = ++b;
    CHECK(temp == NumberWithUnits{201, "m"});
    temp = --a;
    CHECK(temp == NumberWithUnits{1, "km"});
    temp = --b;
    CHECK(temp == NumberWithUnits{200, "m"});

    // post
    temp = a++;
    CHECK(temp == NumberWithUnits{1, "km"});
    temp = b++;
    CHECK(temp == NumberWithUnits{200, "m"});
    temp = a--;
    CHECK(temp == NumberWithUnits{2, "km"});
    temp = b--;
    CHECK(temp == NumberWithUnits{201, "m"});
}

TEST_CASE("multiplication operator")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    // direction: ->
    CHECK(a * 2 == NumberWithUnits(2, "km"));
    CHECK(b * 1 == NumberWithUnits(200, "m"));
    CHECK(c * 10.5 == NumberWithUnits(315, "cm"));
    // direction: <-
    CHECK(2 * a == NumberWithUnits(2, "km"));
    CHECK(1 * b == NumberWithUnits(200, "m"));
    CHECK(10.5 * c == NumberWithUnits(315, "cm"));
}

TEST_CASE("I/O operators")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    // input
    NumberWithUnits input{0, "none"}; //TODO: have to check
    istringstream my_stream_1("1[km]");
    my_stream_1 >> input;
    CHECK(input == a);

    NumberWithUnits input_2(0, "none");
    istringstream my_stream_2("200 [ m ]");
    my_stream_2 >> input_2;
    CHECK(input_2 == b);

    // output
    ostringstream output;
    output << a;
    CHECK(output.str() == "1[km]");

    ostringstream output2;
    output2 << b;
    CHECK(output2.str() == "200[m]");
}