#include <iostream>
#include <complex>			// std::complex
#include <tuple>			// std::tuple
#include <vector>			// std::vector
//#include <utility>
#include "my5_1.hpp"


typedef std::pair<int, float> IntFloatPair;

std::tuple<int, int, int> f2() {
	return { 1,1,2 };
}




int main()
{
	IntFloatPair p(42, 3.14);											// 创建一个pait

	std::cout << std::get<0>(p) << std::endl;							// 访问第一个元素
	std::cout << std::get<1>(p) << std::endl;							// 访问第二个元素
	std::cout << std::tuple_size<IntFloatPair>::value << std::endl;		// 元素个数
	std::tuple_element<0, IntFloatPair>::type first = std::get<0>(p);	// 前面代表类型，比如int

	std::cout << first << std::endl;


	// 
	{
		std::cout << "************section 2*************" << std::endl;
		std::pair<int, float> p;					// 基础类型会默认初始化
		std::cout << std::get<0>(p) << std::endl;							// 访问第一个元素
		std::cout << std::get<1>(p) << std::endl;							// 访问第二个元素

		std::pair<A, int> p2;
	}

	// 
	// 逐块式构造
	{
		std::cout << "************section 3*************" << std::endl;
		std::tuple<int, float> t(1, 2.22);				// 创建一个tuple
		std::pair<int, F00> p1(42, t);					// 直接将上面的t构造

		// 通过传递元素值，这里传入的参数化都必须是tuple，一定要使用第一个参数
		std::pair<int, F00> p2(std::piecewise_construct, std::make_tuple(42), t);
		//std::pair<int, F00> p2(std::piecewise_construct, 42, t);		// ERROR
	}

	// make_pair
	{
		f({ 42, "empty" });			// std::pair
		g({ 42, "chair" });

		std::string s("1"), s2("2");
		auto p = std::make_pair(std::move(s), std::move(s2));
		// 注意: move已经做了剪切工作, 原始的s s2不再有效
		std::cout << p.first << std::endl;
		std::cout << p.second << std::endl;

		// 
		int i = 0;
		auto p1 = std::make_pair(std::ref(i), std::ref(i));		// 形成i的ref引用
		++p1.first;
		++p1.second;
		std::cout << "i: " << i << std::endl;					// i: 2

		// 使用tie来访问元素
		std::pair<char, char> p3 = std::make_pair('x', 'y');
		char c;
		std::tie(std::ignore, c) = p3;						// 忽略第一个，取第二个值
		std::cout << "c: " << c << std::endl;

	}

	// tuple
	{
		std::cout << "************ tuple *************" << std::endl;
		std::tuple<std::string, int, int, std::complex<double>> t;  //默认初始化！！！
		std::cout << std::get<0>(t) << std::endl;
		std::cout << std::get<1>(t) << std::endl;
		std::cout << std::get<2>(t) << std::endl;
		std::cout << std::get<3>(t) << std::endl;


		std::tuple<int, float, std::string> t1(41, 6.2, "nico");
		auto t2 = std::make_tuple(22, 44, "nico");
		std::get<1>(t1) = std::get<1>(t2);				// 赋值操作
		std::cout << "std::get<1>(t1): " << std::get<1>(t1) << std::endl;

		if (t1 < t2) {	// t2被提升到t1
			t1 = t2;
		}

		std::string s;
		std::tuple<std::string&> t3(s);
		std::get<0>(t3) = "hello";			// tuple可以传入引用，这时s的值将会改变
		std::cout << s << std::endl;

		//int i;
		//std::get<i>(t3);					// ERROR 不能为变量

		// 使用make_tuple创建一个引用的tuple
		std::string s1;
		auto t4 = std::make_tuple(std::ref(s1));
		std::get<0>(t4) = "hello";			// tuple可以传入引用，这时s的值将会改变
		std::cout << s1 << std::endl;
	}

	{
		std::tuple<int, float, std::string> t(77, 1.1, "more light");
		std::tuple<int, double> t2(77, 1.1);
		std::tuple<int, double> t3{ 77, 1.1 };
		std::tuple<int, double> t4 = { 77, 1.1 };
		int i;
		float f;
		std::string s;
		//std::make_tuple(std::ref(i), std::ref(f), std::ref(s)) = t;	 // 直接对上面的三个变量赋值0
		//std::cout << i << '\t' << f  << '\t' << s << std::endl;
		// 与此同时，这里使用tie也可以完成上面的操作, 使用std::ingore忽略提取某些元素
		std::tie(i, f, s) = t;
		std::cout << i << '\t' << f  << '\t' << s << std::endl;

		std::vector<std::tuple<int, float>> v{ {1,1.0}, {2,2.0} };
		std::cout << std::get<0>(f2()) << std::endl;
		std::cout << std::get<1>(f2()) << std::endl;
		std::cout << std::get<2>(f2()) << std::endl;

		//foo2(42);
		foo2(std::make_tuple(42));

		int n;
		auto tt = std::tuple_cat(t, std::tie(n));		// 串接
	}


	return 0;
}

