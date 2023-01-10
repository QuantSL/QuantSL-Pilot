#pragma once

#include <string>

#include <antlr4-runtime.h>
#include "QDSLParser.h"

namespace qdsl {

std::string _generateParameterCheck(QDSLParser &parser);
std::string _generateOperatorContainer(QDSLParser &parser);
std::string _generateBasis();
  
int generateCode(std::string filename, QDSLParser &parser);

} // namespace qdsl