/*

    This program demonstrates solving polynomial equations by using
    trial and improvment method in C++

*/
#include<iostream>
#include<cmath>

using Equation = double (*) (double);

double getRoot (double initialGuess, double initialStep, Equation eq, double maxError = 0.001);

double equation1 (double x);

double equation2 (double x);

double equation3 (double x);

int main ()
{
    double root, root2, root3;
    
    root = getRoot(100, 10, equation1);
    std::cout << std::endl;
    std::cout <<"Approximate root for  x^3 + 2x^2 - 10  is                       " << root << std::endl;
    std::cout << std::endl;
    
    root2 = getRoot(10, 2, equation2);
    std::cout << std::endl;
    std::cout <<"Approximate root for  3x^5 + 2x^4 + 7x^3 + 4x^2 - 18x + 10  is  " << root2 << std::endl;
    std::cout << std::endl;

    root3 = getRoot(10, 2, equation3);
    std::cout << std::endl; 
    std::cout <<"Approximate root for  1.5x^7 + 17x^5 - 14x^4 + 3x - 5  is       " << root3 << std::endl;
    
    std::cout << "\nPlease note that an equation may have more than one root" << std::endl;
    return 0;
}

double getRoot (double initialGuess, double initialStep, Equation eq, double maxError)
{
    double root = initialGuess;
    double step = initialStep;
    double error = eq(root);
    double absoluteValueError = std::fabs(error);
    bool flag = false;
    bool priviousFlag;

    if(error > 0)
        flag = true;
    
    while(absoluteValueError > maxError)
    {
        priviousFlag = flag;
        if (error > 0)
        {
            root -= step;
            flag = true;
        }
        else
        {
            root += step;  
            flag = false;  
        }
        error = eq(root);
        absoluteValueError = std::fabs(error);
        
        if(priviousFlag != flag)
        { 
            while(absoluteValueError > maxError)
            {
                step /= 2;
                if(error > 0)
                    root -= step;
                else
                    root += step;
                error = eq(root);
                absoluteValueError = std::fabs(error);
            }
        }
    }

    return root;
}


double equation1(double x)
{
    return x*x*x + 2*x*x - 10;
}

double equation2(double x)
{
    return 3*x*x*x*x*x - 2*x*x*x*x + 7*x*x*x + 4*x*x - 18*x + 10;  
}

double equation3(double x)
{
    return 1.5*x*x*x*x*x*x*x + 17*x*x*x*x*x - 14*x*x*x*x + 3*x - 5;
}