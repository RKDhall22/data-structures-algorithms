#include<bits/stdc++.h>
using namespace std;

// Rearrange Array elements by sign, means the size of array is even here and half elements are positive and half elements are negative. Modify the original array with alternate +ve and -ve elements. The relative order should be maintained.
// 3 1 -2 -5 2 -4  --> 3 -2 1 -5 2 -4

// 1st Approach : Brute Approach --> Will have 2 new arrays, one will store positive elements and another will store the negative elements. Will traverse from the main array and store the positive elements in one array and negative elements in the other array
// TC : O(N)+O(N) ~ O(2N)
// SC : O(N)

void rearrange_Array(int arr[] , int n){
    
    vector<int> positive;    // for storing +ve elements
    vector<int> negative;    /// for storing -ve elements
    
    // Iterate over the array
    for(int i=0 ; i<n ; i++){
        
        if(arr[i] < 0){   // negative element
            negative.push_back(arr[i]);
        }
        
        else{            // +ve element
            positive.push_back(arr[i]);
        }
    }
    
    // Now elements are stored in both the array , hence lets now store these elements in the original array, one from positive array and one from negative array
    
    int posIndex = 0;  // for positive array
    int negIndex = 0;  // for negative array
    
    for(int i=0 ; i<n ; i++){
        
        if(i%2 == 0){   // in even place , +ve elements are there
            
            arr[i] = positive[posIndex++];
        }
        
        else{    // In odd place, -ve elements are there
            
            arr[i] = negative[negIndex++];
        }
    }
}


// 2nd Approach : Optimal one --> Just traverse the array once,and store the +ve and -ve alternate, as we know that positive is at even place and negative is at odd place.
 // TC : O(N)
 // SC : O(N)

void rearrange_Array_2(int arr[] , int n){
    
    vector<int> ans(n,0);  // size N, init with 0
    
    int posIndex = 0 , negIndex = 1;  // starting point for +ve and -ve element
    
    // Iterate the array
    
    for(int i=0 ; i<n ; i++){
        
        if(arr[i] < 0){
            ans[negIndex] = arr[i];
            negIndex+= 2;   // because the next -ve element should be 2 place ahead means 1 3 5 so on..
            
        }
        
        else{
            
            ans[posIndex] = arr[i];
            posIndex+= 2;   // 0 2 4 6 so on..
            
        }
    }
    
    // Print the ans now 
    for(auto it: ans){
        cout<<it<<" ";
        
    }
}

int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter values of Array: ";
    
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    // 1st Approach : Brute Approach --> Will have 2 new arrays, one will store positive elements and another will store the negative elements and then insert the elements in the original array alternate from both the array.
   // TC : O(N)+O(N) ~ O(2N)
   // SC : O(N)
    rearrange_Array(arr , n);
    
    
   // 2nd Approach : Optimal one --> will try to reduce the TC to O(N), means just traversing the array once, but here we are returing the new array, because anyhow we have to take extra array.
   // TC : O(N)
   // SC : O(N)
   
    rearrange_Array_2(arr , n);
    
    for(auto it: arr){
        cout<<it<<" ";
    }
    
    
}