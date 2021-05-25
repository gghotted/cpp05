#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "TargetForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public TargetForm {
 public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
  virtual ~RobotomyRequestForm(void);

  RobotomyRequestForm& operator =
      (const RobotomyRequestForm& robotomyRequestForm);

  virtual void action() const;

 private:
  RobotomyRequestForm(void);
};

#endif
