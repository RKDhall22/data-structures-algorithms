#include<bits/stdc++.h>
using namespace std;

// Lets solve the Occurence count of elements in Array using Recursion. We can solve this by using normal for loop also and also by using Hashing Technique. But here lets solve this using Recusion.

// Time Complexity of this one is also the same as normal while using for loop that is - O(Q*N) , where Q is number of queries and N is the size of Array.

int Occurence(int number, int count , int size , int arr[] , int i){
    
    if(i==size) return count; // Base Condition
    
    if(number == arr[i]) count++;
    
    return Occurence(number, count , size, arr , i+1);
    
}

int main(){
    
    int size;
    cout<<"Enter the size of the Array you want: ";
    cin>>size;
    
    int arr[size];
    
    //for input the values int the Array
    
    cout<<"Enter the values in the Array now : ";
    for(int i=0 ; i<size ; i++){
        
        cin>>arr[i];
        
    }
    
    int q;  // Number of queries
    cout<<"How many elements counts you want to see: ";
    cin>>q;
    
    while(q--){
        
        int number, count=0;
        cout<<"Enter the number to see its count: ";
        cin>>number;
        
        cout<<"The Occurence of :"<<number<<" is :"<<Occurence(number, count , size , arr , 0)<<endl;
        
    }
    
}