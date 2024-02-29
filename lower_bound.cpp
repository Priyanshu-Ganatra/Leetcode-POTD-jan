#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 8, 9};
    auto lower = lower_bound(arr, arr + 3, 11);  // in this case, lower = arr + 3 
    cout << lower - arr << endl; 
    return 0;
}
