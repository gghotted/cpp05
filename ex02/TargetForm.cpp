#include "TargetForm.hpp"

TargetForm::TargetForm(const std::string& name, const std::string& target,
                       const int signGrade, const int executeGrade)
    : Form(name, signGrade, executeGrade), target(target)
{
}

TargetForm::TargetForm(const TargetForm& targetForm)
    : Form(targetForm), target(targetForm.getTarget())
{
}

TargetForm::~TargetForm(void)
{
}

TargetForm& TargetForm::operator = (const TargetForm& targetForm)
{
  Form::operator=(targetForm);
  return *this;
}

const std::string& TargetForm::getTarget() const
{
  return target;
}

TargetForm::TargetForm(void) : Form("", 1, 1)
{
}
