
#include <iostream>
#include "./include/moment.hpp"

int main() 
{
  std::cout << moment::moment(1503228936974) << std::endl;
  std::cout << +moment::moment() << std::endl;
  std::cout << moment::moment().unix() << std::endl;
  std::cout << moment::moment().unix(1503228936) << std::endl;
  std::cout << moment::moment(2017,8,20) << std::endl;

  std::cout << moment::moment(2017, 8, 20, 16,17,05) << std::endl;

  return 0;
}

