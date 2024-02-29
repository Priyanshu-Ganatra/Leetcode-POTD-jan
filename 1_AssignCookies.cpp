#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int contentChildren = 0;
    int j = 0, i = 0;
    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        {
            contentChildren++;
            i++;
        }
        j++;
    }
    return contentChildren;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << "Content Children:" << endl;
    cout << findContentChildren(g, s) << endl;
    return 0;
}