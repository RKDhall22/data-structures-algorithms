#include<bits/stdc++.h>
using namespace std;

// Print now in from N to 1, in decreasing fashion using Recursion

// Time Complexity - O(n) , because n times the function is being called and is there in the stack space until the base condition is being met and then one by one each function is being removed from the stack space.
// Space Complexity - O(n), As the function is getting stored in the stack space upto N times

void f(int n){
    
    if(n==0) return;  // Base Condition
    
    cout<<n<<" ";
    f(n-1);
    
}

int main(){
    
    int n;
    
    cout<<"Enter the number from which you want to print upto 1 :";
    cin >> n;
    
    f(n);
    
    
}

