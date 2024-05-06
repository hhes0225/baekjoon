#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int helmet, vest;
    int maxHDef=0, maxVDef=0;

    cin>>helmet>>vest;

    for(int i=0;i<helmet;i++){
        int input;
        cin>>input;
        
        maxHDef=max(maxHDef, input);
    }

    for(int i=0;i<vest;i++){
        int input;
        cin>>input;
        
        maxVDef=max(maxVDef, input);
    }

    cout<<maxHDef+maxVDef<<endl;
    
    return 0;
}