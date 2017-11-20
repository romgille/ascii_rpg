#include <string>
#include <iostream>

int main() {
  std::string data[] = {
    #include "data.txt"
  };
  for (auto s : data) std::cout << s << std::endl;
}
