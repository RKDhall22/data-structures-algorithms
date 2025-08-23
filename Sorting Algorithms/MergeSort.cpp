#include<bits/stdc++.h>
using namespace std;

// Merge Sort: Divide and Merge

// In merge sort, we keep on dividing the array (by playing with the index of the array) into equal parts till we reach to the last single element.

// After that , we sort the elements and then merge it in a new array or vector. And then inserts the sorted new array/vector into the original array as we want to sort the original array.

// In Merge sort the Time Complexity is: O( N * logN) , as we keeping on dividing the array into 2 equal parts(log N) and we are traversing the whole array to insert the values from the sorted new array to the original array (this will take N time complexity), hence the total time complexity is - O(N * logN)

// The Space Complexity is : O(N), taking the new array with that size of original array.

void Merge(int arr[] , int low , int Mid_Index , int high){
    
    int left=low;  // left side part of Array upto mid from low
    int right=Mid_Index+1;  // Right side part of Array upto high from mid+1
    
    vector<int> temp; // to store the values in sorted order
    
    while(left<=Mid_Index && right<=high){
        
        if(arr[left] < arr[right]){
            
            temp.push_back(arr[left]);
            left++;
            
        }
        else{
            
            temp.push_back(arr[right]);
            right++;
            
        }
    }
    
    // If any one of the 2 conditions above that is left<=mid and right<=high is false, then while loop is over. It means, one part is exhausted, hence there may be some elements still there on left or right side. Hence for that we have to check again and insert those elements in temp vector.
    
    while(left<=Mid_Index){  // checking on left side
        
        temp.push_back(arr[left]);
        left++;
        
    }
    
    while(right<=high){   // checking on right side
        
        temp.push_back(arr[right]);
        right++;
        
    }
    
    // now lets insert all the sorted elements present in temp into the original array.
    
    for(int i=low ; i<=high ; i++){
        
        arr[i]= temp[i-low]; // Here, everytime when merge function is called, the values stored in temp starts from index 0, hence we have to make the index as - (i-low) for example low=4, high=6 then--> arr[4]= temp[0], arr[5]=temp[1] so on.
        
    }
    
    
}



void MergeSort(int arr[] , int low , int high){
    
    if(low >= high) return;  // means both pointing to the same element now, single element 
    
    int Mid_Index= (low+high)/2;// can also write this: low+(high-low)/2 to handle the edge case that is to prevent the interger overflow. If low and high are large positive integers, their sum low + high could exceed the maximum value that the integer data type can hold, leading to an incorrect or negative result due to overflow.
    
    MergeSort(arr , low, Mid_Index); // Left side of the array
    MergeSort(arr, Mid_Index+1 , high); // Right side
    
    Merge(arr, low, Mid_Index , high);  // Now sort and merge
    
    
    
}

int main(){
    
    int n;
    cout<<"Enter the size of Array : ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the values in the array :";
    
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    MergeSort(arr , 0 , n-1);
    
    // print the sorted array now
    
    for(int i=0 ; i<n ; i++){
        
        cout<<arr[i]<<" ";
        
    }
    

    
}