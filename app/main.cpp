#include <iostream>
#include <cstdlib>

#include "Dummy.h"

#include "Array.h"
#include "Array.cpp"

/// \brief Simple main program for testing
int main(int argc, char* argv[])
{
  std::cout << "Running main function !! " << std::endl << std::endl;

  std::system("echo BashCommandEcho");

  std::cout << std::endl << std::endl;

  // Bring in the Dummy class,
  // just to show that it is accessible from main.cpp.
  sample::Dummy instance = sample::Dummy();
  std::cout << "Absolute of -5 is: " << instance.absolute(-5) << std::endl;

  std::cout << std::endl << std::endl;

  // Just to show how template classes will be used
  // See includes (both cpp and header files are included)
  ds::Array<int> arr;
  arr.push(0);
  arr.push(1);
  arr.push(2);
  arr.push(3);
  arr.push(4);
  arr.displayContents();

  return 0;
}
