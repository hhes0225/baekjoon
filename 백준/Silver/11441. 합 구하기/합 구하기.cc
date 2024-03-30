#include <iostream>
#include <vector>

using namespace std;

/*
    접근방법:
    누적합을 이중포문으로 구하면 시간초과됨.
    따라서 배열에 10 20 30 40 50 같은 input을 바로 넣지 말고
    배열에 이전값과 인풋값을 더한 누적합을 넣는다.
    10 30 60 100 150 이렇게.
    그리고 from, to를 받고
    input[to-1]-input[from-2]를 하면 from~to까지의 누적합이 된다.
    이미 input[to-1]은 input[0]~input[to-1]까지의 값이 더해진 값이므로
    예를 들어. 2~4는
    input[3]-input[0] = 100 - 10 = 90 이 된다.
    이렇게 하면 반복문을 하나 줄일 수 있다.
*/

int main(void){
    int inputSize, tCase;
    vector<int> input;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>inputSize;
    input.resize(inputSize);

    for(int i=0;i<inputSize;i++){
        cin>>input[i];
        if(i==0){
            continue;
        }
        input[i]+=input[i-1];
        
    }

    /*for(int i=0;i<inputSize;i++){
        cout<<input[i]<<endl;
    }*/

    cin>>tCase;
    for(int i=0;i<tCase;i++){
        int from, to;
        cin>>from>>to;

        if(from==1){
            cout<<input[to-1]<<"\n";
        }
        else{
            cout<<input[to-1]-input[from-2]<<"\n";
        }

        //cout<<tmpSum<<"\n";
    }
    
    return 0;
}