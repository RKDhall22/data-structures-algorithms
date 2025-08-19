#include<bits/stdc++.h>
using namespace std;

// Now lets Reverse the Array without taking 2 different variables unlike in previous solution used 2 variables i and j for 2 pointers concept.

// When an array is passed to a function as a int*, the function only receives a memory address, not the array's size.

// sizeof is also not reliable in this context:
// While sizeof can be used to get the size of an array at compile time within the same scope where it's defined, it doesn't work when passed as a function parameter because the pointer decays to a simple pointer, losing its size information. 

void f(int i , int arr[] , int n){
    
    if( i>= (n-i-1) )return;  // can write , i>=n/2 also
    
    swap(arr[i] , arr[n-i-1]);
    
    f(i+1, arr , n);
    
}

int main(){
    
    int n;
    
    cout<<"Enter the size of Array you want: ";
    cin>>n;
    
    int arr[n];
    
    cout<<"enter the values in the array now: ";
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    //function call
    
    f(0, arr,n );
    
    // Now lets print the values of array
    
    for(auto i :arr){
        
        cout<<i<<" ";
        
    }
    
    
    
}