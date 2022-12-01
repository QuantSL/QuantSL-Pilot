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

void qoptic::stripCurlyBracesInPlace(std::string &string) {
  string.erase(std::remove(string.begin(), string.end(), '{'), string.end());
  string.erase(std::remove(string.begin(), string.end(), '}'), string.end());
}

std::vector<std::string> qoptic::toSymbol(std::vector<std::string> strings) {
  std::vector<std::string> strippedStrings;
  for (auto string : strings) strippedStrings.push_back(toSymbol(string));
  return strippedStrings;
};

std::string qoptic::toSymbol(std::string string) { return ":" + string; }

size_t _findClosingParenthesis(std::string expression, size_t start) {
  int openParenthesis = 0;
  for (size_t i = start; i < expression.size(); i++) {
    if (expression[i] == '(') openParenthesis++;
    if (expression[i] == ')') {
      openParenthesis--;
      if (openParenthesis == 0) return i;
    }
  }
  return std::string::npos;
}

void qoptic::tokenizeSummations(std::string &expression) {
  size_t pos = expression.find("sum");
  int i = 0;
  while ( pos != std::string::npos ) {
    expression.replace(pos, _findClosingParenthesis(expression, pos + 3) - pos + 1, "#" + std::to_string(i++));
    pos = expression.find("sum", pos + 2);
  }
}

void qoptic::insertSpaces(std::string &expression) {
  for (int i = expression.size() - 1; i > 1; --i) {
    if ( expression[i] == '+' || expression[i] == '-' ||
         expression[i] == '*' || expression[i] == '/' || expression[i] == '=' ) {
      expression.insert(i+1, " "); expression.insert(i, " ");
    }
  }
  if(expression[0] == '+' || expression[0] == '-') expression.insert(1, " ");
}