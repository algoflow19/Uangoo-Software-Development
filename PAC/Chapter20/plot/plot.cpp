#include"plot.h"

template<typename funclass>
void plot(GWindow &gw, funclass fn, double minX, double maxX)
{
    double width=gw.getWidth();
    double height=gw.getHeight();
    double sx0=0;
    double initY=fn(minX);
    double sy0=height;
    double dx=(maxX-minX)/width;
    double maxY=initY;
    double minY=initY;
    for(int i=1;i<width;i++){
        double y=fn(i*dx+minX);
        if(y>maxY) maxY=y;
        if(y<minY) minY=y;
    }

    for(int i=1;i<width;i++){
        double y=fn(i*dx+minX);
        double sx1=i;
        double sy1=height-height*(y-minY)/(maxY-minY);
        gw.drawLine(sx0,sy0,sx1,sy1);
        sx0=sx1;
        sy0=sy1;
    }

}


void plot(GWindow &gw, double (*fn)(double), double start, double finsih)
{
    plot(gw,std::ptr_fun(fn),start,finsih);
}


void plot(GWindow &gw, double (*fn)(double), double minX, double maxX,double minY,double maxY)
{
    plot(gw,std::ptr_fun(fn),minX,maxX,minY,maxY);
}

template<typename funclass>
void plot(GWindow &gw, funclass fn, double minX, double maxX,double minY,double maxY){
    double width=gw.getWidth();
    double height=gw.getHeight();
    double dx=(maxX-minX)/width;
    double sx0=0;
    double sy0=height-height*(fn(minX)-minY)/(maxY-minY);
    for(int i=1;i<width;i++){
        double x=dx*i+minX;
        double y=fn(x);
        double sx1=i;
        double sy1=height-height*(y-minY)/(maxY-minY);
        gw.drawLine(sx0,sy0,sx1,sy1);
        sx0=sx1;
        sy0=sy1;
    }
}
