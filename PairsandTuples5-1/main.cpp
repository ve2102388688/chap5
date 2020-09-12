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
	IntFloatPair p(42, 3.14);											// ����һ��pait

	std::cout << std::get<0>(p) << std::endl;							// ���ʵ�һ��Ԫ��
	std::cout << std::get<1>(p) << std::endl;							// ���ʵڶ���Ԫ��
	std::cout << std::tuple_size<IntFloatPair>::value << std::endl;		// Ԫ�ظ���
	std::tuple_element<0, IntFloatPair>::type first = std::get<0>(p);	// ǰ��������ͣ�����int

	std::cout << first << std::endl;


	// 
	{
		std::cout << "************section 2*************" << std::endl;
		std::pair<int, float> p;					// �������ͻ�Ĭ�ϳ�ʼ��
		std::cout << std::get<0>(p) << std::endl;							// ���ʵ�һ��Ԫ��
		std::cout << std::get<1>(p) << std::endl;							// ���ʵڶ���Ԫ��

		std::pair<A, int> p2;
	}

	// 
	// ���ʽ����
	{
		std::cout << "************section 3*************" << std::endl;
		std::tuple<int, float> t(1, 2.22);				// ����һ��tuple
		std::pair<int, F00> p1(42, t);					// ֱ�ӽ������t����

		// ͨ������Ԫ��ֵ�����ﴫ��Ĳ�������������tuple��һ��Ҫʹ�õ�һ������
		std::pair<int, F00> p2(std::piecewise_construct, std::make_tuple(42), t);
		//std::pair<int, F00> p2(std::piecewise_construct, 42, t);		// ERROR
	}

	// make_pair
	{
		f({ 42, "empty" });			// std::pair
		g({ 42, "chair" });

		std::string s("1"), s2("2");
		auto p = std::make_pair(std::move(s), std::move(s2));
		// ע��: move�Ѿ����˼��й���, ԭʼ��s s2������Ч
		std::cout << p.first << std::endl;
		std::cout << p.second << std::endl;

		// 
		int i = 0;
		auto p1 = std::make_pair(std::ref(i), std::ref(i));		// �γ�i��ref����
		++p1.first;
		++p1.second;
		std::cout << "i: " << i << std::endl;					// i: 2

		// ʹ��tie������Ԫ��
		std::pair<char, char> p3 = std::make_pair('x', 'y');
		char c;
		std::tie(std::ignore, c) = p3;						// ���Ե�һ����ȡ�ڶ���ֵ
		std::cout << "c: " << c << std::endl;

	}

	// tuple
	{
		std::cout << "************ tuple *************" << std::endl;
		std::tuple<std::string, int, int, std::complex<double>> t;  //Ĭ�ϳ�ʼ��������
		std::cout << std::get<0>(t) << std::endl;
		std::cout << std::get<1>(t) << std::endl;
		std::cout << std::get<2>(t) << std::endl;
		std::cout << std::get<3>(t) << std::endl;


		std::tuple<int, float, std::string> t1(41, 6.2, "nico");
		auto t2 = std::make_tuple(22, 44, "nico");
		std::get<1>(t1) = std::get<1>(t2);				// ��ֵ����
		std::cout << "std::get<1>(t1): " << std::get<1>(t1) << std::endl;

		if (t1 < t2) {	// t2��������t1
			t1 = t2;
		}

		std::string s;
		std::tuple<std::string&> t3(s);
		std::get<0>(t3) = "hello";			// tuple���Դ������ã���ʱs��ֵ����ı�
		std::cout << s << std::endl;

		//int i;
		//std::get<i>(t3);					// ERROR ����Ϊ����

		// ʹ��make_tuple����һ�����õ�tuple
		std::string s1;
		auto t4 = std::make_tuple(std::ref(s1));
		std::get<0>(t4) = "hello";			// tuple���Դ������ã���ʱs��ֵ����ı�
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
		//std::make_tuple(std::ref(i), std::ref(f), std::ref(s)) = t;	 // ֱ�Ӷ����������������ֵ0
		//std::cout << i << '\t' << f  << '\t' << s << std::endl;
		// ���ͬʱ������ʹ��tieҲ�����������Ĳ���, ʹ��std::ingore������ȡĳЩԪ��
		std::tie(i, f, s) = t;
		std::cout << i << '\t' << f  << '\t' << s << std::endl;

		std::vector<std::tuple<int, float>> v{ {1,1.0}, {2,2.0} };
		std::cout << std::get<0>(f2()) << std::endl;
		std::cout << std::get<1>(f2()) << std::endl;
		std::cout << std::get<2>(f2()) << std::endl;

		//foo2(42);
		foo2(std::make_tuple(42));

		int n;
		auto tt = std::tuple_cat(t, std::tie(n));		// ����
	}


	return 0;
}

