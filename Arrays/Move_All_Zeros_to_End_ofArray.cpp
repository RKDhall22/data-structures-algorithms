#include<bits/stdc++.h>
using namespace std;

// Move all 0's to the end of the Array

// 1 0 2 3 2 0 0 4 5 1 --> 1 2 3 2 4 5 1 0 0 0 

// Brute Approach
 // TC : O(N) + O(x) + O(N-x) ~ O(2N)
  // SC : O(N)

void Move_Zeros_to_End(int arr[] , int n){
    
    vector<int> temp;

        // Step 1: Lets have all the non zeros stored in temp vector   
            for(int i=0 ; i<n ; i++){   // n times
                
                if(arr[i] != 0 ){
                    
                    temp.push_back(arr[i]); // 1 2 3 2 4 5 1
                    
                }
            }
            
        // Step 2: Now insert these values in the array from start
            for(int i=0 ; i<temp.size() ; i++){   // x times
                
                arr[i] = temp[i];
                
            }

        // Step 3: Now in the remaining places of arr starting from index=temp.size() upto n-1, insert the 0's
            for(int i = temp.size() ; i<n ; i++){    // n-x times
                
                arr[i] = 0;
                
            }
    

}

// 2nd Approach : Better One --> Solving this without taking extra space
  // TC : O(N) + O(N) ~ O(2N)
  // SC : O(1) , no extra space, changes done directly in the original array
  
void Move_Zeros_to_End_1(int arr[] , int n){
    // 3 0 0 1 2 7
    
    int index = 0;
    for(int i=0 ; i<n ; i++){  // N times
        
        if(arr[i] != 0){
            
            arr[index] = arr[i];  // 3 1 2 7 2 7
            index++;
            
        }
        
    }
    
    // Now insert the 0s from position = index upto n in arr
    
    for(int i=index ; i<n ; i++){   // N times, if all the values are 0 in the array
        arr[i] = 0;
        
    }
    
    
}



// 3rd Approach: 2 pointer concept , j points to first 0 and i starts from j+1

 // TC : O(N) + O(N) ~ O(2N)
 // SC : O(1) , no extra space is being used , yes changes are going on in the main array, because that is the requirement of the problem.

        void Move_Zeros_to_End_2(int arr[] , int n){
            
            // Step 1: Find the first 0 and points j there
            int j = -1; 
            
            // Lets iterate over the loop to get the first 0 index
            
            for(int i=0 ; i<n ; i++){
                
                if(arr[i] == 0){
                    
                    j=i;
                    break;
                    
                }
            }
            
            // if after this whole loop , j is still -1, means there are no 0s in the array , so no need to do anything
            
            // But if 0 is there and j is the index of first 0 , then lets start i from j+1

        if( j != -1){

            for(int i=j+1 ; i<n ; i++ ){
                
                if(arr[i] != 0){
                    
                    swap(arr[i] , arr[j]);
                    j++;
                    
                }
            }

        }   
            
            
            
        }


int main(){
    
    int n;
    cout<<"Enter the size of Array :";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the values: ";
    
    for(int i=0 ; i<n ; i++) {
        
        cin >> arr[i];
        
    }
    
    // 1st Approach : Brute
      // Lets store all the non-zero numbers in Array/vector and then will insert these all non-zero numbers from vector to the original Array/Vector and in the remaining places, insert the zero's.
      
     Move_Zeros_to_End(arr, n);

    // 2nd Approach: Better to Optimal  --> Also can do this using the the same array , this is much better in terms of not taking an extra space .

     Move_Zeros_to_End(arr , n);

    // 3rd Approach: Optimal --> 2 pointer approach
     // Lets first find the index for first 0. Keep the pointer lets say j there. And then keep the next pointer lets say i next to j. keep on iterating continously till the last index and j should point at 0. Once arr[i] !=0 , then swap it with arr[j] which consist 0 and then increase j.
 

     Move_Zeros_to_End_2(arr, n);

     
     for(auto i : arr){
         
         cout<<i<<" ";
         
     }
     
    

}
