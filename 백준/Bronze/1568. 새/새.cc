#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int birds;
    int count=0;
    int song=1;

    cin>>birds;

    while(birds>0){
        count++;
        if(birds<song){
            song=1;
        }
        birds-=song;
        song++;
    }

    cout<<count<<"\n";

    return 0;
}