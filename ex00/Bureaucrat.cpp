#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    throw(GradeTooHighException, GradeTooLowException)
    : name(name)
{
  setGrade(grade);
}

Bureaucrat::~Bureaucrat(void)
{
}

const std::string& Bureaucrat::getName() const
{
  return name;
}

int Bureaucrat::getGrade() const
{
  return grade;
}

void Bureaucrat::increaseGrade() throw(GradeTooHighException)
{
  setGrade(grade - 1);
}

void Bureaucrat::decreaseGrade() throw(GradeTooLowException)
{
  setGrade(grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
  return "Too high grade!";
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
  return "Too low grade!";
}

void Bureaucrat::setGrade(int grade)
    throw(GradeTooHighException, GradeTooLowException)
{
  if (grade < maxGrade) throw GradeTooHighException();
  if (grade > minGrade) throw GradeTooLowException();
  this->grade = grade;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureaucrat)
{
  os << '<' << bureaucrat.getName()
     << ">, bureaucrat grade " << bureaucrat.getGrade() << "\n";
  return os;
}
