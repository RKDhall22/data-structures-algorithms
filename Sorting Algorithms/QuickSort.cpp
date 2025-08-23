#include<bits/stdc++.h>
using namespace std;

// Quick sort is all about Divide and Conquer.

// In this we take a Pivot element which we can take any random element from the array and place it at its correct position and insert the elements to its left which are smaller than pivot and to the right greater elements than pivot and this we do everytime until all the elements are there on its correct position.

// Lets see the Quick Sort which does not use an extra space , unlike in Merge Sort which takes vector to store the sorted values. 

// The time complexity of Quick Sort is same as Merge Sort i.e.-> O(N*logN)  here the code is not dividing into 2 equal halfs but yes they are getting split everytime when we have the partition index.

// Space Complexity : O(1), does not take any extra space

int f(int arr[] , int low , int high){
    
    int i=low;
    int j=high;
    int pivot= arr[low]; // Assumed that the first element that is at index low , is that pivot element
    
    while(i<j){ // until i<j, we can do swap if condition matches, if i crosses j, then get out of the loop, because now on the left hand side, the smaller elements are there than pivot and on the right hand side greater elements are there than pivot
    
    // here we have taken arr[i]<= pivot , it means if the elemet value is equal to pivot also, then we will proceed to the next element by assuming will keep the equivalent element on the left hand side only.
     
        while(arr[i]<=pivot && i<=high-1){  // when this loop is false, i will point out to the index at which the element is greater than pivot or i is at last index that is at high
            
            i++;
            
        }
    
        while(arr[j]>pivot && j>=low+1){ // when this loop is false, j will point out to the index at which the element is smaller than pivot or j is at first index that is at low
            
            j--;
            
        }
        
        if(i<j){
            
            swap(arr[i] , arr[j]);
            
        }
            
        }
        
    swap(arr[low] , arr[j]); // At this point the pivot is at its correct position
    return j;  // This is the partition index
    
}

void QuickSort(int arr[] , int low , int high){
    
    if(low < high){ // array size should be greater than 1 because if array has 1 element, it means it sorted then
    
       int PartitionIndex= f(arr , low , high);
       
       QuickSort(arr , low , PartitionIndex-1); // after we have PI , then lets insert the new pivot element to its correct position on the left side which starts from low to PI-1
       
       QuickSort(arr , PartitionIndex+1 , high); // After we have PI , then lets insert the new pivot element to its correct position on the right side which starts from PI+1 to high
       
        
        
    }
    
    
}

int main(){
    
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    
    int arr[n];
    
    // Input the values in the array
    cout<<"Enter the values of Array : ";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    QuickSort(arr , 0 , n-1);
    
    cout<<"The sorted array is : ";
    
    for(int i=0 ; i<n ; i++){
        
        cout<<arr[i]<<" ";
        
    
 }

}
