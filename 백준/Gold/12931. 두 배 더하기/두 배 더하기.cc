#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    문제: 0으로 채워진 배열을 B 배열로 만든다
    풀이: B 배열을 0으로 만들어나가는 과정

    1st 배열 순회:
    arr[i]가 홀수이면 arr[i]--후 count++
    (배열에 있는 값 하나를 1 증가시킨다.)

    2nd 배열 순회:
    1st 순회로 인해 배열의 모든 값이 0이 될 수 있기 때문에
    배열의 모든 값이 0이 되면 continue

    3rd 배열 순회:
    배열 순회하며 arr[i]/=2 후,
    한 번에 count++;
    (배열에 있는 모든 값을 두 배 시킨다.)
    (이때, 1st, 2nd 배열 순회에 의해 
    배열의 모든 값은 전부 0이지 않으며, 0이 아니라면 짝수인 값임을
    보장받았음.
    따라서 /2 하더라도 최소 1이 되지 0이 되지는 않음)
    
*/

vector<int> arr;

int main() {
    int len;
    bool isAllZero=false;
    int count=0;
    
    cin>>len;

    arr.resize(len);

    for(int i=0;i<len;i++){
        cin>>arr[i];
    }

    while(!isAllZero){
        /*
             1st 배열 순회:
            arr[i]가 홀수이면 arr[i]--후 count++
            (배열에 있는 값 하나를 1 증가시킨다.)
        */
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                arr[i]--;
                count++;
            }
        }

        /*
            2nd 배열 순회:
            1st 순회로 인해 배열의 모든 값이 0이 될 수 있기 때문에
            배열의 모든 값이 0이 되면 continue
        */
        int checkZeros=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                checkZeros++;
            }
        }
        if(checkZeros==len){
            isAllZero=true;
            continue;
        }

        /*
            3rd 배열 순회:
            배열 순회하며 arr[i]/=2 후,
            한 번에 count++;
            
            (배열에 있는 모든 값을 두 배 시킨다.)
            
            (이때, 1st, 2nd 배열 순회에 의해 
            배열의 모든 값은 전부 0이지 않으며, 0이 아니라면 짝수인 값임을
            보장받았음.)
            따라서 /2 하더라도 최소 1이 되지 0이 되지는 않음
        */
        for(int i=0;i<arr.size();i++){
            arr[i]/=2;
        }
        count++;

    }

    cout<<count<<"\n";
    
    return 0;
}