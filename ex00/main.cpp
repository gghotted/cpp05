#include "iostream"
#include "Bureaucrat.hpp"

#include "Ui.hpp"

int main()
{
  Ui::setTextColor(Ui::green);
  Bureaucrat* br = 0;
  while (1)
  {
    try
    {
      if (!br) br = new Bureaucrat("gypark", Ui::readInt("grade"));
      std::cout << *br;
      std::string operate = Ui::readStr("+ or -");
      if (operate.compare("+") == 0) br->increaseGrade();
      if (operate.compare("-") == 0) br->decreaseGrade();
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << '\n';
      break;
    }
  }
  delete br;
}
