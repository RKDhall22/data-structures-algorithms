#include<bits/stdc++.h>
using namespace std;

// Print Name n times by using Recursion

// Time Complexity - O(N) , where N times the function is calling itself
// Space Complexity - O(N) , because in stack space , the function is 

void f(int i, int n){ // first time , i=1
    
    if(i>n) return;   // Base condition
    
    cout<<"Rahul Kumar Dhall"<<endl;
    
    f(i+1 , n); // if n=3,  f(2,3) --> f(3,3) --> f(4,3), at (4,3) base condition hits and functions (3,3) , (2,3) gets out of the stack space.
    
}

int main(){
    
    int n;
    
    cout<<"Enter the number of times you want to print the name: ";
    cin>>n;
    
    f(1,n);  // Function call here
    
}
  
  
  
  
  
  
