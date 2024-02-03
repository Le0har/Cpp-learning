#include <iostream>
#include "MyVector.h"

int main()
{
   setlocale(LC_ALL, "Rus");
   try
   {
      MyVector<int> v1;
      MyVector<int> v2(7);
      MyVector<double> v3(7,3.14);

      v1.show();
      v2.show();
      v3.show();

      v2.push_back(15);
      v2.show();

      v2.pop_back();
      v2.show();

      v2.insert(3,9);
      v2.show();

      v2.remove(3);
      v2.show();

      v2.insert(44,9);
      v1.pop_back();
   }
   catch (std::logic_error& error)
   {
      std::cout << error.what() << std::endl;
   }
   catch (std::invalid_argument& error)
   {
      std::cout << error.what() << std::endl;
   }
   return 0;
}
