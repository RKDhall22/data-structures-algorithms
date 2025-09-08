#include<bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum --> Find the subarray which has maximum sum and return that sum

// 1st Approach : Brute one --> Will check the sum of every subarray in the array and store the sum of the subarray whose sum is maximum in maxsum. Will use currsum for current sum of that particular Subarray.
    // TC : O(N*N)
    // SC : O(1)

int maximum_sum_Subarray(int arr[] , int n){
    
    int maxsum = arr[0];
    
    for(int i=0 ; i<n ; i++){
        
        int currsum = 0;
        
        for(int j=i ; j<n ; j++){
            
            currsum = currsum + arr[j];
            
            maxsum = max(currsum , maxsum);
            
        }
    }
    
    return maxsum;
    
}

int main(){
    
    int n;
    cout<<"Enter the size of Array: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter the values: ";
    
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    // 1st Approach : Brute one --> Will check for every subarray and check their sum and store the maximum sum and then return that.
    // TC : O(N*N)
    // SC : O(1)
    
    cout<<maximum_sum_Subarray(arr, n);
    
}