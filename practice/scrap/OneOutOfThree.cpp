#include<iostream>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if(A == B){
        cout << C << endl;
    }else if(A == C){
        cout << B << endl;
    }else if(B == C){
        cout << A << endl;
    }
}