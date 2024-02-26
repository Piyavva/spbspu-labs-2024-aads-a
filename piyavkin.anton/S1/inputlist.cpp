#include "inputlist.hpp"
#include <cstring>
#include <cmath>

std::pair< std::string, piyavkin::List< unsigned int >* >* piyavkin::inputList(std::istream& in, size_t& size, size_t& max_size_list)
{
  size_t max_size = 0;
  std::string str = "";
  std::string name = "";
  size_t capacity = 10;
  std::pair< std::string, List< unsigned int >* >* pairs = new std::pair< std::string, List< unsigned int >* >[capacity] {};
  while (in >> name)
  {
    if (size == capacity)
    {
      std::pair< std::string, List< unsigned int >* >* old_pairs = pairs;
      pairs = new std::pair< std::string, List< unsigned int >* >[capacity + 10] {};
      for (size_t j = 0; j < capacity; ++j)
      {
        pairs[j] = old_pairs[j];
      }
      delete[] old_pairs;
      capacity += 10;
    }
    List< unsigned int >* list = new List< unsigned int >;
    pairs[size].first = name;
    std::getline(in, str);
    str.erase(0, 1);
    while (str != "")
    {
      if (strchr(str.c_str(), ' ') != nullptr)
      {
        std::string str2 = str.substr(0, str.find(' '));
        unsigned int val = std::stoul(str2);
        list->push_back(val);
        ++max_size;
        str.erase(0, str.find(' ') + 1);
      }
      else
      {
        unsigned int val = std::stoul(str);
        list->push_back(val);
        ++max_size;
        str = "";
      }
    }
    pairs[size++].second = list;
    max_size_list = std::max(max_size, max_size_list);
    max_size = 0;
  }
  return pairs;
}