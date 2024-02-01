// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    int tCase;
    int size;
    
    cin>>tCase;
    
    //testcase
    for(int i=0;i<tCase;i++){
        cin>>size;
        
        //print box square
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                if(j==0 || j==size-1||k==0||k==size-1){
                    printf("#");
                }
                else{
                    printf("J");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}