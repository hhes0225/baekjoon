#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> w, k;

    w.resize(10);
    k.resize(10);

    for(int i=0;i<10;i++){
        cin>>w[i];
    }

    for(int i=0;i<10;i++){
        cin>>k[i];
    }

    sort(w.begin(), w.end());
    sort(k.begin(), k.end());

    reverse(w.begin(), w.end());
    reverse(k.begin(), k.end());

    cout<<w[0]+w[1]+w[2]<<" ";
    cout<<k[0]+k[1]+k[2]<<endl;

    
    
    return 0;
}