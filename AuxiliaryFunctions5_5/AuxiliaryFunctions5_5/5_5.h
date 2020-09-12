#pragma once

#include <utility>



class X
{
public:
	X() {};
	~X() {};
	bool operator== (const X& x) const;
	bool operator< (const X& x) const;

private:

};
