// Here the array has both positive and negative numbers

#include<bits/stdc++.h>
using namespace std;

// Longest subarray length with sum K
// 1 2 3 1 1 1 4 2 3, k=3 , maximum length = 3 that is [1 1 1]


// 1st Approach : Brute one --> Use nested loop to store the length
  // TC : O(N*N)
 // SC : O(1)

void longest_Subarray(int arr[] , int n , int k){
    
    int max_len = -1;
    
    for(int i=0 ; i<n ; i++){
        
        int sum = 0;
        
        for(int j=i ; j<n ; j++){
            
            sum = sum + arr[j];
            
            if(sum == k){
                
                max_len = max(max_len , j-i+1);
                
            }
            
            if(sum > k){
                break;  // no need to check further
            }
            
        }
        
    }
    
    cout<<"Max length :"<<max_len;
}

// 2nd Approach : Optimal one --> Using Unordered map to store sum as key and index as value. 
  // TC: O(N), if using unordered map, but if use ordered map , then the TC: O(NlogN). But in unordered map if the worst case arrises because of collisions, then the TC : O(N*N) 
  // SC : O(N)

// This 2nd approach is optimal approach if Array contains positive and negative numbers , both.
   
   void longest_Subarray_2(int arr[] , int n , int k){
       
       unordered_map<int , int> ump;
       
       int max_len = -1;
       int sum = 0;
       
       for(int i=0 ; i<n ; i++){
           
           sum = sum + arr[i];
           
           if(sum == k){
               
               max_len = i+1;
               
           }
           
           int rem = sum - k;  // this is checking for (x-k) is there previously or not
           
           if(ump.find(rem) != ump.end() ) { // means rem is there in map before
           
               max_len = max(max_len , i - ump[rem]);
               
           }
           
           // handling one edge case, if 0 is there in array, so for this, will check if sum is already there in map before not add again because this will change the index position
           
           if( ump.find(sum) == ump.end() ){ // means sum is not there in map
           
               ump[sum] = i;
               
           }
 
       }
       
       cout<<"Maxi length : "<<max_len;
   }

// 3rd Approach : Optimal one


int main(){
    
    int n;
    cout<<"Enter the size : ";
    cin >> n;
    
    int arr[n];
    
    cout<<"Enter the values: ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    int k;
    cout<<"Enter the value of k: ";
    cin >> k;
    
    // 1st Approach: Brute one --> We can use nested loop and run the inner loop start from outer loop index. and if at any point get the result equal to K, will store the length and return the max length after iterate over all the values
      // TC : O(N*N)
      // SC : O(1)
    
      longest_Subarray(arr , n , k);
       
    // 2nd Approach : Better one --> We can use Unordered map or map to store the sum and the position as key-value pair respectively. In this method will check for prefix sum, for example the sum is x upto index i, will check whether there is sum already there (x-k) before , if its there then , get the index length and store the maximum one.
      // Also in this we have to handle one text case that if 0s are there in array for example:-
      // the array is 1 0 0 2 , and if k=2 , then in map the values will be stored as (1,0)--> (1,1) -->(1,2) means now sum=1 is stored at index 2 because key is always unique , hence 0 index is replaced by 1 and then 1 is replaced by 2 and now the pairs are like (1,2) and (3,3) , here we have to check whether in past is 1 sum is there, its there but at index 2 and if we check the difference betn values, its 1 which is correct ans , but not the longest lenght of subarray. The longest length is (0 0 2) that is 3.
      
        longest_Subarray_2(arr , n , k);
      
      
       
       
    
    
    
}