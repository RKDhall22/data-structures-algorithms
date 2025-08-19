#include<bits/stdc++.h>
using namespace std;

// Now lets print from N to 1 , but not using f(i-1, N), means you cannot go in decreasing order that is you cannot pass for eg-if N=3, f(3,3) and then decrease it and print not like this.

// You have to go in increasing order that is f(i+1, N) and the output should be for N=3--> 3,2,1 that is using backtracking.

void f(int i, int n){
    
    if(i>n) return;
    
    f(i+1 , n); // Here we have used f(i+1 , n) means increasing the i.
    
    cout<<i<<" ";  // Here used the cout method after the function call
    
}

int main(){
    
    int n;
    
    cout<<"Enter the number you want to print it till 1 : ";
    cin>>n;
    
    //function call
    f(1,n);
    
    
    
}


// Dry Run this code

// First the function call will be f(1,3)- f(2,3) - f(3,3) - f(4,3), at (4,3) as i>n now, hence return from here, then go to f(3,3), cout<<3, then f(2,3) cout<<2, then f(1,3) cout<<1


