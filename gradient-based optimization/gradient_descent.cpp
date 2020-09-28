/*

    This program demonstrates gradient descent algorithm with C++
    In this implementation, a derivative of a function is computed numerically

*/
#include<iostream>
#include<exception>
#include<vector>

//function pointer alias for equation with various number of variables
using Equation = double (*) (std::vector<double>);

//functio for gradient descent
std::vector<double> gradientDescent (std::vector<double> startingPoint, Equation eq, size_t numberOfVariables, double gamma = 0.01, size_t maxNumberOfIterations = 10000);

//function to compute derivative numerically
double computePartialDerivative(std::vector<double> point, Equation eq, size_t indexOfVariable, double delta = 0.001);

//function to compute gradient numerically
//it uses computePartialDerivative() function
std::vector<double> computeGradient(std::vector<double> point, Equation eq, double delta);

//this function of one variable x^2
double funk1 (std::vector<double> variables);

int main()
{


    return 0;
}


std::vector<double> gradientDescent (std::vector<double> startingPoint, Equation eq, size_t numberOfVariables, double gamma, size_t maxNumberOfIterations)
{
    std::vector<double> result = startingPoint;
    size_t iterationCount = 0;

    while (iterationCount < maxNumberOfIterations)
    {



    }

    return result;
};

double computePartialDerivative (std::vector<double> point, Equation eq, size_t index, double delta)
{
    std::vector<double> vec = point;
    vec[index] += delta;
    double rise = eq(vec) - eq(point);
     
    return rise / delta; 
}

std::vector<double> computeGradient(std::vector<double> point, Equation eq, double delta)
{
    size_t size = point.size();
    std::vector<double> gradient(size);    

    for(size_t i = 0; i < size; i++)
    {
        gradient[i] = computePartialDerivative(point, eq, i, delta);
    }

    return gradient;
}

double funk1 (std::vector<double> variables)
{
    return variables[0] * variables[0]; 
}