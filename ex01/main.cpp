#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Ui.hpp"

int main()
{
  Ui::setTextColor(Ui::green);
  try
  {
    Bureaucrat br("gypark", Ui::readInt("Bureaucrat grade"));
    std::cout << br;
    Form form("can i order a pizza?",
              Ui::readInt("required grade to sign"),
              Ui::readInt("required grade to exec"));

    Ui::setTextColor(Ui::blue);
    Ui::colorPrint("\nform state(before sign)\n");
    std::cout << form;
    Ui::colorPrint("\nBureaucrat sign result\n");
    br.signForm(form);
    Ui::colorPrint("\nform state(after sign)\n");
    std::cout << form;
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }
  return 0;
}
