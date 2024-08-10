#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> slots;
    int n, q;
    int empty=0;

    cin>>n>>q;

    slots.assign(n+1, 0);

    for(int i=0;i<q;i++){
        int from, gap;
        cin>>from>>gap;

        for(int j=from;j<slots.size();j+=gap){
            slots[j]++;
        } 
    }

    for(int j=1;j<slots.size();j++){
        if(slots[j]==0){
            empty++;
        }
    }

    cout<<empty<<"\n";    
    
    return 0;
}