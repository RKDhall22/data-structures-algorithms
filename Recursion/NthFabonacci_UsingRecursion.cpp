#include<bits/stdc++.h>
using namespace std;

// Lets print the Nth Fabonaccci number using Recursion , here we will use 2 function calls and will know how multiple function calls work.

// When there are multiple Recursive function call, not simultaneously the function gets executed , at first the first recursive function gets executed and then it goes to the next recursive function call.

// The time complexity of this code is - O(2^n) - Exponential , but this is not the exact TC , but close
// for eg - n=4, 2^4= 16, but there are only 9 Recursion calls, this is because first its calling to f(3) then f(2)

int f(int n){
    
    if(n<=1) return n;
    
    return f(n-1)+f(n-2); // first (n-1) will go and gets executed and then after its finishes, then (n-2) will go and gets executed
    
}


int main(){
    
    int n;
    
    cout<<"Enter the nth fabo number you want to know: ";
    cin>>n;
    
    cout<<"The value of "<<n<< "fab is: "<< f(n);
    
    
}
