/*

    This program demonstrates solving polynomial equations by using Newton's method in C++

*/

#include<iostream>

//function pointer alias for equation
using Equation = double (*) (double);

//function pointer alias for computing derivative
using Derivative = double (*) (double);

//function to find root for equation by using Newton's method
double getRoot (size_t numberOfIterations, double startingValue, Equation eq, Derivative der);


double func1 (double x);

double der1 (double x);

double func2 (double x);

double der2 (double x);

double func3 (double x);

double der3 (double x);


int main()
{

    std::cout << "An approximate root for   5x^3 + x^2 - 120 = 0                  is " << getRoot(100, 10, func1, der1) << std::endl;
    std::cout << "An approximate root for   x^4 - 5x^3 + 10x^2 - 74 = 0           is " << getRoot(100, 10, func2, der2) << std::endl;
    std::cout << "An approximate root for   4x^5 - 5x^4 + 7x^3 + 4x^2 - 100 = 0   is " << getRoot(100, 10, func3, der3) << std::endl;    

    return 0;
}

double getRoot (size_t numberOfIterations, double startingValue, Equation eq, Derivative der)
{
    
    double root = startingValue;
    
    for(size_t i = 0; i < numberOfIterations; i++)
    {
        root -= eq(root) / der(root);
    }

    return root;
}

double func1 (double x)
{
    return 5*x*x*x + x*x - 120;
}

double der1 (double x)
{
    return 15*x*x + 2*x;
}

double func2 (double x)
{
    return x*x*x*x - 5*x*x*x + 10*x*x - 74;
}

double der2 (double x)
{
    return 4*x*x*x - 15*x*x + 20*x;
}

double func3 (double x)
{
    return 4*x*x*x*x*x - 5*x*x*x*x + 7*x*x*x + 4*x*x - 100;
}

double der3 (double x)
{
    return 20*x*x*x*x - 20*x*x*x + 21*x*x + 8*x;
}


