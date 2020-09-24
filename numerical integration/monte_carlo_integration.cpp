/*

    This program demonstrates numerical integration with Monte Carlo method in C++

*/
#include<iostream>
#include<exception>
#include<random>



//function pointer alias of function equation for integration
using Equation = double (*) (double);


//function for Monter Carlo numeric integration
//function uses stl random library for generating floating point random numbers
//it throws invalid argument exception if starting point is equal or greater than the ending point
double monteCarloIntegration (double lowerBound , double upperBound, double yMax, Equation eq, size_t numberOfPoints = 10000);

double func1(double x);

double func2(double x);

int main ()
{
    std::cout << "Computing definite integral between 1 and 3 of x^2 \n";
    std::cout << "integral computed by Monte Carlo integration with default precision = " << monteCarloIntegration(1, 3, 9, func1) << "\n";
    std::cout << "integral computed by Monte Carlo integration with higher precision  = " << monteCarloIntegration(1, 3, 9, func1, 100000) << "\n";
    std::cout << "the true value of this integral is 8.666..." << std::endl;

    std::cout << "\nComputing definite integral between 1 and 3 of x^3 \n";
    std::cout << "integral computed by Monte Carlo integration with default precision = " << monteCarloIntegration(1, 3, 27, func2) << "\n";
    std::cout << "integral computed by Monte Carlo integration with higher precision  = " << monteCarloIntegration(1, 3, 27, func2, 100000) << "\n";
    std::cout << "the true value of this integral is 20" << std::endl;

    return 0;
}

double monteCarloIntegration (double lowerBound, double upperBound, double yMax, Equation eq, size_t numberOfPoints)
{
    if(lowerBound >= upperBound)
    {
        throw std::invalid_argument("ending point should be greater than starting point");
    }


    std::default_random_engine gen;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    
    size_t i = 0;
    size_t underCurve = 0;
    double range = upperBound - lowerBound;
    double x, yGenerated, yActual;
    double totalArea = yMax * range;
    double result = 0; 

    while(i<numberOfPoints)
    {
        x = lowerBound + range*distribution(gen);  //generating x coordinate between start and end
        yGenerated = yMax*distribution(gen);  //generating y coordinate between 0 and yMax

        yActual = eq(x);

        if(yGenerated < yActual)
            underCurve++;
    
        i++;
    }
    result = underCurve * totalArea / numberOfPoints;
    return result;
}

double func1(double x)
{
    return x * x;
}

double func2(double x)
{
    return x * x * x;
}
