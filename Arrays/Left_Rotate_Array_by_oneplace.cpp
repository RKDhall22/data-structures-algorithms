#include<bits/stdc++.h>
using namespace std;

// Rotate the Array from left by one place
// 1 2 3 4 5 --> 2 3 4 5 1

// Time Complexity : O(N)

// Space Complexity, Extra Space: O(1)  , but yes we are using the array space in order to solve this problem , so to clarify to the interviewer, you have to say that to solve this problem we are using the original array space which is already there whose TC is - O(N), but no extra space we are using O(1)

void SecondApproach( int arr[] , int n){
    
    int temp = arr[0];
    
    for(int i=1 ; i<n ; i++){
        
        arr[i-1] = arr[i];
        
    }
    
    arr[n-1]= temp;
    
}

// 3rd Approach : 2 pointer concept

void ThirdApproach_2Pointer( int arr[] , int n){
    
    int i=0, j=1;
    
    while(j<n){
        
        swap(arr[i] , arr[j]);
        i++;
        j++;
        
    }
    
    // we can solve this using i only that is swaping i with i+1 and i++
    
}

void ForthApproach_2Pointer_1( int arr[] , int n){
    
    int i=0 , j=n-1;
    
    while(j > i){
        
        swap(arr[i] , arr[j]);
        j--;
        
    }
    
    // i value remain constant that is 0 , only j decrement by 1 until it reaches to one position ahead , because when both are pointing to same element there is no use of swaping the element
    
}

int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the values: ";
    for(int i=0 ; i<n ; i++){
        
        cin >> arr[i];
        
    }
    
// There are many ways to solve this question.

// 1st way: Take a new array , insert the values from index 1 of old array upto n-1. and at last insert value of index 0 in new array index n-1. And then insert all the values of new array in old array, but in this, Time Complexity : O(N) and Space Complexity: O(N)

// 2nd way: Store the value of index 0 in a variable and then left shift the values of array by 1 and then at index n-1 , insert the value of index 0 as its stored in new variable. This can be done without taking extra space. Lets solve this 2nd approach.

//   SecondApproach( arr , n); // TC - O(N) , SC- O
  
// 3rd way: Lets use the 2 pointer concept here , in 2 ways we can solve this using 2 pointer concept that is one by keeping i at index 0 and j at index 1 and then do swaping until the last element.
 // 2nd way is i at index 0 and j at index n-1 and then do swaping and only decrement j by 1 because at the first swap of 0 and n-1 , we will get the first element at index n-1 , hence now just decrease the value of j to have all the elements at the correct place
 
//   ThirdApproach_2Pointer( arr , n);
   
   ForthApproach_2Pointer_1( arr, n);  // 2nd way
  
  for(auto it : arr){
      
      cout<<it<<" ";
      
  }
    







}