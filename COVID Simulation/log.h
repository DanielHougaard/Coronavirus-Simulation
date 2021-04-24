#pragma once
#include <Windows.h>
#include "nlohmann/json.hpp"

using nlohmann::json;

class stats {
public:
	static inline ULONG initial_population;
	static inline ULONG current_week;
	static inline ULONG infected;
	static inline ULONG recovered;
};

class logging {
public:
	void log_result();
	void store_result();
private:
	const char* log_path = "COVID-Simulation-Data.json";
	
	json j_array = json::array();
};