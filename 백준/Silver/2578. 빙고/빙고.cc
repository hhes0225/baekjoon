#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> bingo;
int row=0, col=0, diag=0;

void checkBoard(int num){
    for(int i=0;i<bingo.size();i++){
        for(int j=0;j<bingo.size();j++){
            if(bingo[i][j]==num){
                bingo[i][j]=-1;
                return;
            }
        }
    }
}

void checkBingo(){
    //초기화
    row=0;
    col=0;
    diag=0;
    
    //가로빙고
    for(int i=0;i<bingo.size();i++){
        int tmp=1;
        for(int j=1;j<bingo.size();j++){
            if(bingo[i][j-1]==bingo[i][j]){
                tmp++;
            }
        }

        if(tmp==5){
            //cout<<"가로빙고!!"<<endl;
            tmp=0;
            row++;
        }
    }

    //세로 빙고
    for(int i=0;i<bingo.size();i++){
        int tmp=1;
        for(int j=1;j<bingo.size();j++){
            if(bingo[j-1][i]==bingo[j][i]){
                tmp++;
            }
        }

        if(tmp==5){
            //cout<<"세로빙고!!"<<endl;
            tmp=0;
            col++;
        }
    }

    //왼쪽위-오른쪽 아래 대각선 빙고
    int tmp=1;
    for(int i=1;i<bingo.size();i++){
        if(bingo[i-1][i-1]==bingo[i][i]){
                tmp++;
        }

        if(tmp==5){
            //cout<<"대각빙고!!"<<endl;
            tmp=0;
            diag++;
        }
    }
    
    //오른쪽위-왼쪽 아래 대각선 빙고
    tmp=1;
    for(int i=1;i<bingo.size();i++){
        //cout<<i<<" "<<bingo.size()-i-1<<": "<<bingo[i][bingo.size()-1-i]<<endl;
        if(bingo[i-1][bingo.size()-i]==bingo[i][bingo.size()-i-1]){
                tmp++;
        }

        if(tmp==5){
            //cout<<"대각빙고!!"<<endl;
            tmp=0;
            diag++;
        }
    }
    
    //cout<<row<<" "<<col<<" "<<diag<<endl;
}

int main(void){

    
    bingo.resize(5);

    for(int i=0;i<bingo.size();i++){
        bingo[i].resize(5);
    }

    for(int i=0;i<bingo.size();i++){
        for(int j=0;j<bingo.size();j++){
            cin>>bingo[i][j];
        }
    }
    int input;
    int idx=0;
    for(int i=0;i<bingo.size();i++){
        for(int j=0;j<bingo.size();j++){
            idx++;
            cin>>input;

            checkBoard(input);//숫자가 있는 칸 X표시
            //bingo 여부 확인
            checkBingo();
            
            //cout<<row<<" "<<col<<" "<<diag<<endl;
            if(row+col+diag>=3){
                //cout<<"통과욥"<<endl;
                break;
            }
        }
        if(row+col+diag>=3){
                break;
        }
    }

    cout<<idx<<"\n";
    

    return 0;
}