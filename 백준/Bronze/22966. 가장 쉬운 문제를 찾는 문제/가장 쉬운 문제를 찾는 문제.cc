#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second<b.second;
}

int main() {
    int problemNum;
    vector<pair<string, int>> problems;

    cin>>problemNum;

    for(int i=0;i<problemNum;i++){
        string title;
        int num;
        cin>>title>>num;

        problems.push_back({title, num});
    }

    sort(problems.begin(), problems.end(), compare);

    cout<<problems[0].first<<endl;
    
    return 0;
}