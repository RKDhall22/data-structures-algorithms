#include<bits/stdc++.h>
using namespace std;

// Now lets see about Bubble sort - here we push the max element at the end

// Here the TC for Worst and Avg case - O(N^2) , but for best case, when at the first time only if there is no swap, it means the whole array is already sorted. Hence, in that case the best TC is - O(1) , it means the loop runs for only i=1, and then break from there

// In this bubble sort, we compare elements with the adjacent element and push the maximum elememt at the end of the array.

// 3 2 6 7 1 --> 2 3 6 1 7 - Now after 1st iteration, highest is in last
//               2 3 1 6 7 - till 2nd last sorted
//               2 1 3 6 7 - till, 3rd last sorted
//               1 2 3 6 7 - till 4th from end sorted
                 
// Not required to check for last single element which is at index 0, as a single element is already sorted

// lets see how the loop will go for bubble sort:
    //  1st time - 0 -- n-1
    //  2nd time - 0 -- n-2
    //  3rd time - 0 -- n-3
    //  |
    //  |
    //           - 0 -- 1 --> not required to go to till 0th index, as the single element at the end is already sorted.

    // Hence the best time complexity for Bubble Sort is - O(N) , when for i=1, j runs for N times and as array is sorted , no swap betn Elements done, and just break out from there.
 
void Bubble_Sort(int n, int arr[]){

    int flag=0;
    
    for(int i=n-1 ; i>=1 ; i--){
        
        for(int j=0 ; j<=i-1 ; j++){  // Here have to run upto n-1 , because we are comparing j with j+1 , so when j==i , we are comparing with i+1 index, which is not there, so it will give "Runtime Error".
            
            if(arr[j]>arr[j+1]){
                
                swap(arr[j] , arr[j+1]);
                flag=1;
                
            }

        }

        if(flag==0) break;  // It means no swaping occurs betn elements, and all elements are sorted in asc order.
    }

    

}

void Bubble_sort1(int n , int arr[]){
    
   for(int i=0 ; i<n-1 ; i++){   // i goes till n-2
       
       for(int j=0 ; j< n-i-1 ; j++){   // Here, when i=0 and j=n-1 , then it compared to j=n, which index is not present in Array, as it goes from 0 to n-1 , hence for j we have run the loop till n-2, so it compares to n-2 and n-1 only max.
           
           if(arr[j] > arr[j+1]){
               
               swap(arr[j] , arr[j+1]);
               
           }
       }
   }
}

int main(){
    
    int n;
    
    cout<<"Enter the size of Array: ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the array elements: ";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    Bubble_Sort(n , arr);

    Bubble_sort1(n, arr);
    
    // Now lets print the sorted array
    
    for(auto i : arr){
        
        cout<<i <<" ";
        
    }
    
}


                 
                 