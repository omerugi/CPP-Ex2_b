//
// Created by omerugi on 25/04/2020.
//

#ifndef UNTITLED5_SOLVER_HPP
#define UNTITLED5_SOLVER_HPP
#include <iostream>
#include <complex>

using namespace std;

namespace solver{

    class RealVariable{

    public:
        RealVariable()= default;
        RealVariable operator ^ (int a){
            RealVariable x;
            return x; }
        friend RealVariable operator == (RealVariable x, int a){ return x;};
        friend RealVariable operator == (RealVariable x, double a){ return x;};
        friend RealVariable operator == (RealVariable x, RealVariable y){  return x;};
        friend RealVariable operator * (int a,solver::RealVariable x){  return x;}
        friend RealVariable operator - (solver::RealVariable x,int a){  return x;}
        friend RealVariable operator - (solver::RealVariable x,solver::RealVariable y){  return x;}
        friend RealVariable operator + (solver::RealVariable x,int a){  return x;}
        friend RealVariable operator + (solver::RealVariable x,solver::RealVariable y){  return x;}
        friend RealVariable operator + (int a,solver::RealVariable x){  return x;}
        friend RealVariable operator / (solver::RealVariable x,int a){  return x;}
    };

    class ComplexVariable{
    public:
        ComplexVariable ()= default;
        friend ComplexVariable operator * (int a, ComplexVariable y ){ return y;}
        friend ComplexVariable operator -(ComplexVariable y , int a){return y;}
        friend ComplexVariable operator - (ComplexVariable y1, ComplexVariable y2){return y1;}
        friend ComplexVariable operator - (ComplexVariable y, complex<double> a){return y;}
        friend ComplexVariable operator == (ComplexVariable y , int a){return y;}
        friend ComplexVariable operator == (ComplexVariable y , double a){return y;}
        friend ComplexVariable operator == (ComplexVariable y1, ComplexVariable y2){return y1;}
        friend ComplexVariable operator == (ComplexVariable y1, complex<double> a){return y1;}
        friend ComplexVariable operator ^ (ComplexVariable y, int a){return y;}
        friend ComplexVariable operator + (ComplexVariable y1, ComplexVariable y2){return y1;}
        friend ComplexVariable operator + (ComplexVariable y, int a){return y;}
        friend ComplexVariable operator + (int a, ComplexVariable y){return y;}
        friend ComplexVariable operator + (ComplexVariable y, complex<double> v){return y;}
        friend ComplexVariable operator / (ComplexVariable y, int a){return y;}


    };

    inline double solve(RealVariable x){ return 8.0;}
    inline std::complex<double> solve(ComplexVariable y){ return (8i);}


}







#endif //UNTITLED5_SOLVER_HPP

