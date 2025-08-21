#include<bits/stdc++.h>
using namespace std;

// Remove duplicates in-place of sorted array
/// 1 1 2 2 3  --> 1 2 3 2 3

//1st Approach: Take set data struture and insert the elements in it (unique and sorted)
// TC of this approach is : N*logN + N
// Space complexity : O(N) , taking extra space for set

void BruteApproach( int arr[] , int n){
    // arr= 1 1 2 2 3 
    set<int> st;
    
    
    for(int i=0 ; i<n ; i++){ // N times
        
        st.insert( arr[i] );  // st= 1 2 3  , LogN TC of insert operation
        
    } // Total TC - O(N*logN)
    
    // Now in set the unique elements are there, and now insert these elements in the original array from index 0
    
    int index=0;
    
    for(auto it : st){  // N times, if all elements are unique in array, then in set , the size will be same as array
        
        arr[index] = it;
        index++;
        
    }

    
}

// 2nd Approach : Optimal Way, doing it by using 2 pointer , as array is sorted. lets keep i at index=0 , because the first element is always be at index 0 , hence lets keep start checking from index 1, keep j pointer at index 1 and then keep on checking until arr[i] != arr[j], and when its not equal, then push arr[j] at index i+1 and point i to the next index.

// Time Complexity: O(N) , SC - O(1)

void OptimalApproach(int arr[] , int n){
    
    int i=0;
    // 1 1 1 2 2 3 4  --> 1 2 3 4(sorted & unique) 2 3 4
    for(int j=1 ; j<n ; j++){
        
        if(arr[j] != arr[i]){
            
            arr[i+1] = arr[j];
            i++;
            
        }
    }
    
    cout<<"Unique elements are : "<<i+1 <<endl;
}

int main(){
    
    int n;
    
    cout<<"Enter the size of array: ";
    cin >> n;
    
    int arr[n];
    
    cout<<"Enter the values :";
    for(int i=0 ; i<n ; i++){
        
        cin >> arr[i];
        
    }
    
    // 1st Approach: Brute force , TC -  N*logN + N , Space - O(N)
    
    // BruteApproach( arr , n);
    
    // for(auto it : arr){
        
    //     cout<<it<<" ";
        
    // }
    
    // 2nd Approach : Optimal Solution , TC- O(N)
    
    OptimalApproach( arr , n);
    
       for(auto it : arr){
        
        cout<<it<<" ";
        
    }
    
}