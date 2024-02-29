#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;
    unordered_map<char, long long> word1Map;
    unordered_map<char, long long> word2Map;
    long long sum1 = 0;
    long long sum2 = 0;

    for (auto it : word1)
    {
        if (word2.find(it) == string::npos)
            return false;
    }

    for (int i = 0; i < word1.length(); i++)
    {
        word1Map[word1[i]]++;
        word2Map[word2[i]]++;
        sum1 += word1Map[word1[i]];
        sum2 += word2Map[word2[i]];
    }
    if (sum1 == sum2)
        return true;
    else
        return false;
}

int main()
{
    string word1 = "abc";
    string word2 = "bca";
    cout << "Are these two strings close? " << endl;
    cout << boolalpha << closeStrings(word1, word2) << endl;
    return 0;
}