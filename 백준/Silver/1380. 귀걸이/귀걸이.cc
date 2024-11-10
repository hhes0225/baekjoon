#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;



int main() {
    int tCase=1;
    
    while(1){
        int person;
        string name;
        vector<string> students;
        string lost;
        unordered_map<int, int> earings;

        cin>>person;
        cin.ignore();

        if(person==0){
            break;
        }

        for(int i=0;i<person;i++){
            getline(cin, name);
            students.push_back(name);
        }        

        for(int i=0;i<person*2-1;i++){
            int stuNum;
            char ch;
            cin>>stuNum>>ch;

            earings[stuNum]++;
        }

        for(auto it:earings){
            if(it.second==1){
                cout<<tCase<<" "<<students[it.first-1]<<"\n";
            }
        }

        tCase++;

        
        
    }
    return 0;
}