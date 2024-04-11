#include "types.hpp"

piyavkin::InputType::InputType():
  operand(),
  type(detail::operand)
{}
piyavkin::InputType::InputType(unsigned long long val):
  operand(val),
  type(detail::operand)
{}
piyavkin::InputType::InputType(char val, size_t num)
{
  if (num == detail::bracket)
  {
    bracket = val;
    type = detail::bracket;
  }
  else
  {
    operation = val;
    type = detail::operation;
  }
}
piyavkin::detail::TypesPartsExpression piyavkin::InputType::getType() const
{
  return type;
}
char piyavkin::InputType::getBraket() const
{
  return bracket.bracket;
}
char piyavkin::InputType::getOperation() const
{
  return operation.operation;
}
unsigned long long piyavkin::InputType::getOperand() const
{
  return operand.number;
}

piyavkin::Postfix::Postfix():
  operand(0),
  type(detail::operand)
{}
piyavkin::Postfix::Postfix(unsigned long long val):
  operand(val),
  type(detail::operand)
{}
piyavkin::Postfix::Postfix(char val):
  operation(val),
  type(detail::operation)
{}
piyavkin::detail::TypesPartsExpression piyavkin::Postfix::getType() const
{
  return type;
}
char piyavkin::Postfix::getOperation() const
{
  return operation.operation;
}
unsigned long long piyavkin::Postfix::getOperand() const
{
  return operand.number;
}

piyavkin::ConversionExpressionType::ConversionExpressionType():
  operation(0),
  type(detail::operation)
{}
piyavkin::ConversionExpressionType::ConversionExpressionType(char val, size_t num)
{
  if (num == detail::bracket)
  {
    bracket = val;
    type = detail::bracket;
  }
  else
  {
    operation = val;
    type = detail::operation;
  }
}
char piyavkin::ConversionExpressionType::getBraket() const
{
  return bracket.bracket;
}
char piyavkin::ConversionExpressionType::getOperation() const
{
  return operation.operation;
}
piyavkin::detail::TypesPartsExpression piyavkin::ConversionExpressionType::getType() const
{
  return type;
}