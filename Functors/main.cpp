// main.cpp
#include <iostream>
#include <functional> // хранит описание функторов для программ

// функторы - классы объекты, которых можно использовать вместо функций

// устройство памяти
// 0 - pointer
// system-memory
// program-memory
// bss/brs - одна хранит инициализированные другая не инициализированные переменные
// HEAP
// STACK
// program-args - аргументы программы


int Summ(int a, int b) {
	return a + b;
}

int Multiply(int a, int b) {
	return a * b;
}

using		FunctionName = int (* )(int, int); // переопределение типа данных функции type aliacing

typedef		int(*NewName)(int, int); // переопределение типа данных функции type definition

void PrintOperation(int Jane, int Jacob, FunctionName Alg) {
	std::cout << "Our operation take params:\n" <<
		"\tJane - " << Jane << "\n" <<
		"\tJacob - " << Jacob << '\n' <<
		"With result " << Alg(Jane, Jacob) << '\n';
}


class Functor {
public:
	Functor(int val) :num(val) {}
	void operator()(int& val) {
		val = num;
	}

private:
	int num;
};


void OperateArray(int* arr, int length, std::function<void(int&)> alg) {
	for (int i = 0; i < length; ++i) {
		alg(arr[i]);
	}
}

void F02(int& j) {
	j = 9;
}


int main() {

	int i;
	
	int a{ 5 }, b{ 9 };

	std::cout << Summ << " with " << a << " " << b << " args - " << Summ(a,b) << '\n';
	std::cout << Multiply << " with " << a << " " << b << " args - " << Multiply(a, b) << '\n';

	auto pFunc = Summ;

	int (*pFunc2)(int, int); // указатель на функцию синтаксис С
	pFunc = Summ;
	pFunc2 = Multiply;

	PrintOperation(2, 4, Multiply);
	PrintOperation(a, b, pFunc);
	PrintOperation(a, b, pFunc2);


	const int size = 6;
	int* arr = new int[size] {};
	OperateArray(arr, size, F02);

	std::cout << '\n';
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}

	std::cout << "\n\n";

	Functor funtic(4);


	OperateArray(arr, size, funtic);
	std::cout << '\n';
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}

	std::cout << "\n\n";



	return 0;
}