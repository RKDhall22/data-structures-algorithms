#include<bits/stdc++.h>
using namespace std;

// Find the largest element in the array

// Brute Force Approach
// Time Complexity : O(n*logn) , if quick sort is applied then Space- O(1) 

void BruteApproach(int arr[] , int n){
    
    sort(arr, arr+n); // Sort the array , here the TC will be - O(n*logn) , and Space Complexity is - O(1), if uses Quick Sort.
    
    // Now the largest element is at last index as Array is sorted
    
    cout<<"Largest element is : "<<arr[n-1];
    
}

// Optimal Approach
// Time Complexity: O(n), just iterating over every element

void OptimalApproach(int arr[] , int n){
    
    int largest=arr[0];
    
    for(int i=1 ; i<n ; i++){
        
        if(arr[i]>largest){
            
            largest=arr[i];
            
        }
    }
    
    cout<<endl<<"The highest value in the array is with TC n :"<<largest<<endl;
    
    
}

// Another way by using Recursion method 
// Here checking the first and last value and increase low index by 1 and decrease high index by 1, so in this we are checking the upto N/2 times.

// Hence, the Time Complexity: O(N/2) ~ O(N)
void OptimalApproach_byRecursion(int arr[] , int low, int high , int largest){
    
    
    if(low > high) { // Because it may be when low==high, this single element can also be the largest one , so when low cross high, then return
        
        cout<<largest;
        return; 
        
    }
    
    if(arr[low] >= arr[high] && arr[low] > largest ) { // >= because at a point when , low==high and this element is the largest, hence we have to insert this value in largest 
        
        largest=arr[low];
        
    }
    
    else if(arr[high] > arr[low] && arr[high] > largest ){
        
        largest= arr[high];
        
    }
    
    
    // cout<<largest<<" ";
    
    OptimalApproach_byRecursion(arr, low+1 , high-1 , largest );
    
    
    
}

int main(){
    
    int n;
    cout<<"Enter size: ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter values: ";
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    // 1st way to solve
    BruteApproach(arr, n); // Takes time: O(nlogn)
    

    //2nd way to solve
    OptimalApproach(arr,n); // Takes time : O(n)
    

    // 3rd way to solve
    int largest = arr[0]; // Assuming the first values is highest
    OptimalApproach_byRecursion(arr,0, n-1 , largest); // Will use Recursion , TC- O(n/2) ~ O(n)
 
}