#include <iostream>
#include "MyVector.h"

int main()
{

   MyVector v1;
   MyVector v2(7);
   MyVector v3(7,3);

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

   return 0;
}
