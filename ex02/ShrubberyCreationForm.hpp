#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>
#include <exception>
#include "TargetForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public TargetForm {
 public:
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
  virtual ~ShrubberyCreationForm(void);

  ShrubberyCreationForm& operator =
      (const ShrubberyCreationForm& shrubberyCreationForm);

  virtual void action() const;

 private:
  ShrubberyCreationForm(void);

  class FileOpenFailException : public std::exception
  {
   public:
    const char* what() const throw();
  };
};

#endif
