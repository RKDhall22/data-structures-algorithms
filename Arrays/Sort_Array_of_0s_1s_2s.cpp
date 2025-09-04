#include<bits/stdc++.h>
using namespace std;

// Sort the Array of 0s, 1s and 2s
// 1 1 0 1 2 0 2 2 1 --> 0 0 1 1 1 1 2 2 2 

// 2nd Approach : Using 3 variables for storing the count of 0s,1s and 2s
// TC : O(2N)
// SC : O(1)

void Sort(int arr[] , int n){
    
   int count_Zero = 0;   // will store the frequency of 0s
   int count_One = 0;    // will store the frequency of 1s
   int count_Two = 0;    // will store the frequency of 2s
   
   // Lets iterate over the array to store the count of each element
   
   for(int i=0 ; i<n ; i++){
       
       if(arr[i] == 0) count_Zero++;
       else if(arr[i] == 1) count_One++;
       else count_Two++;
       
   }
   
   // Now lets insert the elements in the array in sorted order as per the freq stored in all 3 variables
   
   // for 0s
  for(int i=0 ; i<count_Zero ; i++){
      arr[i] = 0;
  }
   
  // for 1s
  for(int i=count_Zero ; i<count_Zero+count_One ; i++){
      arr[i] = 1;
  }
   
  // for 2s
  for(int i=count_Zero+count_One ; i<n ; i++){
      arr[i] = 2;
  }
   
   
   // Another way to store the values if not using the above for loops
   
//    int index=0;
   
//    // for 0s
//    while(index < count_Zero){
//        arr[index] = 0;
//        index++;
//    }
   
//    // for 1s
//    while(index < count_Zero+count_One){
//        arr[index] = 1;
//        index++;
//    }
   
//    // for 2s
//    while(index < n){
//        arr[index] = 2;
//        index++;
//    }
   
}

int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter values: ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
  // 1st Approach : Brute one --> If use any sorting algorithm like Merge or Quick sort, will get the result that 0s will be at start, 1s after 0 and then all the 2s at the end.
    // TC : O(N*logN)
    // SC : O(N) for Merge , O(1) for Quick
    
 // 2nd Approach: Better one --> Can use hashing by taking any array of size 3 , means index 0 , 1 and 2 will be there. And store the freq in each index of particular element. And then insert the values in original array as per the count of each element in Hash.
  // TC: O(2N)
  // SC : O(1)
 
      Sort(arr , n );
      
      // print the array
   
      for(auto it : arr){
          cout<<it<<" ";
      }
}