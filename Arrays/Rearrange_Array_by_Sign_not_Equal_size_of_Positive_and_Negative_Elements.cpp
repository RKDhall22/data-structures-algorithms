#include<bits/stdc++.h>
using namespace std;

//2nd Case -->  Rearrange Array elements by sign, here its not compulsory that the +ve and -ve elements are equal. May be in the size of 6, 4 are +ve elements and remaining 2 elements are -ve. In this case, have alternate sign until its possible, then have all the remaining elements at the end as per their relative order

// 3 1 -2 2 -5 4  --> 3 -2 1 -5 2 4

// 1st Approach : Brute Approach --> Will have 2 new arrays, one will store positive elements and another will store the negative elements. Will traverse from the main array and store the positive elements in one array and negative elements in the other array
// TC : O(N)+O(N) ~ O(2N)
// SC : O(N)

// 3 1 -2 2 -5 4 
void rearrange_Array(int arr[] , int n){
    
    vector<int> positive;    // for storing +ve elements
    vector<int> negative;    /// for storing -ve elements
    
    // Iterate over the array
    for(int i=0 ; i<n ; i++){
        
        if(arr[i] < 0){   // negative element
            negative.push_back(arr[i]);    // -2 -5
        }
        
        else{            // +ve element
            positive.push_back(arr[i]);    // 3 1 2 4
        }
    }
    
    // Now elements are stored in both the array , hence lets now store these elements in the original array, one from positive array and one from negative array
    
    int posIndex = 0;  // for positive array
    int negIndex = 0;  // for negative array
    
    int smaller_size = min(positive.size() , negative.size()); // store the min size of both because till twice of that, the alternate sign will be possible. In the above array case the value will be 2, means twice of this that is upto 4 positions, the alternate signs will be there.
    
    // 3 -2 1 -5
    for(int i=0 ; i<2*smaller_size; i++){
        
        if(i%2==0){
            arr[i] = positive[posIndex++];
        }
        
        else{
            arr[i] = negative[negIndex++];
        }
    }
    
    // Now in the remaining places, insert the left out elements directly
    
    for(int i=2*smaller_size ; i<n ; i++){
        
        if(positive.size() > negative.size()){  // positive vector is more ele
            
            arr[i] = positive[posIndex++];
            
        }
        
        else{   // negative vector is more elements
            
            arr[i] = negative[negIndex++];
            
        }
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
    
    // 1st Approach : Brute Approach --> Will have 2 new arrays, one will store positive elements and another will store the negative elements and then insert the elements in the original array alternate from both the array until the size of smaller array, means if -ve elements are 2 and +ve are 4, it means 2 +ve and 2 -ve alternate is possible and remaining 2 will be stored as per their relative index.
    
   // TC : O(N)+O(N) ~ O(2N)
   // SC : O(N)
    rearrange_Array(arr , n);
    
    
    for(auto it: arr){
        cout<<it<<" ";
    }
    
    
}