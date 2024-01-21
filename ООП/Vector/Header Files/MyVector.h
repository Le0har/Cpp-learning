#pragma once
#include <iostream>

template <typename T>
class MyVector{
public:
   int size;
   int capacity;
   T* array = nullptr;
   
   MyVector();                                                                  //пустой вектор
   
   MyVector(int size);                                                          //вектор состоит из size чисел, каждое равно 0
   
   MyVector(int size, T value);                                                 //вектор состоит из size чисел, каждое равно value
   
   void show();
   
   void push_back(T value);
   
   void pop_back();
   
   void insert(int index, T value);
   
   void remove(int index);
   
   ~MyVector();
};
