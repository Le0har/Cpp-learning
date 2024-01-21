#include <iostream>
#include "MyVector.h"
#include "MyVector.cpp"

int main()
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

   return 0;
}

