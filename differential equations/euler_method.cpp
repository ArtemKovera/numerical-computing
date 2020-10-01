/*
    
    This program demonstrates Euler method for solving differential equations with C++

*/
#include<iostream>
#include<cmath>

//function pointer alias for equatin determining dy/dx
using Equation = double (*) (double, double);

double eulerSolver(double x, double x0, double y0, Equation eq, double h);

double func1 (double x, double y);

int main ()
{


    return 0;
}

double eulerSolver(double x, double x0, double y0, Equation eq, double h)
{
    double tmp;

    while (x0 < x) 
    { 
        tmp = y0; 
        y0 = y0 + h * eq(x0, y0); 
        x0 = x0 + h; 
    }

    return y0;
}
