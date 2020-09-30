/*

    This program demonstrates gaussian elimination with C++
    In this implementation, matrix is represented as one-dimensional array

*/
#include<iostream>
#include<cmath>
#include<cassert>


//performs Gaussian elimination
//returns the rank of the matrix
size_t gaussElimination(const size_t rows, const size_t columns, double *matrix, const double epsilon = 0.000001);

//void enterMatrix(const size_t rows, const size_t columns, double *matrix);

void printMatrix (const size_t rows, const size_t columns, const double *matrix);

int main ()
{
    const size_t rows1 = 3;
    const size_t columns1 = 4;

    double *matrix = new double [rows1 * columns1] {2, 1, -1, 1, 2, -3, 1, -1, 4, -1, 4, 14};
    
    std::cout << "Matrix: " << std::endl;
    printMatrix(rows1, columns1, matrix);

    double rank1 = gaussElimination(rows1, columns1, matrix);

    std::cout << std::endl;

    std::cout << "Same matrix after Gaussian elimination: " << std::endl;
    printMatrix(rows1, columns1, matrix);
    
    std::cout << "Matrix's rank = " << rank1 << std::endl;
    delete [] matrix;

    return 0;
}



size_t gaussElimination(const size_t rows, const size_t columns, double* matrix, const double epsilon)
{
    size_t i, j, k, l;
    double r;
 
    i = 0; j = 0;
 
    while (i < rows && j < columns)
    {
        r = 0.0;
        for (k = i; k < rows; ++k)
        {
            if (fabs(matrix[k * columns + j]) > r)
            {
                l = k; 
                r = fabs(matrix[k * columns + j]); 
            }
        }
 
        if (r <= epsilon)
        {
            for (k = i; k < rows; ++k)
            {
                matrix[k * columns + j] = 0.0;
            }
            ++j; 
            continue; 
        }
 
        if (l != i)
        {
            for (k = j; k < columns; ++k)
            {
                r = matrix[i * columns + k];
                matrix[i * columns + k] = matrix[l * columns + k];
                matrix[l * columns + k] = (-r);
            }
        }
 

        r = matrix[i * columns + j];
        assert(fabs(r) > epsilon);
 

        for (k = i + 1; k < rows; ++k)
        {
            double c = (-matrix[k * columns + j]) / r;
            matrix[k * columns + j] = 0.0;
            for (l = j + 1; l < columns; ++l)
            {
                matrix[k * columns + l] += c * matrix[i * columns + l];
            }
        }
 
        ++i; ++j; 
    }
 
    return i; 
}

// void enterMatrix(size_t rows, size_t columns, double *matrix)
// {
//     std::cout << "Enter matrix: " << "\n";

//     for(size_t i = 0; i < rows; i++)
//     {

//     }
// }

void printMatrix (const size_t rows, const size_t columns, const double *matrix)
{

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            std::cout << matrix[i*columns + j] << "   ";
        }

        std::cout << "\n";
    }
}