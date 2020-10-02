/*

    This program demonstrates descrete integration method in C++

*/
#include<iostream>
#include<cmath>

using Equation = double (*) (double);

double computeIntegral (double lowerBound, double upperBound, Equation eq, size_t numberOfSections = 1000);

double func1 (double x);

double func2 (double x);

double func3 (double x);

int main()
{
    std::cout << "With default precision " << computeIntegral(1, 4, func1) << std::endl;
    std::cout << "With higher precision  " << computeIntegral(1, 4, func1, 10000) << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "With default precision " << computeIntegral(1, 4, func2) << std::endl;
    std::cout << "With higher precision  " << computeIntegral(1, 4, func2, 10000) << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "With default precision                   " << computeIntegral(1, 4, func3) << std::endl;
    std::cout << "With higher precision                    " << computeIntegral(1, 4, func3, 10000) << std::endl;  
    std::cout << "With 10 times lower precision to default " << computeIntegral(1, 4, func3, 100) << std::endl;  
    
    return 0;
}

double computeIntegral (double lowerBound, double upperBound, Equation eq, size_t numberOfSections)
{
    double sum = 0;
    double diff = upperBound - lowerBound;
    double section = diff / numberOfSections;
    double current = lowerBound;
    double y;

    for(size_t i = 0; i < numberOfSections; i++)
    {
        current += section;
        y = eq(current);
        sum += section * y;
    }

    return sum;
}

double func1 (double x)
{
    return x * x;
}

double func2 (double x)
{
    return 2 * std::log(x) + std::pow(x, 1.5);
}

double func3 (double x)
{
    return std::log(x) - x * x + 100;
}