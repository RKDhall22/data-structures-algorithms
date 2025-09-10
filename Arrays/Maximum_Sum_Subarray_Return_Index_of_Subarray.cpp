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
    

    
    
}