#include <bits/stdc++.h>
using namespace std;

// Rotate Array by k times from Right (Leetcode Problem)
// 1 2 3 4 5 , k=2 --> 4 5 1 2 3

// Given an integer array nums, rotate the array to the left from right by k steps, where k is non-negative.

// Brute Approach:
    // Time Complexity of this code : O(N^2)
    // Space Complexity : O(1) , no extra space, but yes we have used the given array space to swap the elements , hence the space taken for the algorithm is - O(N)

void Rotate_Array_by_k_Right(int arr[], int n, int k)
{

    int rotate = k % n;

    while (rotate > 0)
    {

        int i = 0, j = n - 1;

        while (i < j)
        {

            swap(arr[i], arr[j]);
            i++;
        }

        rotate--;
    }
}

// Better Approach: TC - O(k) + O(N-k) + O(k) ~ O(N+k)
  // Space Complexity: O(k)

// 1 2 3 4 5 , k=2 --> 4 5 1 2 3

void Rotate_Array_by_k_Right_2(int arr[], int n, int k)
{

    vector<int> temp;

    // storing the elements from index n-k till n-1 and will place these elements in the start of the array
    for (int i = n - k; i < n; i++)
    { // k times

        temp.push_back(arr[i]); // 4 5
    }

    // Now lets right shift the elements starting from index 0 to n-k-1 by k positions

    // n-k times
    for (int i = n - k - 1; i >= 0; i--)
    { // element from n-k-1 upto 0th index, here we are going in decreasing order because if go in increasing that is from 0th index to n-k-1 , then in first operation 0th index value going to 2nd index position , so the original value at index 2 is now replaced by 0th index value, so the original value is removed now which is there at index 2. Thats not correct. Hence will start from index -> n-k-1 and go till index 0 to position the value properly.

        // 2 -- 4 --> 2nd index element at index 4 shifted by 2 positions
        // 1 -- 3 --> 1st index element at index 3 shifted by 2 positions
        // 0 -- 2 --> 0th index element at index 2 shifted by 2 positions

        arr[i + k] = arr[i]; // _ _ 1 2 3
        //  cout<<arr[i]<<" "<<arr[i+k];
    }

    // Now lets insert the values of temp in the start positions from index 0 to k-1

    // k times
    for (int i = 0; i < k; i++)
    {

        arr[i] = temp[i]; // 4 5
    }

    // Now the array has element in order --> 4 5 1 2 3
}


// Optimal Approach : Time Complexity -> O (2N) ~ O(N)
   // Space Complexity: O(1) , no extra space

void Reverse(int arr[] , int low , int high){
    
    while(low < high){
        
        swap(arr[low] , arr[high]);
        low++;
        high--;
        
    }
}

 void Rotate_Array_by_k_Right_3(int arr[] , int n , int k){
     
     // If vector is there , we can use the reverse() to reverse the array as below:
     
     //  reverse(nums.begin() , nums.begin() + n-k); 
    //  reverse(nums.begin() + n-k  , nums.end());

    // Can also write the above 2 reverse function by mentioning the end() 
    //  reverse(nums.begin() , nums.end() - k);
    //  reverse(nums.end() -k , nums.end() );
    //  reverse(nums.begin() , nums.end());
    
  // As here we are using the Array , hence lets write the Reverse() function logic manually
  
    Reverse(arr , 0 , n-k-1);  // n-k times
    Reverse(arr , n-k , n-1);  // k times
    Reverse(arr, 0 , n-1);   // n times
    
    
 }

int main()
{

    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];

    cout << "Enter the values in array: ";

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    int k;

    cout << "Enter how many times you want to rotate the array : ";
    cin >> k;

    // Brute Approach: Time Complexity- O(N^2)
        // Space Complexity : O(1)
        // 1st Approach: Will use the 2 pointer approach to rotate the Array, keeping i at 0 and j at n-1 and then swap i and j , after that keep incrementing i by 1. j will be stable at index n-1.

        // 2nd Approach: You can also place i at index n-2 and j at index n-1 and swap arr[i] and arr[j] , and move both i and j to left side by 1 that is i-- and j--.

    Rotate_Array_by_k_Right(arr, n, k);

    // Better Approach: Time Complexity- O(k) + O(N-k) + O(k) ~ O(N+k)
        // Space Complexity : O(k)
        // Used an extra vector to store the k elements from the last in the vector and then insert these k elements in the start of the array

    Rotate_Array_by_k_Right_2(arr, n, k);

    // Optimal Approach: Time Complexity -> O (2N) ~ O(N)
         // Space Complexity: O(1) , no extra space
         // Here reverse the specific part of the array, like reverse values from index 0 -- n-k-1 , then n-k -- n-1 and if now just reverse the array, will the resultant.

     // Time Complexity -> O (2N) ~ O(N)
   // Space Complexity: O(1) , no extra space

    Rotate_Array_by_k_Right_3(arr , n , k);

    for (auto it : arr)
    {

        cout << it << " ";
    }

}
