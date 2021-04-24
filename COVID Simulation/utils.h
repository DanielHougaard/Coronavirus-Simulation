#pragma once
#include <random>
class utils
{
public:
	template<class T>
	inline T random_number(T min, T max) { // Please, never pass bad types to this.
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_real_distribution<> dist6(min, max); // Generate random number between min and max.

		return (T)dist6(rng);
	}

	bool random_percentage(double pct);
	void print_line(int len, char ch);
};

