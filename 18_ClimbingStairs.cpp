#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    // TLE
    // if(n == 2){
    //     return 2;
    // }
    // if(n == 1){
    //     return 1;
    // }
    // int ans = climbStairs(n-1) + climbStairs(n-2);
    // return ans;

    // Brute
    int prev1 = 0;
    int prev2 = 1;
    for (int i = 0; i <= n - 2; i++)
    {
        int temp = prev1 + prev2;
        prev1 = prev2;
        prev2 = temp;
    }
    return prev1 + prev2;
}

int main()
{
    int n = 5;
    cout << climbStairs(n) << endl;
    return 0;
}