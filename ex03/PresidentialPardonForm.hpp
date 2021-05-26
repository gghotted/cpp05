#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "TargetForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public TargetForm {
 public:
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
  virtual ~PresidentialPardonForm(void);

  PresidentialPardonForm& operator =
      (const PresidentialPardonForm& presidentialPardonForm);

  virtual void action() const;

 private:
  PresidentialPardonForm(void);
};

#endif
