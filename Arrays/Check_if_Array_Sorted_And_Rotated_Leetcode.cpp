#include<bits/stdc++.h>
using namespace std;

// Check if Array is Sorted and Rotated ( LeetCode Problem )

//Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.


// 1st Approach
    // Time Complexity of the below code : O(3N) ~ O(N)
    // Space Complexity, as took new vector : O(N)

        bool BruteApproach(int arr[] , int n){
            
            vector<int> v;
            int firstindex = 0; // init with 0 , if array is just sorted, not rotated, then firstindex value will be 0 only and the 2nd for loop will go from i=0 to n-1 and enters all the array sorted values in the vector.
            
        // Finding firstindex at which arr[i] < arr[i-1]
            for(int i=1 ; i<n ; i++){
                
                if(arr[i] < arr[i-1]){
                    
                    firstindex = i;
                    break;
                    
                }
            }
            
        // // Insert from firstindex to n-1
        //     for(int i = firstindex ; i<n ; i++){
                
        //         v.push_back(arr[i]);
                
        //     }

        // // Insert from 0 to firstindex-1
        //     for(int i=0 ; i < firstindex ; i++){
                
        //         v.push_back(arr[i]);
                
        //     }

            // Lets club the above 2 for loops into a single one

        int startindex=0; // to insert the values from index 0 --> firstindex-1

        for(int i=0 ; i<n ; i++){ // run for n times
            
            if(firstindex < n){  // run from firstindex to n-1
                
                v.push_back(arr[firstindex]);
                firstindex++;
                
            }
            
            else{  // run from index 0 to firstindex-1
                
                v.push_back(arr[startindex]);
                startindex++;
                
            }
        }
            
            
        // Now vector has all the elements of the array and in the order before array is rotated. Now lets check whether vector has sorted elements or not.

        for(int i=1 ; i<n ; i++) {
            
            if(v[i] >= v[i-1]){
                //okay , move next at its greater than previous value
                
            }
            
            else{
                
                return false; // not greater, means not sorted
                
            }
        }
        //   cout<<"firstindex :"<<firstindex<<endl;
        
        //   for(auto it : v){
            
        //       cout<<it<<" ";
            
        //   }
        
        return true;
        
        }

// Here the TC : O(N^2) + O(N) ~ O(N^2) --> Everytime the  inner while loop is running for (j-i) times that is equal to the value of firstindex for example array is --> 4 5 1 2 3 , here firstindex value is 2 , intially i is 0, hence firstindex-i = 2 , so everytime there is total 2 swaping performed until low reaches to j and then increment j and i by 1

// Space Complexity is : O(1)
bool BruteApproach_2( int arr[] , int n){
    
    int firstindex;
    
    for(int i=1 ; i<n ; i++){
        
        if(arr[i] < arr[i-1]){
            
            firstindex = i;
            break;
            
        }
    }
    
    // Now we have firstindex 
    
    int i=0 , j=firstindex;
    
    while(j<n){
        
        int low = i;
        
        while(low != j){
            
            swap( arr[low] , arr[j]);
            low++;
            
        }
        
        j++;
        i++;
        
    }
}

// 2nd Approach : Optimal One --> lets find the firstindex whose value is less than the previous element. And from there reverse the nums from firstindex to nums.size() and from 0 to firstindex -1.
        // Time Complexity of the code : O(N)
        // Space Complexity : O(1) , no extra space

        // 3 4 5 1 2  -->Firstindex = 3, -- 5 4 3 2 1 --> now if check this array is sorted in desc
        // 2 1 3 4  --> Firstindex= 1, -- 2 4 3 1  --> If check this one , its not sorted in any way
        // 1 2 3 --> Firstindex = not there --> It means array is already sorted correctly

        // So from the above example what we get that is, if FirstIndex exists then reverse and check. And if FirstIndex does not exist then , the array is already sorted because it means there is no value in the array which is arr[i] < arr[i-1].

    bool check(vector<int>& nums) {
    // Lets now find out the firstindex

    int firstindex = -1; // Init with -1 , if there is any element in nums which is nums[i] < nums[i-1] , then firstindex is i, but if not , then firstindex is remain -1 , means array is already sorted.

        for(int i=1 ; i < nums.size() ; i++){

            if( nums[i] < nums[i-1] ){

                  firstindex = i;
                  break;

            }

        }

        if(firstindex != -1 ){  // Means firstindex exist in nums
          
                reverse( nums.begin() , nums.begin() + firstindex );  //  5 4 3
                reverse(nums.begin() + firstindex , nums.end() );  // 2 1  

                // Now the array is --> 5 4 3 2 1 , we can reverse this also, but no need, we can check this array only, if arr[i] < arr[i-1] , then okay proceed and if not, then array is not sorted one, return false.

                for(int i=1 ; i<nums.size() ; i++){  // 5 4 3 2 1

                   if(nums[i] > nums[i-1]){  // not sorted in desc
                     return false;
                   }

                }

                // return true; // once for loop is over , it means i reaches till end and no element is there which satisfy arr[i] > arr[i-1], means all values are sorted in desc

        }

        return true; // This for firstindex == -1, means in array no element is there which is smaller than the previous element , means all are sorted and also if the above for loop in if statement reaches to end , it means the array is sorted in desc order , hence can use this singel return true statement for both the conditions.

 }

int main(){
    
    int n;
    
    cout<<"Enter the size of Array: ";
    cin >> n;
    
    int arr[n];
    vector<int> nums;
    int values;
    
    cout<<"Enter the values in the array: ";
    
    for(int i=0 ; i<n ; i++){
        
        cin >> arr[i];

        //for storing the elements into nums vector
        cin >> values;
        nums.push_back(values);
        
    }
    
    
    // 1st Approach: Brute force --> Will take an extra Vector/Array and store the values in that in the order at which the array is rotated, means as the array is sorted and rotated , hence it will check for the first index at which arr[i] < arr[i-1] and from this index that is from index i , will store the elements in new Vector upto n-1 , and then from index 0 --> i-1 , and then will check the new vector whether its sorted or not. If sorted then return true , else return false.
    
    
   cout<< BruteApproach(arr , n);

   cout<< BruteApproach_2(arr, n);

   cout<< check(nums);





    

}
