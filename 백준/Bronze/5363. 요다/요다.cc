#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int tCase;
   
    cin>>tCase;
    cin.ignore();

    for(int i=0;i<tCase;i++){
         vector<string> yoda;
        string input;
        string tmp="";

        getline(cin, input);

        for(int j=0;j<input.size();j++){
              if(input[j]==' '){
                  yoda.push_back(tmp);
                  tmp="";
              }
              else if(j==input.size()-1){
                  tmp+=input[j];
                  yoda.push_back(tmp);
              }
            else{
                tmp+=input[j];
            }
        }

        yoda.push_back(yoda[0]);
        yoda.push_back(yoda[1]);

        for(int j=2;j<yoda.size();j++){
            cout<<yoda[j]<<" ";
        }
        cout<<"\n";
        
    }
    return 0;
}