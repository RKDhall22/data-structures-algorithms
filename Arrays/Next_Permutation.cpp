#include<bits/stdc++.h>
using namespace std;

// Find Next Permutation --> An Array is given, find out the next permutation of the array , for example if the array is 2 1 3, it means if we see all the permutations of this array in dictionary format, then the next permutation of this is --> 2 3 1

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
    
    // 1st Approach : Brute one --> Will store all the permutation of the array in an vector array in sorted format and then do the linear search with the given array and find out the next permutation.
    
    vector<vector<int>> ans;   // to store all the permutation
    vector<int> ds; // this will store specific permutation
    int vis[n] = {0}; // this will store whether element of that position is inserted or not, if inserted, then make that position 1, so that next time will check and if found 1, then not take that element.
    
    next_Permutation(arr, n , ans, ds, vis );
    
}