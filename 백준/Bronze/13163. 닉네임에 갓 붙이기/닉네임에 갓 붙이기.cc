#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int tCase;
    cin>>tCase;

    cin.ignore();

    for(int i=0;i<tCase;i++){
        string input;
        vector<string> nickname;
        getline(cin, input);

        string tmp="";
        for(int j=0;j<input.size();j++){
            if(input[j]!=' '){
                tmp+=input[j];
            }
            else{
                nickname.push_back(tmp);
                tmp="";
            }
        }
        nickname.push_back(tmp);

        nickname[0]="god";

        for(int j=0;j<nickname.size();j++){
            cout<<nickname[j];
        }

        cout<<"\n";
    }
    
    return 0;
}