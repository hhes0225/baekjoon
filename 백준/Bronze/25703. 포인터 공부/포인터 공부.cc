#include <iostream>
using namespace std;

int main() {
    int times;
    cin>>times;

    cout<<"int a;\n";

    for(int i=0;i<times;i++){
        cout<<"int ";

        for(int j=0;j<i+1;j++){
            cout<<"*";
        }

        if(i==0){
            cout<<"ptr = &a;\n";
            continue;
        }
        else if(i==1){
            cout<<"ptr"<<i+1<<" = &ptr;\n";
            continue;
        }
        cout<<"ptr"<<i+1<<" = &ptr"<<i<<";\n";
    }
    return 0;
}