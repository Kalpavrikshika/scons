#include <iostream>
#include "./lib/filewriter.hpp"

FileWriter myWriter;

int main()
{
    int a = 64;
    int b = 8;
    int divRes = myWriter.div(a,b);
    int addRes = myWriter.add(a,b);
    int subRes = myWriter.sub(a,b);
    int multiRes = myWriter.mult(a,b);
    int sqrRes = myWriter.sqr(a);
        if (divRes = 0 && (b !=0 || a !=0))
    {
        std::cout << "There was an error in writing file" ;
    }
        if (addRes = 0 && (b > 0 && a > 0))
    {
        std::cout << "There was an error in writing file" ;
    }
        if (subRes = 0 && (a > 0))
    {
        std::cout << "There was an error in writing file" ;
    }
        if (multiRes = 0 && (b !=0 || a !=0))
    {
        std::cout << "There was an error in writing file" ;
    }
        if (sqrRes = 0 && (b !=0 || a !=0))
    {
        std::cout << "There was an error in writing file" ;
    }
        myWriter.close();

    return 0;
}