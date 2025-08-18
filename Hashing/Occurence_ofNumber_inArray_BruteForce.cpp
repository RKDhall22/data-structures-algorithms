#include<bits/stdc++.h>
using namespace std;

// To solve the Occurence of the element in the array using brute force approach

// Here the time complexity is - O(Q*N) , for 1 element the TC is O(N) , hence for q number of queries the TC - q * O(N)--> O(q*N)

int f(int number, int n , int arr[]){
    
    int count=0;
    
    for(int i=0 ; i<n ; i++){
        
        if(arr[i]==number) count++;
        
    }
    
    return count;
}


int main(){
    
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    
    int arr[n];
    
    //Let take the input for the elements of Array
    
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
        
    }
    
    int q; // Number of queries
    cout<<"Enter the number of elements you want to check: ";
    cin>>q;
    
    while(q--){
        
        int number;
        cout<<"Enter the number to check: ";
        cin>>number;
        cout<<"The Occurence is :" <<f(number, n , arr)<<endl;
        
        
    }
    
    
    
}