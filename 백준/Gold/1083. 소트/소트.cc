#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;

//n, m 인덱스의 값 교환
void switching(int n){
    int tmp = nums[n+1];
    nums[n+1] = nums[n];
    nums[n] = tmp;
}
//결과 출력
void printNums(){
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main() {
    int length;
    
    vector<int> sorted;
    int changeable=0;

    //입력받기
    cin>>length;
    nums.resize(length);

    for(int i=0;i<length;i++){
        cin>>nums[i];
    }
    cin>>changeable;

    //내림차순 정렬 답지
    sorted=nums;
    sort(sorted.begin(), sorted.end());
    reverse(sorted.begin(), sorted.end());

    //주어진 횟수만큼 sort
    while(changeable>0){
        //정렬된 상태라면 더 검사하지 않고 반복문 탈출
        if(nums==sorted){
            break;
        }

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==sorted[i]){//답지와 같은 위치라면 이상적 위치임
                continue;
            }
            
            //배열 중 최대값의 인덱스 찾기
            int idx = max_element(nums.begin()+i, nums.end())-nums.begin();
            //cout<<idx<<" idx is max"<<endl;
            //cout<<"but "<< changeable<<" imes left\n";

            //이 인덱스가 변경 가능 횟수보다 크다면
            if(changeable<idx){
                //검사 시작 인덱스 ~ 변경 가능 횟수 만큼의 인덱스 범위만 검사해서 범위 내의 최대값의 인덱스 찾기
                idx = max_element(nums.begin()+i, nums.begin()+i+changeable+1)-nums.begin();
                //cout<<idx<<" is less than changeable and max"<<endl;
            }

            //변경할 인덱스의 값이 검사 시작 인덱스 값보다 클 경우에만 변경
            if(nums[i]<nums[idx]){
                for(int j=idx-1;j>=i;j--){
                    //변경 가능할 경우에만 변경, 변경 시 changeable 1 차감
                    if(changeable>0){
                        switching(j);
                        changeable--;
                    }
                    //cout<<j<<", "<<idx<<endl;
                    
                }
            }
            
            //printNums();
        }
        //cout<<changeable<<" times left\n";
    }

    //결과 출력
    printNums();
    
    return 0;
}
