#include <iostream>
#include <queue>
using namespace std;

void firstQueue(int n){
    queue<int> myqueue;
    
    for(int x = 1; x <= n; ++x){
        myqueue.push(x*n);
    }

    if (myqueue.empty()){
        cout<<"Queue is Empty!"<<endl;
    } else {
        queue<int> temp_q = myqueue;

        cout<<"Size of your queue is: "<<myqueue.size()<<endl;
        cout<<"\nWith elements: ";
        while(!temp_q.empty()){
            cout<<" " <<temp_q.front();
            temp_q.pop();
        }
    }
    cout<<endl;
}

void swapQueue(queue<string> &q1, queue<string> &q2){
    cout<<endl;
    if(q1.empty() || q2.empty()){
        cout<<"Invalid queues with sizes equals to NULL!"<<endl;
        return;
    }
    if (q1.size() != q2.size()){
        cout<<"Inavlid queues with different sizes!"<<endl;
        return;
    }

    q1.swap(q2);
    cout<<"Queues after swapping:"<<endl;
    
    queue<string> temp1 = q1;
    queue<string> temp2 = q2;
    while(!temp1.empty() && !temp2.empty()){
        cout<<"Q1: "<<temp1.front()<<"\t\t";
        temp1.pop();
        cout<<"Q2: "<<temp2.front()<<endl;
        temp2.pop();
    }
    cout<<endl;
}

int main(){
    string interest_q1[] = {"Playing", "Studing"};
    string interest_q2[] = {"Cooking", "Running"};

    firstQueue(5);

    queue<string> q1, q2;
    for(const string &s : interest_q1){
        q1.push(s);
    }
    for(const string &s : interest_q2){
        q2.push(s);
    }
    
    swapQueue(q1, q2);
    getchar();

    return 0;
}