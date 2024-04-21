#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int tCase;
    cin>>tCase;

    
    for(int i=0;i<tCase;i++){
        vector<int> basicStats;
        vector<int> additionalStats;
        vector<int> result;

        basicStats.resize(4);
        additionalStats.resize(4);
        result.resize(4);

        for(int j=0;j<4;j++){
            cin>>basicStats[j];
            
        }
        for(int j=0;j<4;j++){
            cin>>additionalStats[j];
        }

        for(int j=0;j<4;j++){
            result[j]=basicStats[j]+additionalStats[j];

            if(j<=1){
                if(result[j]<1){
                    result[j]=1;
                }
            }
            else if(j==2){
                if(result[j]<0){
                    result[j]=0;
                }
            }
        }

        int attack;
        attack=result[0]+5*result[1]+2*result[2]+2*result[3];

        cout<<attack<<endl;
    }

    return 0;
}