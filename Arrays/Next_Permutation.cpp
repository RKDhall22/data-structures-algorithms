#include<bits/stdc++.h>
using namespace std;

// Find Next Permutation --> An Array is given, find out the next permutation of the array , for example if the array is 2 1 3, it means if we see all the permutations of this array in dictionary format, then the next permutation of this is --> 2 3 1


// 1st Approach : Brute Approach : Will store all the permutations by using Recursion concept and then do the linear search to find out the next permutation

void next_Permutation(vector<int>& arr , int n , vector<vector<int>>& ans, vector<int>& ds, int vis[] ){
    
    if(ds.size() == n){       // Base Condition
        ans.push_back(ds);  
        return;
    }
    
    for(int i=0 ; i<n ; i++){
        
        if(vis[i] == 0){
            
            vis[i] = 1;    // Means taken that element in ds
            ds.push_back(arr[i]);
            next_Permutation(arr, n, ans, ds, vis, cp);
            
            vis[i] = 0;  // after permutation done, then remove that so to have a new permutation
            ds.pop_back();
            
        }
    }
    
    // After the above loop over, we have all the permutations in the ans vector, now lets find the next permutation by comparing the arr vector with the vectors inside the ans vector
    
    
}

int main(){
    
    int n;
    cout<<"Enter the size of vector :";
    cin >> n;
    
    vector<int> arr;
    int value;
    
    cout<<"Enter values: ";
    
    // Insert values
    for(int i=0 ; i<n ; i++){
        cin >> value;
        arr.push_back(value);
    }
    
    // 1st Approach : Brute one --> Will store all the permutation by using Recursion of the array in an vector array in sorted format and then do the linear search with the given array and find out the next permutation.
    
    vector<vector<int>> ans;   // to store all the permutation
    vector<int> ds; // this will store specific permutation
    int vis[n] = {0}; // this will store whether element of that position is inserted or not, if inserted, then make that position 1, so that next time will check and if found 1, then not take that element again.
    
    // Before that lets sort the array and also before sorting lets store the original vector in any another on
    
    vector<int> cp(arr);
    sort(arr.begin() , arr.end());
    
    next_Permutation(arr, n , ans, ds, vis);
    
    // for(auto const& it : ans){
        
    //     for(auto const& it1 : it){
    //         cout<<it1<<" ";
    //     }
    //     cout<<endl;
    // }
    
    size_t index=0;  // Use size_t for indices, as it is unsigned
    for(size_t i=0 ; i<ans.size() ; i++){
        
        if(ans[i] == cp){
            index = i;
            break;
        }
    }
    
    // Check if there is a next permutation
      if (index + 1 < ans.size()) {
    // Print the next permutation
    for (int element : ans[index + 1]) {
        cout << element << " ";
    }
  } 

else {
    // This was the last permutation; print the first one
    for (int element : ans[0]) {
        cout << element << " ";
    }
    
   }
    
}

