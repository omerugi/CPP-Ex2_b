//
// Created by omerugi on 25/04/2020.
//

#ifndef UNTITLED5_SOLVER_HPP
#define UNTITLED5_SOLVER_HPP
#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

namespace solver{

    class RealVariable{

    public:
        double a;
        double b;
        double c;
        RealVariable():a(0),b(1),c(0){};

        RealVariable(RealVariable &x1):a(x1.a),b(x1.b),c(x1.c){}

        friend RealVariable& operator^(RealVariable& x,int q);
        friend RealVariable& operator == (RealVariable& x, int a);
        friend RealVariable& operator == (RealVariable& x, double a);
        friend RealVariable& operator == (RealVariable& x, RealVariable& y);
        friend RealVariable& operator * (int a,RealVariable& x);
        friend RealVariable& operator - (RealVariable& x,int a);
        friend RealVariable& operator - (RealVariable& x,RealVariable& y);
        friend RealVariable& operator + (RealVariable& x,int a);
        friend RealVariable& operator + (RealVariable& x,RealVariable& y);
        friend RealVariable& operator + (int a,RealVariable& x);
        friend RealVariable& operator / (RealVariable& x,int a);

        bool is_zero();
    };

    class ComplexVariable{

    public:
        double a;
        complex<double> b;
        complex<double> c;
        ComplexVariable():a(0),b(1),c(0){};

        friend ComplexVariable operator * (int a, ComplexVariable y );
        friend ComplexVariable operator -(ComplexVariable y , int a);
        friend ComplexVariable operator - (ComplexVariable y1, ComplexVariable y2);
        friend ComplexVariable operator - (ComplexVariable y, complex<double> a)  ;
        friend ComplexVariable operator == (ComplexVariable y , int a)   ;
        friend ComplexVariable operator == (ComplexVariable y , double a);
        friend ComplexVariable operator == (ComplexVariable y1, ComplexVariable y2);
        friend ComplexVariable operator == (ComplexVariable y1, complex<double> a) ;
        friend ComplexVariable operator ^ (ComplexVariable y, int a);
        friend ComplexVariable operator + (ComplexVariable y1, ComplexVariable y2);
        friend ComplexVariable operator + (ComplexVariable y, int a);
        friend ComplexVariable operator + (int a, ComplexVariable y);
        friend ComplexVariable operator + (ComplexVariable y, complex<double> v);
        friend ComplexVariable operator / (ComplexVariable y, int a);


    };

    inline double solve(RealVariable x){

        if(x.a == 0){
            double res = -x.c/x.b;

            if(x.b == 0){
                throw runtime_error ("inf");
            }
            return res;
        }

        double delta = pow(x.b,2)-4*x.a*x.c;
        if(delta < 0){
            throw runtime_error ("exception: no real solution");
        }
        double a = 2*x.a;
        double res = (-1*x.b + pow(delta,0.5))/a;

        return res;
    }

    inline std::complex<double> solve(ComplexVariable x){

        if(x.a == 0){
            complex<double> res = -x.c/x.b;

            if(x.b == complex<double>(0)){
                throw runtime_error ("inf");
            }
            return res;
        }

        complex<double> delta = pow(x.b,2)-4*x.a*x.c;
        double a = 2*x.a;
        complex<double> res = (complex<double>(-1)*x.b + sqrt(delta))/a;

        return res;
    }

}

void print();
#endif //UNTITLED5_SOLVER_HPP

