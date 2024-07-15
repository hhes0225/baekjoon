#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int oneHand, noLook, pon;

    int clubNum;
    int maxScore=-1;

    cin>>oneHand>>noLook>>pon;

    cin>>clubNum;

    for(int i=0;i<clubNum;i++){        
        int tmpScore=0;

        for(int j=0;j<3;j++){
            int a,b,c;
            cin>>a>>b>>c;
            tmpScore+=a*oneHand+b*noLook+c*pon;
        }

        maxScore=max(maxScore, tmpScore);
    }

    cout<<maxScore<<endl;
    
    return 0;
}