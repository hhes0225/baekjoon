#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> LCS;

int main() {
    string s1, s2;
    string pw="";
    
    cin>>s1>>s2;

    LCS.resize(s2.size()+1, vector<int>(s1.size()+1, 0));


    for(int i=1;i<s1.size()+1;i++){
        if(s2[0]==s1[i-1]){
            LCS[1][i]= LCS[0][i-1]+1;
        }
        else{
            LCS[1][i]=max(LCS[0][i-1], LCS[0][i]);
        }
    }

    for(int i=1;i<s2.size()+1;i++){
        if(s2[i-1]==s1[0]){
            LCS[i][1]= LCS[i-1][0]+1;
        }
        else{
            LCS[i][1]=max(LCS[i-1][0], LCS[i][0]);
        }
    }
    
    //LCS 구하기
    for(int i=1;i<s2.size()+1;i++){
        for(int j=1;j<s1.size()+1;j++){
            if(s2[i-1]==s1[j-1]){
                LCS[i][j]= LCS[i-1][j-1]+1;//
            }
            else{
                LCS[i][j]=max(LCS[i][j-1], LCS[i-1][j]);
            }
        }
    }

    int i=s2.size(), j=s1.size();
    //LCS[0].size==s1.size()+1
    
    while(i>0&&j>0){
        if(s2[i-1]==s1[j-1]){
            pw+=s1[j-1];//매칭되면 pw에 추가
            i--;j--;//대각선 이전으로 이동
        }
        else{//더 큰 값이 있는 방향으로 이동
            if(LCS[i-1][j]>=LCS[i][j-1]){
                i--;
            }
            else j--;
        }
    }

    reverse(pw.begin(), pw.end());

    /*
    for(auto i:LCS){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";*/

    cout<<pw<<"\n";
    
    return 0;
}