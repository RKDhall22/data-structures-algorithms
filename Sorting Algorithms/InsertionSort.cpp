#include<bits/stdc++.h>
using namespace std;

// Lets see Insertion Sort- It takes the element and place it in its correct order.

// For Insertion Sort, the Worst and Avg TC is - O(N^2)

// Dry run for TC Calculation : 1+2+3 -- n-1 = n(n+1)/2 == n^2

// But the best case TC is when in the inner for/while loop , there is no swaping happens, if j>j-1, means numbers are already sorted, so swaping is not there, therefore no use of taking j upto index 1, so we can break from the start point instead of going to index 1. So, in this case the TC is - O(N).

// Here, we can start from index 1 as , we compare that element with its all previous elements and drop that element at its correct order.

// // 3 2 6 7 1 --> 2 3 6 7 1   check for idx=1 , swap
//                  2 3 6 7 1   check for idx=2 , no swap
//                  2 3 6 7 1   check for idx=3 , no swap
//                  1 2 3 6 7   check for idx=4 , swap to its correct position

void Insertion_Sort(int n , int arr[]){
    
    for(int i=1 ; i<n ; i++){
        
        int j=i;
        
        while(j>0 && arr[j]<arr[j-1]){
            
            swap(arr[j] , arr[j-1]);
            j--;
            
        }
    }
    
    
}

// Using for loop inside too , lets see the code 
void Insertion_Sort1(int n , int arr[]){
    
    for(int i=1 ; i<n ; i++){
        
        for(int j=i ; j>0 ; j--){
            
            if(arr[j]<arr[j-1]){
                
                swap(arr[j] , arr[j-1]);
                
            }

            else{

                break;  // If the element is at its correct position 

            }
        }
    }
    
}

int main(){
    
    int n;
    cout<<"Enter the size :";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the Array values: ";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    // Insertion_Sort(n , arr);
    
    Insertion_Sort1(n, arr);
    
    //print the sorted array
    
    for(auto i : arr){
        cout<<i<<" ";
        
    }
    
    
    
    
    
}
                 