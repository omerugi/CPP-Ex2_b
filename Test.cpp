// authors: Lilach Mor & Omer Rugi

/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * Date: 2020-02
 */

#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"
using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("one x") {

RealVariable x;
CHECK(solve(2*x-4 == 10) == 4);
CHECK(solve(3*x-9 == 0) == 3);
CHECK(solve(6*x-x-4*x-12 == 10) == 22);
CHECK(solve(4*x-3+2*x+6==2*x-4*x-x+12) == 1);
CHECK(solve(3*x-3+1*x-6==3*x-5*x-x) == 1);
CHECK(solve(3*x+1*x+0==3*x-5*x-x+6+9) == 1);
CHECK(solve(3*x-6==3) == 3);
CHECK(solve(2*x-9 == 3) == 7);
CHECK(solve(4*x-9 == 7) == 4);
CHECK(solve(3*x-30 == 3) == 11);
CHECK(solve(5*x-9 == 1) == 2);
CHECK(solve(7*x+10 == -4) == -2);
CHECK(solve(10*x+10 == -4) == -1.4);
CHECK(solve(20*x+10 == -4) == -0.7);
CHECK(solve(5*x+10 == -4) == -2.8);
CHECK(solve(4*x+10 == -4) == -3.5);
CHECK(solve(10*x== 25) == 2.5);
CHECK(solve(2*x == 25) == 12.5);

}

