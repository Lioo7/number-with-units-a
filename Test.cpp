/**
 * Unit tests.
 * AUTHORS: <Lioz Akirav>
 * Date: 2021-04
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

// TEST_CASE("Valid and equal snowman code - no spaces")
// {
//     /* Assert True */
//     CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
// }

// TEST_CASE("Valid and equal snowman code - with spaces") {
//     CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
// }

ifstream units_file{"units.txt"};
TEST_CASE("adds units from a text file")
{
    NumberWithUnits::read_units(units_file);
    // TODO: have to add some testss
}

TEST_CASE("checks basic arithmetic operators on distance elements")
{
    NumberWithUnits a{1, "km"};  // 1km = 1,000m = 100,000cm
    NumberWithUnits b{200, "m"}; // 0.2km = 200m = 20,000cm
    NumberWithUnits c{30, "c"};  // 0.0003km = 0.3m = 30cm
    NumberWithUnits a_n{-1, "km"};  // -1km = -1,000m = -100,000cm
    NumberWithUnits b_n{-200, "m"}; // -0.2km = -200m = -20,000cm
    NumberWithUnits c_n{-30, "c"};  // -0.0003km = -0.3m = -30cm

    // +
    CHECK(a + b == NumberWithUnits(1.2, "km"));
    CHECK(b + a == NumberWithUnits(1200, "m"));
    CHECK(a + c == NumberWithUnits(1.0003, "km"));
    CHECK(c + a == NumberWithUnits(100030, "cm"));
    CHECK(b + c == NumberWithUnits(200.3, "m"));
    CHECK(c + b == NumberWithUnits(20030, "cm"));
    // -
    CHECK(a - b == NumberWithUnits(0.8, "km"));
    CHECK(b - a == NumberWithUnits(800, "m"));
    CHECK(a - c == NumberWithUnits(0.997, "km"));
    CHECK(c - a == NumberWithUnits(99970, "cm"));
    CHECK(b - c == NumberWithUnits(199.7, "m"));
    CHECK(c - b == NumberWithUnits(19070, "cm"));
    // +=
    CHECK(a += NumberWithUnits{2, "km"} == NumberWithUnits(3, "km"));
    CHECK(b += NumberWithUnits{100, "m"} == NumberWithUnits(300, "m"));
    CHECK(c += NumberWithUnits{20, "cm"} == NumberWithUnits(50, "cm"));
    // -=
    CHECK(a -= NumberWithUnits{3, "km"} == NumberWithUnits(2, "km"));
    CHECK(b -= NumberWithUnits{300, "m"} == NumberWithUnits(100, "m"));
    CHECK(c -= NumberWithUnits{50, "cm"} == NumberWithUnits(20, "cm"));
    // +
    CHECK((+a_n) == a);
    CHECK((+b_n) == b);
    CHECK((+c_n) == c);
    // -
    CHECK((-a) == a_n);
    CHECK((-b) == b_n);
    CHECK((-c) == c_n);
}

TEST_CASE("checks basic arithmetic operators on mixed elements")
{
    NumberWithUnits d_a{1, "km"};  
    NumberWithUnits d_b{200, "m"}; 
    NumberWithUnits d_c{30, "c"};  
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
    // CHECK_THROWS(d_a += NumberWithUnits{2, "g"}); // TODO: what's the problem?
    // CHECK_THROWS(d_b += NumberWithUnits{100, "m"});
    CHECK_THROWS(d_c += d_c);
    // -=
    // CHECK_THROWS(a -= NumberWithUnits{3, "km"} == NumberWithUnits(2, "km"));
    // CHECK_THROWS(b -= NumberWithUnits{300, "m"} == NumberWithUnits(100, "m"));
    // CHECK_THROWS(c -= NumberWithUnits{50, "cm"} == NumberWithUnits(20, "cm"));
}