#include <bits/stdc++.h>
using namespace std;

// Now lets check whether the String is Palindrome or not

// This is similar to Reverse logic that is if after reverse both are same, then its palindrom, but instead of reversing the string, if we check the condition that is for eg- "abba" , check for s[i] with s[n-i-1] and if at any point both the values are not equal, string is not Palindrome.
// Lets solve this using Functional way

// The time complexity is - O(n/2) , half time iterate on String , where n, size of String
// Auxiliary Space - O(n/2) , in the stack space that is being returned

bool f(int i, string &s)
{

    if (i >= s.size() / 2)
        return true;

    if (s[i] != s[s.size() - i - 1])
        return false;

    return f(i + 1, s);

    //      Compiler's Limited Analysis: While a programmer may know that the conditions cover all possibilities, the compiler doesn't perform such in-depth logical analysis. The compiler assesses the function's structure. If there's no explicit else block or an unconditional return, there's a chance of reaching the end of the function without returning a value.

    // Need for Unconditional Return: To satisfy the compiler and ensure a value is always returned, an unconditional return statement is needed at the function's end https://www.reddit.com/r/cpp_questions/comments/s6x9ts/warning_control_reaches_end_of_nonvoid_function/. This can be done by making the final recursive call a return statement, by replacing the second if statement with an else block, or by adding a default return at the function's end.
    
    // In short, even if the initial if statements will eventually return a value, the compiler doesn't make that assumption. It requires a guaranteed return in every possible execution path to prevent undefined behavior.
}

int main()
{

    // string s="abababa";

    string s;

    cout << "Enter the string to check whether its Palindrome or not: ";
    cin >> s;

    cout << f(0, s);
}

// Output:

// s= "navan"
// 1

// s="naven"
// 0
