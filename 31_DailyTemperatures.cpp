#include <bits/stdc++.h>
using namespace std;

// tc and sc : O(n)
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;
    int i = 0;

    while (i < temperatures.size())
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}