#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class GradeTooHighException;
class GradeTooLowException;

class Form
{
 public:
  Form(const std::string& name, const int signGrade, const int executeGrade);
  Form(const Form& form);
  virtual ~Form();

  Form& operator = (const Form& form);

  const std::string& getName() const;
  const bool& getIsSigned() const;
  const int& getSignGrade() const;
  const int& getExecuteGrade() const;
  void beSigned(const Bureaucrat& bureaucrat);

 private:
  Form();

  class GradeTooHighException : public std::exception
  {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
   public:
    const char* what() const throw();
  };

  static const int& checkValidGrade(const int& grade);
  bool checkSignAllowed(const int& grade) const;

  static const int minGrade = 150;
  static const int maxGrade = 1;
  const std::string name;
  const int signGrade;
  const int executeGrade;
  bool isSigned;
};

std::ostream& operator << (std::ostream& os, const Form& form);

#endif
