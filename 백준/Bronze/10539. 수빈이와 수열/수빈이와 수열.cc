#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



int main(void){
    int tCase;
    vector<int> rule;
    int sum=0;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;
        
        if(i==0){
            rule.push_back(input);
        }        
        else{
            //cout<<"rule[i-1]: "<<rule[i-1]<<", input*(i+1): "<<input*(i+1)<<endl;
            rule.push_back(input*(i+1));
        }    
    }
    

    for(int i=0;i<tCase;i++){
        if(i==0){
            cout<<rule[i]<<" ";
        }        
        else{
            cout<<rule[i]-rule[i-1]<<" ";
        } 
        
        
    }

    cout<<"\n";

    return 0;
}