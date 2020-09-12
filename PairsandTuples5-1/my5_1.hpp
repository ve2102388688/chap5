#pragma once

#ifndef _CHAP5_1
#define _CHAP5_1

#include <utility>					// std::pair
#include <tuple>					// std::tuple
#include <string>

void f(std::pair<int, const char*>) {}
void g(std::pair<const int, std::string>) {}

void foo()
{
	std::pair<int, const char*> p(42, "hello");
	f(p);		// calls implicitly generated constructor
	g(p);		// calls template constuctor
}

class A {
public:
	A() {}
	A(A&);
};

class F00 {
public:
	F00(std::tuple<int, float>) {
		std::cout << "F00(std::tuple<int, float>)" << std::endl;
	}
	template <typename... Args>
	F00(Args... args) {
		std::cout << "F00(Args... args)" << std::endl;
	}
};


template <typename... Args>
void foo2(const std::tuple<Args...> t) {}


#endif // !_CHAP5_1


