#include <bits/stdc++.h>
using namespace std;

// About Pairs

void explainPair()
{

    pair<int, int> p = {12, 1};

    cout << " 1st value is " << p.first << " and 2nd value is " << p.second << endl;

    // Pair contains 2 values only , and if wants to insert more values have to mention pair inside pair

    pair<int, pair<int, int>> p1 = {10, {2, 4}};

    cout << p1.first << " " << p1.second.second << " " << p1.second.first << endl;

    // now using pair as data type for Array

    pair<int, int> arr[] = {{1, 3}, {2, 4}, {1, 40}, {8, 9}};

    cout << arr[2].second; // prints 40
}

// About Vectors in C++ , which is dynamic in nature not as Array which has fixed size, We cannot modify the size of Array once declared, hence in that case where we dont know the size , we use vector that time.

void explainVector()
{

    vector<int> v; // declaration of Vector

    // "push" and "emplace" both inserts the value , but emplace function is faster as compare to push.
    v.push_back(1);
    v.emplace_back(8);

    vector<pair<int, int>> v1;

    v1.push_back({1, 3});
    v1.emplace_back(40, 20); // here the syntax is little change, not required to mention the "{}"

    vector<int> v2(5, 10); // here size is declared as 5 and in all places , 10 value is there. {10,10,10,10,10}

    // Can also mention the vector without the value , only size

    vector<int> v3(5); // here just created with size 5 and in all positions the value is either 0 or garbage value according to Compiler

    // If want to copy the container of v2 in some other vector, mentioned below:

    vector<int> v4(v2); // now v4 has {10,10,10,10,10}

    // you can always increase the size of vector like by adding push_back function and it will add the element at the back.

    // Now to access the value of vector, it is same like array, that is v[position] or you can user Iterator

    // Here lets first user like Array to access the value
    cout << v2[1] << " " << v1[1].first << endl; // 10 40

    // Now lets user Iterator to access the value.

    vector<int>::iterator a = v.begin(); // it means in a, the address is stored of first value.

    // v.begin() will point to the address of the first value and to get the value stored in that address, you have to mention the * in front of v.begin() for example --> *(a);

    cout << *(a) << endl;

    a++; // now here a, points to the address of 2nd value

    cout << " The value at 2nd position is :" << *(a);

    // As there is begin() , there is also one more important function that is end()

    vector<int>::iterator b = v.end(); // Here b will point to the address which is there after the address of last element.
    // means when you do b-- , now it will point to the address of last element/value.

    cout << *(b) << endl; // This will return the value as 0 or garbage value

    b--; // now this is pointed to the address of last value in vector

    cout << "The value present in the last address of vector is : " << *(b);

    // There is back() which prints the value present in the last index

    cout << endl
         << "the value present in the last index " << v.back() << endl;

    // how to print all the values of the vector

    // 1st method

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {

        cout << *(it) << " ";
    }

    cout << endl;

    // 2nd Method

    // auto takes the data type automatically based on the value given to the variable
    // here auto takes the data type that is iterator because of begin() and end() which is used in Iterator
    for (auto it = v.begin(); it < v.end(); it++)
    {

        cout << *(it) << " ";
    }

    cout << endl;

    // 3rd menthod

    // Here the data type that auto will take is Integer , as it points to the value inside the vector
    //  The below one is for-each loop
    for (auto it : v)
    {

        cout << it << " ";
    }

    v.erase(v.begin() + 1);

    cout << endl;

    for (auto it : v)
    {

        cout << it << " ";
    }

    v.push_back(90);

    // now if want to remove multiple values from vector, then the syntax would be something like,

    v.erase(v.begin() + 1, v.begin() + 3); //  v.begin()+3 not included, means 2nd and 3rd element erased

    cout << endl;

    for (auto it : v)
    {

        cout << it << " ";
    }

    cout << endl;

    // Insert function

    vector<int> vc(2, 100);            // {100,100}
    vc.insert(vc.begin(), 300);        // {300, 100 , 100}
    vc.insert(vc.begin() + 1, 2, 400); // {300 , 400, 400 , 100,100}

    // Lets print the values inside vs vector

    for (auto i = vc.begin(); i != vc.end(); i++)
    {

        cout << *(i) << " ";
    }

    // 2nd way is via for-each loop

    cout << endl;

    for (auto i : vc) // Here auto takes the data type of int , as integer value is there inside vector
    {

        cout << i << " ";
    }

    vector<int> copy(2, 50);                         // {50 , 50}
    vc.insert(vc.begin(), copy.begin(), copy.end()); // {50, 50 ,300 , 400, 400 , 100,100}

    // lets print the values to check whether copy vector is there inside vc vector or not

    for (auto i : vc)
    {

        cout << i << " "; // 50 50 300 400 400 100 100
    }

    // size of vector

    cout << endl
         << vc.size() << endl; // 6

    // To remove the element from the last in vector

    vc.pop_back(); // {50, 50 , 300, 400, 400 , 100}

    // to check the values now,
    for (auto i : vc)
    {

        cout << i << " "; // {50, 50 , 300, 400, 400 , 100}
    }

    // To swap 2 vectors

    vector<int> v5 = {10, 1, 100, 23};

    v5.push_back(9);

    vector<int> v6 = {1, 2, 4};

    v6.swap(v5); // v6 = {10,1,100,23,9} , v5 = { 1,2,4}

    cout << endl;

    for (auto i : v5)
    {

        cout << i << " ";
    }

    cout << endl
         << v5.back(); // it prints the last value , back()

    // to clear to vector , means to make it empty , use clear()

    v5.clear();

    //     terminate called after throwing an instance of 'std::out_of_range'
    //   what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
    cout << "2nd value: " << v5.at(0);

    // this for loop will not print anything as v5 is empty ,
    for (auto i : v5)
    {

        cout << "Hey";
        cout << i << " Empty ";
    }

    cout << endl
         << v5.empty(); // this empty() returns true (1) if empty or false (0) value if not empty
}

