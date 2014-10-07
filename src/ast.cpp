#include "ast.h"
#include "parser.h"

std::ostream & operator<<(std::ostream & os, const Node & node)
{
  node.print(os);
  return os;
}

std::ostream & NBlock::print(std::ostream & os) const
{
    os << "Block: {" << std::endl;
    for (int i = 0; i < statements.size(); i++)
    {
      os << *(statements[i]) << std::endl;
    }
    os << "}" << std::endl;
    return os;
}

std::ostream & NVariableDeclaration::print(std::ostream & os) const
{
  os << "Variable decl: " << type << " " << name;
  if (initializationExpression != NULL)
    os << " " << *initializationExpression;
  os << std::endl;
  return os;
}

std::ostream & NFunctionDeclaration::print(std::ostream & os) const
{
  os << "Function decl: " << type << " " << ident << "(";
  for (int i = 0; i < variables.size(); i++)
    {
      os << *(variables[i]) << " ";
    }
  os << ") " << *body << std::endl;
  
  return os;
}

std::ostream & NAssignmentStatement::print(std::ostream & os) const
{
  os << "Assignment: " << ident << " = " << expr << std::endl;
  return os;
}

std::ostream & NBinaryOperator::print(std::ostream & os) const
{
  os << "Binary Op: " << lhs << " " << op << " " << rhs << std::endl;
  return os;
}

std::ostream & NIdentifier::print(std::ostream & os) const
{
  os << "Identifier: " << value;
  return os;
}

std::ostream & NReturn::print(std::ostream & os) const
{
  os << "Return: " << retExpr << std::endl;
  return os;
}

std::ostream & NDouble::print(std::ostream & os) const
{
  os << "Value: " << value;
  return os;
}

std::ostream & NInt::print(std::ostream & os) const
{
  os << "Value: " << value;
  return os;
}

std::ostream & NValue::print(std::ostream & os) const
{
  os << "Generic NValue" << std::endl;
  return os;
}

std::ostream & NUInt::print(std::ostream & os) const
{
  os << "Value: " << value;
  return os;
}

std::ostream & NString::print(std::ostream & os) const
{
  os << "Value: " << value;
  return os;
}

std::ostream & NLoopStatement::print(std::ostream & os) const
{
  os << "Loop: " << list << " as " << asVar << std::endl;
  os << "{" << loopBlock << "}" << std::endl;
  return os;
}

std::ostream & NIfStatement::print(std::ostream & os) const
{
  if (elseblock == NULL && elseif == NULL)
    os << "If: (" << condition << ") then " << thenblock << std::endl;
  if (elseblock != NULL && elseif == NULL)
    os << "If: (" << condition << ") then: " << thenblock << " else: " << *(elseblock) << std::endl;
  if (elseblock == NULL && elseif != NULL)
    {
      os << "If: (" << condition << ") then " << thenblock << std::endl;
      os << "Else if: " << *(elseif) << std::endl;
    }
  if (elseblock != NULL && elseif != NULL)
    {
      os << "If: (" << condition << ") then " << thenblock << std::endl;
      os << "Else if: " << *(elseif) << " else: " << *(elseblock) << std::endl;
    }
  return os;
}

std::ostream & NFunctionCall::print(std::ostream & os) const
{
  os << "Function Call: " << ident << std::endl;
  for (int i = 0; i < args.size(); i++)
    {
      os << args[i] << std::endl;
    }
  return os;
}

std::ostream & NList::print(std::ostream & os) const
{
  os << "List: ";
    for (int i = 0; i < value.size(); i++)
    {
      os << value[i] << " ";
    }
    os << std::endl;
    return os;
}