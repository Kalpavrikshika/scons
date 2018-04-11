#ifndef MANDELBROT_H
#define MANDELBROT_H

class MandelbrotGen
{
public:
    MandelbrotGen(int h, int w, int m) : imageHeight(h), imageWidth(w), maxN(m){}
    MandelbrotGen() : imageHeight(1200), imageWidth(1200), maxN(255){}
    void generateImage(void);

private:
    int imageHeight, imageWidth, maxN;
    double mapToI(int y, int imH, double minI, double maxI);
    double mapToR(int x, int imW, double minR, double maxR);
    int findMandelBrot(double cr, double ci, int maxIt);
    double genRandomAxes(void);
};


#endif // !MANDELBROT_H