#include<bits/stdc++.h>
using namespace std;
int Hash[10000000]; // So here all the values by default declares to 0 instead of Garbage Values and here we declared Hash globally.

// Due to this stack size limit, the maximum size for int, double, or char arrays declared locally is generally around 10^6 elements.

// bool arrays, requiring less memory per element, can sometimes be larger, potentially up to 10^7 elements, within the stack's constraints.

// Consequently, int, double, or char arrays declared globally can usually be much larger, often up to 10^7 elements.

// bool arrays declared globally can be even larger, potentially reaching 10^8 elements, again due to their smaller memory footprint per element.

// The primary reason for this difference in maximum array size is the memory allocation strategy. Local arrays consume stack space, which is limited, while global arrays reside in the data segment, offering more available memory. Attempting to declare an array larger than the available stack space will result in a stack overflow error, often manifesting as a segmentation fault.

// Important thing - The size of int Array is maximum 10^6 that is arr[10^6] if used inside int main() , and if used outside int main() , then can have maximum length to 10^7 - arr[10^7] , like mentioned above

// Lets see about Hashing- Prestoring/Fetching , it stores the number of times the element occurs in the array and when requires can give the occurence of the number.

// for eg- n=  9 , size of Array
//      Array=  2,1,2,3,4,1,12,2,12
//      q=4 , where q is number of element you want to see the occurence
//      2,12,4,1 --> here inserted 4 elements to check and their occurence

// total TC- O(N) + O(M)

int main(){
    
    int n;
    cout<<"Enter the size of the Array: ";
    cin>>n;
    
    int arr[n];
    // Insert the value of Array
    
    cout<<"Enter the elements in the array: ";
    for(int i=0 ; i<n ; i++){
        
        cin>>arr[i];
        
    }
    
    // int Hash1[10000000]; // This will give Segmentation fault 
    
    // Now lets do the precompute to check the occurence using Hashing technique
   

    // int Hash[13] = {0}; // Here, used size 13 , because we know the maximum element which is in Array is 12, hence as array starts from index 0, hence the size should be 13 (index-12) of Hash , where we can have the occurence of number 12.
    
    // Also we have declared intially the occurence at all the position in Hash is 0 , once the elements comes from arr[] , will increase the count by 1 by going to the index directly of Hash.
    
    for(int i=0 ; i<n ; i++){   // TC- O(N) , where N is size of Array
        
        Hash[arr[i]] +=1;
        
    }
    
    // Now lets check the count of elements by printing the elements of the Hash
    // cout<<endl;
    
    // for(int i=0 ; i<13 ; i++){
    //     cout<<Hash[i]<<" ";  // 0 2 3 1 1 0 0 0 0 0 0 0 2
    // }
   
    // now lets see the element count one by one
    
    int q;  // Number of queries
    cout<<endl<<"Enter how many times you want to see the counts: ";
    cin>>q;
    
    while(q>0){  // fetch  , TC - O(M), M is how many times you want to check numbers occurence , total TC- O(N) + O(M)
        
        int number;
        cout<<"Enter the number: ";
        cin>>number;
        
        cout<<"The count of :"<<number<<" is :"<<Hash[number]<<endl;
        q--;
        
    }
    
    

    
}