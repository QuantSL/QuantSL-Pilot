#pragma once

#include <vector>
#include <string>

namespace qoptic {

class SummationTree;  

class BaseTree {
public:
  virtual ~BaseTree() = default;
  virtual void addChildIndices(std::vector<std::string> childIndices) = 0;
  virtual void addChildTree(             SummationTree* childTree) = 0;
  virtual void addChildOperator(std::string childOperator, std::vector<std::string> childOperatorIndex) = 0;
};

class SummationTree : public BaseTree {
private:
  std::vector<std::vector<std::string>> _childrensIndices;
  std::vector<std::string> _childrenOperators;
  std::vector<std::vector<std::string>> _childrenOperatorsIndices;
  std::vector<SummationTree*> _childrenTrees;

public:
  ~SummationTree() { for (SummationTree* childTree : _childrenTrees) delete childTree;}

  std::string expression;
  std::vector<std::string> indices;
  std::vector<std::string> lowerBounds;
  std::vector<std::string> upperBounds;

  SummationTree(std::string expressionIn, std::vector<std::string> indicesIn,
                std::vector<std::string> lowerBoundsIn, std::vector<std::string> upperBoundsIn);
  
  void addChildIndices(std::vector<std::string> childIndices)  { _childrensIndices.push_back(childIndices); }
  void addChildTree(             SummationTree* childTree)     { _childrenTrees.push_back(childTree); }
  void addChildOperator(std::string childOperator, std::vector<std::string> childOperatorIndex) {
    _childrenOperators.push_back(childOperator);
    _childrenOperatorsIndices.push_back(childOperatorIndex);
  }

  std::string generateIndexSampler(std::string indentation);
  std::string generateDefinition(std::string indentation);
};

class DefinitionTree : public BaseTree {
private:
  std::vector<std::vector<std::string>> _childrensIndices;
  std::vector<std::string> _childrenOperators;
  std::vector<std::vector<std::string>> _childrenOperatorsIndices;
  std::vector<SummationTree*> _childrenTrees;

public:
  ~DefinitionTree() { for (SummationTree* childTree : _childrenTrees) delete childTree; }

  std::string expression;
  std::string name;
  std::vector<std::string> indices;

  DefinitionTree(std::string expressionIn, std::string nameIn, std::vector<std::string> indicesIn);

  void addChildIndices(std::vector<std::string> childIndices)  { _childrensIndices.push_back(childIndices); }
  void addChildTree(             SummationTree* childTree)     { _childrenTrees.push_back(childTree); }
  void addChildOperator(std::string childOperator, std::vector<std::string> childOperatorIndex) {
    _childrenOperators.push_back(childOperator);
    _childrenOperatorsIndices.push_back(childOperatorIndex);
  }
    
  std::string generateIndexSampler(std::string parameterCheck);
  std::string generateDefinition(std::string parameterCheck, std::string basisGeneration);
};

} // namespace qoptic