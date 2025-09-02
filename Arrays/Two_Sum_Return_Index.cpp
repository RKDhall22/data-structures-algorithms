#include<bits/stdc++.h>
using namespace std;

// 2 Sum problem, return the index of the pairs which gives sum equal to target


// 1st Approach : Brute One --> Will use nested loop and check is any pair exist with sum equal to target , if yes then return the index of both the pair, else return (-1,-1)
  // TC : O(N*N)
 // SC : O(1)

pair<int, int> two_Sum(int arr[] , int n, int target){
    
    for(int i=0 ; i<n-1 ; i++){
        
        for(int j=i+1; j<n ; j++){
            
            if(arr[i]+arr[j] == target){
                return {i,j};
            }
            
        }
    }
    
    return {-1,-1};
}

// 2nd Approach : Will use map to store each element and check for the element equals to (target-currelement) whether its there in map already or not. If at the iterating the end of the array , we does not get the element equal to (target-currelement), then there is no pair exist whose sum is equal to target.// TC : O(N) , if uses unordered map, if worst case occurs then O(N*N), but if uses map the always the TC : O(N*logN)
    // SC : O(N)

pair<int, int> two_Sum_2(int arr[], int n , int target){
    
    unordered_map<int , int> ump;
    
    // Iterate over array to store the elements with its index into map
    for(int i=0 ; i<n ; i++){
        
        int more = target-arr[i];
        
        if(ump.find(more) != ump.end()){
            
            return {ump[more] , i};
            
        }
        
        ump[arr[i]] = i;
        
    }
    
    return {-1, -1};
    
}
 
int main(){
    
    int n;
    cout<<"Enter the size: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter the values: ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    int target;
    cout<<"Enter the target value: ";
    cin >> target;
    
    // 1st Approach : Brute one--> Using nested loop to check whether any pair exist with sum equal to target
    // TC : O(N*N)
    // SC : O(1)
    
    cout<<two_Sum(arr , n , target).first<<" "<<two_Sum(arr , n , target).second;
    
    // 2nd Approach : Better one/Optimal one --> Will using map/undordered map to store the elements and its index, and check whether the element equal to (target-currelement) is already there in map or not, if its there then return the index of current element and the index of element equals to (target-currelement)
    // TC : O(N) , if uses unordered map, if worst case occurs then O(N*N), but if uses map the always the TC : O(N*logN)
    // SC : O(N)
    
   cout<<two_Sum_2(arr, n, target).first<<" "<<two_Sum_2(arr,n, target).second;
   
   
   // Note : We can solve this using 2 pointer concept by first storing each element and is corresponding index in any other data structure like vector/map and then sort it, so it will be sorted as per the first value that is the element itself and then we can check for target. But this is not an optimal solution because here we are taking Space that is O(2*N), which is not optimal. Hence, in this the TC : O(N*logN) for sorting and SC: O(2*N).
   
   
    
}