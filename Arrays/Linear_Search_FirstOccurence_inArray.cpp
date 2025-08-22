#include<bits/stdc++.h>
using namespace std;

// Linear Search in Array , first occurence

// Approach: Iterate over the array elements from start to find out the first occurence and return its index.
  // If want to find out the last occurence , then you can start from end of the array.
  
  // Time Complexity: O(N)
  // Space Complexity: O(1), no extra space
void LinearSearch(int arr[] , int n , int num){
    
    for(int i=0 ; i<n ;i++){
        
        if(arr[i] == num){
            cout<<i<<" ";
            break;
        }
         
        
    }
}

int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter the values : ";
    
    for(int i=0 ; i<n ; i++){
        
        cin >> arr[i];
        
    }
    
    int num;
    cout<< "Enter the value you want to search in Array the index: ";
    cin >> num;
    
    
    LinearSearch(arr , n , num);
    
}