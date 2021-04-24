#include "simulation.h"
#include "utils.h"
#include "log.h"

std::vector<person_t>simulation::populate_simulation(int total_population, int start_infected, data_infection_t infection_data) { // Initalize the simulation
	std::vector<person_t> tmp_people;
	ULONG infected_count = 0;
	for (int i = 0; i < total_population; i++) {
		bool infected = false;
		if (infected_count < start_infected) {
			infected = true; // 50% chance of being infected.
			infected_count++;
		}
		person_t person(infected, i, infection_data);
		tmp_people.push_back(person);
	}
	stats::initial_population = total_population;
	return tmp_people;
}

void simulation::socialize(std::vector<person_t>& people, data_social_t social_data) {
	utils u;
	int weeklyInfected = 0;
	for (auto& person : people) {
		int people_met = 0;
		int people_threshold = u.random_number<int>(social_data.min, social_data.max);
		while (people_met < people_threshold) {
			person_t random_person = people[u.random_number<ULONG>(0, people.size() - 1)];
			if (!person.infected && random_person.infected && random_person.id != person.id) {
				if (person.can_infect()) {
					person.infected = true;
					person.weeks_infected = 0;
					stats::infected++;
					break;
				}
			}
			people_met++;
		}
	}
}

void simulation::update_infected(std::vector<person_t>& people) {
	for (auto& person : people) {
		if (person.weeks_infected >= 2 && person.infected) {
			person.infected = false;
			person.infection_risk = person.infection_risk * 0.40;
			person.weeks_infected = 0;
			stats::infected--;
			stats::recovered++;
		}
		if (person.infected)
			person.weeks_infected++;
	}
}

