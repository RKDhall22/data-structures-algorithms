#include<bits/stdc++.h>
using namespace std;

// Now lets solve the summation of first N number using Recursion.

// Normally you can do this by using for loop or by the formula of 1+2+3--N= N(N+1)/2

// But, here we have to do this using Recursion.

// Here, in 2 ways by Recursion we can solve this

// 1st way is by parameterized function  and 2nd is by using functional that is returning the value to main function.

// Lets solve by 1st method :

// In this function we have used the decreasing way to adding the values in sum variable (N=3) where intially 3 added , then 2 then 1 then return

void f(int i , int sum){  // f(3,0)
    
    if(i<1){
        
        cout<<sum;
        return;
        
    }
    
    f(i-1 , sum+i);
    
}

// Now lets solve this in increasing fashion

void f1(int i , int n, int sum){ // f1(1,3,0)
    
    if(i>n){
        
        cout<<sum;
        return;
    }
    
    f1(i+1, n , sum+i);
    
    
    
}

int main(){
    
    int n, sum=0;
    
    cout<<"Enter the number upto which you want the sum of :";
    cin>>n;
    
    //function call
     f(n,sum); // This is what we have did in decreasing order that is f(i-1 , sum) means 3+2+1
    
    // Now lets see it in increasing way that is 1+2+3
    // 1st Method
    f1(1,n, sum);
    
    
    
    
    
    
    
    
}