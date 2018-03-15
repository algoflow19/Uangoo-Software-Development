#include <iostream>
#include <string>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"
#include"map.h"
#include<fstream>
#include"console.h"
using namespace std;

// When using pointer in c++, you must remember to release the alloced memory.


void readBASICProgram(ifstream& infile, Map<int, string> &codeList);
void runProgram(int startCol, Map<int,string> &codeList, EvaluationContext &context);
bool detemindIfTure(TokenScanner& scanner,EvaluationContext& context);

int main() {
   ifstream infile;
   infile.open("infile");
   Map<int,string> codeList;
   readBASICProgram(infile,codeList);
   EvaluationContext context;
   runProgram(0,codeList,context);
   return 0;
}

void readBASICProgram(ifstream& infile,Map<int,string> &codeList){
    string tmp;
    int codePripority;
    while(true){
        infile>>tmp;
        if(infile.fail()||tmp=="RUN") break;
        codePripority=stringToInteger(tmp);
        getline(infile,tmp);
        codeList.add(codePripority,tmp);
    }
}

void runProgram(int startCol,Map<int,string> &codeList,EvaluationContext &context){
    TokenScanner scanner;
    scanner.scanNumbers();
    scanner.ignoreWhitespace();
    Expression* exp;
    for(int col : codeList){
        if(col< startCol) continue;
        scanner.setInput(codeList.get(col));
        string command=scanner.nextToken();
        if(command=="LET"){
            exp=parseExp(scanner);
            exp->eval(context);
            continue;
        }
        if(command=="PRINT"){
            exp=parseExp(scanner);
            cout<<exp->eval(context)<<endl;
            continue;
        }
        if(command=="INPUT"){
            int value;
            cout<<"Please input the value:";
            cin>>value;
            context.setValue(context.getAddress(scanner.nextToken()),value);
            continue;
        }
        if(command=="GOTO"){
            int col=stringToInteger(scanner.nextToken());
            runProgram(col,codeList,context);
            break;
        }
        if(command=="IF"){
            if(detemindIfTure(scanner,context)){
                if(scanner.nextToken()=="THEN"){
                    int col=stringToInteger(scanner.nextToken());
                    runProgram(col,codeList,context);
                    break;
                }
                else error("syntax error!");
            }
            continue;
        }
        if(command=="END") break;
        error("syntax error:'"+command+"' in line "+integerToString(col)); //  A useful syntax check
    }
}


bool detemindIfTure(TokenScanner& scanner,EvaluationContext& context){
    int leftValue=readE(scanner,0)->eval(context);
    string firstOp=scanner.nextToken();
    bool first,second=false;
    if(scanner.getTokenType(firstOp)==OPERATOR){
        string SecondOp=scanner.nextToken();
        if(SecondOp=="=")
            second=true;
        else{
            scanner.saveToken(SecondOp);
            second=false;
        }
    } else error("Syntax error!");
    int rightValue=readE(scanner,0)->eval(context);
    if(firstOp=="<")
        first=leftValue<rightValue;
    else if(firstOp==">")
        first=leftValue>rightValue;
    else first=false;
    if(second) second=leftValue==rightValue;

    return first||second;
}
