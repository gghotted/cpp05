#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name)
{
  setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
    : name(bureaucrat.name)
{
  *this = bureaucrat;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& bureaucrat)
{
  grade = bureaucrat.grade;
  return *this;
}

const std::string& Bureaucrat::getName() const
{
  return name;
}

int Bureaucrat::getGrade() const
{
  return grade;
}

Bureaucrat::Bureaucrat()
{
}

void Bureaucrat::increaseGrade()
{
  setGrade(grade - 1);
}

void Bureaucrat::decreaseGrade()
{
  setGrade(grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Too high grade!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Too low grade!";
}

void Bureaucrat::setGrade(int grade)
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
