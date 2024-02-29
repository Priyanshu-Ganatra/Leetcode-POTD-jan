#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (auto x : arr)
    {
        freq[x]++;
    }
    unordered_set<int> s;
    for (auto x : freq)
    {
        s.insert(x.second);
    }
    return freq.size() == s.size();
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << boolalpha << uniqueOccurrences(arr) << endl;
    return 0;
}