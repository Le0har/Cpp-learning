#pragma once
#include <iostream>

class MyException : public std::exception {
   public:
      MyException(const char* msg);
};