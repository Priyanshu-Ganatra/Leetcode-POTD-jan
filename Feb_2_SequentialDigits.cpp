#include <bits/stdc++.h>
using namespace std;

vector<int> sequentialDigits(int low, int high)
{
    string c = "123456789";
    vector<int> a;

    for (int i = 0; i < c.size(); i++)
    {
        for (int j = i + 1; j <= c.size(); j++)
        {
            int curr = stoi(c.substr(i, j - i));
            if (curr <= high && curr >= low)
            {
                a.push_back(curr);
            }
        }
    }
    sort(a.begin(), a.end());
    return a;
}

int main()
{
    int low = 100, high = 300;
    vector<int> ans = sequentialDigits(low, high);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}