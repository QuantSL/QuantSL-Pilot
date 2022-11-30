#pragma once

#include <string>

#include <antlr4-runtime.h>
#include "QOVisitor.h"

namespace qoptic {
  
void generateCode(std::string filename, QOVisitor &visitor);

} // namespace qoptic