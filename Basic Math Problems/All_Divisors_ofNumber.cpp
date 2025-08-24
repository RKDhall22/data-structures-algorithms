#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Print All Divisors

    int n;

    cout << "Enter the number for which you wants the factor of it: ";
    cin >> n;

    // 1st Method is the standard one , by using the greedy approach that is running the loop from 1 upto N and then check who divides the number fully

    // In this approach the time complexity is O(N)
    for (int i = 1; i <= n; i++)
    {

        if (n % i == 0)
            cout << i << " ";
    }

    cout << endl
         << "Below is result with 2nd Approach: " << endl;

    // Lets see another approach where we does not have to traverse upto Nth number
    // In this if we see the calculation properly if we run the loop upto N^1/2 that is sqrt(N) times, will get all the factors.

    // eg:  N= 36, run for 36^1/2= 6 times, factors --> 1*36 , 2*18 , 3*12 , 4*9 , 6*6 , if we see upto this, will get that all the factors are present here, that is --> 1,36,2,18,3,12,4,9,6

    // So , how we will get the second number, by dividing the N with the first factor that is if 1 is the 1st factor, then the 2nd factor will be 36/1=36, same if 2 is 1st, then 2nd is ,36/2=18

    // So, in this way if we run the loop upto N^1/2 then will get all the numbers.

    // lets see the code for this
    //  Instead of writing sqrt(), which itself is a function will take some more time for calculation , this will increase the time complexity of the code, hence will use basic Maths here.
    //  i<=sqrt(n)  ==> i*i=n , that is taking square on both sides

    // Result will be --> 1 36 2 18 3 12 4 9 6 , which is not sorted, so you can sort this by taking a vector and then sort this.

    // We are taking vector as we dont know the number of factors,hence vector is dynamic , not like Array which is fixed size

    // As the output is not sorted, its --> 1 36 2 18 3 12 4 9 6, hence now to sort this will use vector sort function

    vector<int> v;

    for (int i = 1; i * i <= n; i++)
    { // Time Complexity -- O(sqrt(n))

        if (n % i == 0)
        {

            v.emplace_back(i); // emplace_back() is faster than push_back()

            if (i != n / i)
            { // we are checking this because, 6*6 is factor of 36, but if not use this condition, then it will print 6 ,2 times

                v.emplace_back(n / i);
            }
        }
    }

    // now lets sort the vector

    sort(v.begin(), v.end()); // Time Comp: O(n * logn), here n is number of factors which are inside the vector v

    // Now lets print the values inside the vector

    for (auto i : v)
    { // Time Comp: O(n) , n = no. of factors present in vector

        cout << i << " ";
    }

    // Generally the time complexities --> O(1)> O(logn) > O(n)^1/2 > O(n) > O(nlogn) > O(n)^2 and so on.

    //  Hence, the time complexity is --> O(n)^1/2 + O(nlogn) + O(n) --> O(nlogn)

    // Now ,lets take Set data structure which automatically takes the unique value in sorted order, and its time complexity is O(logn)

    cout << endl
         << "Lets see now by taking set: ";

    set<int> st;

    for (int i = 1; i * i <= n; i++)  // O(sqrtn)
    {

        if (n % i == 0)
        {

            st.insert(i);

            if (i != n / i)
            {

                st.insert(n / i);
            }
        }
    }

    for (auto i : st)  // O(n) , here n is the number of factors which are there inside the st
    {

        cout << i << " ";

    }

    // Hence, instead of taking vector we can take set which is better as the time complexity is O(logn) and it automatically gives the result in sorted order.

    // Output

//     Enter the number for which you wants the factor of it: 36  --> O(n)
//      1 2 3 4 6 9 12 18 36 
//     Below is result with 2nd Approach:   --> O(nlogn) because used sort() to sort the vector
//      1 2 3 4 6 9 12 18 36 
//     Lets see now by taking set: 1 2 3 4 6 9 12 18 36 -->O(n) , but here , n is factors which are there in st


}