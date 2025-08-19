#include<bits/stdc++.h>
using namespace std;

// Factorial of Number by paramterized way , means no need to return the value , just cout inside the function

void f(int i , int fact){
    
    if(i==0){  // Here we have to check the edge case also, by checking for 0, because 0!= 1
        
        cout<<fact;
        return;
        
    }
    
    f(i-1 , fact*i);  // f(3,1) - f(2,3) -f(1,6)--> At (1,6) base condition met, cout<<6 , then return
    
}

int main(){
    
    int n , fact=1;
    
    cout<<"Enter the number of which you want the factorial :";
    cin>>n;
    
    f(n,fact);

    // You can also do this in increasing manner by taking f(1,n,fact) and it will be like--> 1*1- 1*2 - 2*3 - 6*4(incorrect here as 4>3) hence, cout<<6 and then return.
    // But in this one , we are taking an extra variable which takes extra space
    
    
}