#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string input;
    int markPos1=-1, markPos2=-1;

    getline(cin, input);

    
    for(int i=0;i<input.size();i++){
        
        if(i==0 && input[i]=='\"'){
            markPos1=0;
        }
        if(i!=0 && input[i]=='\"'){
            markPos2=i;
        }
    }

    //cout<<markPos1<<" "<<markPos2<<endl;

    if(markPos1==0 && markPos2==input.size()-1){
        if(input=="\"\""){//빈 문자열일경우 CE
            cout<<"CE\n";
        }
        else{
            for(int i=1;i<input.size()-1;i++){
                cout<<input[i];
            }
        }
        cout<<"\n";
    }
    else{
        cout<<"CE\n";
    }
    
    
    
    return 0;
}