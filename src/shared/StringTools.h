#pragma once

#include <string>
#include <vector>

namespace qdsl {

bool contains(std::vector<std::string> strings, std::string query);
bool isNumber(std::string string);

template<typename T> std::vector<std::string> convertToSrings(std::vector<T> vec) {
  std::vector<std::string> strings;
  for (T element : vec) strings.push_back(std::to_string(element));
  return strings;
}

std::string formatIndex(const std::vector<std::string> subsystems, std::string index);

std::string separateBy(std::vector<std::string> strings, std::string separator);
template<typename T>
std::string separateByComma(     std::vector<T> vec) {return separateBy(convertToSrings(vec), ", ");}
template<typename T>
std::string separateByUnderscore(std::vector<T> vec) {return separateBy(convertToSrings(vec), "_");}
template<> inline
std::string separateByComma<std::string>(     std::vector<std::string> vec) {return separateBy(vec, ", ");}
template<> inline
std::string separateByUnderscore<std::string>(std::vector<std::string> vec) {return separateBy(vec, "_");}


std::vector<std::string> stripCurlyBraces(std::vector<std::string> strings);
std::string stripCurlyBraces(std::string string);
void stripCurlyBracesInPlace(std::string &string);

std::vector<std::string> toSymbol(std::vector<std::string> strings);
std::string toSymbol(std::string string);

void tokenizeSummations(std::string &expression);
void insertSpaces(std::string &expression);

} // namespace qdsl