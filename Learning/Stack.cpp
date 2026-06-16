#include <iostream>
#include <stack>
using namespace std;

template<typename T>
void printStack(stack<T> s){
    while(!s.empty()){
        cout<<s.top() <<" ";
        s.pop();
    }
    cout<<endl;
}

int firstStack(int n){
    stack<int> myStack;

    for(int i = 1; i <= n; ++i){
        myStack.push(i);
    }

    cout<<"Your Stack: ";
    printStack(myStack);

    cout<<"Your Stack's size before popping "<< myStack.top() << " is: "<<myStack.size()<<endl;

    int temp_top = myStack.top();
    myStack.pop();
    cout<<"Your Stack after popping "<< temp_top <<" (which was the top): ";
    printStack(myStack);

    cout<<"Your Stack's size after popping " << temp_top << " is: " << myStack.size()<<endl;

    cout<<"Do you want to push a value into your Stack? (y/n) ";
    char c;
    cin>>c;
    if(c == 'y' || c == 'Y'){
        cout<<"Enter how many values do you want to enter: ";
        int x;
        cin>>x;
        cout<<"Enter your values one by one: \n";
        for(int i = 0; i < x; ++i){
            int value;
            cin>> value;
            myStack.push(value);
        }
        cout<<"Now your stack is: ";
        printStack(myStack);
        cout<<"Now your stack's top is: "<<myStack.top()<<endl;
        cout<<"Now your stack's size is: "<<myStack.size()<<endl;
    }

    return 0;
}

int main(){
    firstStack(5);
}