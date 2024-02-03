//#include "MyVector.h"
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

   template <typename T> MyVector<T>::MyVector()                                                                  //пустой вектор
   {
      size = 0;
      capacity = 10;
      T* array = new T[capacity];
   }

   template <typename T> MyVector<T>::MyVector(int size): size(size), capacity(size*1.5), array(new T[capacity])  //вектор состоит из size чисел, каждое равно 0
   {
      for(int i=0; i<size; i++)
      {
         array[i] = 0;
      }
   }

   template <typename T> MyVector<T>::MyVector(int size, T value): size(size), capacity(size*1.5), array(new T[capacity])  //вектор состоит из size чисел, каждое равно value
   {
      for(int i=0; i<size; i++)
      {
         array[i] = value;
      }
   }

   template <typename T> void MyVector<T>::show()
   {
      for(int i=0; i<size; i++)
      {
         std::cout << array[i] << " ";
      }
      std::cout << std::endl;
   }

   template <typename T> void MyVector<T>::push_back(T value)
   {
      array[size] = value;
      size++;
      if (size == capacity)
      {
         capacity = size * 1.5;
         T* array2 = new T[capacity];
         for(int i=0; i<size; i++)
         {
            array2[i] = array[i];
         }
         delete[] array;
         array = array2;
      }
   }

   template <typename T> void MyVector<T>::pop_back()
   {
      if(size == 0)
      {
         throw std::logic_error("Ошибка! Вектор итак пуст!");
      }
      array[size-1] = 0;
      size--;
   }

   template <typename T> void MyVector<T>::insert(int index, T value)
   {
      if(index < 0 || index > size)
      {
         throw std::invalid_argument("Ошибка! Попытка вставить элемент по несуществующему индексу!");
      }
      size++;
      if (size == capacity)
      {
         capacity = size * 1.5;
         T* array2 = new T[capacity];
         for(int i=0; i<size; i++)
         {
            array2[i] = array[i];
         }
         delete[] array;
         array = array2;
      }
      T temp1, temp2;
      temp1 = array[index];
      array[index] = value;
      for(int i=index+1; i<size; i++)
      {
         temp2 = array[i];
         array[i] = temp1;
         temp1 = temp2;
      }
   }

   template <typename T> void MyVector<T>::remove(int index)
   {
      if (size == 0)
      {
         throw std::logic_error("Ошибка! Вектор итак пуст!");
      }
      size--;
      for(int i=index; i<size; i++)
      {
         array[i] = array[i+1];
      }
   }

   template <typename T> MyVector<T>::~MyVector()
   {
      delete[] array;
   }

