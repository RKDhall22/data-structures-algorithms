#include<bits/stdc++.h>
using namespace std;

// 2 Sum problem , if sum of 2 variables is equal to target , return yes else no.

// 1st Approach : Using nested loop to find if any pair exist of Sum equal to Target.
 // TC : O(N*N)
 // SC : O(1)

string two_Sum(int arr[] , int n, int target){
    
    for(int i=0 ; i<n-1 ; i++){
        
        for(int j=i+1 ; j<n ; j++){
            
            if(arr[i]+arr[j] == target){
                
                return "Yes";
                
            }
            
        }
    }
    
    return "No";
    
}

// 2nd Approach : Better one --> Using map/unordered map to store elements as key and index as value and check for the element equals to (target-x), whether this is present already or not in map, if its present return yes, else no.
 // TC : O(N) , if using unordered map, in worst case it can go upto O(N*N), thats very rare. If using ordered map, then TC : O(N*logN)
 // SC : O(N), in worst case

string two_Sum_2(int arr[] , int n , int target){
    
    unordered_map<int , int> ump;
    
    //traverse over array element and store it in ump
    for(int i=0 ; i<n ; i++){
        
        int more = target - arr[i];  
        
        if(ump.find(more) != ump.end()){  // it means target-x is there in map
           
           return "Yes";
            
        }
        
        ump[arr[i]] = i;
        
    }
    
    return "No";
}

// 3rd Approach : Sort the array and then use 2 pointer concept to find if any pair exist which gives sum equals to target
 // TC : O(N*logN) + O(N) ~ O(N*logN)
 // SC : O(1)

string two_Sum_3(int arr[] , int n , int target){
    
    int left = 0;
    int right = n-1;
    
    // first lets sort the Array
    sort(arr, arr+n);   // N*LogN
    
    while(left < right){  // cannot write as left<=right, because want pair, not same number addition gives result equal to target
    
       if(arr[left]+arr[right] == target){
           return "Yes";
       }
       
       else if(arr[left]+arr[right] < target){
           left++;
       }
       else{
           right--;
       }
        
    }
    
    return "No";
    
}

int main(){
    
    int n;
    cout<<"Enter size: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter values in array : ";
    
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    int target;
    cout<<"Enter the target value: ";
    cin >> target;
    
    // 1st Approach : Brute one --> Will use nested for loop and check for each number with other number and if the sum is equal to target, then return yes else return No.
    // TC : O(N*N)
    // SC : O(1)
    
      cout<< two_Sum(arr , n , target);
      
    // 2nd Approach : Better one --> will use Hashing means will use map/unordered map to store the elements as key and index as value. In this logic is , will check if element x is there in map, is in that map, any other element of value (target-x) is there or not. If its there, then it means 2 values are there whose sum is equal to target. If at the end, no value found which equals to (target-x), then return No.
     // TC : O(N*logN)
     // SC : O(N)
    
      cout<< two_Sum_2(arr, n , target);
      
    // 3rd Approach : Optimal Approach in terms of Space Complexity: As we have to just say yes or no, hence in the 2nd approach we are using extra space, hence if we sort the array, then we can use 2 pointer concept, hence in this approach the time complexity remains same that is O(N*logN) because of sorting function , but the SC becomes O(1).
    // TC : O(NlogN)
    // SC : O(1)
    
      cout<< two_Sum_3(arr , n , target);
      
      
      
}