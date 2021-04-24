#include "log.h"
#include "nlohmann/json.hpp"
#include <fstream>
void logging::log_result(){
	json j;
	j["Week " + std::to_string(stats::current_week)]["Current Week"] = stats::current_week;
	j["Week " + std::to_string(stats::current_week)]["Initial Population"] = stats::initial_population;
	j["Week " + std::to_string(stats::current_week)]["Infected"] = stats::infected;
	j["Week " + std::to_string(stats::current_week)]["Recovered"] = stats::recovered;

	this->j_array.push_back(j);
}

void logging::store_result(){
	std::ofstream logging(this->log_path);
	logging << this->j_array.dump(4);

	if (logging.fail())
		MessageBoxA
		(
			NULL,
			"Failed to store simulation data\nDepending on where the program is located it may need administrative permissions.",
			"Error",
			MB_ICONERROR | MB_OK
		);
	logging.close();
}
