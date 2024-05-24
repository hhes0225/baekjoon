#include <iostream>
#include <vector>
using namespace std;

int main() {
    int stuNum, endTime;
    vector<int> interval;
    int firework=0;
    
    cin>>stuNum>>endTime;

    for(int i=0;i<stuNum;i++){
        int tmp;
        cin>>tmp;
        interval.push_back(tmp);
    }

    for(int i=1;i<=endTime;i++){
        for(int j=0;j<interval.size();j++){
            if(i%interval[j]==0){
                firework++;
                break;
            }
        }
    }

    cout<<firework<<"\n";
    
    return 0;
}