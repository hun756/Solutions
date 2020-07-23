#include "postfixevaluation.hpp"
#include <iostream>
#include <string>

void info()
{
  std::cout << "Welcome to Postfix Evaluation Program" << '\n'
            << "1 - Write your expression according to postfix notation." << '\n'
            << "2 - Write your expression using space : ex: 12 13 16 + * 63 -" << '\n'
            << "Good Luck :)" << '\n'
            << "--------------------------------------------------------------\n";
}

int main(int argc, char const *argv[])
{
  info();


  std::string       userInput;
  char              controlContinue;
  PostfixEvolution* p;

  do
  {
    std::cout << "Write Expressions : ";
    std::getline(std::cin >> std::ws, userInput);

    p = new PostfixEvolution(userInput);
    p->showResult();

    delete p;
    p = NULL;

    std::cout << "Do you want to continue ? (Y/N) ";
    std::cin >> controlContinue;

  } while (controlContinue == 'Y' || controlContinue == 'y');
  

  return 0;
}
