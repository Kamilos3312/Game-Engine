#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Debug {
public:
	template <class T, class U>
	static void Log(T title, U desc) {
		#if _DEBUG
		std::cout << "[" << title << "] " << desc << std::endl;
		#endif

		write(title, desc);
	}

	static void empty() {
		std::ofstream file;
		file.open("log.txt", std::ofstream::out | std::ofstream::trunc);
		if (!file.is_open())
			exit(-1);
		file.close();
	}

	template <class T, class U>
	static void write(T title, U desc) {
		std::ofstream file;
		file.open("log.txt", std::ios::out | std::ios::app);
		if (!file.is_open())
			return;

		file << "[" << title << " ] " << desc << "\n";
		file.close();
	}
};