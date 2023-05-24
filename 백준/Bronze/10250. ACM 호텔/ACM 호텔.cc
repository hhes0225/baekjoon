#include <iostream>
using namespace std;

int main(void) {
	int tCase;
	int totalFloor;
	int totalRoom;
	int customerOrder;
	int customerFloor=1;
	int customerRoom=1;

	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		customerFloor = 1;
		customerRoom = 1;
		cin >> totalFloor >> totalRoom >> customerOrder;

		customerFloor = customerOrder % totalFloor;
		if (customerFloor == 0)
			customerFloor = totalFloor;
		customerRoom = customerOrder / totalFloor + 1;
		if (customerFloor == totalFloor)
			customerRoom--;

		/*for (int i = 0; i < customerOrder; i++) {
			if (customerFloor + 1 > totalFloor) {
				customerFloor = 1;
				customerRoom++;
			}
			else {
				customerFloor++;
			}

			cout << i << ": " << customerFloor << "&" << customerRoom << endl;
		}*/

		//cout << "==" << endl;
		if(customerRoom<10)
			cout << customerFloor << "0" << customerRoom << "\n";
		else
			cout << customerFloor << customerRoom << "\n";
		//cout << "==" << endl;
	}




	return 0;
}