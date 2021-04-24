#pragma once
#include <Windows.h>
#include "simulation.h"
#include "utils.h"
#include "log.h"

// Essential simulation variables
ULONG min_people_meet = 0; // Minumum people each person meet.
ULONG max_people_meet = 17; // Maximum people each person meet.
float min_infection_risk = 0.06; // Minumum infection risk for each person
float max_infection_risk = 0.14; // Maximum people each person meet.

int main() {
	utils u;
	simulation sim;
	logging log;

	std::vector<person_t>people = sim.populate_simulation(1000, 10, {min_infection_risk, max_infection_risk}); // 10 out of 1000 people will be infected at first
	for (const auto& person : people) {
		if (person.infected)
			stats::infected++;
	}

	while (stats::current_week++ < 52) { // Do simulation for 52 weeks.
		log.log_result();
		system("cls");
		printf("===== Week: %lu =====\nPopulation: %lu\nInfected: %lu\nRecovered: %lu\n", stats::current_week, people.size(), stats::infected, stats::recovered);
		u.print_line(19, '=');
		printf("\n\nPress any key to go to next week.");
		(void)_getch();
		sim.socialize(people, {min_people_meet, max_people_meet});
		sim.update_infected(people);
	}
	log.store_result();
	exit(EXIT_SUCCESS);
}