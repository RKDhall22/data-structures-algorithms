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

// 3rd Approach : Optimal One --> Will use Moore's voting algorithm to check for the majority element.
// TC : O(N) + O(N)
// SC : O(1)

int majority_Element_3(int arr[], int n){
    
    int count=0;
    int number;  // to store the element everytime when count is 0
    
    // lets iterate over array
    for(int i=0 ; i<n ; i++){
        
        if(count == 0){
            count = 1;
            number = arr[i]; // storing new element from array everytime when count is 0, because if count is 0, it means from previous all elements, there is no element who is in majority
            
        }
        
        else if(number == arr[i]){  // means previous element is equal to current element
            count++;
            
        }
        
        else {
            
            count--;
            
        }
    }
    
    // now again lets again iterate over array to check whether the element which is stored in number variable is the one who is in majority or not
    // We can also check here before iterating again that if count = 0, it means no element is there in majority. Hence no need to iterate again.
    
    int count1=0;
    
    for(int i=0 ; i<n ; i++){
        if(arr[i] == number) count1++;
    }
    
    // cout<<number<<" "<<count<<endl;
    
    if(count1 > n/2) return number;
    
    return -1;  // no element is in majority 
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

    cout<<majority_Element_2(arr , n);

      // 3rd Approach : Optimal one --> Moore's Voting Algorithm , here in this we take 2 parameters , one is element and 2nd is count variable. Initially the count is 0, and once we get the count equals to 0, will store the everytime new array element in one variable lets say number and when if the next array element is equal to number then increase the count and if not equal then decrease the count. Here the intiution of the algo is, if any element is there in majority the count will not be 0 , for example if the element occurs 3 times in a 5 size array, it means this element's count cannot be make to 0 as only remaining 2 elements are there will declines the value of count to 1, not 0, hence it means majority element is there in array.
       // TC : O(N) + O(N)
      // SC : O(1)
    
    cout<<majority_Element_3(arr, n);
      

}
