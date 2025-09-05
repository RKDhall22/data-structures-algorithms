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

// 3rd Approach : Optimal One --> Using Dutch national flag algorithm.
// TC : O(N)
// SC : O(1)
void Sort_2(int arr[] , int n){
    
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    // Until mid is smaller or equal to high we have to check, because if mid crosses high, means we have covered whole array.
    
   while(mid <= high){  
        
        if(arr[mid] == 0){
            swap(arr[low] , arr[mid]);
            low++;   
            mid++;  // move the array to next part
            
        }
        
        else if(arr[mid] == 1){
            mid++;   // just shrink the array from left side
        }
        
        else {
            
            swap(arr[mid] , arr[high]);
            high--;   // just shrink array from end side
            
        }
    }
    
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
    
 // 2nd Approach: Better one --> Can take 3 variable for storing the count of 0s ,1s and 2s and then insert the values in the array as per the freq of each element.
  // TC: O(2N)
  // SC : O(1)
 
      Sort(arr , n );

    // 3rd Approach : Optimal Approach : Dutch National Flag Algorithm , in this we take 3 pointers name it low, mid and high , where the concept is like:
    
      // 0 to (low-1) --> all 0s
      // low to (mid-1) --> all 1s
      // mid to high --> elements consist of 0/1/2 , this is our array part
      // high+1 to n-1 --> all 2s
      
     // If we visualize this, we have the pointers low and mid points to 0th index and high points to last index, because our array is not sorted and consist of elements 0/1/2. If we assume this, we satisfy the above conditions that is, if low points to 0th index, its means before low that is (0 to low-1), there does not exist any element and so on. Our assumption is from mid to high the array consist elements randomly means not sorted having 0/1/2
     
     // So now lets see how the above concept works that is Dutch National flag algo. 
      // 1) If we encounter 0, then what the concept says, 0 should be in the range of (0 to low-1), hence swap(arr[low],arr[mid]), because at index low as per the concept, 1 is starting, hence we are swaping index low with index mid, it means now 0 is placed at index low, so now the low is pointing to the next index because as 0 is at low index now, hence low has to be increase by 1 so that the above concept is followed. and with that also we have to increase mid by 1, because we are assuming that at mid now 1 is there after swapping which makes this now as mid-1 index. Hence, mid now works from index mid+1.
      
      // 2) If we encounter 1, it means there is nothing to do, because as per the concept the elements before mid that is till mid-1, 1s are there, it means just shift mid by 1.
      
      // 3) If we encounter 2, then as we know that from index (high+1 till n-1), 2s are there, hence in this case we have to swap the element which is there at index high so that the continuation still remains the same, now just shrink the high part means high index is now decreased by 1.
      
             Sort_2(arr, n); 
      
      // print the array
   
      for(auto it : arr){
          cout<<it<<" ";
      }

}
