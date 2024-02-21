#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    string str;
    vector<string> num;
    
    getline(cin, str);
    
    string tmp="";
    for(int i=0;i<str.size();i++){
        if(str[i]!=','){
            tmp+=str[i];
        }
        else{
            num.push_back(tmp);
            tmp="";
        }
    }
    num.push_back(tmp);//마지막 수 처리
    
    int sum=0;
    for(int i=0;i<num.size();i++){
        sum+=stoi(num[i]);
    }
    
    cout<<sum<<"\n";
    
    return 0;
}