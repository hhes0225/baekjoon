#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,w,l;
    cin>>n>>w>>l;

    queue<int> cars;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        cars.push(tmp);
    }
    
    vector<int> timeline;
    timeline.push_back(0);

    int prevStart=2;
    
    for(int i=0;i<w;i++){
        timeline.push_back(cars.front());
    }
    cars.pop();
    

    while(!cars.empty()){
        int carWeight=cars.front();
        cars.pop();

        for(int i=prevStart;i<timeline.size();i++){
            if(timeline[i]+carWeight<=l){
                prevStart=i;
                break;
            }
        }

        if(timeline[prevStart]+carWeight<=l){
            int dup=timeline.size()-prevStart;

            for(int i=0;i<dup;i++){
                timeline[i+prevStart]+=carWeight;
            }

            prevStart++;

            int left=w-dup;
            for(int i=0;i<left;i++){
                timeline.push_back(carWeight);
            }

        }
        else{
            
            prevStart=timeline.size()+1;
            for(int i=0;i<w;i++){
                timeline.push_back(carWeight);
            }
        }
    }    

    // for(auto i:timeline) cout<<i<<" ";
    // cout<<"\n";

    cout<<timeline.size()<<"\n";
    
    
    return 0;
}