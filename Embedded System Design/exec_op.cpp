#include<time.h>
#include<iostream>
#include<unistd.h>

using namespace std;


int main()
{



    int pid2=fork();
    char * arg[]={"ls","-l",(char *)0};  // the frist arg of execv() must be
    char * arg2[]={"ls",(char *)0};

    if(pid2==0)
        execv("/bin/ls", arg); //Do not need a NULL pointer and give the arg in array-form
    else
    {
        cout<<"father is there"<<endl;
         execv("/bin/ls",arg2);

    }

 return 0;
}
