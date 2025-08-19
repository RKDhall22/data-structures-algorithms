#include<bits/stdc++.h>
using namespace std;

// Print lineraly from 1 to N, but via Backtracking, not using i+1 inside function, it means we are going back and printing the result.

void f(int i, int n){  
    
    if(i<1) return; //Base Condition, here we can write if (i==0) also,
    
    f(i-1 , n ); 
    cout<<i<<" "; // Here, we have used the cout method after the function call
    
}

int main(){
    
    int n;
    
    cout<<"Enter the number upto which you want to print from 1: ";
    cin>>n;
    
    f(n,n);
    
}


// Dry Run

//n=3

// first call, (3,3)-(2,3)-(1,3)-(0,2), at (0,2) base condition met, hence return from there, then it will go to f(1,3) ,after this, next line that is "cout<<i" will execute, here i=1, then after this line, function (1,3) , finishes.
// Now, it will go to (2,3) , the exceutes, the cout<<i , that is 2
// then (3,3), excutes , cout<<i , this is 3

//Hence the output is now --> 1,2,3










