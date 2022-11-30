#include "StringTools.h"
#include <algorithm>

bool qoptic::contains(std::vector<std::string> strings, std::string query) {
  for (std::string string : strings) {
    if (string == query) return true;
  }
  return false;
}

bool qoptic::isNumber(std::string string) {
  for (char c : string) if ( !isdigit(c) ) return false;
  return true;
}

std::string qoptic::formatIndex(const std::vector<std::string> subsystems, std::string index) {
  if ( contains(subsystems, index) ) return ":" + index;
  return index;
}

std::string qoptic::separateByComma(std::vector<std::string> strings) {
  std::string result = "";
  if ( strings.size() == 0 ) return result;
  
  for (std::string string : strings) {
    result += string + ", ";
  }
  return result.substr(0, result.size() - 2);
}

std::vector<std::string> qoptic::stripCurlyBraces(std::vector<std::string> strings) {
  std::vector<std::string> strippedStrings;
  for (auto string : strings) strippedStrings.push_back(stripCurlyBraces(string));
  return strippedStrings;
};

std::string qoptic::stripCurlyBraces(std::string string) {
  string.erase(std::remove(string.begin(), string.end(), '{'), string.end());
  string.erase(std::remove(string.begin(), string.end(), '}'), string.end());
  return string;
}

std::vector<std::string> qoptic::toSymbol(std::vector<std::string> strings) {
  std::vector<std::string> strippedStrings;
  for (auto string : strings) strippedStrings.push_back(toSymbol(string));
  return strippedStrings;
};

std::string qoptic::toSymbol(std::string string) { return ":" + string; }