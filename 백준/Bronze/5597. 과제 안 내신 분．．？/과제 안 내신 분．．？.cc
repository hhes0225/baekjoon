#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<bool> student;

    student.resize(31);

    for(int i=0;i<28;i++){
        int input;
        cin>>input;
        
        student[input]=true;
    }

    for(int i=1;i<31;i++){
        if(student[i]==false){
            cout<<i<<"\n";
        }
    }

    

    return 0;
}