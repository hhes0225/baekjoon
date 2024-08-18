#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<string, string> PSS;

bool compare(PSS a, PSS b){
    return a.first<b.first;
}


int main() {
    vector<PSS> records;
    int teamBScore=0;
    int teamRScore=0;
    
    for(int i=0;i<8;i++){
        string time, team;
        cin>>time>>team;

        records.push_back({time, team});
    }

    sort(records.begin(), records.end(), compare);

    //for(auto it: records){
    //    cout<<it.first<<" "<<it.second<<endl;
    //}

    int assignedScore=10;
    for(int i=0;i<8;i++){
        if(records[i].second=="R"){
            teamRScore+=assignedScore;
        }
        else{
            teamBScore+=assignedScore;    
        }
        
        if(i<2){
            assignedScore-=2;
        }
        else{
            assignedScore--;
        }
    }

    //cout<<teamRScore<<" "<<teamBScore<<endl;

    if(teamBScore>teamRScore){
        cout<<"Blue";
    }
    else{
        cout<<"Red";
    }

    
    return 0;
}