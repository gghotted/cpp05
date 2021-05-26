#ifndef TARGETFORM_HPP
#define TARGETFORM_HPP

#include <string>
#include "Form.hpp"

class TargetForm : public Form {
 public:
  TargetForm(const std::string& name, const std::string& target,
              const int signGrade, const int executeGrade);
  TargetForm(const TargetForm& targetForm);
  virtual ~TargetForm(void);

  TargetForm& operator = (const TargetForm& targetForm);

  const std::string& getTarget() const;

 private:
  TargetForm(void);

  const std::string target;
};

#endif
