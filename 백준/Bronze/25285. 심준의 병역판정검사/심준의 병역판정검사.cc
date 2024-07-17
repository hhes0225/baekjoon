#include <iostream>
#include <string>
using namespace std;

int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        double height, weight;
        int level;
        double bmi;

        cin>>height>>weight;

        bmi=weight/(height*0.01*height*0.01);

        if(height<140.1){
            level=6;
        }
        else if(height>=140.1 && height<146.0){
            level=5;
        }
        else if(height>=146.0 && height<159.0){
            level=4;
        }
        else if(height>=159.0 && height<161.0){
            if(bmi>=16.0 && bmi<35.0){
                level=3;
            }
            else if(bmi<16.0 || bmi>=35.0){
                level=4;
            }
        }
        else if(height>=161.0 && height<204.0){
            if(bmi>=20.0 && bmi<25.0){
                level=1;
            }
            else if((bmi>=18.5 && bmi<20.0)||(bmi>=25.0 && bmi<30.0)){
                level=2;
            }
            else if((bmi>=16.0 && bmi<18.5)||(bmi>=30.0 && bmi<35.0)){
                level=3;
            }
            else if(bmi<16 || bmi>35.0){
                level=4;
            }
        }
        else{
            level=4;
        }

        cout<<level<<"\n";
    }
    
    return 0;
}