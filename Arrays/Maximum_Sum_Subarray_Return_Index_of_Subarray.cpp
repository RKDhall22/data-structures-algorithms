#include<bits/stdc++.h>
using namespace std;

// Maximum Sum Subarray  --> Return the Subarray index now, which has maximum sum, there can be multiple Subarray with same maximum sum, return any of the indexes.

// -2 -3 4 -1 -2 1 5 -3  --> Maximum Sum Subarray index --> [2,6]

// 1st Approach : Brute one --> As we get the currsum value greater than maxsum, at that time will store the value of i in startindex and value of j in endindex, because at a particular point when i is constant and j keeps on iterating from i to n-1, that time, whatever i value is there in startindex, it will be same as i is constant, only endindex value keeps on changing when currsum > maxsum.

    // TC : O(N*N)
    // SC : O(1)

void maximum_sum_Subarray(int arr[] , int n){
    
    int maxsum = INT_MIN;
    int startindex = -1;
    int endindex = -1;
    
    for(int i=0 ; i<n ; i++){
        
        int currsum = 0;
        
        for(int j=i ; j<n ; j++){
            
            currsum = currsum + arr[j];
            
           if(currsum > maxsum){
               
               startindex = i;
               endindex = j;
               maxsum = currsum;
               
           }
            
        }
    }
    
    cout<<startindex<<" "<<endindex<<endl;
    // return maxsum;
    
}

// 2nd Approach: Using Kadane's algo to find the startindex and endindex
// TC : O(N)
// SC : O(1)

void maximum_sum_Subarray_2(int arr[] , int n){
    
    int maxsum = INT_MIN;
    int currsum = 0;
    int startindex = -1;
    int endindex = -1;
    
    for(int i=0 ; i<n ; i++){
        
        if(currsum == 0){
            startindex = i;
        }
        
        currsum = currsum + arr[i];
        
        if(currsum > maxsum){
            maxsum = currsum;
            endindex = i;
        }
        
        if(currsum < 0){
            currsum = 0;
        }
        
    }
    
    cout<<startindex<<" "<<endindex;
    
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
    
// 1st Approach : Brute one --> Will check for every subarray and check their sum and store the starting index and end index in two variables and then at the end return those variables as start index and end index.
    // TC : O(N*N)
    // SC : O(1)
    
    maximum_sum_Subarray(arr, n);

     // 2nd Approach : Using Kadane's algorithm here to find the startindex and endindex of the Subarray which has maximum sum. Will store the value of index in startindex once we get the currentsum value equals to 0 and then keep on moving to next element and as we get currsum value greater than maxsum, that index will be stored in endindex and it changes as if next element is also positive then endindex value also change
    // TC : O(N)
   // SC : O(1)

     maximum_sum_Subarray_2(arr , n);
    

    
    

}
