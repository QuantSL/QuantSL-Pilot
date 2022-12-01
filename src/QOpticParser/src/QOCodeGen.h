#pragma once

#include <string>

#include <antlr4-runtime.h>
#include "QOParser.h"

namespace qoptic {

std::string _generateParameterCheck(QOParser &parser);
std::string _generateOperatorContainer(QOParser &parser);
std::string _generateBasis();
  
int generateCode(std::string filename, QOParser &parser);

} // namespace qoptic