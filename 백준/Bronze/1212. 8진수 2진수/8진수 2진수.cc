// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string oct;
    vector<string> sample ={"000","001","010","011","100","101","110", "111"};
    string binary="";
    
    cin>>oct;
    
    for(int i=0;i<oct.size();i++){
        string octToBin = sample[oct[i]-'0'];
        if(i==0){//0으로 시작하는것을 방지하기 위함
            /*if(oct[i]-'0'==0){
                continue;
            }
            else 
            if(oct[i]-'0'<=3){
                
            }*/
            binary+=to_string(stoi(octToBin));
        }
        else{
            binary+=octToBin;
        }
    }
    cout<<binary<<"\n";
    
    
    

    return 0;
}