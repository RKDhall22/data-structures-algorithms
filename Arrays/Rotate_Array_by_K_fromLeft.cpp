#include<bits/stdc++.h>
using namespace std;

// Rotate Array by k times from Left (Leetcode Problem)
// 1 2 3 4 5 , k=2  --> 3 4 5 1 2

// Given an integer array nums, rotate the array to the right from left by k steps, where k is non-negative.

// Brute Approach: O(N^2)
    // Time Complexity of this code : O(N^2)
    // Space Complexity : O(1) , no extra space, but yes we have used the given array space to swap the elements , hence the space taken for the algorithm is - O(N)

void Rotate_Array_by_k_Left(int arr[] , int n , int k){
    
    int rotate = k % n;
    
    while( rotate > 0){  // Max N times
        
        int i=0 , j=n-1;
        
        while(j > i){   // N times
            
            swap( arr[i] , arr[j]);
            j--;
            
        }
        
        rotate--;
        
    }
}

// Better Approach: TC O(K) + O(N-K) + O(N) ~ O(2N) 
//    Space Complexity: O(K)

// 1 2 3 4 5 , k=2
void Rotate_Array_by_k_Left_2( int arr[], int n , int k){
    
    vector<int> temp;
    
    k = k%n;

// Insert the first k elements in temp vector

    for(int i=0 ; i<k ; i++){
        
        temp.push_back(arr[i]);  // temp =[ 1 2 ]
        
    }
    
// left shift element starting from index k upto n-1 by k positions

    for(int i=k ; i<n ; i++){
        
        // index -- position , hence the relation is --> (i-k)
        // 2 -- 0 --> element at index 2 left shift by 2 to index 0
        // 3 -- 1 --> element at index 3 left shift by 2 to index 1
        // 4 -- 2 --> element at index 4 left shift by 2 to index 2
        
        arr[i-k] = arr[i];  // {1 2 3 4 5} --> { 3 4 5 4 5 }
        
    }
    
// Now insert the values from temp to array from index start from n-k, here in this case , it starts from index 4

     for(int i=n-k ; i<n ; i++){  
         
         arr[i] = temp[i-(n-k)];  // arr[n-k] = temp[0], arr[n-k+1]=temp[1]
         
         // Or you can also mention index=0 above this for loop and write arr[i] = temp[index] and then index++.
         
     }
    
    
}

// Optimal Approach : TC - O(2N) ~ O(N)
//   Space Complexity : O(1), not take any extra space

    // 1 2 3 4 5 , k=2  --> 3 4 5 1 2
    // We can also write the reverse function manually to reverse the array by taking the start and end index
    // Lets also write the reverse function manually to reverse the array within the specified limit.

void Reverse(int arr[] , int start , int end){
    
    while( start < end){
        
        swap(arr[start] , arr[end]);
        start++;
        end--;
        
    }

}
void Rotate_Array_by_k_Left_3(int arr[],int n ,int k){

    // reverse() function is a part of the Standard Template Library (STL) and is used to reverse the order of elements within a specified range. 
    // reverse() function takes two iterators as arguments: 
        // first: An iterator pointing to the beginning of the range to be reversed.
        // last: An iterator pointing to one position past the end of the range to be reversed.
    k = k%n;
    // reverse(arr , arr+k);  // 2 1 3 4 5  , 1st two values reversed
    // reverse(arr+k , arr+n); //2 1 5 4 3  , last 3 values reversed
    
    // Now if reverse the whole array , then we get the resultant array
    
    // reverse(arr, arr+n);  // 3 4 5 1 2

// Calling the Reverse function manually without using the reverse() STL   
    Reverse(arr, 0 , k-1 );   // k times 
    
    Reverse(arr, k , n-1);   // n-k times
    
    Reverse(arr, 0 , n-1);    // n times
    
    
}

int main(){
    
    int n;
    cout<<"Enter the size : ";
    cin >> n;
    
    int arr[n];
    
    cout<<"Enter the values in array: ";
    
    for(int i=0 ; i<n ; i++){
        
        cin >> arr[i];
        
    }
    
    int k;
    
    cout<<"Enter how many times you want to rotate the array : ";
    cin >> k;
    

// Brute Approach : Time Complexity --> O(N^2) , Space Complexity --> O(1) , No extra space

    // 1st Approach: Will use the 2 pointer approach to rotate the Array, keeping i at 0 and j at n-1 and then swap i and j , after that keep decrementing j by 1. i will be stable at index 0.

    // 2nd Approach: You can also place i at index 0 and j at index 1 and swap arr[i] and arr[j] , and move both i and j to right side by 1 that is i++ and j++.

   Rotate_Array_by_k_Left( arr , n , k);   // Brute Approach


// Better Approach

    // 3rd Approach: Take an extra vector to store the elements from the start upto k and then at the end insert these elements the original array. And also the elements which are there after k , left shift those elements by k position.

    // 1 2 3 4 5 --> k=2 , temp-{1,2} , --> elements after 2 , that is from 3 should be left shift by 2 so that end array after 2 rotations to right is --> 3 4 5 1 2

    Rotate_Array_by_k_Left_2(arr , n , k);  // Better Approach


// Optimal Approach

    // 4th Approach: If we reverse the array first from index 0 to upto k-1 , and then from index k to n-1 for example , 1 2 3 4 5  , k=2 --> from 0 -- 1 that is [ 2 1 3 4 5 ] and from 2 -- 4 that is [ 2 1 5 4 3] and now if we reverse the whole array that is from index 0 to n-1 , then will get the desired output.

    // 2 1 5 4 3 --> reverse it --> 3 4 5 1 2 

    Rotate_Array_by_k_Left_3(arr, n , k);



    
    for(auto it : arr){
        
        cout<<it<<" ";
        
    }
    
}