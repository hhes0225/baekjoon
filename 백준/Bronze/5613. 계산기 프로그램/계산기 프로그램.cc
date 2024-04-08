 #include <iostream>
using namespace std;

int main() {
    int operand;
    char opChar;
    int result=0;
    int cnt=0;

    //첫번째는 바로 result에 담는다.
    cin>>operand;
    cnt++;
    result=operand;
    
    while(1){
        if(cnt%2==1){//연산자
            cin>>opChar;

            if(opChar=='='){
                break;
            }
        }
        else{//피연산자
            cin>>operand;

            switch (opChar) {
                case '+': result+=operand; break;
                case '-': result-=operand; break;
                case '*': result*=operand; break;
                case '/': result/=operand; break;
            }
        }

        cnt++;
    }

    cout<<result<<"\n";
    
    
    
    return 0;
}