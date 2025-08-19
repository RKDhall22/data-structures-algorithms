#include<bits/stdc++.h>
using namespace std;

// Now lets solve this by functional way,

int f(int n){
    
    if(n==1) return 1;  
    return n+f(n-1); // We have divided the problem into smaller parts
    
}

int main(){
    
    int n;
    
    cout<<"Enter the number upto which you want the sum: ";
    cin>>n;
    
    cout<<f(n);
    
}


// Dry run

// f(3) --> 3+f(2) --> 2+f(1) -->f(1) will return 1 and then 2+1=3 , so f(2 ) will 3 , then f(3) will return 3+3=6 and this 6 will go to main() and prints.


