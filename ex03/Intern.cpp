#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern& intern)
{
  (void)intern;
}

Intern::~Intern(void)
{
}

Intern& Intern::operator = (const Intern& intern)
{
  (void)intern;
  return *this;
}

Form* Intern::makeForm(const std::string& name, const std::string& target) const
{
  static const pair forms[] = {
      {"presidential pardon", &Intern::createPresidentialPardonForm},
      {"robotomy request", &Intern::createRobotomyRequestForm},
      {"shrubbery creation", &Intern::createShrubberyCreationForm},
      {0, 0}};
  for (int i = 0; forms[i].name != 0; i++)
    if (name.compare(forms[i].name) == 0)
    {
      Form* form = (this->*forms[i].create)(target);
      std::cout << "Intern creates " << form->getName() << "\n";
      return form;
    }
  std::cout << name << ": no such form!\n";
  return 0;
}

Form* Intern::createPresidentialPardonForm(const std::string& target) const
{
  return (new PresidentialPardonForm(target));
}

Form* Intern::createRobotomyRequestForm(const std::string& target) const
{
  return (new RobotomyRequestForm(target));
}

Form* Intern::createShrubberyCreationForm(const std::string& target) const
{
  return (new ShrubberyCreationForm(target));
}
