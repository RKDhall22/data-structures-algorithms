#include<bits/stdc++.h>
using namespace std;

// Maximum consecutive 1's in the Array

 //  1 1 0 1 1 1 0 1 1 0 1 1 1 1 --> 4 
 
 int Maximum_ones(int arr[] , int n){
     
     int count = 0 , maxi = 0;
     
     for(int i=0 ; i<n ; i++){
         
         if( arr[i] == 1){
             count++;
             maxi = max( maxi, count);
             
         }
         
         else{
             
             count = 0;
             
         }
     }
     
     return maxi;
     
 }

int main(){
    
    int n;
    
    cout<< " Enter the size of Array : ";
    cin >> n;
    
    int arr[n];
    
    cout<<"Enter the values in array : ";
    for(int i=0 ; i<n ; i++){
        
        cin >> arr[i];
        
    }

    // Lets solve this using the optimal approach as its stright forward .

    // TC : O(N)
    // SC : O(1)
    
    cout<< Maximum_ones(arr , n);
    
    
    
}