/*
********
********
********
********
*/


#include <iostream>
using namespace std;

void pattern1(int r, int c){
    for (int i = r; i > 0; i--){
        for (int j = 1; j <= c; j++){
            cout<<"*";
        }
        cout<<endl;
    }
};

/* 
*----
**---
***--
****-
*****
*/

void pattern2(int r, int c){
    cout<<endl;
    int size;
    for (int i = 1; i <= r; i++){
        for (int j = 0; j <= c; j++){
            if (j < i){
                cout<<"* ";
            }
            
        }
        size = c - i;
        for (int k = 1; k <= size; k++){
            cout<<"- ";
        }
        cout<<endl;
    }
}

/*
*
**
***
****
*****
******
*/

void pattern3(int r){
    cout<<endl;
    for (int i = 1; i <= r; ++i){
        for (int j = 1; j <= i; ++j){
            cout<<"* ";
        }
        cout<<endl;
    }
}

/* 
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *   
*/

void pattern4(int r){
    if (r % 2 == 1){
        cout<<endl;
    } else {
        return;
    }

    int mid_row = ((r - 1) / 2) + 1;

    //First Half
    for (int i = 1; i <= mid_row; ++i){
        for(int j = 1; j <= mid_row - i; ++j){
            cout<<" ";
        }
        for (int j = 1; j <= (i * 2) - 1; ++j){
            cout<<"*";
        }
        cout<<endl;
    }

    // Second Half
    for (int i = mid_row - 1; i > 0; --i){
        for(int j = 1; j <= mid_row - i; ++j){
            cout<<" ";
        }
        for (int j = 1; j <= (i * 2) - 1; ++j){
            cout<<"*";
        }
        cout<<endl;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pattern1(4, 8);
    pattern2(5, 5);
    pattern3(6);
    pattern4(9);
}