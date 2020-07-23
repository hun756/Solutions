#include <cctype>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <cmath>
#include <stack>
#include <typeinfo>

#include "postfixevaluation.hpp"

PostfixEvolution::PostfixEvolution()
{
}


/** @constructor
 * 
 */
PostfixEvolution::PostfixEvolution(std::string exp) : exp(exp) 
{
  vec = splitExp(' ');
}


void PostfixEvolution::setExp(std::string exp) 
{
  this->exp = exp;
  setVec();
}


std::string PostfixEvolution::getExp() const
{
  return exp;
}


std::vector<std::string> PostfixEvolution::splitExp(char seperator) 
{
  std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = exp.find(seperator, pos)) != std::string::npos)
    {
        std::string substring(exp.substr(prev_pos, pos-prev_pos));

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(exp.substr(prev_pos, pos-prev_pos));

    return output;
}


int PostfixEvolution::convert(std::string& str) 
{
  int temp = 0, summary = 0;

  for (int i = str.size() - 1; i >= 0 ; --i)
  {
    if (i == str.size() - 1)
    {
      const int tempvar = (static_cast<int>(str[i]) - 48);
      summary += tempvar;
    }

    else
    {
      const int tempvar = (static_cast<int>(str[i]) - 48) * static_cast<int>(pow(10, temp));
      summary += tempvar;
    }
    
    ++temp;
  }

  return summary;
}


bool PostfixEvolution::_isDigit(std::string& str)
{
  int count = 0;
  for (int i = 0; i < str.size() ; ++i)
  {
      const int controlVar = static_cast<int>(str[i]);

      if (isdigit(controlVar)) ++count;
  }

  return count == str.size();
}


char PostfixEvolution::operatorControl(std::string& str) 
{
  std::string contolArray = "+-*/";

  for (int i = 0; i < contolArray.size(); ++i)
    if (contolArray[i] == str[0]) return contolArray[i];

  return 0;
}


void PostfixEvolution::setVec() 
{
  vec = splitExp(' ');
}


int PostfixEvolution::calculatePostfix() 
{
  std::stack<int> st;

  for (std::string vals : vec)
  {
    if (_isDigit(vals))
    {
      const int ara = convert(vals);
      st.push(ara);
    }

    else
    {
      int val1 = st.top();
      st.pop();
      int val2 = st.top();
      st.pop();

      char control = operatorControl(vals);

      switch (control)
      {
      case '+':
        st.push(val2 + val1);
        break;

      case '-':
        st.push(val2 - val1);
        break;

      case '*':
        st.push(val2 * val1);
        break;

      case '/':
        st.push(val2 / val1);
        break;

      default: throw std::domain_error("Error, operator is not found..!");
      }
    }
  }

  return st.top();

}


void PostfixEvolution::showResult() 
{
  setVec();
  int result = calculatePostfix();
  std::cout << "Result : " << result << std::endl;
}
