#include <iostream>

template <typename T>
class LinkedList;

template <typename T> std::ostream& operator<<(std::ostream& out, const LinkedList<T>& lst);

template <typename T>
class LinkedList {
public:
   struct Node {
      T data;
      Node* prev;
      Node* next;

      Node(T data) : data(data), prev(nullptr), next(nullptr)
      {
      }
   };

   Node* head;
   Node* tail;

   LinkedList();

   ~LinkedList();
   
   Node* pushFront(T data);
   
   Node* pushBack(T data);
   
   void popFront();
   
   void popBack();
  
   Node* getAt(int index);
   
   Node* operator[](int index);
   
   Node* insert(int index, T data);
   
   void erase(int index);

   template <typename T1> friend std::ostream& operator<< (std::ostream& out, const LinkedList<T1>& lst);
   
};

template <typename T> LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr)
{
}

template <typename T> LinkedList<T>::~LinkedList()
{
   while (head != nullptr)
   {
      popFront();
   }
}

template <typename T> typename LinkedList<T>::Node* LinkedList<T>:: pushFront(T data)
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

template <typename T> typename LinkedList<T>::Node* LinkedList<T>:: pushBack(T data)
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

template <typename T> void LinkedList<T>:: popFront()
{
   if (head == nullptr)
   {
      throw std::logic_error("Удалять нечего! Список и так пуст.");
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

template <typename T> void LinkedList<T>:: popBack()
{
   if (tail == nullptr)
   {
      throw std::logic_error("Удалять нечего! Список и так пуст.");
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

template <typename T> typename LinkedList<T>::Node* LinkedList<T>:: getAt(int index)
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

template <typename T> typename LinkedList<T>::Node* LinkedList<T>:: operator[](int index)
{
   return getAt(index);
}

template <typename T> typename LinkedList<T>::Node* LinkedList<T>:: insert(int index, T data)
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

template <typename T> void LinkedList<T>:: erase(int index)
{
   Node* ptr = getAt(index);
   if (ptr == nullptr)
   {
      throw std::invalid_argument("Не могу удалить! Нету элемента с таким индексом!");
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

template <typename T> std::ostream& operator<<(std::ostream& out, const LinkedList<T>& lst)
{
   typename LinkedList<T>::Node* ptr = lst.head;
   while (ptr != nullptr)
   {
      out << ptr->data << " ";
      ptr = ptr->next;
   }
   return out;
}