// About List , another container which is similar properties as Vector

void explainList()
{

    list<int> ls;

    ls.push_back(2);    // {2}
    ls.emplace_back(4); //{2,4}

    // In vector we use insert which is costly takes too much time
    // and push_front() is much faster in list
    ls.push_front(10); // {10,2,4}

    // on a list of a type that can be default-constructed (like int, where default construction results in zero-initialization
    ls.emplace_front();

    // Updated list is now : ls = {0,10,2,4}

    for (auto i : ls)
    {

        cout << i << " "; // {0,10,2,4}
    }
}

// Now lets see about deque

void explainDeque()
{

    deque<int> dq;

    dq.push_back(2);      // {2}
    dq.emplace_back(9);   // {2,9}
    dq.push_front(30);    // {30,2,9}
    dq.emplace_front(90); // {90,30 , 2, 9}

    dq.pop_back();  // {90, 30 , 2}
    dq.pop_front(); // {30,2}

    cout << endl;
    // Lets see the elements in deque now

    for (auto i : dq)
    {

        cout << i << " "; // {30,2}
    }
}

// Now lets see about stack, similar to others in syntax wise , its LIFO
// In stack ,there are only 3 operations, push() , top() and pop()

void explainStack()
{

    // The time complexity of stack is O(1), as all the 3 operations take constant time to solve
    stack<int> st;

    st.push(9); // {9}
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(12);
    st.push(10); // {9,1,2,4,12,10}

    // In C++, the std::stack container adapter follows the Last-In-First-Out (LIFO) principle, meaning you can only directly access the element at the top of the stack. You cannot access elements by "index or randomly like in arrays or vectors ".
    //  To access the top element of a std::stack, use the .top() method:

    cout << endl
         << "top element is: " << st.top(); // 10
    st.pop();                               // { 9,1,2,4,12}

    cout << endl
         << "now , top element is: " << st.top(); // 12

    cout << endl
         << " Size of the stack is : " << st.size(); // 5

    cout << endl
         << "is the stack is empty? " << st.empty(); // 0 , as its not empty

    // To swap the stack values

    stack<int> st1, st2;

    st1.swap(st2);
}

