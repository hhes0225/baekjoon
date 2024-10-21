#include <iostream>
#include <vector>
#define LIMIT 1e5
using namespace std;


vector<int> dptb;
//i를 표현할 수 있는 방법의 수

void dp(){
    dptb[0]=1;

    for(int i=1;i<=3;i++){
        for(int j=i;j<LIMIT;j++){
            dptb[j]+=dptb[j-i];
        }
    }

    /*
    for(int i=0;i<LIMIT;i++){
        cout<<dptb[i]<<" ";
    }
    cout<<"\n";
    */

}

int main() {
    int tCase;

    dptb.assign(LIMIT, 0);

    cin>>tCase;

    dp();
    
    for(int i=0;i<tCase;i++){
        int num;
        cin>>num;
        
        cout<<dptb[num]<<"\n";
    }
    
    return 0;
}