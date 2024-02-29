#include <bits/stdc++.h>
using namespace std;

class Solution
{

    long resolves(int a, int b, char Operator)
    {
        if (Operator == '+')
            return a + b;
        else if (Operator == '-')
            return a - b;
        else if (Operator == '*')
            return (long)a * b;
        return a / b;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long> Stack;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {

            if (tokens[i].size() == 1 and tokens[i][0] < 48)
            {
                long integer2 = Stack.top();
                Stack.pop();
                long integer1 = Stack.top();
                Stack.pop();

                string Operator = tokens[i];
                cout << Operator << " ";
                long resolvedAns = resolves(integer1, integer2, Operator[0]);
                Stack.push(resolvedAns);
            }
            else
                Stack.push(stol(tokens[i]));
        }
        return Stack.top();
    }
};

// driver code with 1 test case
int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution obj;
    cout << obj.evalRPN(tokens) << endl;
    return 0;
}

