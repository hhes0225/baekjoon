#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;


    for(int i=0;i<tCase;i++){
        int participants, seats;
        unordered_map<int, int> match;
        int unavailable=0;
        
        cin>>participants>>seats;

        for(int i=0;i<seats;i++){
            match.insert({i+1, 0});
        }

        for(int i=0;i<participants;i++){
            int input;
            cin>>input;

            if(match[input]==0){
                match[input]++;
            }
            else{
                unavailable++;
            }
        }

        cout<<unavailable<<"\n";
    }
    
    return 0;
}