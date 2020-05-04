#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using namespace solver;


RealVariable& solver::operator^(RealVariable &x, int q) {

    if(q == 1){
        return x;
    }
    if(q == 0){
        auto *x1 = new solver::RealVariable;
        x1->b = 0;
        x1->c++;
        return *(x1);
    }
    if (q>2){
        throw runtime_error("power greater then 2");
    }

    auto *x1 = new solver::RealVariable;
    x1->b = 0;
    x1->a++;

    return *(x1);
}

RealVariable& solver::operator==(RealVariable &x, int a) {

    auto *x1 = new solver::RealVariable(x);
    x1->c-=a;

    return *(x1);
}

RealVariable &solver::operator==(RealVariable &x, double a) {

    auto *x1 = new solver::RealVariable(x);
    x1->c-=a;

    return *(x1);

}

RealVariable &solver::operator==(RealVariable &x, RealVariable &y) {


    auto *x1 = new solver::RealVariable(x);
    x1->a -= y.a;
    x1->b -= y.b;
    x1->c -= y.c;

    return *(x1);

}

RealVariable &solver::operator*(int a, RealVariable &x) {

    auto *x1 = new solver::RealVariable(x);

    x1->a *=a;
    x1->b *= a;
    x1->c *= a;
    return *(x1);
}

RealVariable &solver::operator-(RealVariable &x, int a) {

    auto *x1 = new solver::RealVariable(x);
    x1->c -= a;
    return *(x1);
}

RealVariable &solver::operator-(RealVariable &x, RealVariable &y) {

    RealVariable *x1;
    if(x.is_zero()){
        x1 = new solver::RealVariable(x);
        x1->b = 1;
    }
    else{
        x1 = new solver::RealVariable(x);
    }
    RealVariable *y1;
    if(y.is_zero()){
        y1 = new solver::RealVariable(y);
        y1->b =1;
    }
    else{
        y1 = new solver::RealVariable(y);
    }
    x1->a -= y1->a;
    x1->b -= y1->b;
    x1->c -= y1->c;

    return *(x1);
}

RealVariable &solver::operator+(RealVariable &x, int a) {

    auto *x1 = new solver::RealVariable(x);


    x1->c += a;
    return *(x1);
}

RealVariable &solver::operator+(RealVariable &x, RealVariable &y) {

    auto *x1 = new solver::RealVariable(x);
    x1->a += y.a;
    x1->b += y.b;
    x1->c += y.c;

    return *(x1);
}

RealVariable &solver::operator+(int a, RealVariable &x) {

    auto *x1 = new solver::RealVariable(x);
    x1->c += a;
    return *(x1);
}

RealVariable &solver::operator/(RealVariable &x, int a) {

    if(a == 0){
        throw runtime_error ("divied by zero");
    }
    auto *x1 = new solver::RealVariable(x);
    x1->b /= a;
    return *(x1);

}

bool RealVariable::is_zero(){

    return a == 0 && b == 0 && c == 0 ;

}

ComplexVariable solver::operator*(int a, ComplexVariable y) {
    auto *x1 = new solver::ComplexVariable(y);

    x1->a *=a;
    x1->b *= a;
    x1->c *= a;
    return *(x1);
}

ComplexVariable solver::operator-(ComplexVariable x, int a) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c -= a;
    return *(x1);
}

ComplexVariable solver::operator-(ComplexVariable x, ComplexVariable y){
    auto *x1 = new solver::ComplexVariable(x);
    x1->a -= y.a;
    x1->b -= y.b;
    x1->c -= y.c;

    return *(x1);
}

ComplexVariable solver::operator-(ComplexVariable x, complex<double> a) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c-=a;

    return *(x1);
}

ComplexVariable solver::operator==(ComplexVariable x, int a) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c-=a;

    return *(x1);
}

ComplexVariable solver::operator==(ComplexVariable x, double a) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c-=a;

    return *(x1);
}

ComplexVariable solver::operator==(ComplexVariable x, ComplexVariable y) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->a -= y.a;
    x1->b -= y.b;
    x1->c -= y.c;

    return *(x1);
}

ComplexVariable solver::operator==(ComplexVariable x, complex<double> a) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c-=a;

    return *(x1);
}

ComplexVariable solver::operator^(ComplexVariable x, int q) {
    if(q == 1){
        return x;
    }
    if(q == 0){
        auto *x1 = new solver::ComplexVariable;
        x1->b = 0;
        x1->c+=1;
        return *(x1);
    }
    if (q>2||q<0){
        throw runtime_error("power greater then 2");
    }

    auto *x1 = new solver::ComplexVariable;
    x1->b = 0;
    x1->a++;

    return *(x1);
}

ComplexVariable solver::operator+(ComplexVariable x, ComplexVariable y) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->a += y.a;
    x1->b += y.b;
    x1->c += y.c;

    return *(x1);
}

ComplexVariable solver::operator+(ComplexVariable x, int a) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c+=a;

    return *(x1);
}

ComplexVariable solver::operator+(int a, ComplexVariable x) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c+=a;

    return *(x1);
}

ComplexVariable solver::operator+(ComplexVariable x, complex<double> v) {
    auto *x1 = new solver::ComplexVariable(x);
    x1->c+=v;

    return *(x1);
}

ComplexVariable solver::operator/(ComplexVariable x, int a) {
    if(a == 0){
        throw runtime_error ("divied by zero");
    }
    auto *x1 = new solver::ComplexVariable(x);
    x1->b /= a;
    return *(x1);
}

