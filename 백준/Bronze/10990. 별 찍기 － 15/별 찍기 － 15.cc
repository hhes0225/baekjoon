 #include <iostream>
using namespace std;

int main() {
    int input;
    int previous=1;
    cin>>input;

    for(int i=0;i<input;i++){
        //공백
        for(int j=1;j<input-i;j++){
            cout<<" ";
        }

        cout<<"*";

        if(i!=0){
            //중간공백
            for(int j=0;j<previous;j++){
                cout<<" ";
            }

            cout<<"*";
            previous+=2;
        }

        cout<<"\n";
    }
    
    
    return 0;
}