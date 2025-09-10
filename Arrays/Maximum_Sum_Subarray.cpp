#include<bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum --> Find the subarray which has maximum sum and return that sum
// -2 -3 4 -1 -2 1 5 -3  --> Maximum Sum = 7

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

// 2nd Approach : Optimal one --> Using Kadane's Algorithm 
    // TC: O(N)
    // SC: O(1)

int maximum_sum_Subarray_2(int arr[] , int n){
    
    int maxsum = INT_MIN;
    int currsum = 0;
    
    for(int i=0 ; i<n ; i++){
        
        int currsum = currsum + arr[i];
        
        maxsum = max(currsum , maxsum);
    
        if(currsum < 0){
            
            currsum = 0;
            
        }
        
    }
    
   if(maxsum < 0) return 0;  // For empty subarray case which means if maxsum is negative( if the requirement is there in the problem) , return 0
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

    // 2nd Approach : Optimal Approach --> Kadane's Algorithm , will keep on adding the element until the sum is positive, if its negative then make the currsum = 0, and then move on to the next element.
    // TC : O(N)
    // SC : O(1)
    
    cout<<maximum_sum_Subarray_2(arr, n);
    

}

