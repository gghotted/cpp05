#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : TargetForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm)
    : TargetForm(robotomyRequestForm)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator =
    (const RobotomyRequestForm& robotomyRequestForm)
{
  TargetForm::operator=(robotomyRequestForm);
  return *this;
}

void RobotomyRequestForm::action() const
{
  std::cout << "wing.. wing.. wing..\n";
  if (rand() % 2)
    std::cout << getTarget() << " has been robotomized.\n";
  else
    std::cout << getTarget() << " has been fail.\n";
}

RobotomyRequestForm::RobotomyRequestForm(void)
    : TargetForm("", "", 1, 1)
{
}
