#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int tCase;
    
    cin>>tCase;
    cin.ignore();
    

    for(int i=0;i<tCase;i++){
        string input;
        string tmp="";
        vector<string> sentence;

        getline(cin, input);
        
        for(int i=0;i<input.size(); i++){
            if(input[i]==' '){
                sentence.push_back(tmp);
                tmp="";
            }
            else{
                tmp+=input[i];
            }
        }

        sentence.push_back(tmp);
        reverse(sentence.begin(), sentence.end());

        cout<<"Case #"<<i+1<<": ";
        for(int i=0;i<sentence.size();i++){
            cout<<sentence[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}