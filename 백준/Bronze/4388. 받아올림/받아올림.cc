#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    

    while(1){
        int up=0;
        cin>>a>>b;

        if(a=="0"&&b=="0"){
            break;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string longer, shorter;

        if(a.size()>b.size()){
            longer=a;
            shorter=b;
        }
        else{
            longer=b;
            shorter=a;
        }
        
        for(int i=0;i<shorter.size();i++){
            if(longer[i]-'0'+shorter[i]-'0'>=10){
                longer[i+1]++;
                up++;
            }
        }

        for(int i=shorter.size();i<longer.size();i++){
            if(longer[i]-'0'>=10){
                if(i!=longer.size()-1)
                    longer[i+1]++;
                up++;
            }
            
        }

        cout<<up<<"\n";
    }

    return 0;
}