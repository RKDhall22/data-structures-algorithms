#include<bits/stdc++.h>
using namespace std;

// Intersection of 2 Arrays.

// a[]=   1 2 2 3 3 4 4 9
// b[]=   2 2 3 3 4 8


// InterArr[] = 2 2 3 3 4


// 1st Approach : Brute
   // TC : O(n1*n2)
   // SC: O()
  vector<int> Intersection(int a[] , int b[] , int n1, int n2){
      
      vector<int> InterArr;  // have intersection of both
      int visitedArr[n2] = {0}; // size of n2 , init with 0 all places
      
      for(int i=0 ; i<n1 ; i++){  // a Array
          
          for(int j=0 ; j<n2 ; j++){  // b Array
          
              
              if(a[i] == b[j] && visitedArr[j] == 0 ){
                  
                  InterArr.push_back(a[i]);
                  visitedArr[j] = 1;  //means now visited for that index
                  break; // now move for next element
                  
              }
              
              if(a[i] < b[j]){
                  break;  // No need to check further, as array is sorted
                   
              }
             
          }
      }
      
    //   for(auto it: visitedArr){
          
    //       cout<<it<<" ";
    //   }
      
      return InterArr;
      
  }


// 2nd Approach: Optimal one --> 2 pointer concept , as Arrays are sorted
   // TC: O(n1 + n2) , at worst case, i iterate over all elements of a and j iterate over all elemenets of b
   // SC: O(n1+n2) ,in worst case to return the ans that is InterArr
vector<int> Intersection2(int a[] , int b[] , int n1 , int n2){
    
    int i=0 , j=0;
    
    vector<int> InterArr;
    
    while( i < n1 && j < n2){
        
        if( a[i] == b[j] ){
            
            InterArr.push_back( a[i] ); // or can insert b[j]
            i++;
            j++;
            
        }
        
        else if(a[i] < b[j]){
            
            i++;
            
        }
        
        else{
            
            j++;
            
        }
        
    }
    
    return InterArr;
    
}


int main(){
    
    int n1 , n2;
    cout<<"Enter the size of both the array : ";
    cin >> n1 >> n2;
    
    int a[n1] , b[n2];
    
    cout<<"Enter the value for a1 Array : ";
    
    for(int i=0 ; i<n1 ; i++){
        
        cin >> a[i];
        
    }
    
    cout<<"Enter the values for 2nd Array : ";
    
    for(int i=0 ; i< n2 ; i++){
        
        cin >> b[i];
        
    }
    
// 1st Approach : Brute One--> will keep i pointer at the first index of a array ( can also keep it at first index b array ) , and always starts j with index 0 of b array and check if a[i] == b[j] , if its equal then before inserting that element into the InterArr, have to check whether the correponding element is already there or not.
   // So for this will create a visited Array of size n1 or n2 and mark all the elements intially 0 and if we are not visited its corresponding element then only insert the value a[j] in InterArr and mark visited Array as 1(means visited) ,and then break from there. So, for next time will go for the next corresponding position.

// Example below:

        // a[n1]=   1 2 2 3 3 4 4 9 , i pointer here
        // b[n2]=   2 2 3 3 4 8     , j pointer here
        // vis[n2]= 0 0 0 0 0 0
        //          1 1 1 1 1 0   --> Hence, InterArr = [ 2,2,3,3,4 ]
        
        // Now lets keep i pointer to b array and j to a array
        
        // b[n2]=   2 2 3 3 4 8     , i pointer on b
        // a[n1]=   1 2 2 3 3 4 4 9  , j poinrer on a
        // vis[n1]= 0 0 0 0 0 0 0 0
        //          0 1 1 1 1 1 0 0 --> InterArr = [2,2,3,3,3]
        
        
     vector<int>InterArr = Intersection(a, b , n1 , n2);
     
     cout<<endl;
     for(auto it: InterArr){
         
         cout<<it<<" ";
         
     }


// 2nd Approach: Optimal One --> As the Array is sorted, lets use 2 pointer concept, pointing i and j pointer to the first index of both the arrays.
  // if a[i] < b[j] , then increase i by 1 
  // if b[j] < a[i  , then increase j by 1
  // if a[i] == b[j] , then insert the value in InterArr and increase i and j by 1
  
 // And this will run until i < n1 or j < n2
 
    vector<int> InterArr2 = Intersection2(a , b , n1 , n2);
    
    for(auto it : InterArr2){
        
        cout<<it<<" ";
        
    }
    




    
}