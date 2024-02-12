// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.size()==b.size()){
        return a<b;
    }
    else{
        return a.size()<b.size();
    }
}

int main() {
    int tCase;
    vector<string> homework;
    cin>>tCase;
    
    for(int i=0;i<tCase;i++){
        string input;
        string tmp="";
        
        cin>>input;
        
        for(int j=0;j<input.size();j++){
            //문자열 중 숫자 부분만 추가
            if(isdigit(input[j])){
                if(!(tmp=="" && input[j]=='0'))
                    tmp+=input[j];
                
                if(j==input.size()-1){
                    //cout<<"tmp: "<<tmp<<endl;
                    if(tmp==""){
                        tmp="0";
                    }
                    homework.push_back(tmp);
                    tmp="";
                }
                else if(!(isdigit(input[j+1]))){
                    if(tmp=="")
                        tmp="0";
                    homework.push_back(tmp);
                    tmp="";
                }
            }
            
        }
        
    }
    
    sort(homework.begin(), homework.end(), compare);
    
    //cout<<"hello\n";
    for(int i=0;i<homework.size();i++){
        cout<<homework[i]<<"\n";
    }
    

    return 0;
}