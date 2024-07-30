#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void){
    string input;

    cin>>input;

    if(input.find('A')!=string::npos){
        replace(input.begin(), input.end(), 'B', 'A');
        replace(input.begin(), input.end(), 'C', 'A');
        replace(input.begin(), input.end(), 'D', 'A');
        replace(input.begin(), input.end(), 'F', 'A');
    }
    else if(input.find('B')!=string::npos){
        replace(input.begin(), input.end(), 'C', 'B');
        replace(input.begin(), input.end(), 'D', 'B');
        replace(input.begin(), input.end(), 'F', 'B');
    }
    else if(input.find('C')!=string::npos){
        replace(input.begin(), input.end(), 'D', 'C');
        replace(input.begin(), input.end(), 'F', 'C');
    }
    else{
        fill(input.begin(), input.end(), 'A');
    }

    cout<<input<<"\n";
    
    return 0;
}
