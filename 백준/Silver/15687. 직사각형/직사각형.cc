/*
	boj15687
	직사각형의 정보를 저장할 클래스 Rectangle을 구현하시오.

	C++14, C++17
	클래스 이름: Rectangle

	생성자
	Rectangle(width, height): 직사각형의 가로 길이를 width, 세로 길이를 height 설정한다. 
		width는 1,000보다 작거나 같은 자연수, height는 2,000보다 작거나 같은 자연수이다.

	멤버 변수
	int width: 직사각형의 가로 길이
	int height: 직사각형의 세로 길이

	멤버 함수
	int get_width() const: 직사각형의 가로 길이를 리턴한다.
	int get_height() const: 직사각형의 세로 길이를 리턴한다.
	void set_width(int width): 직사각형의 가로 길이를 width로 변경한다. 만약, width가 0보다 작거나 같거나, 1,000보다 크면 변경하지 않는다.
	void set_height(int height): 직사각형의 세로 길이를 height로 변경한다. 만약, height가 0보다 작거나 같거나, 2,000보다 크면 변경하지 않는다.
	int area() const: 직사각형의 넓이를 리턴한다.
	int perimeter() const: 직사각형의 둘레 길이를 리턴한다.
	bool is_square() const: 정사각형이면 true, 아니면 false를 리턴한다.
*/

class Rectangle {
private:
	int width;
	int height;

public:
	Rectangle(int width, int height) {
		this->width = width;
		this->height = height;
	}

	int get_width() const;//const: 쓰기 금지. 자료 조회만 가능한 메소드
	int get_height() const;

	void set_width(int width);
	void set_height(int height);

	int area() const;
	int perimeter() const;
	bool is_square() const;
};

int Rectangle :: get_width() const {
	return width;
}

int Rectangle::get_height() const {
	return height;
}

void Rectangle::set_width(int width) {
	if(width>0 && width<=1000)
		this->width = width;
}
void Rectangle::set_height(int height) {
	if (height > 0 && height <= 2000)
		this->height = height;
}

int Rectangle::area() const {
	return width * height;
}
int Rectangle::perimeter() const {
	return (2 * width) + (2 * height);
}
bool Rectangle::is_square() const {
	if (width == height)
		return true;
	else
		return false;
}
