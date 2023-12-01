#include <iostream>
#include <string>

using namespace std;

/*
   은민이는 4와 7을 좋아하고, 나머지 숫자는 싫어한다. 금민수는 어떤 수가 4와 7로만 이루어진 수를 말한다.

   N이 주어졌을 때, N보다 작거나 같은 금민수 중 가장 큰 것을 출력하는 프로그램을 작성하시오.
*/

int main(void) {
   int n;
   cin >> n;
   int maxResult=4;

   for (int i = 1; i <= n; i++) {
      string strN = to_string(i);
      bool isResult = true;

      for (int j = 0; j < strN.size(); j++) {
         if (strN[j] != '4' && strN[j] != '7'){
            isResult = false;
            break;
         }
      }

      if (isResult){
         //cout << "pass: " << i << endl;
         maxResult = i;
      }
   }

   cout << maxResult << endl;
   

   return 0;
}