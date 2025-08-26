#include<bits/stdc++.h>
using namespace std;

// Missing Number in Array 
 // eg - {1 ,2 , 4, 5} , N=5 , Array should contain elements from 1 to N, find the number which is missing, here in this case , 3 is missing, so output should be 3.
 // 0 will not be there in the Array
 
 
 // 1st Approach : Brute One --> Linear Search
    // TC : O(N * N) , in worst case
   // SC : O(1) , no extra space
 
 int LinearSearch( int arr[] , int n){
     
     int num;
     
     for(num=1 ; num<=n ; num++){  // checking with every number here start from 1 upto N with the array elements below
         
          int flag=0;
          
             for(int j=0 ; j<n-1 ; j++){
                 
                 if ( arr[j] == num ){
                     
                     flag = 1;
                     break;
                     
                 }
                 
             }
         
         if(flag==0){
             break;
         }
     }
     
     return num;
     
 }
 
 // 2nd Method: Hash Method , will take a hash array and init the value 0 in all the places and once get the respective value, will mark that position with 1 and at the end the one remains with 0 , it means that element in the array is missing.

    // TC : O(2N)
    // SC: O(N+1) , taking hash vector
 
 void HashMethod(int arr[] , int n){
     
        vector<int> hash(n+1 , 0); // size of n+1 because as index starts from index 0 , hence has to get the index n also, hence the size is n+1 , declared all with 0
        
        for(int i=0 ; i<n-1 ; i++){
            
            hash[arr[i]] = 1;
            
        }
        
        for(int i=1 ; i<=n ; i++){
            
            if(hash[i] == 0 ){
                
                cout<< i<<" ";
                break;
                
            }
            
            
        }

 }

// 3rd Approach : 

  // 3.1 Optimal One --> Summation Way
  // TC : O(N)
  // SC : O(1)
 
void Summation_Method(int arr[] , int n){
      
        int sum = n*(n+1)/2;
        
    // Now lets find the array sum and then subtract is from sum, the missing element will get then 
        int arrsum=0;
        
        for(int i=0 ; i<n-1 ; i++){
            
            arrsum+= arr[i];
            
        }
        
        cout<<sum-arrsum;
      
  }

      // 3.2 --> Optimal --> XOR Operation , 
         //XOR is better than Summation because for example the number is - 10^5 and when do n(n+1)/2 --> it results in 10^5(10^5+1)/2 ~ 10^10 , which int data type cannot have, has to use long data type which takes little more memory, but using XOR will not make 10^5 to a higher value , 10^5 will remain 10^5 in XOR operation , hence this is better than Summation Way.
    
void XOR_Operation(int arr[] , int n){
    
        // Instead of writing 2 loops one for XOR from 1 to N and another loop for XOR of the elements in Array, we can write both together in 1 for loop.
        
        int XOR1 = 0;  // for elements from 1 to N
        int XOR2 = 0;  // for array elements
        
        // arr= 1 2 4 5
        for(int i=0 ; i<n-1 ; i++){   // i -> 0 1 2 3
            
        XOR2 = XOR2 ^ arr[i];  // 0^1 - 1^2 - 1^2 ^ 4 - 1^2^4 ^ 5
        
        XOR1 = XOR1 ^ (i+1); //  0 ^ 1 ,  1^2  , 1^2 ^ 3 , 1^2^3 ^ 4
        
        // so, XOR1 has been done for 1,2,3,4 but number 5 is left, so this will do after this for loop finish
        
        }
        
        XOR1 = XOR1 ^ n;   // Here 5 is also included
        
    // Now in XOR1-> 1^2^3^4^5 is there and in XOR2 -> 1^2^4^5 is there. Now lets do XOR1 ^ XOR2 to get the missing number

    cout<< (XOR1 ^ XOR2);  // cout << (XOR1 ^ XOR2); // Parentheses ensure XOR is evaluated first
    

}
     
     
 
 int main(){
     
     int n;
     cout<<"Enter the number between which you want to find the missing:";
     cin >> n;
     
     int arr[n-1];
     
     cout<<"Enter the values in Array : ";
     
     for(int i=0 ; i<n-1 ; i++){  // indices are - 0,1,2,3
     
        cin >> arr[i];
         
     }
     
// 1st Approach : Brute One --> will take num from 1 upto N and then do linear Search in the array and check whether that element is present or not. And if any number is not present the return that number and break

   // TC : O(N * N) , in worst case
   // SC : O(1) , no extra space
      
      cout<< LinearSearch(arr , n);

      
// 2nd Approach: Better one --> Will take a hash array of size n+1, and init all the positions with 0. Once we get the values, will mark that particular position with 1.

    // TC : O(2N)
    // SC: O(N+1) , taking hash vector

      HashMethod(arr, n);

       
// 3rd Approach : Optimal Approach --> there are 2 optimal approach , 
 
  // 3.1 --> first is --> Summation and 2nd is -> XOR operation.
  // XOR is little bit more better than the summation option.

   // 3.1 Lets solve first using Summation Operartion
       // TC : O(N)
       // SC : O(1)
  
      Summation_Method(arr , n);

      // 3.2 --> Lets solve this now by XOR method
    // in XOR(^) operation , same value results in 0 , 0 XOR any number is that number itself.
     // 2 ^ 2 =0
     // 2^2^2^2^2 = 0^0 = 0
     // 3^3^3^3^3 = 0^0^3 = 3
     
     // So, for 1 2 4 5 --> Missing is 3 
     // By XOR1 --> 1^2^3^4^5
     //    XOR2 --> 1^2^4^5
     // Then , XOR1 ^ XOR2 --> 0^0^3^0^0 --> 3
     
      XOR_Operation(arr , n);
      
         

 }