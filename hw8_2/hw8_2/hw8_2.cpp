/*
파일명: hw8_2.cpp
작성자: 201632025 이혜지
작성일: 2018/05/08
내용: 추상클래스 Animal, 이를 상속하는 Dog, Person 클래스를 정의하고 이용하는 프로그램
*/
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Animal {
public:
	string name;
	Animal(string name) : name(name) {}
	string getName() {
		return name;
	}
	virtual void sound() = 0;
	virtual void newYear() = 0;
	virtual void print() = 0;
};

class Dog : public Animal {
public:
	double speed;
	Dog(string name, double speed) : Animal(name), speed(speed){}
	virtual void newYear() {
		speed = speed + 5;
	}
	virtual void sound() {
		cout << "멍멍" << ends;
	}
	virtual void print() {
		cout << this->getName() << "  시속" << speed << "km" << endl;
	}
};

class Person : public Animal {
public:
	int age;
	Person(string name, int age) : Animal(name), age(age){}
	virtual void newYear() {
		age += 1;
	}
	virtual void sound() {
		cout << "안녕" << ends;
	}
	virtual void print() {
		cout << this->getName() << "  나이" << age << "세" << endl;
	}
};
int main()
{
	cout << "hw8_2: 이혜지" << endl;
	cout << endl;

	Animal * ani[4];
	ani[0] = new Dog("진돌이", 13.5);
	ani[1] = new Dog("진순이", 12.5);
	ani[2] = new Person("홍길동", 20);
	ani[3] = new Person("박길동", 25);

	for (int i = 0; i < 4; ++i) {
		ani[i]->print();
	}
	cout << endl;

	for (int i = 0; i < 4; ++i) {
		ani[i]->sound();
		cout << ani[i]->getName() << endl;
	}
	cout << endl;

	cout << "------1년 후------" << endl;

	for (int i = 0; i < 4; ++i) {
		ani[i]->newYear();
	}

	for (int i = 0; i < 4; ++i) {
		ani[i]->print();
	}
	cout << endl;

	cout << "------2년 후------" << endl;

	for (int i = 0; i < 4; ++i) {
		ani[i]->newYear();
	}

	for (int i = 0; i < 4; ++i) {
		ani[i]->print();
	}
}

