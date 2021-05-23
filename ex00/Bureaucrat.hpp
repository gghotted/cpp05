#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class GradeTooHighException;
class GradeTooLowException;

class Bureaucrat
{
 public:
  Bureaucrat(const std::string& name, int grade)
             throw(GradeTooHighException, GradeTooLowException);
  Bureaucrat(const Bureaucrat& bureaucrat);
  virtual ~Bureaucrat(void);

  Bureaucrat& operator = (const Bureaucrat& bureaucrat);

  const std::string& getName() const;
  int getGrade() const;
  void increaseGrade() throw(GradeTooHighException);
  void decreaseGrade() throw(GradeTooLowException);

 private:
  Bureaucrat();
  class GradeTooHighException : public std::exception
  {
   public:
    const char* what() const _NOEXCEPT;
  };
  class GradeTooLowException : public std::exception
  {
   public:
    const char* what() const _NOEXCEPT;
  };

  void setGrade(int grade) throw(GradeTooHighException, GradeTooLowException);

  static const int minGrade = 150;
  static const int maxGrade = 1;
  const std::string name;
  int grade;
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureaucrat);

#endif
