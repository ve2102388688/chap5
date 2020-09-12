#include "5_5.h"

void foo()
{
	using namespace std::rel_ops;		// 使用rel_ops，只需要定义==,<即可，下面的!=,>直接使用
	X x1, x2;
	if (x1 != x2) {

	}
	if (x1 > x2) {

	}
}