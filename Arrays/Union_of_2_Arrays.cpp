#include<bits/stdc++.h>
using namespace std;

// Union of 2 sorted arrays and the union array should also have elements in the sorted fashion only

// 1st Approach: Brute Approach --> Take Set data structure

// TC : O(n1logn) + O(n2logn) + O(n1+n2)
// SC:  O(n1+n2) + O(n1+n2) , this second one (n1+n2) for union array used to return the ans , not using it in the algo, just used it to return the ans
    vector<int>  Union(int a1[] ,int a2[] , int n1, int n2){
        
        set<int> st;
        vector<int> UnionArr;
        
        // lets iterate through the first array a1 and insert the values in set
        
            for(int i=0 ; i<n1 ; i++){  // TC: n1*logn , where n is size of set which is varying , so cannot provide the exact value
                
                st.insert(a1[i]);
                
            }
        
        // now lets iterate through the second array a2 and insert the values in set
        
            for(int i=0 ; i<n2 ; i++){   // TC: n2*logn
                
                st.insert(a2[i]);
                
            }
        
        // Now at this stage set has all the unique elements that is nothing but the Union of a1 and a2. ( a1 U a2)
        
        // now lets insert the set values in Union Array
        
            for(auto it : st){   // n1+n2 , in worst case all values are unique
                
                UnionArr.push_back(it);
                
            }
        
        return UnionArr;
        
        
    }

// 2nd Approach: 2 pointer concept
 // TC : O(n1 + n2)
 // SC : O(n1 + n2), for returing the UnionArr, else there is no extra space used.

vector<int> Union_2(int a1[] , int a2[] , int n1 , int n2){
    
      vector<int> UnionArr;
      
      int i=0 , j=0;
      
     while(i < n1 && j < n2){
          
          if(a1[i] <= a2[j]){
             
        // for first insertion in UnionArr, there is no element, hence UnionArr.back() results in undefined behavior. so to tackle that we have used the condition of UnionArr.size() == 0, to bypass for first insertion
        
              if(UnionArr.size() == 0 || UnionArr.back() != a1[i]){
                  
                  UnionArr.push_back(a1[i]);
                  
              }
              
              i++; // Irrespective of its equivalent or not, have to increase i everytime , because if element at i is already there in UnionArr, then not insert it again , just move on and if insert then too move on to next element.
              
              
          }
          
          else{
              
               if(UnionArr.size() == 0 || UnionArr.back() != a2[j]){
                  
                  UnionArr.push_back(a2[j]);
                  
              }
              
              j++;
              
          }
         
      }
      
    // Now there may be some elements left in a1 array or in a2 array so for that too we have to check

 // for a1 array
 // We are checking for UnionAr.size() == 0 || in both a1 and a2 because may be there is an edge case where one array is empty, in that case , only either a1 or a2 elements will go inside the UnionArr. Means only one while loop below will run, in that case we have to check size =0 , to insert the first element.
    while( i < n1){
        
        if(UnionArr.size() == 0 || UnionArr.back() != a1[i]){
            
            UnionArr.push_back( a1[i] );
            
        }
        
        i++;
    }
    
 // for a2 array
    while( j < n2){
        
        if(UnionArr.size() == 0 || UnionArr.back() != a2[j] ){
            
            UnionArr.push_back( a2[j] );
            
        }
        
        j++;
        
    }
      
      return UnionArr;
      
}

int main(){
    
    int n1 , n2;
    
    cout<<"Enter the size of both the arrays : ";
    cin >> n1 >> n2;
    
    int a1[n1] , a2[n2];
    
    // input elements in first array
    
    cout<<"Enter the values in 1st array: ";
    
    for(int i=0 ; i<n1 ; i++){
        
        cin >> a1[i];
        
    }
    
    // cout<<endl;
    cout<<"Enter the values in the 2nd array :";
    
    for(int i=0 ; i<n2 ; i++){
        
        cin >> a2[i];
        
    }
    
    
    
// 1st Approach: Brute Approach-> Take Set data structure and store the elements from both the array , these values will be stored in the sorted order only.
   // TC : O(n1logn) + O(n2logn) + O(n1+n2)
   // SC:  O(n1+n2) + O(n1+n2)
      vector<int> UnionArr = Union(a1 , a2 , n1 , n2);
    
// 2nd Approach : Optimal One -> As both the arrays are sorted, hence we can use 2 pointer concept, pointing one pointer i at the start of one array a1 and j pointer at the start of another array a2, and then store the values by comparing both values at index i and j , then insert the smaller one in Union Array with that also check the last element of Union Array, whether its equivalent to the current element positioned at index a1[i] or a2[j] , if yes, then already that element is there in Union Array, hence no need to insert again. Move on to next element. 

 // TC : O(n1 + n2)
 // SC : O(n1 + n2), for returing the UnionArr, else there is no extra space used.

    vector<int> UnionArr = Union_2(a1 , a2 , n1 , n2);
    
    
    for(auto it : UnionArr){
        
        cout<<it <<" ";
        
    }
    
    
    
    
    
}