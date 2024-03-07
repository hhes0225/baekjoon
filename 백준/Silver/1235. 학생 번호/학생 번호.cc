#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tCase;
    vector<string> stuNum;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        string tmp;
        cin>>tmp;

        reverse(tmp.begin(), tmp.end());
        stuNum.push_back(tmp);
    }

    bool isAtomic=false;
    int atomic=1;   
    vector<string> tmpVec; 

    while(1){
        if(isAtomic==true){
            break;
        }
        
        //substr로 축소된 학번 추출
        for(int i=0;i<stuNum.size();i++){
            tmpVec.push_back(stuNum[i].substr(0, atomic));
            //cout<<tmpVec[i]<<endl;
        }
        
        //학번 중복 여부 확인
        for(int i=0;i<tmpVec.size();i++){
            //중복 값 존재한다면
            if(find(tmpVec.begin()+i+1, tmpVec.end(), tmpVec[i])!=tmpVec.end()){
                //cout<<tmpVec[i]<<" 중복\n";
                isAtomic=false;
                break;
            }
            else{
                isAtomic=true;
            }
        }

        if(isAtomic==false){
            atomic++;
            tmpVec.clear();
        }
    }

    cout<<tmpVec[0].size()<<"\n";

    
    return 0;
}