#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int tCase;
    vector<int> input;

    cin>>tCase;

    input.resize(tCase);

    for(int i=0;i<tCase;i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end());

    cout<<input[input.size()-1]<<endl;
    
    return 0;
}