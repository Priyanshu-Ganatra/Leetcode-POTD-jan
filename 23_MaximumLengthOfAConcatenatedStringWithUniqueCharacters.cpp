#include <bits/stdc++.h>
using namespace std;

void backTrack(const vector<string> &arr, string current, int start, int &maxLength)
{
    if (maxLength < current.length())
        maxLength = current.length();

    for (int i = start; i < arr.size(); i++)
    {
        if (!isValid(current, arr[i]))
            continue;

        backTrack(arr, current + arr[i], i + 1, maxLength);
    }
}

bool isValid(const string &currentString, const string &newString)
{
    unordered_set<char> charSet;

    for (char ch : newString)
    {
        if (charSet.count(ch) > 0)
        {
            return false;
        }

        charSet.insert(ch);

        if (currentString.find(ch) != string::npos)
        {
            return false;
        }
    }

    return true;
}

int maxLength(vector<string> &arr)
{
    int maxLength = 0;
    backTrack(arr, "", 0, maxLength);
    return maxLength;
}

int main()
{
    vector<string> arr = {"un", "iq", "ue"};
    cout << "Max length of a concatenated string with unique characters:" << endl;
    cout << maxLength(arr) << endl;
    return 0;
}