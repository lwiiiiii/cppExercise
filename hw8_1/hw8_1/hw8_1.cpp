
/*
파일명: hw8_1.cpp
작성자: 201632025 이혜지
작성일: 2018/05/08
내용: Animal 추상 클래스를 상속받는 Dog, Person 클래스를 정의하고
		이용하는 프로그램
*/
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Animal {
private:
	string name;
public:
	Animal(string name) : name(name){

	}
	string getName() {
		return name;
	}
	virtual void sound() = 0;
};

class Dog : public Animal {
public:
	Dog(string name) : Animal(name) {}
	virtual void sound() {
		cout << "멍멍" << ends;
	}
};

class Person : public Animal {
public:
	Person(string name) : Animal(name){}
	virtual void sound() {
		cout << "안녕" << ends;
	}
};

int main()
{
	cout << "hw8_1: 이혜지" << endl;

	Dog * dog = new Dog("진돌이");
	Person * man = new Person("홍길동");

	dog->sound();
	cout << dog->getName() << endl;
	man->sound();
	cout << man->getName() << endl;
	
}

