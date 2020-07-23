#ifndef POSTFIXEVALUATION_HPP
#define POSTFIXEVALUATION_HPP

#include <iostream>
#include <vector>

class PostfixEvolution
{
public:

// constructor
PostfixEvolution();
PostfixEvolution(std::string);

// setter and getters
void setExp(std::string);
std::string getExp() const;

// split method
std::vector<std::string> splitExp(char);

// calculate Postfix method
int calculatePostfix();

// convert method
int convert(/* std::vector<std::string>& */ std::string&);

// is vector has digit?
bool _isDigit(std::string&);

// operator control
char operatorControl(std::string&);

// printing result on the screen
void showResult();


private:
  std::string exp;
  std::vector<std::string> vec;

  void setVec();
};

#endif /* End of include guard : POSTFIXEVALUATION_HPP */