#include <iostream>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int totalCookie, eatCookie;
        cin>>totalCookie>>eatCookie;
        int days;

        if(totalCookie%eatCookie==0){
            days=totalCookie/eatCookie;
        }
        else{
            days=totalCookie/eatCookie+1;
        }

        cout<<days<<endl;
        
    }
    return 0;
}