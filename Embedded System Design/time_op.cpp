#include<time.h>
#include<iostream>
#include <unistd.h>

using namespace std;


int main()
{

    time_t tloc;
    tloc=time(NULL);

    struct tm *t;
    struct tm *pt;

    t=gmtime(&tloc);

    sleep(3); //Need to include <unistd.h> to use it

    cout<<"The time of 3 seconds ago is "<<t->tm_year<<":"<<t->tm_mon<<":"<<t->tm_mday<<
    ":"<<t->tm_hour<<":"<<t->tm_sec<<endl;

    sleep(1);
    time_t t1;
    //
    time(&t1); // or get current time; same as: timer = time(NULL)
    time_t *t1_p;
    t1_p =&t1;
    pt=gmtime( t1_p );

    /* It seems that time() just assign a const value to a place
    and if a pointer of the type of "time_t" would caused core dumped*/



    cout<<"The time of 3 seconds ago is "<<pt->tm_year<<":"<<pt->tm_mon<<":"<<pt->tm_mday<<
    ":"<<pt->tm_hour<<":"<<pt->tm_sec<<endl;


     //time_t seems long int type?


 return 0;
}
