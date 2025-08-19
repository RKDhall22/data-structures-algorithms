#include<bits/stdc++.h>
using namespace std;

// Now here will do this factorial in functional way means in this one will return the result to the function call which is there in the main()

int f(int n){
    
    if(n==0) return 1;
    
    return n*f(n-1); // Here we have return the value to the main() because of which we have made the function return type as "int".
    
}


int main(){
    
    int n;
    
    cout<<"Enter the number of which you want the factorial of : ";
    cin>>n;
    
    cout<<"Factorial is : "<<f(n);
    
}


// Dry Run

//f(3)- 3*f(2) - 2*f(1) - 1*f(0) - f(0) returns 1 -- f(1)=1*1 , f(2)= 2*1 ,f(3)= 3*2-->6, returns 6 to main()


