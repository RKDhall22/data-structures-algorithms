#include<bits/stdc++.h>
using namespace std;

// Majority Element --> Majority element is the one whose count is more than half the size of the array.
// 2 2 3 3 1 2 2  --> Output - 2 , count is 4 which is greater than 7/2 = 3

// 1st Approach : Brute one --> Checking each element and store its count and return when the count is more than half the size of the array. 
// TC : O(N*N)
// SC : O(1)

int majority_Element(int arr[] , int n){
    
    for(int i=0 ; i<n ; i++){
        
        int count = 0;
        
        for(int j=0 ; j<n ; j++){
            
            if(arr[i] == arr[j]) count++;
            
        }
        
        if(count > n/2){
            return arr[i];
        }
        
    }
    
    return -1;
}

// 2nd Approach: Better one --> Will use map to store the element and its count and then return the element whose count is more than n/2
// TC : O(N), if best and avg for unordered map, if worst then TC : O(N*N)
 // but if use ordered map , then TC is always : O(N*logN) + O(N)
 // SC :O(N), if array contains all unique elements

int majority_Element_2(int arr[] , int n){
    
    unordered_map<int , int > ump;
    
    //iterate over array to store the count of elements
    for(int i=0 ; i<n ; i++){  
        ump[arr[i]]++;
    }
    
    // Now lets iterate over map to check the count value with n/2
    for(auto it : ump){
        
        if(it.second > n/2) return it.first;
        
    }
    
    return -1;
    
}

int main(){
    
    int n;
    cout<<"Enter the size of Array: ";
    cin >> n ; 
    
    int arr[n];
    cout<<"Enter the values : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    // 1st Approach : Brute one --> Check for each element and store its count, and if at any moment the count of any element is more than the half the size of Array that is the Majority Element and return that element. If after traversing whole Array, we does not get the any element like that return -1.
     // TC : O(N*N)
    // SC : O(1)

      cout<<majority_Element(arr , n);
       
    // 2nd Approach : Better one --> Will use map to store the element and its count and then iterate over array to check which element is there in map whose count is more than n/2.
    // TC : O(N), if best and avg for unordered map, if worst then TC : O(N*N)
   // but if use ordered map , then TC is always : O(N*logN) + O(N)
   // SC :O(N), if array contains all unique elements
    
      cout<<majority_Element_2(arr , n);
      
}