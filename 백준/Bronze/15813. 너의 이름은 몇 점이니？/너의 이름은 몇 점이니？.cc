#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    string name;
    int score=0;

    cin>>length>>name;

    for(int i=0;i<name.size();i++){
        score+=(int)name[i]-(int)'A'+1;
    }

    cout<<score<<"\n";
    
    return 0;
}