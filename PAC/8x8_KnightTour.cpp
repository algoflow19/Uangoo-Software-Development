#include <iostream>
#include <string>
#include<iomanip>
#include<grid.h>
using namespace std;

bool doneKingnightTour(Grid<int> & chessBoard, int & count, int cols, int rows);
bool isVaildPositon(Grid<int> & chessBoard, int & x, int & y);
void printChessBoard(Grid<int> & chessBoard);
void fillGrid(Grid<int> & smallBoard,Grid<int> & bigBoard);

int main() {

    Grid<int> chessBoard(4,8);
    int x,y;
    x=0;
    y=2;
    int count=1;
   doneKingnightTour(chessBoard,count,x,y);

   Grid<int> resultGrid(8,8);
   fillGrid(chessBoard,resultGrid);
   
   count++;
   x=4;y=2;
   
   if(doneKingnightTour(resultGrid,count,x,y))
       printChessBoard(resultGrid);

    return 0;
}




bool isVaildPositon(Grid<int> &chessBoard, int &x, int &y){
    if(chessBoard.inBounds(x,y)&&chessBoard.get(x,y)==0)
        return true;
    return false;
}


bool doneKingnightTour(Grid<int> & chessBoard, int & count, int  cols, int  rows){

    if(!isVaildPositon(chessBoard,cols,rows))
        return false;
    else if(count==chessBoard.numCols()*chessBoard.numRows())
    {
        chessBoard.set(cols,rows,count);
        return true;
    }

    chessBoard.set(cols,rows,count);
    count++;
    if (doneKingnightTour(chessBoard, count, cols - 2, rows + 1))
        return true;
    if (doneKingnightTour(chessBoard, count, cols - 1, rows + 2)
    ) return true;
    if (doneKingnightTour(chessBoard, count, cols + 2, rows + 1))
        return true;
    if (doneKingnightTour(chessBoard, count, cols + 2, rows - 1))
        return true;
    if (doneKingnightTour(chessBoard, count, cols - 2, rows - 1)
    ) return true;
    if (doneKingnightTour(chessBoard, count, cols + 1, rows + 2)
    ) return true;
    if (doneKingnightTour(chessBoard, count, cols + 1, rows - 2)
    ) return true;
    if (doneKingnightTour(chessBoard, count, cols - 1, rows - 2)
    )  return true;
    count--;
    chessBoard.set(cols,rows,0);

    return false;
}

void printChessBoard(Grid<int> & chessBoard){
    for(int x=0;x<=chessBoard.numRows()-1;x++){
        for(int y=0;y<=chessBoard.numCols()-1;y++)
            if(chessBoard.get(x,y)==0)
                cout<<"[  ]";
            else
                cout<<"["<<setw(2)<<chessBoard.get(x,y)<<"]";
        cout<<endl;
    }
    return ;
}

void fillGrid(Grid<int> & smallBoard,Grid<int> & bigBoard){
    for(int x=0;x<=smallBoard.numRows()-1;x++){
        for(int y=0;y<=smallBoard.numCols()-1;y++)
        {
            int tmpint;
            tmpint=smallBoard.get(x,y);
            bigBoard.set(x,y,tmpint);
        }
}
    return ;
}
