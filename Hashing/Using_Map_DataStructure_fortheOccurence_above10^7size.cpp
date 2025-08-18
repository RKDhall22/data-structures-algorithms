#include<bits/stdc++.h>
using namespace std;

// As we know the maximum size of Array for int, double or char locally inside the main() is- 10^6 as the data is stored in stack space (LIFO) of memory and globally outside main() is 10^7 as this data is stored in Data Segment part.

// If we want to store data dynamically using new or malloc keyword, then this data is stored in Heap, not stack.

// So to tackle this, we are using Map data struture here which will store in form of (key-value) pair. Here, we will use key as that particular number which is there inside the array as key is always referred as unique and will store the frequency of elements in value pair.

// Also, here using Map , instead of using Hash Array is better, as in Hash array, we are taking the size of Hash, just greater than the highest value in the Array, and if for eg- some values are not there in Array like 3,4 and the maximum value is 13, then in Hash Array, will store the occurence for 3 and 4 too which will be 0, but storing that also, so this will consume the space inside the stack space.

int main(){
    
    int n;
    cout<<"Enter the size of the Array: ";
    cin>>n;
    
    int arr[n];
    map<int,int> mpp; // Lets declare map here
    
    cout<<"Enter the values inside the array: ";

    for(int i=0 ; i<n ; i++){  // In this loop only did the precompute part
        
        cin>>arr[i];
        mpp[arr[i]]++;  // instead of taking another for loop to take in the values of array inside map, here only we have used it.
        // this does not add a drastic change in the TC because it will be like - O(N)+O(N)--> O(2N) == O(N)
        
        
    }


       //If want to check all the elements of map(key-value) , then lets print the element,
       
    for(auto i:mpp){
        
        cout<<i.first<<"-->"<<i.second<<endl;
        
    }
    
    int q; // Number of queries we want to check for
    
    cout<<"Enter the number of queries you want to check: ";
    cin>>q;
    
    while(q--){
        
        int number;
        cout<<"Enter the number to check its occurence :";
        cin>>number;
        
        cout<<"The count of "<<number<<" is: "<<mpp[number]<<endl;
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}