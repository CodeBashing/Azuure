#pragma once

#include <iostream>
#include "fileutils.h"

namespace azuure { namespace utils {
	std::string readFile(const std::string & filepath) {
		std::ifstream in(filepath);
		if (!in.is_open()) {
			std::cout << "Failed to open file at : " << filepath << std::endl;
			return "";
		}
		std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		return contents;
	}
}}
