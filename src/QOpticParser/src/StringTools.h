#pragma once

#include <string>
#include <vector>

namespace qoptic {

bool contains(std::vector<std::string> strings, std::string query);
bool isNumber(std::string string);

std::string formatIndex(const std::vector<std::string> subsystems, std::string index);

std::string separateByComma(std::vector<std::string> strings);

std::vector<std::string> stripCurlyBraces(std::vector<std::string> strings);
std::string stripCurlyBraces(std::string string);

std::vector<std::string> toSymbol(std::vector<std::string> strings);
std::string toSymbol(std::string string);

} // namespace qoptic