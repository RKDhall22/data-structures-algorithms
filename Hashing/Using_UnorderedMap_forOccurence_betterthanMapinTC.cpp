#include<bits/stdc++.h>
using namespace std;


// Here , we are using Unordered Map which will also give the output correctly , just the keys are not in sorted order. 

// The best part of using Unordered_Map is , for best and avg TC for storing/fetching is -> O(1). The worst case is- O(N) , but it is very rare that you will get the TC in worst case, you will always get the TC in best or Avg case only that is O(1).

// The TC comes in worst case -> O(N) is very rare and the reason of coming this one is due to internal collision

// The reason for Worst case is, whatever hash they (Means Map or Unordered Map) are using internally be it, Division Method, Folding Method OR Mid Square Method , it ends up to "all the keys heads up to the same hash index" , and thats why O(N) TC is very rare while using Unordered_Map. 

// Hence, always use Unordered_Map over Map, if it fails in terms of Time Limit Exceeded, then only you have to go with Map.

int main(){
    
    string str;
    
    cout<<"enter the string to check :";
    cin>>str;
    
    unordered_map<char,int> mpp;
    
    for(int i=0 ; i<str.size() ; i++){
        
        mpp[str[i]]++; // eg-> (a,2), (e,0)
        
    }


    // lets print the Map
    for(auto i:mpp){
        
        cout<<i.first<<"-->"<<i.second<<endl;  // It will give result in sorted order

//         enter the string to check :WSFeeAWTE
//         A-->1
//         E-->1
//         F-->1
//         S-->1
//         T-->1
//         W-->2
//         e-->2  // as ASCII of e = 101
        
    }
    
    int q;
    cout<<"Enter the total number of queries: ";
    cin>>q;
    
    while(q--){
        
        char c;
        cout<<"enter the char you want to check its count in string: ";
        cin>>c;
        
        cout<<"The count of "<<c<<" is :"<<mpp[c]<<endl;
        
    }
    
    
}

