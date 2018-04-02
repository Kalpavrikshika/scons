#include <fstream>
#include "filewriter.hpp"

std::ofstream resultfile("results.txt");

int FileWriter::add(int a, int b)
{
    int res;
    if (resultfile.is_open())
    {
        res = a + b;
        resultfile << "Addition \n" ;
        resultfile << res << std::endl;
    } else
    {
        res = 0;
    }
    return res;
}

int FileWriter::div(int a, int b)
{
    int res;
    if (resultfile.is_open())
    {
        res = a / b;
        resultfile << "Division \n" ;
        resultfile << res << std::endl;
    } else
    {
        res = 0;
    }
    return res;
}

int FileWriter::sub(int a, int b)
{
    int res;
    if (resultfile.is_open())
    {
        res = a - b;
        resultfile << "Subtraction \n" ;
        resultfile << res << std::endl;
    } else
    {
        res = 0;
    }
    return res;
}

int FileWriter::mult(int a, int b)
{
    int res;
    if (resultfile.is_open())
    {
        res = a * b;
        resultfile << "Multiplication \n" ;
        resultfile << res << std::endl;
    } else
    {
        res = 0;
    }
    return res;
}

int FileWriter::sqr(int a)
{
    int res;
    if (resultfile.is_open())
    {
        res = a * a;
        resultfile << "Squares \n" ;
        resultfile << res << std::endl;
    } else
    {
        res = 0;
    }
    return res;
}

void FileWriter::close()
{
    resultfile.close();
}