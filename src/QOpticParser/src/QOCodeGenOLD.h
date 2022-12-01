#pragma once

#include <string>

#include <antlr4-runtime.h>
#include "QOVisitor.h"

namespace qoptic {

std::string _generateParameterCheck(QOVisitor &visitor);
std::string _generateOperatorContainer(QOVisitor &visitor);
std::string _generateBasis();
  
void generateCode(std::string filename, QOVisitor &visitor);

} // namespace qoptic