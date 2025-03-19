#include <bits/stdc++.h>
using namespace std;
const int Block=1;
const int Water=2;

vector<vector<int>> world;
vector<int> blocks;
int main() {
    int h, w;
    cin>>h>>w;

    world.assign(h, vector<int>(w, 0));
    blocks.resize(w);

    for(auto &b:blocks){
        cin>>b;
    }
    
    for(int i=h-1;i>=0;i--){
        for(int j=0;j<w;j++){
            if(blocks[j]!=0){
                world[i][j]=Block;
                blocks[j]--;
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(world[i][j]==1){
                int end=-1;
                for(int k=j+1;k<w;k++){
                    if(world[i][k]==Block){
                        end=k;
                        break;
                    } 
                }

                if(end==-1) continue;
                else{
                    for(int k=j+1;k<end;k++){
                        world[i][k]=Water;
                    }
                }
            }
        }

        /*
        for(auto i:world){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        cout<<"------------------\n";
        */
    }

    int waterArea=0;
    for(auto i:world){
        for(auto j:i){
            if(j==Water) waterArea++;
        }
    }

    cout<<waterArea<<"\n";
    
    return 0;
}