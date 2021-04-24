#include "utils.h"
#include <random>

bool utils::random_percentage(double pct)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0, 1); // <- random number between 0-1
	// I've decided to split all the variables up into their own individual variable. I've done this solely for debugging purposes.
	auto random_num = dist(rng);
	bool above_pct = (random_num > pct);

	return above_pct;
}

void utils::print_line(int len, char ch) {
	for (int i = 0; i < len; i++)
		printf("%c", ch);
}

