/*
*파일이름 : hw11_1.cpp
*작성자 : 201632025 이혜지
*작성일 : 2018.05.16
*파일내용 : 연산자를 오버로딩하여 정수형 배열을 가지는
*			BoundCheckIntArray 객체 연산을 수행함
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;

public:
	BoundCheckIntArray(int len) :arrlen(len)
	{
		arr = new int[len];
	}

	BoundCheckIntArray(const BoundCheckIntArray &copy) { //복사 생성자
		arr = new int[copy.arrlen];

		for (int i = 0; i < copy.arrlen; ++i) {
			arr[i] = copy.arr[i];
		}

		arrlen = copy.arrlen;
	}

	int& operator[] (int idx)
	{
		if (idx<0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int operator[] (int idx) const
	{
		if (idx<0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}

	void operator=(const BoundCheckIntArray &ref) {
		if (arrlen < ref.arrlen) {
			cout << "값을 복사하려는 배열의 크기가 작습니다." << endl;
			exit(1);
		}
		else {
			for (int i = 0; i < ref.arrlen; ++i) {
				arr[i] = ref.arr[i];
			}
			arrlen = ref.arrlen;
		}
	}

	friend ostream & operator<<(ostream & out, const BoundCheckIntArray &ref);

	friend istream & operator>>(istream & in, const BoundCheckIntArray &ref);

	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

ostream & operator<<(ostream &out, const BoundCheckIntArray &ref) {
	for (int i = 0; i < ref.arrlen; ++i) {
		out << i << "번째 원소: " << ref.arr[i] << endl;
	}
	return out;
}

istream & operator>>(istream &in, const BoundCheckIntArray &ref) {
	for (int i = 0; i < ref.arrlen; ++i) {
		cout << i << "번째 원소: ";
		in >> ref.arr[i];
	}
	return in;
}
int main()
{
	cout << "hw11_1: 이혜지" << endl << endl;

	BoundCheckIntArray arr(5);

	for (int i = 0; i<5; i++)
		arr[i] = (i + 1) * 11;

	cout << "arr 출력" << endl; // cout 연산자 중복
	cout << arr << endl << endl;

	BoundCheckIntArray cpy1 = arr;    // 복사생성자
	cout << "cpy1 출력" << endl;
	cout << cpy1 << endl << endl;

	BoundCheckIntArray cpy2(3);
	cout << "cpy2 입력" << endl;
	cin >> cpy2;    // cin 연산자 중복
	cout << endl;

	cout << "cpy2 출력" << endl;
	cout << cpy2 << endl << endl;

	BoundCheckIntArray cpy3(5);
	cpy3 = cpy2;   // 대입 연산자 중복
	cout << "cpy3 출력" << endl;
	cout << cpy3 << endl << endl;

    return 0;
}

