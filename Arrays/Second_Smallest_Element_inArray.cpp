#include<bits/stdc++.h>
using namespace std;

// 2nd Smallest element in the Array

// 1st Approach: Brute force --> Just sort the array, and if no duplicates are there, arr[1] is the 2nd smallest.
// If duplicates are there, then traverse the array from start until arr[i+1]!= arr[i] , and then print arr[i+1] as 2nd Smallest.
// Time Complexity of this - O(nlogn)+O(n) , nlogn for sorting function and n for traversing the array is duplicate elements are there


// 2nd Approach: Better one --> Fist find the smallest element in the array and then compare every other element with this to find the 2nd smallest element.
// Time Complexity of this one - O(2n)

// Lets solve this 2nd approach

void BetterApproach(int arr[] , int n){
    
    int smallest = arr[0], second_smallest = INT_MAX;
    
    for(int i=1 ; i<n ; i++){
        
        if(arr[i] < smallest){
            
            smallest = arr[i];
            
        }
    }
    
    for(int i=0 ; i<n ; i++){
        
        if(arr[i] != smallest && arr[i] < second_smallest){
            
            second_smallest = arr[i];
            
        }
    }
    
    cout<<"2nd smallest is : "<<second_smallest;
}


// 3rd Approach : Optimal one --> In this , in a single loop only , will find the smallest and 2nd smallest. The logic is simple, if x is the smallest element in the array and now y is smaller than x, it means y is the smallest and now x is the 2nd smallest.
// Time Complexity for this one: O(n)

void OptimalApproach(int arr[] , int n){
    
    int smallest= arr[0] , second_smallest= INT_MAX;
    
    for(int i=0 ; i<n ; i++){
        
        if(arr[i] < smallest){
            
            second_smallest = smallest;
            smallest = arr[i];
            
        }
        
        else if(arr[i] != smallest && arr[i] < second_smallest){
            
            second_smallest = arr[i];
            
        }
    }
    
    cout<<endl<<"2nd smallest via optimal approach is : "<<second_smallest;
    
}


int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the values in the array: ";
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    // 2nd approach - Better one
    BetterApproach(arr , n );
    
    // 3rd approach - Optimal one
    OptimalApproach(arr , n);
    
    
        
}












