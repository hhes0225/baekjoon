#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tCase;
    vector<int> input;
    vector<int> order;

    cin>>tCase;
    
    input.resize(tCase);
    
    for(int i=0;i<tCase;i++){
        cin>>input[i];
    }

    for(int i=0;i<tCase;i++){
        order.insert(order.begin()+input[i], i+1);
    }

    for(int i=0;i<tCase;i++){
        cout<<order[tCase-1-i]<<" ";
    }

    cout<<"\n";

    
    return 0;
}