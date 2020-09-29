/*

    This program demonstrates gradient descent algorithm with C++
    In this implementation, a derivative of a function is computed numerically

*/
#include<iostream>
#include<vector>
#include<iomanip>

//function pointer alias for equation with various number of variables
using Equation = double (*) (std::vector<double>);

//functio for gradient descent
std::vector<double> gradientDescent (std::vector<double> startingPoint, Equation eq, double gamma = 0.1, size_t maxNumberOfIterations = 10000);

//function to compute derivative numerically
double computePartialDerivative(std::vector<double> point, Equation eq, size_t indexOfVariable, double delta = 0.001);

//function to compute gradient numerically
//it uses computePartialDerivative() function
std::vector<double> computeGradient(std::vector<double> point, Equation eq, double delta);

//this function of one variable    x^2
double func1 (std::vector<double> variables);

//this function of two variables   (x-3)^2 / 4 + (y-6)^2 / 9
double func2 (std::vector<double> variables);

int main()
{
    std::cout << std::fixed << std::setprecision(3) << std::endl;    
    
    //demonstrating gradientDescent() for a function with one variable
    std::vector<double> vec1 = {3.0};
    std::vector<double> vec2 = gradientDescent(vec1, func1);
    std::cout << "For a function x^2" << "\n";    
    std::cout << "Starting point = " << vec1[0] << "  Minimum = " << vec2[0] << "\n";
      
    std::cout << std::endl;

    //demonstrating gradientDescent() for a function with two variables
    std::vector<double> vec3 = {0.0, 0.0};
    std::vector<double> vec4 = gradientDescent(vec3, func2);
    std::cout << "For a function (x-3)^2 / 4 + (y-6)^2 / 9" << "\n";
    std::cout << "Starting point = " << vec3[0] << ", " << vec3[1] << "  | Minimum = " << vec4[0] << ", " << vec4[1] << std::endl;

    
    return 0;
}


std::vector<double> gradientDescent (std::vector<double> startingPoint, Equation eq, double gamma, size_t maxNumberOfIterations)
{
    std::vector<double> result = startingPoint;
    std::vector<double> vec1 = startingPoint;
    std::vector<double> vec2 = vec1;

    size_t size = startingPoint.size();
    size_t iterationCount = 0;
    double minimum1 = eq(startingPoint);
    double minimum2 = minimum1;

    while (iterationCount < maxNumberOfIterations)
    {
        minimum1 = minimum2;
        vec1 = computeGradient(result, eq, 0.0001);
        for(size_t i = 0; i < size; i++)
            vec2[i] -= gamma * vec1[i];

        minimum2 = eq(vec2);

        if(minimum2 < minimum1)
        {
            result = vec2;
            iterationCount++;
        }
        else
        {
            return result;
        }
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

double func1 (std::vector<double> variables)
{
    return variables[0] * variables[0]; 
}

double func2 (std::vector<double> variables)
{
    return ((variables[0] - 3)*(variables[0] - 3)) / 4 + ((variables[1] - 6)*(variables[1] - 6)) / 9;
}