// Now lets see about Queue
// Here too in Queue, all the operations performed in constant time that is O(1)

void explainQueue()
{

    queue<int> q;

    q.push(1);     // {1}
    q.push(4);     //{1,4}
    q.push(7);     // {1,4,7}
    q.emplace(10); // {1,4,7,10}

    q.back() += 5; // 10+5 = 15

    cout << "The last element is :" << q.back() << endl; // 15

    cout << " The front element is : " << q.front() << endl; // 1

    q.pop(); // {4,7,15} , first element popped out

    cout << "Now the updated first element is : " << q.front(); // 4

    // Remaining all the operations are similar to the stack that is . size, empty, swap.
}

// Now lets see for the Priority_Queue , push() and pop() time complexity is O(log n) and for top() its O(1)

void explainPriority_Queue()
{

    // Now lets see for the Priority_Queue
    //  In priority queue, the highest int, char, string(in terms in char) stays at the top as per their priority

    priority_queue<int> pq; // This is also known as Max-Heap , as the highest number stored at top

    pq.push(2); // 2
    pq.push(7); // 2,7
    pq.push(1); // 1,2,7
    pq.push(3); // 1,2,3,7

    cout << endl
         << "The element at the top is : " << pq.top() << endl; // 7

    pq.pop(); // 1,2,3

    cout << " Now the top is element is : " << pq.top() << endl; // 3

    // size , swap , empty function same as others

    // Now to store the minimum value at the top, we use Minimum heap

    priority_queue<int, vector<int>, greater<int>> pq1; // Syntax of minimum heap

    pq1.push(5); // 5
    pq1.push(1); // 5 , 1
    pq1.push(3); // 5,3,1
    pq1.push(9); // 9,5,3,1

    // now lets see the top most element
    cout << "The top-most element is :" << pq1.top() << endl; // 1

    pq1.pop(); // 9,5,3

    cout << " Now the top element is :" << pq1.top() << endl; // 3

    pq1.emplace(100); // 100,9,5,3

    cout << " Now the top element is :" << pq1.top() << endl; // 3
}

// Now lets see about another container that is Set
// 2 main things about set is - Sorted and Unique values
// All operations in set take log(n) time complexity

void explainSet()
{

    set<int> st;

    st.insert(1);  // 1
    st.emplace(9); // 1,9
    st.insert(4);  // 1,4,9
    st.insert(3);  // 1,3,4,9
    st.insert(3);  // 1,3,4,9  will not add again the same value, unique only

    // begin() , end() , rbegin() , empty() , swap() , rend() , size() is same as others

    // 1,3,4,9

    auto it = st.find(3); // it returns an iterator which points to 3 , means points to the address

    // 1,3,4,9
    auto it1 = st.find(7); // as 7 is not there, "it" will return st.end// (), which points to the address which is after the last // value's address.

    st.erase(4); // 1,3,9 -- It takes logarithmic time --> O(logn)

    int cnt = st.count(1); // This will count the number of 1's in the set, but it will always be either 1 or 0

    cout << "count is :" << cnt; // returns 1 if the value 1 exists in set else 0

    auto it2 = st.find(9);
    st.erase(it2); // here erased the address, takes constant time  --> O(1) which is faster as compare to erasing the value directly, hence, always try to erase the address of that value

    // 1 , 3 , 4,9

    auto a = st.find(1);
    auto b = st.find(4);

    st.erase(a, b); // b is not included [first , last)-- new set is --> 4,9

    // lower_bound() and upper_bound() function works in the same way as in vector it does

    // 1,3,4,9
    auto x = st.lower_bound(1); // points to the address of 1st element
    auto y = st.upper_bound(4); // points to the address next to element 4 that is points to element 9
}

