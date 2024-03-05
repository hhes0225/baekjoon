#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tCase;
    string a, b;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        cin>> a>>b;
        vector<int> distance;
        distance=vector<int>(a.size(), 0);

        for(int j=0;j<a.size();j++){
            if(a[j]<=b[j]){
                distance[j]=(b[j]-a[j]);
            }
            else{
                distance[j]=((b[j]+26)-a[j]);
            }
        }
        
        cout<<"Distances: ";
        for(int j=0;j<distance.size();j++){
            cout<<distance[j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}