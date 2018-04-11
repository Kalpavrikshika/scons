#include "./lib/mandelbrot.hpp"
MandelbrotGen myGen(512,512,256);

int main()
{
    myGen.generateImage();
    return 0;
}