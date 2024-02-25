#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string input;
    int notation;
    long long int decimal=0;

    cin>>input>>notation;

    for(int i=0;i<input.size();i++){
        if(input[i]>='A' && input[i]<='Z'){
            //cout<<(int)(input[i]-'A'+10)<<endl;
            decimal+=(pow(notation, input.size()-i-1) * (int)(input[i]-'A'+10));
        }
        else{
            //cout<<(int)(input[i]-'0')<<endl;
            decimal+=(pow(notation, input.size()-i-1) * (int)(input[i]-'0'));
        }
        
    }  
    
    cout<<decimal<<"\n";

    return 0;
}