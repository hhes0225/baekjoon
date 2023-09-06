#include <iostream>

using namespace std;

int main(void) {

   int tCase;

   int x, y;

   int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, axis = 0;

   cin >> tCase;

   for (int i = 0; i < tCase; i++) {

      cin >> x >> y;

      if (x > 0 && y > 0) {

         Q1++;

      }

      else if (x < 0 && y > 0) {

         Q2++;

      }

      else if (x < 0 && y < 0) {

         Q3++;

      }

      else if (x > 0 && y < 0) {

         Q4++;

      }

      else {

         axis++;

      }

   }

   cout << "Q1: " << Q1 << '\n';

   cout << "Q2: " << Q2 << '\n';

   cout << "Q3: " << Q3 << '\n';

   cout << "Q4: " << Q4 << '\n';

   cout << "AXIS: " << axis << '\n';

   return 0;

}