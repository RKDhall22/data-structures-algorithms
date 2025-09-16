#include<bits/stdc++.h>
using namespace std;

// Print all Permutations of Array
// 1 2 3 --> 1 2 3 , 1 3 2 , 2 1 3, 2 3 1 , 3 1 2 , 3 2 1

// 1st Approach : Brute Approach --> Will use recursion to find out all the permutations of the Array
// TC : O(N!*N)  , N times the loop is running
  // SC : O(N) + O(N)
void Permutation(int arr[], vector<int> &ds , vector<vector<int>> &ans, int freq[] , int n){
    
    if(ds.size() == n){          // Base Condition
        ans.push_back(ds);
        return;
    }
    
    for(int i=0 ; i<n ; i++){
        
        if(freq[i] == 0){  // Means not included
            
            ds.push_back(arr[i]);
            freq[i] = 1;   // Marked tick means its there now
            
            Permutation(arr, ds, ans, freq, n);
            
            freq[i] = 0;
            ds.pop_back();
            
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
    
// 1st Approach : Brute Approach --> Will use recursion here to find all the permutations of the Array
  // TC : O(N!*N)  , N times the loop is running
  // SC : O(N) + O(N)

   int freq[n] = {0};  // Init with 0 , used this to check whether we have taken that particular value from Array in the other data structure lets take vector here to store the permutations.
   
   vector<int> ds;  // will store the particular permutation. This we will add in the Ans vector
   
   // Also will have an Ans vector which stores all the permutations. So, its type will be of vector
   
   vector<vector<int>> ans;
   
   Permutation(arr, ds , ans , freq , n);
  
   
   
}