#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    string joiEx="JOI", ioiEx="IOI";
    int joi=0, ioi=0;

    cin>>input;

    for(int i=0;i<input.size()-2;i++){
        if(input.substr(i, 3)=="JOI"){
            joi++;
        }
        else if(input.substr(i, 3)=="IOI"){
            ioi++;
        }

    }

    cout<<joi<<"\n"<<ioi<<"\n";

    return 0;
}