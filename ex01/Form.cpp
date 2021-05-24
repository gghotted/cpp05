#include "Form.hpp"

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
    throw(GradeTooHighException, GradeTooLowException)
    : name(name),
      signGrade(checkValidGrade(signGrade)),
      executeGrade(checkValidGrade(executeGrade)),
      isSigned(false)
{
}

Form::Form(const Form& form)
    throw(GradeTooHighException, GradeTooLowException)
    : name(form.name),
      signGrade(checkValidGrade(form.signGrade)),
      executeGrade(checkValidGrade(form.executeGrade))
{
  *this = form;
}

Form::~Form()
{
}

Form& Form::operator = (const Form& form)
{
  isSigned = form.isSigned;
  return *this;
}

const std::string& Form::getName() const
{
  return name;
}

const bool& Form::getIsSigned() const
{
  return isSigned;
}

const int& Form::getSignGrade() const
{
  return signGrade;
}

const int& Form::getExecuteGrade() const
{
  return executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException)
{
  if (!checkSignAllowed(bureaucrat.getGrade()))
    throw GradeTooLowException();
  isSigned = true;
}

Form::Form() : name(""), signGrade(1), executeGrade(1)
{
}

const char* Form::GradeTooHighException::what() const throw()
{
  return "Form: Too high grade!";
}

const char* Form::GradeTooLowException::what() const throw()
{
  return "Form: Too low grade!";
}

const int& Form::checkValidGrade(const int& grade)
    throw(GradeTooHighException, GradeTooLowException)
{
  if (grade < maxGrade)
    throw GradeTooHighException();
  if (minGrade < grade)
    throw GradeTooLowException();
  return grade;
}

bool Form::checkSignAllowed(const int& grade) const
{
  return grade <= signGrade;
}

std::ostream& operator << (std::ostream& os, const Form& form)
{
  std::cout << "form: " << form.getName() << "\n";
  std::cout << "signed: " << std::boolalpha << form.getIsSigned() << '\n';
  std::cout << "required grade to sign: " << form.getSignGrade() << '\n';
  std::cout << "required grade to exec: " << form.getExecuteGrade() << '\n';
  return os;
}
