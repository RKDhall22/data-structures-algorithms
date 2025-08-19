#include<bits/stdc++.h>
using namespace std;

// Print linearly from 1 to N using Recursion

void f(int i , int n){
    
    if(i>n) return;  // Base Condition
    
    cout<<i<<" ";
    f(i+1 , n);
    
}

int main(){
    
    int n;
    
    cout<<"Enter the number upto which you want to print from 1: ";
    cin>> n;
    
    f(1,n);
    
}



