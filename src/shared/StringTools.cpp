#include "StringTools.h"
#include <algorithm>

bool qdsl::contains(std::vector<std::string> strings, std::string query) {
  for (std::string string : strings) {
    if (string == query) return true;
  }
  return false;
}

bool qdsl::isNumber(std::string string) {
  for (char c : string) if ( !isdigit(c) ) return false;
  return true;
}

std::string qdsl::formatIndex(const std::vector<std::string> subsystems, std::string index) {
  if ( contains(subsystems, index) ) return ":" + index;
  return index;
}

std::string qdsl::separateBy(std::vector<std::string> strings, std::string separator) {
  std::string result = "";
  if ( strings.size() == 0 ) return result;
  
  for (std::string string : strings) result += string + separator;
  return result.substr(0, result.size() - separator.size());
}

void qdsl::addUnique(std::vector<std::string> &target, std::vector<std::string> inputs) {
  for (std::string input : inputs) {
    if ( !contains(target, input) ) target.push_back(input);
  }
}

std::vector<std::string> qdsl::stripCurlyBraces(std::vector<std::string> strings) {
  std::vector<std::string> strippedStrings;
  for (auto string : strings) strippedStrings.push_back(stripCurlyBraces(string));
  return strippedStrings;
};

std::string qdsl::stripCurlyBraces(std::string string) {
  string.erase(std::remove(string.begin(), string.end(), '{'), string.end());
  string.erase(std::remove(string.begin(), string.end(), '}'), string.end());
  return string;
}

void qdsl::stripCurlyBracesInPlace(std::string &string) {
  string.erase(std::remove(string.begin(), string.end(), '{'), string.end());
  string.erase(std::remove(string.begin(), string.end(), '}'), string.end());
}

std::vector<std::string> qdsl::toSymbol(std::vector<std::string> strings) {
  std::vector<std::string> strippedStrings;
  for (auto string : strings) strippedStrings.push_back(toSymbol(string));
  return strippedStrings;
};

std::string qdsl::toSymbol(std::string string) { return ":" + string; }

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

void qdsl::tokenizeSummations(std::string &expression) {
  size_t pos = expression.find("sum");
  int i = 0;
  while ( pos != std::string::npos ) {
    expression.replace(pos, _findClosingParenthesis(expression, pos + 3) - pos + 1, "#" + std::to_string(i++));
    pos = expression.find("sum", pos + 2);
  }
}

void qdsl::insertSpaces(std::string &expression) {
  for (int i = expression.size() - 1; i > 1; --i) {
    if ( expression[i] == '+' || expression[i] == '-' ||
         expression[i] == '*' || expression[i] == '/' || expression[i] == '=' ) {
      expression.insert(i+1, " "); expression.insert(i, " ");
    }
  }
  if(expression[0] == '+' || expression[0] == '-') expression.insert(1, " ");
}