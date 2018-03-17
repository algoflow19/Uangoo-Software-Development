#ifndef PLOT_H
#define PLOT_H
#include"gwindow.h"
#include<functional>
#include<algorithm>
/*
 * Please note that this funtation can only draw positive x-y funtation
 */


template<typename funclass>
void plot(GWindow& gw,funclass fn,double start,double finish);

void plot(GWindow& gw,double (*fn)(double),double start,double finsih);



template<typename funclass>
void plot(GWindow &gw, funclass fn, double minX, double maxX,double minY,double maxY);

void plot(GWindow &gw, double (*fn)(double), double minX, double maxX,double minY,double maxY);

#endif // PLOT_H

