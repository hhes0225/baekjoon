#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


int main() {
    double temperature;
    double prevTemp;

    cin>>prevTemp;

    if(prevTemp==999){
        return 0;
    }
    
    while(1){
        cin>>temperature;

        if(temperature==999){
            break;
        }

        printf("%.2lf\n", temperature-prevTemp);

        prevTemp=temperature;
    }
    
    
    return 0;
}