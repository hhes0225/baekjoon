#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define LIMIT 3

class Member{
    public :
    int solved;
    int stuNum;
    string lastName;
};

bool compare1(Member a, Member b){
    return a.stuNum<b.stuNum;
}

bool compare2(Member a, Member b){
    return a.solved>b.solved;
}

int main() {
    vector<Member> memList;
    memList.resize(LIMIT);
    
    for(int i=0;i< LIMIT;i++){
        cin>>memList[i].solved>>memList[i].stuNum>>memList[i].lastName;
    }

    //sort 1
    sort(memList.begin(), memList.end(), compare1);

    cout<<memList[0].stuNum%100<<memList[1].stuNum%100<<memList[2].stuNum%100<<"\n";

    //sort 2
    sort(memList.begin(), memList.end(), compare2);

    cout<<memList[0].lastName[0]<<memList[1].lastName[0]<<memList[2].lastName[0]<<"\n";

    /*
    for(int i=0;i< LIMIT;i++){
        cout<<memList[i].solved<<" "<<memList[i].stuNum<<" "<<memList[i].lastName<<"\n";
    }
    */
    
    return 0;
}