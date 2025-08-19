#include<bits/stdc++.h>
using namespace std;

// Lets reverse the array using Recursion

//1st Method- By taking two pointers concept, here will take 2 different variables, one pointing to first index and one point to last index.

// One thing to keep in mind is that, Array is passed by Reference, means the value changes in its original memory.

//This means the function receives the memory address of the array's beginning, not a copy of the entire array.
//Passing arrays by value (making a full copy) would be inefficient, especially for large arrays, as it would consume significant memory and processing time. Passing a pointer (the address) is much more efficient. Just unlike variables we dont use '&' symbol for array as its automatically takes the address.

void f(int i , int j , int arr[]){
    
    if(i>=j) return;
    
    swap(arr[i] , arr[j]);
    
    f(i+1, j-1, arr);
    
}

int main(){
    
    int n ;
    
    cout<<"Enter the size of array you want: ";
    cin>>n;
    
    int arr[n];
    
    // lets insert the value in array now
    cout<<"Enter the values in the array : ";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    f(0,n-1,arr); // passed 1st index , last index and array
    
    // Now lets print the values of Array
    
    for(int i=0 ; i<n ; i++){
        
        cout<<arr[i]<<" ";
        
    }
    
    
}