#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
    double input;
    const double gravity = 0.167;

    while(1){
        cin>>input;
        if(input<0){
            break;
        }

        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", input, input*gravity);
    }
    
    return 0;
}