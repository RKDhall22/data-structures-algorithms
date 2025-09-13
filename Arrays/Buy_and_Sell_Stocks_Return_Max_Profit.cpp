#include<bits/stdc++.h>
using namespace std;

// Best time to buy and sell stocks, return the maximum profit. First Buy and then sell.

// 7 1 5 3 6 4  ---> output is - 5, as will buy the stock at 1$ and sell at 6$ , hence the maximum profit is 5$. It cannot go in other way that buy at 1$ and sell at 7$ because 7 appears before 1 , hence it will be buy at 7 and sell at 1, so it means having 6$ loss.


// 1st Approach : Will use nested loop to store the maximum profit and return the max profit.
// TC : O(N*N)
// SC : O(1)

int buy_sell_Stock(int arr[] , int n){
    
    int max_profit = INT_MIN;
    
    for(int i=0 ; i<n-1 ; i++){  // Buy side
        
        int cost = 0;   // means profit cant be negative
        
        for(int j=i+1 ; j<n ; j++){
            
            int cost = arr[j] - arr[i];   // Profit = Sell - buy
            
            max_profit = max(max_profit , cost);
            
        }
        

    }
    
    return max_profit;
    
}

// 2nd Approach : Better one/ Optimal one --> Will use DP concept here to store the min value and then find the difference betn ith element and min element to get the maximum profit
// TC : O(N)
// SC : O(1)

// 7 1 5 3 6 4 
int buy_sell_Stock_2(int arr[] , int n){
    
    int min_value = arr[0];
    int max_profit = INT_MIN;
    
    for(int i=1 ; i<n ; i++){   // starting from 1st index, because 0th index is like buy price
    
       int cost = arr[i] - min_value;   // Profit 
       max_profit = max(max_profit , cost);
       
       min_value = min(min_value , arr[i]); // everytime we are checking the min_value
        
       cout<<cost<<" "<<min_value<<endl;
       
    }
    
    // cout<<endl;
    return max_profit;
}

int main(){
    
    int n;
    
    cout<<"Enter the size of Array: ";
    cin >> n;
    
    int arr[n];
    cout<<"Enter the values: ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    // 1st Approach: Brute force --> Will use nested loop and check for the price diff and store the maximum price and return that.
    // TC : O(N*N)
    // SC : O(1)
    
    cout<<buy_sell_Stock(arr, n);

     // 2nd Approach: Better one/ Optimal one --> Will use dynamic programming concept where will store the min value before ith index element. Once, get the minimum value, then find the difference with the ith index element to get the max profit.
    // TC : O(N)
   // SC : O(1)
    
    cout<<buy_sell_Stock_2(arr , n);

}
