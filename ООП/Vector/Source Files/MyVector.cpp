#include "MyVector.h"

   MyVector::MyVector()                                                                  //пустой вектор
   {
      size = 0;
      capacity = 10;
      int* array = new int[capacity];
   }

   MyVector::MyVector(int size): size(size), capacity(size*1.5), array(new int[capacity])  //вектор состоит из size чисел, каждое равно 0
   {
      for(int i=0; i<size; i++)
      {
         array[i] = 0;
      }
   }

   MyVector::MyVector(int size, int value): size(size), capacity(size*1.5), array(new int[capacity])  //вектор состоит из size чисел, каждое равно value
   {
      for(int i=0; i<size; i++)
      {
         array[i] = value;
      }
   }

   void MyVector::show()
   {
      for(int i=0; i<size; i++)
      {
         std::cout << array[i] << " ";
      }
      std::cout << std::endl;
   }

   void MyVector::push_back(int value)
   {
      array[size] = value;
      size++;
      if (size == capacity)
      {
         capacity = size * 1.5;
         int* array2 = new int[capacity];
         for(int i=0; i<size; i++)
         {
            array2[i] = array[i];
         }
         delete[] array;
         array = array2;
      }
   }

   void MyVector::pop_back()
   {
      if(size == 0)
      {
         std::cout << "Вектор итак пуст!" << std::endl;
         return;
      }
      array[size-1] = 0;
      size--;
   }

   void MyVector::insert(int index, int value)
   {
      if(index < 0 || index > size)
      {
         std::cout << "Ошибка! Попытка вставить элемент по несуществующему индексу." << std::endl;
         return;
      }
      size++;
      if (size == capacity)
      {
         capacity = size * 1.5;
         int* array2 = new int[capacity];
         for(int i=0; i<size; i++)
         {
            array2[i] = array[i];
         }
         delete[] array;
         array = array2;
      }
      int temp1, temp2;
      temp1 = array[index];
      array[index] = value;
      for(int i=index+1; i<size; i++)
      {
         temp2 = array[i];
         array[i] = temp1;
         temp1 = temp2;
      }
   }

   void MyVector::remove(int index)
   {
      if (size == 0)
      {
         std::cout << "Вектор итак пуст!" << std::endl;
         return;
      }
      size--;
      for(int i=index; i<size; i++)
      {
         array[i] = array[i+1];
      }
   }

   MyVector::~MyVector()
   {
      delete[] array;
   }
