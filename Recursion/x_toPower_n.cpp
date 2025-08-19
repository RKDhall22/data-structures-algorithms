#include<bits/stdc++.h>
using namespace std;

// x^n

// 1st approach brute force, running the loop upto n times, lets solve this using Recursion, for this the time complexity is - O(N) , where N is the power

int f(int x, int n){
    
    if(n==1) return x;
    
    return x*f(x, n-1);
    
}

int main(){
    
    int x,n;
    
    cout<<"Enter the value of x and n :";
    cin>>x>>n;
    
    cout<<f(x,n);
    
    
    
}