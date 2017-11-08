#include <iostream>
#include <string>
#include "direction.h"
#include "gwindow.h"
#include "maze.h"
#include "point.h"
#include"vector.h"
using namespace std;

int main() {

   GWindow gw;
   Maze maze("SampleMaze.txt", gw);
   Vector<Point> pathSet;
   Vector<Point> tmpPath;
   int result;
   result=fristFindPath(maze, maze.getStartPosition(),pathSet,tmpPath);
   if(result==-1)
       cout<<"Can't find the way "<<endl;
   else
       cout<<"The length is "<<result<<endl;

   for(int x=0;x<=5;x++)
       for(int y=0;y<=5;y++){
       if(maze.isMarked(Point(x,y)))\
           maze.unmarkSquare(Point(x,y));
       }
   for(Point point : pathSet){
        maze.markSquare(point);

   }

   return 0;

}

int fristFindPath(Maze & maze, Point start, Vector<Point> & path, Vector<Point> &tmpPath){
    int tmpcount=0;
    int thisFinsh=-1;
    solveMaze(maze,start,path,tmpPath,tmpcount,thisFinsh);
    return thisFinsh;
}

bool solveMaze(Maze & maze, Point start,Vector<Point> & path,
               Vector<Point> & tmpPath,int &tmpcount,int &thisFinsh) {
    if (maze.isOutside(start)) {

        if(thisFinsh==-1)
            thisFinsh=tmpcount;
        if(tmpcount<thisFinsh)
            thisFinsh=tmpcount;
        path=tmpPath;
        return true;
    }
   if (maze.isMarked(start)) return false;

   maze.markSquare(start);
   tmpcount++;
   tmpPath.add(start);
   for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (!maze.wallExists(start, dir)) {
         if (solveMaze(maze, adjacentPoint(start, dir),path,tmpPath,tmpcount,thisFinsh)) {
            return true;
         }
      }
   }
   tmpcount--;
   tmpPath.remove(tmpPath.size()-1);

   //maze.unmarkSquare(start);
   return false;
}

Point adjacentPoint(Point start, Direction dir) {
   switch (dir) {
    case NORTH: return Point(start.getX(), start.getY() - 1);
    case EAST:  return Point(start.getX() + 1, start.getY());
    case SOUTH: return Point(start.getX(), start.getY() + 1);
    case WEST:  return Point(start.getX() - 1, start.getY());
   }
   return start;
}
