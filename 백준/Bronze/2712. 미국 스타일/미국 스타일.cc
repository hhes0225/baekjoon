#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void unitChange(double input, string unit){
    if(unit=="kg"){
        printf("%.4lf lb\n", input*2.2046);
    }
    else if(unit=="lb"){
        printf("%.4lf kg\n", input*0.4536);
    }
    else if(unit=="l"){
        printf("%.4lf g\n", input*0.2642);
    }
    else{
        printf("%.4lf l\n", input*3.7854);
    }
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        double input;
        string unit;
        
        cin>>input>>unit;

        unitChange(input, unit);
    }
    
    return 0;
}