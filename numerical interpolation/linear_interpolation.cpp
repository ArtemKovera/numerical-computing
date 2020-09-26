/*

    This program demonstrates numerical interpolatin method in C++

*/
#include<iostream>
#include<vector>
#include<exception>
#include<algorithm>
#include<cmath>

//this function takes coordinates of two pointes, 
//and returns koeficients k and b in linear equation y = kx + b of these points
std::pair<double, double> linear_equation(std::pair<double, double> point1, std::pair<double, double> point2);


//this function uses stl sort() algorithm
//it throws std::invalid_argument exception
double getY(std::vector<std::pair<double, double>> &points, double x);


std::vector<std::pair<double, double>>::iterator find(std::vector<std::pair<double, double>> &points, double x);

int main()
{
    std::pair<double, double> point1 = {2, 2};
    std::pair<double, double> point2 = {5, 3};
    
    std::pair<double, double> coeff = linear_equation(point1, point2);

    std::cout << coeff.first << " " << coeff.second << std::endl;

    std::vector<std::pair<double, double>> vector = {{4, 16}, {0, 0}, {1, 1}, {2, 4}, {3, 9}};



    std::sort(vector.begin(), vector.end());

    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i].first << " " << vector[i].second << std::endl;
    }

    
    std::cout << "The answear is " << getY(vector, 1.5) << std::endl;

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
    
    for(size_t i = 0; i < points.size(); i++)
    {
        if(x > points[i].first && x < points[i+1].first)
        {
            auto coefficients = linear_equation(points[i], points[i+1]);
            return coefficients.first * x + coefficients.second;
        }
    }
    
}

std::vector<std::pair<double, double>>::iterator find(std::vector<std::pair<double, double>> &vec, double x)
{
    std::vector<std::pair<double, double>>::iterator it = vec.begin();
    size_t index;
    double tmp;

    while(true)
    {
        index = vec.size() / 2;  
        it += index;      
        tmp = (*it).first;
        if(std::fabs(tmp - x) < 0.0001)
            return it;    

        if(x > tmp)
        {
            if(x < (*(it+1)).first)
            {
                
                return it;
                std::cout << "it's OK" << std::endl;
                break;
            }
                
            
            std::vector<std::pair<double, double>> vec2 (it, vec.end()); 
            find(vec2, x);
        }
            
        if(x < tmp)
        {
            if(x > (*(it-1)).first)
                return (it-1);

            std::vector<std::pair<double, double>> vec2 (vec.begin(), it);
            find(vec2, x); 
        }   
    }
 
}








