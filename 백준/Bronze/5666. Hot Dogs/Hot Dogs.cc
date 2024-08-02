#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    double a, b;

    while(cin>>a>>b){
        printf("%.2lf\n", a/b);
    }
    return 0;
}