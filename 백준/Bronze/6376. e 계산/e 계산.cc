#include<iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<double> factorial;
vector<double> e;

void dpFact(){
    factorial.resize(9+1);

    factorial[0]=1;
    factorial[1]=1;

    for(int i=2;i<=9;i++){
        factorial[i]=factorial[i-1]*i;
    }
    
}

void dpE(){
    e.resize(9+1);

    e[0]=1;
    e[1]=2;

    for(int i=2;i<=9;i++){
        e[i]=e[i-1]+(1/factorial[i]);
    }
    
}

int main(void){

    dpFact();
    dpE();

    cout<<"n e\n";
    cout<<"- -----------\n";
    
    for(int i=0; i<=9;i++){
        if(i<=1){
            printf("%d %.lf\n", i, e[i]);
        }
        else if(i==2){
            printf("%d %.1lf\n", i, e[i]);
        }
        else{
            printf("%d %.9lf\n", i, e[i]);
        }
        
    }

    
    
    return 0;
}