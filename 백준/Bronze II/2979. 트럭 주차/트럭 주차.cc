#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a,b,c;
    int aEnter, aExit;
    int bEnter, bExit;
    int cEnter, cExit;
    vector<int> parking;
    parking=vector<int>(101, 0);
    int parkingCost=0;

    cin>>a>>b>>c;
    
    cin>>aEnter>>aExit;
    cin>>bEnter>>bExit;
    cin>>cEnter>>cExit;

    for(int i=aEnter+1;i<=aExit;i++){
        parking[i]++;
    }

    for(int i=bEnter+1;i<=bExit;i++){
        parking[i]++;
    }

    for(int i=cEnter+1;i<=cExit;i++){
        parking[i]++;
    }

    for(int i=1;i<101;i++){
        if(parking[i]==1){
            parkingCost+=(parking[i]*a);
        }
        else if(parking[i]==2){
            parkingCost+=(parking[i]*b);
        }
        else if(parking[i]==3){
            parkingCost+=(parking[i]*c);
        }
        else{
            continue;
        }
    }
    
    cout<<parkingCost<<"\n";
    
    return 0;
}