#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    //1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    else{
        int aSum=0, bSum=0;

        for(int i=0;i<a.size();i++){
            if(a[i]>='0' && a[i]<='9'){
                aSum+=(int)a[i]-(int)'0';
            }
            if(b[i]>='0' && b[i]<='9'){
                bSum+=(int)b[i]-(int)'0';
            }
        }

        //cout<<aSum<<" "<<bSum<<"\n";
        
        //2. 만약 서로 길이가 같다면, 
        //A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. 
        //(숫자인 것만 더한다)
        if(aSum!=bSum){
            return aSum<bSum;
        }
        //3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 
        //숫자가 알파벳보다 사전순으로 작다.
        else{
            return a<b;
        }
        
    }
    
}

int main(void){
    int tCase;
    vector<string> serialNum;

    cin>>tCase;
    
    serialNum.resize(tCase);
    
    for(int i=0;i<tCase;i++){
        cin>>serialNum[i];        
    }


    sort(serialNum.begin(), serialNum.end(), compare);

    for(int i=0;i<tCase;i++){
        cout<<serialNum[i]<<"\n";   
    }

    return 0;
}