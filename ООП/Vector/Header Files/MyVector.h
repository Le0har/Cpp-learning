#pragma once
#include <iostream>

class MyVector{
public:
   int size;
   int capacity;
   int* array = nullptr;

   MyVector();                                                                  //пустой вектор
   
   MyVector(int size);                                                          //вектор состоит из size чисел, каждое равно 0
   
   MyVector(int size, int value);                                               //вектор состоит из size чисел, каждое равно value
   
   void show();
   
   void push_back(int value);
   
   void pop_back();
   
   void insert(int index, int value);
   
   void remove(int index);
   
   ~MyVector();
  
};
