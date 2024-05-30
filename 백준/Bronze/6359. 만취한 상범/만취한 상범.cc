#include <iostream>
#include <vector>
using namespace std;

vector<bool> isRoomOpen;

void drunk(int rooms){

    for(int i=1;i<=rooms;i++){
        for(int j=i;j<=rooms;j+=i){
            if(isRoomOpen[j]==true){
                isRoomOpen[j]=false;
            }
            else{
                isRoomOpen[j]=true;
            }
        }
    }
}

int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int rooms;
        int open=0;
        cin>>rooms;
        
        isRoomOpen.clear();
        isRoomOpen.resize(rooms+1);

        drunk(rooms);

        for(int j=0;j<isRoomOpen.size();j++){
            if(isRoomOpen[j]==true){
                open++;
            }
        }

        cout<<open<<"\n";
    }
    
    return 0;
}