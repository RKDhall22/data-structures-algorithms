#include<bits/stdc++.h>
using namespace std;

// Check whether the array is sorted or not.

// Time Complexity : O(n)

bool Array_Sorted_orNot(int arr[] , int n){
    
    for(int i=0 ; i<n-1 ; i++){
        
        if(arr[i] < arr[i+1]){
            // okay proceed to next then
        }
        
        else{
            return false;
        }
    } 
    
    return true;
    
}

int main(){
    
    int n;
    
    cout<<"Enter the size of array :";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the values in the array: ";
    
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    
    cout<<Array_Sorted_orNot(arr , n);
    
    
}