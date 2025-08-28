#include<bits/stdc++.h>
using namespace std;

// Find the element whose occurence is one only, other are two.

// 1st Approach : Brute one
 // TC : O(N*N)
 // SC : O(1)

void one_Occurence(int arr[] , int n){
    
    int count;
    
    for(int i=0 ; i<n ; i++){
        
        count =0;
        
        for(int j=0 ; j<n ; j++){
            
                if(arr[i] == arr[j]){
                    
                    count++;
                    
                }
                
                if(count == 2){  // little bit more optimized
                    break;
                }
        }
        
        if(count == 1){
            
            cout<<arr[i];
            break;
            
        }
    }
}

// 2nd Approach: Better One --> Using hashmap or hashtable to store the occurence. Size of hashmap is highest value of array +1 means , hash[high+1]
   // TC : O(N) + O(N) + O(N) ~ O(3N)
   // SC : O(Maximum_Element + 1)

void one_Occurence_1(int arr[] , int n){
    
    int maxi = arr[0];
    
    // find out the highest value
    for(int i=0 ; i<n ; i++){   // N times
        
        maxi = max( maxi , arr[i]);  // stores the maximum value
        
    }
    
    vector<int> hash(maxi+1 , 0);
    
    // Now lets iterate over the array to store the frequency of the values in hash 
    for(int i=0 ; i< n ; i++){  // N times
        
        hash[arr[i]]++;
        
    }
    
    // Now lets iterate over the hash and the element whose frequency is 1 , that is the result means occurence is 1 of that element.
    
    for(int i=0 ; i<n ; i++){   // N times, in worst case if the element is not present the occurence is 1 of the maxi element, then this loop checks till last index
        
        if(hash[i] == 1){
            
            cout<<i<<" ";
            break;
            
        }
    }
    
    
}
// 3rd Approach : Better one -- Using Unordered Map to have the frequency of the values and then return the value whose frequency is 1
  // TC : O(N) + O(N/2+1)
  // SC: O(N/2+1)

 // 1 2 1 3 4 3 4
void one_Occurence_2(int arr[] , int n){
    
    unordered_map<int , int> ump;
    
    // lets iterate over the array and take the count of values
    
    for(int i=0 ; i<n ; i++){   // N times
        
        ump[arr[i]]++;  // (1,2) (2,1) (3,2) (4,2) , not necessay the order is sorted
        
    }
    
    // now lets iterate over the unordered map to get the result that is to get the value whose occurence is 1 in the array
    for(auto it : ump){   // N/2+1 , as every element occurs twice, only one element is occurred once. hence in map/unordered map , the elements count will be (n/2+1) only.
        
        if(it.second == 1){
            
            cout<<it.first<<" ";
            break;
            
        }
    }
    

}

// 4th Approach : Using XOR operation on the array elements.
 // TC : O(N)
 // SC : O(1)

void one_Occurence_3(int arr[] , int n){
    
    int XOR = 0;
    
    //lets iterate over the array and do the XOR operation
    for(int i=0 ; i<n ; i++){
        
        XOR = XOR ^ arr[i];  // 1^2^1^3^4^4^3  --> 0^2 --> 2
        
    }
    
    cout<<XOR;
    
}

int main(){
    
    int n;
    
    cout<<"Enter the size of Array : ";
    cin >> n;
    
    int arr[n];
    
    cout<<"Enter the values in the array : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

// 1st Approach : Brute One --> Will use nested loop and find the occurence of element.
  // TC : O(N*N)
  // SC : O(1) , not extra space used

    one_Occurence(arr , n);
    
// 2nd Approach : Better One --> Can use the Hashmap/Hash Table to store the values and its respective frequency and the size of the Hash table is the whatever the highest value is there in the array
   // TC : O(N) + O(N) + O(N) ~ O(3N)
   // SC : O(Maximum_Element + 1)

    one_Occurence_1(arr , n);
    
// 3rd Approach : Using Map or Unordered Map data struture to store the value and its frequency in (key-value) pair.
 // As unordered map is better in terms of Avg and best case time complexity , hence will use unordered map here.
 
   // TC : O(N) + O(N/2+1)
  // SC: O(N/2+1)
 
  one_Occurence_2(arr , n);
   
 // 4th Approach : Optimal One --> Using XOR operation over the array elements, as only one element occurs once in the array and all other occurs twice, then doing XOR means at the end only that single element whose occurence is once will be there XOR with 0 and this result gives output that single element.
  // means --> 1^2^1^3^4^4^3  --> 0^2 --> 2 (got the output)
 // TC : O(N)
 // SC : O(1)
     
     one_Occurence_3(arr , n);
   
    
    
    
}