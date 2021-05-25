#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : TargetForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm)
    : TargetForm(shrubberyCreationForm)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =
    (const ShrubberyCreationForm& shrubberyCreationForm)
{
  TargetForm::operator=(shrubberyCreationForm);
  return *this;
}

void ShrubberyCreationForm::action() const
{
  static const char* tree = "\
      /_-_\\\n\
    /~~   ~~\\\n\
/~~         ~~\\\n\
{               }\n\
\\  _-     -_  /\n\
  ~  \\ //  ~\n\
_- -   | | _- _\n\
  _ -  | |   -_\n\
      // \\";
  std::ofstream ofs(getTarget() + "_shrubbery");
  if (ofs.fail())
    throw FileOpenFailException();
  ofs << tree;
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : TargetForm("", "", 1, 1)
{
}

const char* ShrubberyCreationForm::FileOpenFailException::what() const throw()
{
  return "fail open file";
}
