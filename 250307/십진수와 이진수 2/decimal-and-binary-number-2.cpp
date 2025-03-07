#include <bits/stdc++.h>

using namespace std;

string N;

int main() {
    cin >> N;
    int dec=0;
    vector<int> reBin;

    for(int i=0;i<N.size();i++){
        dec=(dec*2)+(N[i]-'0');
    }

    dec*=17;

    while(dec>1){
        reBin.push_back(dec%2);
        dec/=2;
    }
    reBin.push_back(dec);
    reverse(reBin.begin(), reBin.end());

    for(auto r:reBin){
        cout<<r;
    }

    return 0;
}