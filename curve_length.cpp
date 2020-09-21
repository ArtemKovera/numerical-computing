/*

    This program demonstrates finding length of a curve by numerical method in C++

*/
#include<iostream>
#include<cmath>

//function pointer alias for curve equation
using CurveEquation = double (*) (double);

//function to find a length of a curve 
double findLength (double start, double finish, CurveEquation eq, size_t numberOfSections = 1000);

double func1 (double x);

double func2 (double x);

double func3 (double x);

int main ()
{

    std::cout << "Length of func1 curve from 0 to 3 is " << findLength(0, 3, func1) << std::endl;
    std::cout << "Length of func2 curve from 0 to 3 is " << findLength(0, 3, func2) << std::endl;
    std::cout << "Length of func3 curve from 0 to 3 is " << findLength(0, 3, func3) << std::endl;


    return 0;
}

double findLength (double start, double finish, CurveEquation eq, size_t numberOfSections)
{
    double length = 0;
    double y0, y1;
    double diff = finish - start;
    double width = diff / numberOfSections;
    double widthSquared = width * width;
    double currentX = start + width;
    
    y0 = eq(start);

    for (size_t i = 0; i < numberOfSections; i++)
    {
        y1 = eq(currentX);
        length += std::sqrt(widthSquared + std::pow((y1 - y0), 2));
        y0 = y1;
        currentX += width;
    }

    return length;
}

double func1 (double x)
{
    return x * x;
}

double func2 (double x)
{
    return x * x * x + 4;
}

double func3 (double x)
{
    return  0.01 * std::pow(x, 5) + 1;
}
