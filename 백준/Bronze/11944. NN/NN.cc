#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;

    cin>>n>>m;

    //n을 n번 출력한 것의 길이가 m보다 크면 m길이만큼만 출력
    if(to_string(n).size()*n>m){
        string tmp;
        if(m%to_string(n).size()!=0){
            for(int i=0;i<m/to_string(n).size()+1;i++){
                tmp+=to_string(n);
            }

            for(int i=0;i<m;i++){
                cout<<tmp[i];
            }
        }
        else{
            for(int i=0;i<m/to_string(n).size();i++){
                cout<<n;
            }
        }
        
    }
    else{//아닐 경우 n을 n번 출력
        for(int i=0;i<n;i++){
            cout<<n;
        }
    }

    cout<<endl;

    return 0;
}