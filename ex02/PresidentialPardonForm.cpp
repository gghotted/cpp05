#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : TargetForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm)
    : TargetForm(presidentialPardonForm)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator =
      (const PresidentialPardonForm& presidentialPardonForm)
{
  TargetForm::operator=(presidentialPardonForm);
  return *this;
}

void PresidentialPardonForm::action() const
{
  std::cout << getTarget() << " has been pardoned by Zafod Beeblerox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(void)
    : TargetForm("", "", 1, 1)
{
}
