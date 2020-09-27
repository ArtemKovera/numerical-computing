/*

    This program demonstrates numerical linear interpolation method in C++

*/
#include<iostream>
#include<vector>
#include<exception>
#include<algorithm>
#include<cmath>

//this function takes coordinates of two points, 
//and returns coefficients k and b in linear equation y = kx + b for these points
std::pair<double, double> linear_equation(std::pair<double, double> point1, std::pair<double, double> point2);


//this function returns y coordinate based on linear interpolation
//this function uses stl sort() algorithm
//it throws std::invalid_argument exception
double getY(std::vector<std::pair<double, double>> &points, double x);


int main()
{   
    //demonstrating linear_equation() function
    std::pair<double, double> point1 = {2, 6};
    std::pair<double, double> point2 = {3, 9};
    std::pair<double, double> coeff = linear_equation(point1, point2);
    std::cout << "For points {2, 6} and {3, 9}, k = " << coeff.first << "  and b = " << coeff.second << "\n";
    std::cout << std::endl;

    
    //demonstrating getY() function with a vector consisting of several points for x^2 equation
    std::vector<std::pair<double, double>> vector = {{4, 16}, {0, 0}, {1, 1}, {2, 4}, {3, 9}, {5, 25}, {6, 36}};
    std::cout << std::endl;
    std::cout << "At point 1.5 linear interpolation of x^2 with given actual values is " << getY(vector, 1.5) << "\n";
    std::cout << "At point 1.6 linear interpolation of x^2 with given actual values is " << getY(vector, 1.6) << "\n";
    std::cout << "At point 1.7 linear interpolation of x^2 with given actual values is " << getY(vector, 1.7) << "\n";
    std::cout << "At point 2.5 linear interpolation of x^2 with given actual values is " << getY(vector, 2.5) << "\n";
    std::cout << "At point 3.5 linear interpolation of x^2 with given actual values is " << getY(vector, 3.5) << "\n";
    

    //demonstrating getY() function with a vector consisting of several points for x^3 equation
    std::vector<std::pair<double, double>> vector2 = {{1.5, 3.375}, {0, 0}, {1, 1}, {2, 8}, {2.5, 15.625}, {3, 27}, {0.5, 0.125}};
    std::cout << std::endl;
    std::cout << "At point 0.2 linear interpolation of x^3 with given actual values is " << getY(vector2, 0.2) << "\n";
    std::cout << "At point 1.2 linear interpolation of x^3 with given actual values is " << getY(vector2, 1.2) << "\n";
    std::cout << "At point 2.2 linear interpolation of x^3 with given actual values is " << getY(vector2, 2.2) << "\n";
    std::cout << "At point 2.8 linear interpolation of x^3 with given actual values is " << getY(vector2, 2.8) << "\n";
    std::cout << "At point 2.9 linear interpolation of x^3 with given actual values is " << getY(vector2, 2.9) << "\n";
    

    return 0;
}

std::pair<double, double> linear_equation(std::pair<double, double> point1, std::pair<double, double> point2)
{
    std::pair<double, double> kb;

    kb.first = (point2.second - point1.second) / (point2.first - point1.first);

    kb.second = point1.second - kb.first*point1.first;

    return kb;
}

double getY(std::vector<std::pair<double, double>> &points, double x)
{
    std::sort(points.begin(), points.end());
    
    if(x > points.back().first || x < points[0].first)
    {
        throw std::invalid_argument("x coordinate has to be in proper range");
    } 

    size_t size = points.size();
    auto pt = points.begin();
    
    for(size_t i = 0; i < points.size(); i++)     //could be implemented more efficiently using binary search though
    {
        if (x == points[i].first)
            return points[i].second;

        if(x > points[i].first && x < points[i+1].first)
        {
            auto coefficients = linear_equation(points[i], points[i+1]);
            return coefficients.first * x + coefficients.second;
        }
    }
    
}
