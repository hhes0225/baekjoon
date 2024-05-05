#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    string input;

    while(1){
        cin>>input;
        int sum=0;

        if(input=="0"){
            break;
        }

        while(1){
            for(int i=0;i<input.size();i++){
                sum+=(int)input[i]-(int)'0';
            }

            if(to_string(sum).size()==1){
                cout<<sum<<"\n";
                break;
            }

            input=to_string(sum);
            sum=0;
        }
        
    }
    
    return 0;
}