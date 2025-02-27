#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;

vector<string> dna;

int main() {
    int n, m;
    cin>>n>>m;

    dna.resize(n);

    for(auto&d:dna){
        cin>>d;
    }

    /*
    for(auto d:dna){
        cout<<d<<"\n";
    }
    cout<<"\n";*/

    string minDistDna="";
    int minDistance=0;

    //문자열 구하기
    //세로드립으로 보고 가장 빈도수 높은 문자 채택해서 문자열 구성
    for(int i=0;i<m;i++){
        unordered_map<char, int> freq;
        vector<pair<char, int>> freqVec;

        for(int j=0;j<n;j++){
            freq[dna[j][i]]++;
        }

        for(auto it=freq.begin();it!=freq.end();it++){
            freqVec.push_back(*it);
        }

        sort(freqVec.begin(), freqVec.end(), [](pair<char, int> a, pair<char, int> b){
            if(a.second!=b.second)
                return a.second>b.second;
            else{
                return a.first<b.first;
            }
        });

        /*
        for(auto f:freqVec){
            cout<<f.first<<" "<<f.second<<"\n";
        }
        cout<<"\n";
        */
    
        minDistDna+=freqVec[0].first;
    }

    //해당 문자열로 해밍 거리 구하기
    for(auto d:dna){
        int tmpDist=0;
        for(int i=0;i<m;i++) {
            if(minDistDna[i]!=d[i]){
                tmpDist++;
            }
        }

        minDistance+=tmpDist;
    }

    cout<<minDistDna<<"\n";
    cout<<minDistance<<"\n";
    
    return 0;
}