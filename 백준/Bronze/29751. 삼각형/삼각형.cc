#include <iostream>

using namespace std;

/*
	boj29751
	양의 정수 W, H가 주어진다. 
	밑변의 길이가 W이고, 높이가 H인 삼각형의 넓이를 구하시오.

	삼각형 넓이 = 
	밑변 * 높이 / 2
*/

int main(void) {
	double width, height;
	double triangle;

	cin >> width >> height;

	triangle = (width * height) / 2;

	printf("%.1lf\n", triangle);

	return 0;
}