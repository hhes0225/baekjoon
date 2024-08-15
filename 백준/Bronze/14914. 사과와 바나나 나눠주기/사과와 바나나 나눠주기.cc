#include <iostream>
#include <vector>
using namespace std;

int main() {
    int apple, banana;
    vector<int> gcds;

    cin>>apple>>banana;
    int until = min(apple, banana);
    
    for(int i=1;i<=until;i++){
        if(apple%i==0 && banana%i==0){
            gcds.push_back(i);
        }
    }


    for(int i=0;i<gcds.size();i++){
        cout<<gcds[i]<<" "<<apple/gcds[i]<<" "<<banana/gcds[i]<<"\n";
    }
    
    return 0;
}