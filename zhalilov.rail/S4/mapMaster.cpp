#include "mapMaster.hpp"

#include <iostream>

zhalilov::MapMaster::MapMaster(std::map < std::string, primaryMap > &maps):
  maps_(maps)
{
  std::pair < std::string, commandFunc > cmdPair;
  cmdPair = std::make_pair < std::string, commandFunc >("print", &MapMaster::printCmd);
  commands_.insert(cmdPair);
  cmdPair = std::make_pair < std::string, commandFunc >("complement", &MapMaster::complementCmd);
  commands_.insert(cmdPair);
  cmdPair = std::make_pair < std::string, commandFunc >("intersect", &MapMaster::intersectCmd);
  commands_.insert(cmdPair);
  cmdPair = std::make_pair < std::string, commandFunc >("union", &MapMaster::unionCmd);
  commands_.insert(cmdPair);
}

void zhalilov::MapMaster::doCommandLine(std::istream &input, std::string &result)
{
  std::ios_base::fmtflags ff(input.flags());
  input >> std::noskipws;
  List < std::string > cmdSource;
  std::string tmp;
  char delim = 0;
  while (input && delim != '\n')
  {
    input >> tmp;
    if (input)
    {
      cmdSource.push_back(tmp);
    }
    input >> delim;
  }
  input.flags(ff);

  if (cmdSource.empty())
  {
    result = std::string();
    return;
  }
  std::string cmdName = cmdSource.front();
  cmdSource.pop_front();
  (this->*commands_[cmdName])(cmdSource, result);
}

void zhalilov::MapMaster::printCmd(List < std::string > &cmdSource, std::string &result)
{
  if (cmdSource.capacity() != 1)
  {
    throw std::invalid_argument("incorrect command");
  }
  getMapSource(cmdSource.back(), result);
}

void zhalilov::MapMaster::complementCmd(List < std::string > &cmdSource, std::string &result)
{
  if (cmdSource.capacity() != 3)
  {
    throw std::invalid_argument("incorrect command");
  }
  primaryMap &secondMap = maps_.at(cmdSource.back());
  cmdSource.pop_back();
  primaryMap &firstMap = maps_.at(cmdSource.back());
  result = cmdSource.front();
  auto firstIt = firstMap.cbegin();
  auto firstEnd = firstMap.cend();
  primaryMap resultMap;
  while (firstIt != firstEnd)
  {
    if (secondMap.find(firstIt->first) == secondMap.end())
    {
      int currKey = firstIt->first;
      std::string currValue = firstIt->second;
      resultMap.insert(std::pair < int, std::string >(currKey, currValue));
    }
  }
}

void zhalilov::MapMaster::intersectCmd(List < std::string > &cmdSource, std::string &result)
{}

void zhalilov::MapMaster::unionCmd(List < std::string > &cmdSource, std::string &result)
{}

void zhalilov::MapMaster::getMapSource(const std::string &mapName, std::string &source)
{
  auto it = maps_.at(mapName).cbegin();
  auto end = maps_.at(mapName).cend();
  source = mapName;
  while (it != end)
  {
    source += std::to_string(it->first);
    source += it->second;
  }
}
