#include <bits/stdc++.h>

using namespace std;

int a, b;
string n;

int main() {
    cin >> a >> b;
    cin >> n;

    int dec=0;
    //a진수->10진수로 변환
    for(int i=0;i<n.size();i++){
        dec=(dec*a)+(n[i]-'0');
    }

    //cout<<dec<<"\n";

    vector<int> toB;
    //10진수->b진수로 변환
    while(dec>b-1){
        toB.push_back(dec%b);
        dec/=b;
    }

    toB.push_back(dec);
    reverse(toB.begin(), toB.end());

    for(auto t:toB){
        cout<<t;
    }

    return 0;
}