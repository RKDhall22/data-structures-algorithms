#include<bits/stdc++.h>
using namespace std;

// Lets see about Sorting Algorithms- Selection Sort

// Lets calculate the TC --> n+(n-1)+(n-2) _ _ _ 2= n(n+1)/2 -1 ( its nothing but summation of n numbers , but as it goes till 2 , hence subtract 1 , but that too is not considered). Hence, the TC is--> O(n^2).for Best, Avg and Worst case.


// In selection sort , we get the minimum element from the whole array and then swap its index with the indexes from the start of the array

// So we take out the index of the minimal element after whole traversal and then swap with the starting elements index

// 3 2 6 7 1-->  1 2 6 7 3  - after 1st sort, sorted till 1st position
//               1 2 6 7 3  - after 2nd sort, sorted till 2nd position 
//               1 2 3 7 6  - after 3rd sort, sorted till 3rd position
//               1 2 3 6 7  - after 4th sort, sorted till 4th position

// lets see how the loop will go for Selection sort:
    //  1st time - 0 -- n-1
    //  2nd time - 1 -- n-1
    //  3rd time - 2 -- n-1
    //  |
    //  |       - (n-2)--(n-1)

// from the above example, it means if we run the loop upto n-2 ( in this case upto index 3) , then its sufficient to sort the array, as its obvious that for a single element the array is already sorted.

void selection_sort(int n , int arr[]){
    
    for(int i=0 ; i<=n-2 ; i++){
        
        int min_idx = i;
       
        
        for(int j=i ; j<=n-1 ; j++){
            
            if(arr[j] < arr[min_idx]){
                
                min_idx = j;
                
            }
            
        }
        
        swap(arr[i] , arr[min_idx]);
        
    }
}

int main(){
    
    int n;
    
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    
    //Array input
    
    cout<<"Enter the elements in array: ";
    
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        
    }
    
    selection_sort(n , arr);
    
    // Now lets print the array
    
    for(int i=0 ; i<n ; i++){
        
        cout<<arr[i]<<" ";
        
    }
    
}