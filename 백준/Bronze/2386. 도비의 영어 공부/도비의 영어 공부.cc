#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input;
    char comp;

    while(1){
        int count =0;
        
        cin>>comp;
        cin.ignore();
        getline(cin, input);

        if(comp=='#'){
            break;
        }

        transform(input.begin(), input.end(), input.begin(), ::tolower);
        
        for(int i=0;i<input.size();i++){
            if(input[i]==comp){
                count++;
            }
        }

        cout<<comp<<" "<<count<<"\n";
    }
    
    return 0;
}