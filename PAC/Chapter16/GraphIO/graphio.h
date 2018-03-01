#ifndef GRAPHIO_H
#define GRAPHIO_H
#include"graphtypes.h"
#include<iostream>

void readGraph(SimpleGraph & g, std::istream & infile);

void writeGraph(SimpleGraph & g, std::ostream & outfile);

#endif // GRAPHIO_H

