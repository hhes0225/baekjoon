#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<int>& cups, int from, int to){
    int tmp=cups[from];

    cups[from]=cups[to];
    cups[to]=tmp;
}

int main() {
    int tCase;
    vector<int> cups;
    cin>>tCase;

    cups.resize(3+1);

    cups[1]=1;

    for(int i=0;i<tCase;i++){
        int from, to;

        cin>>from>>to;

        swap(cups, from, to);
        
    }


    for(int i=1;i<cups.size();i++){
        if(cups[i]==1){
            cout<<i<<"\n";
        }
    }
    
    return 0;
}