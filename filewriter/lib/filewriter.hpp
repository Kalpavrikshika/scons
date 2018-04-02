#ifndef FILEWRITER_H
#define FILEWRITER_H

class FileWriter
{
public:
    FileWriter(){}
    int add(int a, int b);
    int sub(int a, int b);
    int div(int a, int b);
    int mult(int a, int b);
    int sqr(int a);
    void close();
};


#endif // !FILEWRITER_H