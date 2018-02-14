#include <iostream>
#include <string>
#include"priorityqueue.h"
//#include"console.h"

using namespace std;

int main() {

    PriorityQueue<int> st;
    st.enqueue(22,1.52);
    st.enqueue(21,1.51);
    st.enqueue(1,0.3);
    st.enqueue(2,3.3);
    st.enqueue(2,3.3);
    st.enqueue(4,2.3);
    cout<<st.dequeue()<<endl;
    cout<<st.dequeue()<<endl;
    cout<<st.dequeue()<<endl;
    cout<<st.dequeue()<<endl;
    cout<<st.dequeue()<<endl;
    cout<<st.dequeue()<<endl<<endl;


    Vector<int> vec;
    vec.add(2);
    vec.add(33);
    vec.add(9);
    vec.add(1);
    vec.add(88);
    vec.add(6);
    vec.add(-33);
    vec.add(-10);
    vec.add(5);
    st.sort(vec);

    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    cout<<st.dequeue(vec)<<endl;
    return 0;

}


