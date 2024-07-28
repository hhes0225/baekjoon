#include <iostream>
#include <cmath>
#include <stdio.h>
#define PI 3.14159
using namespace std;

int main() {
    int tCase;
    double maxVol = -1;
    
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        char command;
        double r, h;
        double result;
        cin>>command;

        //4/3, 1/3으로 할 것이 아니라, 4.0/3.0 이런 식으로 해야함!!
        //위처럼 하면 정수 연산해서 0 or 1이 결과로 나오게됨
        
        if(command=='S'){
            //Sphere: V = (4/3)πr3
            cin>>r;
            result = (4.0/3.0)*PI*pow(r, 3);
        }
        else{
            cin>>r>>h;

            if(command=='C'){
                //Cone: V = (1/3)πr2h
                result = (1.0/3.0)*PI*pow(r,2)*h;
            }
            else{//command=='L'
                //Cylinder: V = πr2h
                result = PI*pow(r,2)*h;
                
            }
        }

        maxVol = max(maxVol, result);
    }

    
    printf("%.3lf", maxVol);
    
    return 0;
}