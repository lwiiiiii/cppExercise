/*
*	파일이름 : hw10_3.cpp
	작성자 : 201632025 이혜지
	작성일 : 2018.05.15
	파일내용 : 연산자를 오버로딩하여 time클래스 객체 연산
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Time {
private:
	int hours;
	int minutes;

public:
	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m) {
		hours = h;
		minutes = m;
	}
	void adjust() {
		if (minutes >= 60) {
			hours += (minutes / 60);
			minutes = (minutes % 60);
		}
		if (hours > 24) {
			hours = (hours % 24);
		}
	}
	void operator++() {
		minutes += 1;
		this->adjust();
	}
	void operator++(int) {
		++minutes;
		this->adjust();
	}
	void operator+=(int t) {
		minutes += t;
		this->adjust();
	}
	friend ostream & operator<<(ostream & out, const Time &ref);
};

ostream & operator<<(ostream & out, const Time &ref) {
	if (ref.minutes > 9 && ref.hours > 9)
		out << ref.hours << " : " << ref.minutes << "\n";
	else if(ref.minutes < 10 && ref.hours > 9)
		out << ref.hours << " : 0" << ref.minutes << "\n";
	else if (ref.minutes > 9 && ref.hours < 10)
		out << "0" << ref.hours << " : " << ref.minutes << "\n";
	else
		out << "0" << ref.hours << " : 0" << ref.minutes << "\n";
	return out;
}

int main()
{
	cout << "hw10_3: 이혜지 \n" << endl;

	Time t1(10, 59);

	cout << t1;
	++t1;
	cout << t1;
	t1++;
	cout << t1;
	t1 += 125;
	cout << t1;

    return 0;
}