// Lets see of multiset , here the elements are sorted but not unique, can have same elements multiple times
void explainMultiSet()
{

    multiset<int> mt;

    mt.insert(1); // 1
    mt.insert(1); // 1,1
    mt.insert(1); // 1,1,1
    mt.insert(2);
    mt.insert(2);
    mt.insert(3); // 1,1,1,2,2,3

    // to erase the element

    mt.erase(1); // This will erase all 1's from multiset

    // now to erase only particular element , better to erase then the address

    mt.erase(mt.find(1)); // this find() will point to the address of the 1st occurence of 1 and delete that address , now --> 1,1

    // to delete the elements upto some range

    mt.erase(mt.find(1), mt.find(2) + 2); // 0th and 1st index removed,only 2nd index element is there --> 1  [first, last)

    // rest all functions are same as set
}

// Lets see about Unordered Set
// Elements are not sorted here as the name , but unique elements present , All operations are in O(1) time.

void explainUnordered_Set()
{

    unordered_set<int> us;

    // All operations are same as Set, except lower_bound() and upper_bound() is not used in unordered set
    // but in a worst case, probably once in a million the time complexity goes to O(N), this is very rare
}

// Now lets see about Map
// Solves in generally Log(n) times
// Stores data, key-value pair, where key is always unique and value can be same of different keys, the differentiator is only the key which is unique , like same students name(value) in class but their uniqueness is their Roll-no(key)

// Map stores unqiue keys in sorted order similar to set

void explainMap()
{

    // lets see the declaration, key and value can be of any data-type
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    map<pair<int, int>, int> mpp2;

    mpp[1] = 2; // (key,value) --> {1,2}

    // Another way of adding key-value
    mpp.emplace(3, 1); // {1,2} , {3,1}

    mpp.insert(2, 4); // {1,2} , {2,4} , {3,1}

    mpp2[{2, 3}] = 10; // {{2,3},10}

    // Now lets iterate in mpp
    // first option is using begin() and end() in for loop
    // Another is for-each loop

    for (auto i : mpp)
    {

        cout << " (" << i.first << "," << i.second << ")"; // output --> (1,2) (2,4) (3,1)
        // cout<<i<<" ";
    }

    cout << endl;

    cout << mpp[1] << " "; // it will print the value of key 1 that is -- 2
    cout << mpp[5];        // This will print NULL or 0 as this key is not there

    auto it = mpp.find(3); // the iterator "it" will point to (3,1)

    // Now to access the value via Iterator or address
    //     The error cout << *(it).first when using an iterator it with a std::map arises because of operator precedence. The dot operator (.) has higher precedence than the dereference operator (*).
    // This means *(it).first is evaluated as *( (it).first ). However, it is an iterator, not a direct object with members like first. The first member belongs to the std::pair object that the iterator points to.
    // To correctly access the key (the first element of the std::pair) pointed to by the iterator, one must first dereference the iterator to get the std::pair object, and then access its first member. This can be done in two ways: Using parentheses to enforce precedence.
    cout << endl
         << "The value of (3,1) is " << (*it).second;

    // 2nd way to print the value by using the arrow ->
    cout << endl
         << "The key of (3,1) is: " << it->first;

    auto it1 = mpp.find(5); // As key-5 is not there , hence it will point to end() , which points to address which is after the map ends , hence the answer will be 0

    // Map=(1,2) (2,4) (3,1)
    cout << endl
         << "For key 5 which does not exist, the value is :" << (*it1).second; // 0

    auto it2 = mpp.lower_bound(2);
    auto it3 = mpp.upper_bound(3);

    cout << endl
         << "For lower bound :" << (*it2).second; // 4
    cout << endl
         << "For upper bound :" << (*it3).second; // Upper bound points to key which is just greater than 3, as 3 is the highest key in Map, hence , it3 points to mpp.end(), so the result will be any random number or undefined behavior or can be 0

    // erase, size, swap, empty are as same as above
}

