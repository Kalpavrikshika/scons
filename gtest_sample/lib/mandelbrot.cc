#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mandelbrot.hpp"
using namespace std;

// To view → http://paulcuth.me.uk/netpbm-viewer/

int MandelbrotGen::findMandelBrot(double cr, double ci, int maxIt)
{
    int i = 0;
    double real_z = 0.0, i_z = 0.0;
    while (i < maxIt && ((real_z * real_z) + (i_z * i_z)) < 4.0)
    {
        double bounds = (real_z * real_z) - (i_z * i_z) + cr;
        i_z = 2.0 * (real_z * i_z) + ci;
        real_z = bounds;
        i++;
    } 

    return i;
}

double MandelbrotGen::mapToR(int x, int imW, double minR, double maxR)
{
    double range = maxR - minR;
    return (x * ( range / imW) + minR);
}

double MandelbrotGen::mapToI(int y, int imH, double minI, double maxI)
{
    double range = maxI - minI;
    return (y * (range / imH) + minI);
}

double MandelbrotGen::genRandomAxes(void)
{
 
  double rand_val;
  double pointsH  = 3.0265;
  double  pointsL = 1.00028;
  rand_val = pointsL + double( ( rand()  * (pointsL / pointsH))/ (RAND_MAX / (pointsH - pointsL)));
  return rand_val;
}

void MandelbrotGen::generateImage(void)
{
    double minReal, maxReal, minIm, maxIm;
   // Generate fractal domains
    maxReal = genRandomAxes();
    minReal = (0.0 - (genRandomAxes()));
    maxIm = genRandomAxes();
    minIm = 0.0 - (maxIm);

    
    cout << "Max Real is : " << maxReal << endl;
    cout << "Min Real is : " << minReal << endl;
    cout << "Max Imaginary : " << maxIm << endl;
    cout << "Min Imaginary : " << minIm << endl;

    // Create File
    ofstream ppmOut("image.ppm");
    ppmOut << "P3" << endl;
    ppmOut << imageWidth << " " << imageHeight << endl;
    ppmOut << "255" << endl;
    for (int y = 0; y < imageHeight; y++)
    {
        for (int x = 0; x < imageWidth; x++)
        {
            double cr = mapToR(x, imageWidth, minReal, maxReal);
            double ci = mapToI(y, imageHeight, minIm, maxIm);

            /**
             * Using Bernstein Polys
             * r(t)=9⋅(1−t) * t^2
             * g(t)=15⋅(1−t) ^2 * t^3
             * b(t)=8.5⋅(1−t)^3 * t
             * */
            int itNum = findMandelBrot(cr, ci, maxN);
            int maxN_3 = itNum * itNum * itNum;
            double t = (double)itNum/(double)maxN;
            int n = (int)(t * (double) maxN_3);
           	int red = (int)(9*(1-t)*t*t*t*255);
            int green = (int)(15*(1-t)*(1-t)*t*t*255);
            int blue =  (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);

            ppmOut << red << " " << green << " " << blue << " ";
        }
        ppmOut << endl;
    }
    ppmOut.close();
}