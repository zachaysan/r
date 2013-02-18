
// import standard c++ stuff
#include <iostream>
#include <string>
#include <sstream>

void log( std::string my_text ){
  std::cerr << my_text;
  std::cerr << "\n";
}

void log( int my_int ){
  std::cerr << my_int;
  std::cerr << "\n";
}
