#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tCase;
    int taesu;
    int listLimit;
    vector<pair<int, int>> ranking;

    cin>>tCase>>taesu>>listLimit;
    
    int tmp;
    cin>>tmp;
    ranking.push_back({tmp, 1});

    for(int i=1;i<tCase;i++){
        cin>>tmp;
        if(tmp==ranking[i-1].first){
            ranking.push_back({tmp, ranking[i-1].second});
        }
        else{
            ranking.push_back({tmp, i+1});
        }
    }

    /*for(int i=0;i<ranking.size();i++){
        cout<<ranking[i].first<<" "<<ranking[i].second<<endl;
    }*/
    
    int taesuRank=1;
    for(int i=0;i<ranking.size();i++){
        if(taesu>=ranking[i].first){
            //cout<<"bigger or same\n";
            taesuRank=ranking[i].second;
            break;
        }
        else{
            taesuRank++;
        }
    }
    
    //cout<<taesuRank<<"\n";
    
    //만약 태수 순위가 마지막 순위와 점수가 같은데 순위 리미트에 사람이 꽉 찼다면
    if(taesu==ranking[ranking.size()-1].first && ranking.size()>=listLimit){
        taesuRank=-1;
    } 
    
    //만약 태수 점수가 순위권이 아니라면
    if(taesuRank>listLimit){
        taesuRank=-1;
    }
    /*if(taesu<ranking[ranking.size()-1].first){
        if(ranking.size()>=listLimit){
            taesuRank=-1;
        }
        else{
            taesuRank=ranking[ranking.size()-1].second+1;
        }
    }*/
    
    cout<<taesuRank<<endl;

    return 0;
}