// Now lets see of MultiMap

void explainMultiMap()
{

    // (1,3),(1,9),(2,7),(3,1),(3,2)
    // Everything same as map liked sorted, but can have duplicate keys
    // only mpp[key] cannot be used here
}

// Now lets see of UnOrdered Map
// Solves in generally O(1), in worst case like once in a million takes O(N), this is very rare

void explainUnorderedMap()
{

    // (1,3),(3,1),(2,7)  --> not sorted, but keys are unique
    // Same as set but not sorted.
    // Unique Keys
}

// Lets learn some Algorithms before deep dive in Coding Problems

// Lets write the comparator function here

bool comp(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false; // in false condition, it swaps

    // Last condition is both second is same, now have to check the first
    if (p1.first > p2.first)
        return true;
    else
        return false; // here if both first is same , then no need to swap
}

void Algorithms()
{

    // Lets sort this array by using STL, not using any sorting algo
    int a[] = {3, 1, 10, 9, 12};

    // 1st method
    sort(a, a + 5); // a points to first iterator and a+5 points to end() means [a,a+5);--> 1,3,9,10,12

    // sort(a.begin(), a.end()) cannot be directly used with a raw C-style array in C++. The begin() and end() methods are members of container classes like std::vector, std::list, std::string, etc., which provide iterators to their elements.

    // //2nd method, if using vector, list or String then can use begin() and end()
    // sort(a.begin() , a.end());

    //   cout<<endl;

    // If wants sorting from any particular position like want sorting from 3rd to 5th position --> 10,9,12 -- 9,10,12

    sort(a + 2, a + 5); // 3,1,9,10,12

    // if wants sorting in descending order

    sort(a, a + 5, greater<int>()); // 12,10,9,3,1 , // Used greater<int>() to sort the array in desc order

    for (auto i : a)
    {

        cout << i << " ";
    }

    // Lets see how to sort the array or vector in our way, as per our requirement

    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};

    // sort this above one according to the 2nd element, if second element is same , then sort it according to 1st element but in desc --> {4,1}, {2,1}, {1,2}

    sort(arr, arr + 3, comp); // Comp here is the comparator function which always return the boolean value.

    // Now lets print the value of arr[] to check
    for (auto i : arr)
    {

        cout << i.first << "," << i.second << " "; //  4,1  2,1  1,2
    }

    // one more important STL is _builtin_popcount();
    int num = 7;                       // in binary its --> 111
    int cnt = __builtin_popcount(num); // This gives binary 1's

    cout << "The number of 1s in 7 that is 111 is : " << cnt << endl;

    long long num1 = 2838811939891;
    cnt = __builtin_popcountll(num1); // this is for long long data type

    cout << " for long number now the 1s are : " << cnt << endl;

    // Now to know the permutations of a number, we use next_permutation();

    string s = "213"; //-->123 , 132 , 213 , 231 , 312 , 321
    // to get all the permutations, always make sure the string is sorted as next_permutation() sorts in dictionary order

    // for eg -->if s= 231 , then permuatation is --> 231 , 312 , 321

    // hence to sort the string,

    sort(s.begin(), s.end()); // here now the s = 123

    do
    {

        cout << s << endl; // 123 , 132 , 213 , 231 , 312 , 321

    } while (next_permutation(s.begin(), s.end()));

    // Last one is to get the maximum number in array we use max_element() which points to the address of the maximum element and same is min_element() for to find the minimum element

    int ar[] = {1, 9, 37, 12, 10};

    int maxi = *max_element(ar, ar + 5); // used * to get the value from that address

    cout << "The highest element in array is :" << maxi;
    cout << endl
         << "The minimum element in array:" << *min_element(ar, ar + 5);
}

int main()
{

    // C++ STL has divided into 4 parts
    //  1 Algorithms
    //  2 Containers
    //  3 Functions
    //  4 Iterators

    // Lets start with Containers and before that lets start with Pair
}
