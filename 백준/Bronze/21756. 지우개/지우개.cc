#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    queue<int> nums;

    for(int i=1;i<=n;i++){
        nums.push(i);
    }

    //for(int i=1;i<=n;i++){
    //    cout<<nums.front()<<endl;
    //}

    while(1){
        if(nums.size()==1){
            break;
        }

        int numSize = nums.size();
        for(int i=1;i<=numSize;i++){
            if(i%2==1){
                nums.pop();
            }
            else{
                int tmp = nums.front();
                nums.pop();
                nums.push(tmp);
            }
        }
    }

    cout<<nums.front()<<"\n";
    
    return 0;
}