#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> arr;
    arr.resize(10);

    for(auto &a:arr){
        cin>>a;
    }

    reverse(arr.begin(), arr.end());

    for(auto a:arr){
        cout<<a;
    }

    
    return 0;
}