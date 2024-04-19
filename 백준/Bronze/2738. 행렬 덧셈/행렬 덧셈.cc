#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> a,b,c;
    int n, m;

    cin>>n>>m;

    a.resize(n);
    b.resize(n);
    c.resize(n);

    for(int i=0;i<n;i++){
        a[i].resize(m);
        b[i].resize(m);
        c[i].resize(m);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}