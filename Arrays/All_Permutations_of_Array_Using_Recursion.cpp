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

// 2nd Approach : Optimal one --> Using swapping technique to get all the permutations

void Permutation_2(int index, int arr[] , int n , vector<vector<int>>& ans){
    
    if(index == n){    // Base Condition
        ans.push_back(arr);
        return;
    }
    
    for(int i=index , i<n ; i++){
        
        swap(arr[index] , arr[i]);  // Swapping to get the possible outcomes of permutations
        Permutation(index+1 , arr , n , ans);
        swap(arr[index] , arr[i]);   // Again making the array in its original form that that is 1 2 3 so that in the next swap, 1 will swap with 2 and then 1 will swap with 3.
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

   sort(arr, arr+n);   // If wanted the permutations in dictionary format
   
   Permutation(arr, ds , ans , freq , n);

// 2nd Approach : Optimal one --> Using swapping technique to have all the permutations by swapping the 0th index 0th index itself, then swap with 1st index, then swap with 2nd index in case of 3 elements.
    // for example --> 1 2 3 
    // first 1 will swap with 1 to get the first Permutation part that is 1 2 3
    // then 1 will swap with 2nd index to get the 2nd Permutation part that is 2 1 3
    // then 1 will swap with 3rd index to get the 3rd permutation part that is 3 2 1
    // Now we have all the elements positioned at index 0 so that we can make all the permutations.
   
    
     Permutation(0 , arr , n , ans);
     

// To print all the permutations
   for(const auto& it: ans){
       
       for(const auto& it1 : it){
             cout<<it1<<" ";
       }
       
       cout<<endl;
   
   }
  
   
   
}

