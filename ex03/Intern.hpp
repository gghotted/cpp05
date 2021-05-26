#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "TargetForm.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern(void);
  Intern(const Intern& intern);
  virtual ~Intern(void);

  Intern& operator = (const Intern& intern);

  Form* makeForm(const std::string& name, const std::string& target) const;
  Form* createPresidentialPardonForm(const std::string& target) const;
  Form* createRobotomyRequestForm(const std::string& target) const;
  Form* createShrubberyCreationForm(const std::string& target) const;

 private:
  typedef struct pair_s
  {
    const char* name;
    Form* (Intern::*create)(const std::string& target) const;
  }              pair;
};

#endif
