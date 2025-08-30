#include<bits/stdc++.h>
using namespace std;

// Longest subarray length with sum K , Array contains only positives and 0 .
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

// 2nd Approach : Better one --> Using Unordered map to store sum as key and index as value. If Array contains both positive and negative elements, then this is the optimal Approach.
 // But if we have only 0s and positive elements in the array, then we have one better solution than this that is we can using 2 pointer concept.
  // TC: O(N) , in worst case, the TC will be O(N*N) as unordered map gives O(N), in worst case. If use map , the TC will always be O(NlogN)
  // SC : O(N)
   
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
   
   
 // 3rd Approach : 2 pointer concept --> will have 2 pointers lets say left and right pointer, both initially pointing to the first index. Will keep on moving the right pointer and keep on adding the values in sum variable and once get sum equal to k , will store the length. If at any point the value of sum is greater than k, then will shrink the sum by removing the value indexed at left pointer from sum and move left pointer to right and keeps on doing this until sum is greater than K 
 
 // TC : O(2N) , if observe carefully the outer loop right<n , runs for N times, but the inner while loop as a whole also runs for N times, its not like the inner while loops runs N times when outer loops run for 1 time. As a whole the inner loop also runs for N times. Hence the overall TC is - O(2N)
 
 // SC : O(1) , as no extra space is using.
 
 void longest_Subarray_3(int arr[] , int n , int k){
     
     int sum = arr[0];  // Intially left and right pointer points to the first index, hence lets take that element as current sum value
     
     int left=0, right=0;
     int max_len = 0;
     
     while(right < n){
         
         while(left<=right && sum > k){  // means has to remove the element from left index , and continue doing this until sum > k and 
         
            sum = sum - arr[left];
            left++;
             
         }
         
         if(sum == k){
             
             max_len = max(max_len , right-left+1);
             
         }
         
         right++; // to add the next value , first have to move right pointer by 1 and then add the next value in the sum
         
         sum = sum + arr[right];
         
     }
     
     cout<<"Max length : "<<max_len;
     
 }
 
 


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
       
    // 2nd Approach : Optimal one --> We can use Unordered map or map to store the sum and the position as key-value pair respectively. In this method will check for prefix sum, for example the sum is x upto index i, will check whether there is sum already there (x-k) before , if its there then , get the index length and store the maximum one.
      // Also in this we have to handle one text case that if 0s are there in array for example:-
      // the array is 1 0 0 2 , and if k=2 , then in map the values will be stored as (1,0)--> (1,1) -->(1,2) means now sum=1 is stored at index 2 because key is always unique , hence 0 index is replaced by 1 and then 1 is replaced by 2 and now the pairs are like (1,2) and (3,3) , here we have to check whether in past is 1 sum is there, its there but at index 2 and if we check the difference betn values, its 1 which is correct ans , but not the longest lenght of subarray. The longest length is (0 0 2) that is 3.
       // TC: O(N) , in worst case, the TC will be O(N*N) as unordered map gives O(N), in worst case. If use map , the TC will always be O(NlogN)
       // SC : O(N)
      
        longest_Subarray_2(arr , n , k);
        
    //  3rd Approach : 2 pointer concept --> will have 2 pointers lets say left and right pointer, both initially pointing to the first index. Will keep on moving the right pointer and keep on adding the values in sum variable and once get sum equal to k , will store the length. If at any point the value of sum is greater than k, then will shrink the sum by removing the value indexed at left pointer from sum and move left pointer to right and keeps on doing this until sum is greater than K. And this approach is applicable if Array has 0s and positive numbers only
    
        longest_Subarray_3(arr , n , k);
        
      
      
       
       
    
    
    
}