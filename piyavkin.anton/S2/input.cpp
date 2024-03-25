#include "input.hpp"

void piyavkin::input(std::istream& in, List< Queue< InputType > >& queues)
{
  char symbol = 0;
  in >> std::noskipws;
  while (in)
  {
    Queue< InputType > q;
    InputType val;
    while (in >> symbol && symbol != '\n')
    {
      if (symbol == ' ')
      {
        continue;
      }
      else if (symbol == '(' || symbol == ')')
      {
        val.type = detail::bracket;
        val.symbol.bracket.bracket = symbol;
      }
      else if (std::isdigit(symbol))
      {
        std::string result = "";
        while (symbol != ' ' && symbol != '\n')
        {
          result += symbol;
          in >> symbol;
        }
        val.type = detail::operand;
        val.symbol.operand.number = std::stoll(result);
        if (symbol == '\n')
        {
          q.push(val);
          break;
        }
      }
      else
      {
        val.type = detail::operation;
        val.symbol.operation.operation = symbol;
      }
      q.push(val);
    }
    queues.push_back(q);
  }
  in >> std::skipws;
}