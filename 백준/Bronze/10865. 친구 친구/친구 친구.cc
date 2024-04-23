#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int tCase, friends;
    cin>>friends>>tCase;
    vector<int> relationship;

    relationship.resize(friends+1);

    for(int i=0;i<tCase;i++){
        int from, to;
        cin>>from>>to;

        relationship[from]++;
        relationship[to]++;
    }

    for(int i=1;i<relationship.size();i++){
        cout<<relationship[i]<<"\n";
    }

    

    return 0;
}