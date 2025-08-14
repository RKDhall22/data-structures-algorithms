#include<bits/stdc++.h>
using namespace std;

// 2nd largest element in the array

// TC - O(nlogn)+ O(n) , nlogn for sort, and n for traversing in array
void BruteApproach( int arr[] , int n){
    
    sort(arr, arr+n);  // nlogn
    
    while(n>0){   // n traverse in worst case
        
        if(arr[n-2] == arr[n-1]){
            n--;
        }
        else{
            cout<<"2nd largest is : "<<arr[n-2];
            break;
        }
    }
}


// Better Approach:TC- O(n) + O(n) ~ O(2n)

void BetterApproach(int arr[] , int n){
    
    // Lets first find out largest and then 2nd largest
    
    int largest=arr[0];
    
    for(int i=0 ; i<n ; i++){  // n times
        
        if(arr[i] > largest){
            
            largest = arr[i];
            
        }
    }
    
    // now, as we get the largest one, lets find out the 2nd largest
    
    int second_largest = -1; // if no 2nd largest is there in array return -1
    
    for(int i=0 ; i<n ; i++){    // n times
        
        if(arr[i] > second_largest && arr[i] != largest){
            
            second_largest = arr[i];
            
        }
    }
    
    cout<<"2nd largest one is : "<< second_largest;
    
}

// Optimal Approach
// If all positibve numbers , then can assign value to second_largest that is -1. If Negative numbers are also there in the array, then can init second_largest as = INT_MIN


void OptimalApproach(int arr[] , int n){
    
    int largest= arr[0] , second_largest = -1; 
    
    for(int i=0 ; i<n ; i++){
        
        if(arr[i] > largest){
            
            second_largest = largest;
            largest = arr[i];
            
        }
        
        else if(arr[i] < largest && arr[i] > second_largest){
            
            second_largest = arr[i];
            
      }
   
    }
    
    cout<<"2nd largest is : "<< second_largest;
    
    
}

int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the elements: ";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }

// 1st way : TC - O(nlogn)+ O(n)
    // BruteApproach(arr, n); 
    

// 2nd way :TC- O(n) + O(n) ~ O(2n)
//   BetterApproach(arr, n);
   
// 3rd way: TC- 
   OptimalApproach(arr, n);
   
    
    
    
}