#include<bits/stdc++.h>
using namespace std;

// Find number of Subarrays with sum K, Array contains all elements , positive and negative.


// 1st Approach : Brute one --> Using nested loop and count how many times the sum is occuring as K and then return the count.
 // TC : O(N*N)
 // SC : O(1) , no extra space used

void Number_Subarray(int arr[] , int n, int k){
    
    int count = 0;
    
    for(int i=0 ; i<n ; i++){
        
        int sum = 0;
        
        for(int j=i ; j<n ; j++){
            
            sum = sum + arr[j];
            
            if(sum == k){
                count++;
            } 
            
            else if(sum > k) {
                break;
            }
        }
        
    }
    
    cout<<"Number of Subarray with sum K is : "<<count;
    
}

int main(){
    
    int n;
    cout<<"Enter size: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter valuess : ";
    for(int i=0 ; i<n; i++){
        cin >> arr[i];
        
    }
    
    int k;
    cout<<"Enter the value of k: ";
    cin >> k;
    
    // 1st Approach : Brute one --> Lets use the nested loop and find out doing the sum of each element and if at at moment the sum is greater than k, break the inner loop from there. If before that the sum is K, take the count and move on.
    
       Number_Subarray(arr , n , k);
       
    // 2nd Approach : Optimal one --> 
}