#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <random>
#include <conio.h>
#include "utils.h"
struct data_infection_t {
	float min, max;
};
struct data_social_t {
	ULONG min, max;
};


struct person_t {
	person_t(bool infected, ULONG id, data_infection_t infection_data) {
		utils u;
		if (infected)
			this->infected = true;
		this->id = id;
		this->infection_risk = u.random_number<float>(infection_data.min, infection_data.max);
	}

	bool can_infect() {
		utils u;
		srand(u.random_number<int>(0, 10000000)); // This can be improved. Using srand is never really ideal from my past experience.
		return rand() % 100 < (this->infection_risk * 100);
	}

	bool infected = false;
	int weeks_infected = 0;
	ULONG id = 0;
	float infection_risk = 0.0;
};

class simulation {
public:
	std::vector<person_t>populate_simulation(int totalSize, int startInfected, data_infection_t infection_data);
	void update_infected(std::vector<person_t>& people);
	void socialize(std::vector<person_t>& people, data_social_t social_data);
};