#include <iostream>

using namespace std;

int main(void){
    int people;
    int sizes[6];
    int tUnit, pUnit;
    int tShirts=0;
    int pens, pen;
    
    cin>>people;
    for(int i=0;i<6;i++){
        cin>>sizes[i];
    }
    cin>>tUnit>>pUnit;

    for(int i=0;i<6;i++){
        tShirts+=(sizes[i]/tUnit);
        
        if(sizes[i]%tUnit!=0){
            tShirts++;
        }
    }

    cout<<tShirts<<"\n";

    pens=people/pUnit;
    pen=people%pUnit;

    cout<<pens<<" "<<pen<<"\n";
}