#include <iostream>

struct Node {
   int data;
   Node* prev;
   Node* next;

   Node(int data) : data(data), prev(nullptr), next(nullptr)
   {
   }
};

class LinkedList {
public:
   Node* head;
   Node* tail;

   LinkedList() : head(nullptr), tail(nullptr)
   {
   }

   ~LinkedList()
   {
      while (head != nullptr)
      {
         popFront();
      }
   }

   Node* pushFront(int data)
   {
      Node* ptr = new Node(data);
      ptr->next = head;
      if (head != nullptr)
      {
         head->prev = ptr;
      }
      if (tail == nullptr)
      {
         tail = ptr;
      }
      head = ptr;
      return ptr;
   }

   Node* pushBack(int data)
   {
      Node* ptr = new Node(data);
      ptr->prev = tail;
      if (tail != nullptr)
      {
         tail->next = ptr;
      }
      if (head == nullptr)
      {
         head = ptr;
      }
      tail = ptr;
      return ptr;
   }

   void popFront()
   {
      if (head == nullptr)
      {
         std::cout << "Удалять нечего! Список и так пуст." << std::endl;
         return;
      }
      Node* ptr = head->next;
      if (ptr != nullptr)
      {
         ptr->prev = nullptr;
      }
      else
      {
         tail = nullptr;
      }
      delete head;
      head = ptr;
   }

   void popBack()
   {
      if (tail == nullptr)
      {
         std::cout << "Удалять нечего! Список и так пуст." << std::endl;
         return;
      }
      Node* ptr = tail->prev;
      if (ptr != nullptr)
      {
         ptr->next = nullptr;
      }
      else
      {
         head = nullptr;
      }
      delete tail;
      tail = ptr;
   }

   Node* getAt(int index)
   {
      Node* ptr = head;
      for (int i = 0; i < index; i++)
      {
         if (ptr == nullptr)
         {
            return ptr;
         }
         ptr = ptr->next;
       }
      return ptr;
   }

   Node* operator[] (int index)
   {
      return getAt(index);
   }

   Node* insert(int index, int data)
   {
      Node* right = getAt(index);
      if (right == nullptr)
      {
         return pushBack(data);
      }
      Node* left = right->prev;
      if (left == nullptr)
      {
         return pushFront(data);
      }
      Node* ptr = new Node(data);
      ptr->prev = left;
      ptr->next = right;
      left->next = ptr;
      right->prev = ptr;
      return ptr;
   }

   void erase(int index)
   {
      Node* ptr = getAt(index);
      if (ptr == nullptr)
      {
         std::cout << "Не могу удалить! Нету элемента с таким индексом!" << std::endl;
         return;
      }
      if (ptr->prev == nullptr)
      {
         popFront();
         return;
      }
      if (ptr->next == nullptr)
      {
         popBack();
         return;
      }
      Node* left = ptr->prev;
      Node* right = ptr->next;
      left->next = right;
      right->prev = left;
      delete ptr;
   }

   void print()
   {
      Node* ptr = head;
      while (ptr != nullptr)
      {
         std::cout << ptr->data << " ";
         ptr = ptr->next;
      }
      std::cout << std::endl;
   }
};


int main()
{
   setlocale(LC_ALL, "Rus");
   LinkedList list;

   list.pushBack(1);
   list.pushBack(2);
   list.pushBack(3);
   list.pushBack(4);

   list.print();

   std::cout << list[1]->data << std::endl;
  
   list.insert(2, -5);
   list.insert(33, -9);

   list.print();

   list.erase(2);
   list.erase(44);

   list.print();
}

