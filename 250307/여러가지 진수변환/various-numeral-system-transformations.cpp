#include <bits/stdc++.h>

using namespace std;

int N, B;

int main() {
    cin >> N >> B;
    vector<int> changeDigit;

    while(N>B-1){
        changeDigit.push_back(N%B);
        N/=B;
    }

    changeDigit.push_back(N);
    reverse(changeDigit.begin(), changeDigit.end());
    
    for(auto c:changeDigit){
        cout<<c;
    }

    return 0;
}