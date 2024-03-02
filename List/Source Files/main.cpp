#include <iostream>
#include "LinkedList.h"

int main()
{
   setlocale(LC_ALL, "Rus");
   try
   {
      LinkedList<int> list;

      list.pushBack(1);
      list.pushBack(2);
      list.pushBack(3);
      list.pushBack(4);

      std::cout << list << std::endl;

      std::cout << list[1]->data << std::endl;
  
      list.insert(2, -5);
      list.insert(33, -9);

      std::cout << list << std::endl;

      list.erase(2);
      //list.erase(44);

      std::cout << list << std::endl;
   }
   catch (std::logic_error& error)
   {
      std::cout << error.what() << std::endl;
   }
   catch (std::invalid_argument& error)
   {
      std::cout << error.what() << std::endl;
   }
}