TEST_CASE("complex one x") {

ComplexVariable x;
CHECK(solve(2*x-4 == 10i) == complex<double>(2.0,5));
CHECK(solve(3*x-9i == 0) == 3i);
CHECK(solve(6*x-x-4*x-12 == 10) == complex<double>(22,0));
CHECK(solve(4*x-3+2*x+6==2*x-4*x-x+12) == complex<double>(1,0));
CHECK(solve(3*x-3+1*x-6==3*x-5*x-x) == complex<double>(1,0));
CHECK(solve(3*x+1*x+0==3*x-5*x-x+6+9) == complex<double>(1,0));
CHECK(solve(3*x-6==3i) == complex<double>(2,1));
CHECK(solve(2*x-9i == 3) == complex<double>(1,3));
CHECK(solve(4*x-9 == 7) == complex<double>(4,0));
CHECK(solve(3*x-30i == 3i) == 11i);
CHECK(solve(5*x-9i == 1i) == 2i);
CHECK(solve(7*x == -14i) == -2i);
CHECK(solve(10*x== 25i) == 2.5i);
CHECK(solve(2*x == 25) == complex<double>(12.5,0));
CHECK(solve(10*x -5== 25i) == complex<double>(0.5,2.5));
CHECK(solve(10*x -5i== 25) == complex<double>(2.5,0.5));
CHECK(solve(2*x -3i == 25) == complex<double>(12.5,1.5));
CHECK(solve(2*x -3 == 25i) == complex<double>(1.5,12.5));
}
TEST_CASE("squer") {
RealVariable x;
CHECK((solve((x^2) == 81) == 9||solve((x^2) == 81) == -9));
CHECK((solve((x^2) == 16) == 4||solve((x^2) == 16) == -4));
CHECK((solve((x^2) == 9) == 3||solve((x^2) == 9) == -3));
CHECK((solve((x^2) == 4) == 2||solve((x^2) == 4) == -2));
CHECK(solve((x^2) == 81) != 9.0001);
CHECK(solve((x^2) == 16) != 4.0001);
CHECK_THROWS_AS(solve((x^2) == -16), std::exception);
CHECK_THROWS_AS(solve((x^2) == -9) ,std::exception);
CHECK_THROWS_AS(solve((x^2) == -4) ,std::exception);
CHECK_THROWS_AS(solve((x^2) == -81), std::exception);
CHECK(((solve((x^2) == 6.5025f) == 2.55)||(solve((x^2) == 6.5025f) == -2.55)));
CHECK(((solve((x^2) == 1.5625) == 1.25)||(solve((x^2) == 1.5625) == -1.25)));
CHECK_THROWS_AS(solve((x^2) == -6.5025), std::exception);
CHECK_THROWS_AS(solve((x^2) == -1.5625), std::exception);
}
TEST_CASE("complex squer") {
ComplexVariable x;
CHECK((solve((x^2) == 81) == complex<double>(9,0) || solve((x^2) == 81) == complex<double>(-9,0)));
CHECK((solve((x^2) == 16) == complex<double>(4,0)||solve((x^2) == 16) == complex<double>(-4,0)));
CHECK((solve((x^2) == 9) == complex<double>(3,0)||solve((x^2) == 9) == complex<double>(-3,0)));
CHECK((solve((x^2) == 4) == complex<double>(2,0)||solve((x^2) == 4) == complex<double>(-2,0)));
CHECK(solve((x^2) == 81) != complex<double>(9.0001f,0));
CHECK(solve((x^2) == 16) != complex<double>(4.0001f,0));
CHECK(solve((x^2) == -16) != 4.0001i);
CHECK((solve((x^2) == -81)== 9i||solve((x^2) == -81)== -9i));
CHECK((solve((x^2) == -9) == 3i||solve((x^2) == -9) == -3i));
CHECK((solve((x^2) == -4) == 2i||solve((x^2) == -4) == -2i));
CHECK((solve((x^2) == -16) == 4i||solve((x^2) == -16) == -4i));
CHECK(((solve((x^2) == 6.5025) == complex<double>(2.55,0))||(solve((x^2) == 6.5025f) == complex<double>(-2.55,0))));
CHECK(((solve((x^2) == 1.5625) == complex<double>(1.25,0))||(solve((x^2) == 1.5625) == complex<double>(-1.25,0))));
CHECK(((solve((x^2) == -6.5025f) == 2.55i)||(solve((x^2) == -6.5025f) == -2.55i)));
CHECK(((solve((x^2) == -1.5625) == 1.25i)||(solve((x^2) == -1.5625) == -1.25i)));
}
TEST_CASE("polinom") {
RealVariable x;
CHECK((solve((x^2) + 5*x  == -6) == -3||solve((x^2) + 5*x  == -6) == -2));
CHECK((solve((x^2) + 5*x  == 6) == -5||solve((x^2) + 5*x  == 6) == -1));
CHECK((solve((x^2) + 12 == -8*x) == -6||solve((x^2) + 12 == -8*x) == -2));
CHECK((solve((x^2) + 5*x  == 0) == 0||solve((x^2) + 5*x  == 0) == 5));
CHECK((solve(3*x + (x^2) - 8*x + 16 == 5*x) == 8||solve(3*x + (x^2) - 8*x + 16 == 5*x) == 2));
CHECK((solve((x^2) - 6*x +1 == 0) == 5.82||solve((x^2) - 6*x +1 == 0) == 0.17));
CHECK((solve((x^2) +8*x -20 == 0) == -10||solve((x^2) +8*x -20 == 0) == 2));
CHECK((solve((x^2)- 7*x + 14 = 2*x) == 2||solve((x^2)- 7*x + 14 = 2*x) == 7));
CHECK((solve( (x^2)+5*x +4 == 0) == -1||solve( (x^2)+5*x +4 == 0) == -4));
CHECK((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==4||solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==-4));
CHECK_THROWS_AS(solve((x^2) + 4*x  == -5), std::exception);
CHECK_THROWS_AS(solve((x^2) +2 == -2*x), std::exception);
CHECK_THROWS_AS(solve((x^2) + 6*x  == -13), std::exception);
CHECK_THROWS_AS(solve((x^2) - 8*x +17 == 0), std::exception);
CHECK_THROWS_AS(solve((x^2) -2*x +26 == 0), std::exception);
CHECK_THROWS_AS(solve((x^2)- 7*x + 14 == 2*x), std::exception);
CHECK_THROWS_AS(solve((x^2) -2*x + 5 == 2*x), std::exception);
}
TEST_CASE("complex polinom") {
ComplexVariable x;
CHECK((solve((x^2) + 4*x  == -5) ==complex<double>(-2,1)||solve((x^2) + 4*x  == -5) == complex<double>(-2,-1)));
CHECK((solve((x^2) + 2*x + 4 == 20 + 6*x/2 - x) == complex<double>(-4,0)||solve((x^2) + 2*x + 4 == 20 + 6*x/2 - x) == complex<double>(4,0)));
CHECK((solve((x^2) +8*x -20 == 0) == complex<double>(-10,0)||solve((x^2) +8*x -20 == 0) == complex<double>(-2,0)));
CHECK((solve((x^2) + 5*x  == 0) == complex<double>(0,0)||solve((x^2) + 5*x  == 0) == complex<double>(5,0)));
CHECK((solve((x^2) +2 == -2*x) == complex<double>(-1,1)||solve((x^2) + 2 == -2*x) == complex<double>(-1,-1)));
CHECK((solve((x^2) + 6*x  == -13) == complex<double>(-3,2)||solve((x^2) + 6*x  == -13) == complex<double>(-3,-2)));
CHECK((solve((x^2) - 6*x +1 == 0) == complex<double>(5.82,0)||solve((x^2) - 6*x +1 == 0) == complex<double>(0.17,0)));
CHECK((solve((x^2) == complex<double>(9,40)) == complex<double>(-5,4)||solve((x^2) == complex<double>(9,40)) == complex<double>(5,-4)));
CHECK((solve(3*x + (x^2) - 8*x + 16 == 5*x) == complex<double>(8,0)||solve(3*x + (x^2) - 8*x + 16 == 5*x) == complex<double>(2,0)));
CHECK((solve((x^2) + 12 == -8*x) == complex<double>(-6,0)||solve((x^2) + 12 == -8*x) == complex<double>(-2,0)));
CHECK((solve((x^2) - 8*x +17 == 0) == complex<double>(4,1)||solve((x^2) - 8*x +17 == 0) == complex<double>(4,-1)));
CHECK((solve((x^2) -2*x +26 == 0) == complex<double>(1,5)||solve((x^2) -2*x +26 == 0) == complex<double>(-1,5)));
CHECK((solve((x^2)- 7*x + 14 = 2*x) == complex<double>(2,0)||solve((x^2)- 7*x + 14 = 2*x) == complex<double>(7,0)));
CHECK((solve((x^2) -2*x + 5 = 2*x) == complex<double>(2,1)||solve((x^2)- 2*x + 5 = 2*x) == complex<double>(2,-1)));
CHECK((solve( (x^2)+5*x +4 == 0) == complex<double>(-1,0)||solve( (x^2)+5*x +4 == 0) == complex<double>(-4,0)));
CHECK((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==complex<double>(4,0)||solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==complex<double>(-4,0)));
CHECK((solve((x^2) + 5*x  == -6) == complex<double>(-3,0)||solve((x^2) + 5*x  == -6) == complex<double>(-2,0)));
CHECK((solve((x^2) + 5*x  == 6) == complex<double>(-5,0)||solve((x^2) + 5*x  == 6) == complex<double>(-1,0)));
}
