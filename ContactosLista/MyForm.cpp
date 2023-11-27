#include "MyForm.h"
#include <iostream>
#include <string>
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ContactosLista::MyForm form;
    Application::Run(% form);
}

/*int siz = 10;

int modulo(std::string a){ 
  return a.length() % siz;
}

class Vertex{
public:
  Vertex *next;
  std::string value;
  Vertex(std::string value) { this->value = value; }
};

class HashTable {
private:
  Vertex *head, *tail;

public:
  HashTable() {
    head = tail = nullptr;
  }
  void insert(std::string val, HashTable *table);
  void search(std::string val, HashTable *table);
  void remove(std::string val, HashTable *table);
  void print(HashTable *table);
};

void HashTable::insert(std::string val, HashTable *table) {
  int i = modulo(val);
  Vertex *vtx = new Vertex(val);
  if (table[i].tail == nullptr) {
    table[i].head = table[i].tail = vtx;
    return;
  }
  table[i].tail->next = vtx;
  table[i].tail = vtx;
}

void HashTable::search(std::string val, HashTable *table) {
  int i = modulo(val);
  if (table[i].head == nullptr) {
      std::cout<<"No se encontro el valor "<<val<< std::endl;
    return;
  }
  Vertex *temp = table[i].head;
  int pos=0, notfound=1;;
  while (temp != nullptr) {
    if (temp->value==val){
      notfound=0;
      break;
    }
    pos++;
    temp = temp->next;
  }
  if(notfound){
      std::cout<<"No se encontro el valor "<<val<< std::endl;
    return;
  }
  std::cout << "El valor " << val << " se encuentra en la posición " << i << "," << pos << std::endl;
  }

void HashTable::remove(std::string val, HashTable *table) {
  int i = modulo(val);
  if (table[i].head == nullptr) {
      std::cout<<"No existe ese valor";
    return;
  }
  Vertex *temp = table[i].head;
  if (temp->value == val) {
    if(temp==nullptr){
      table[i].head=nullptr;
      delete temp;
      std::cout << "Se elimino el valor "<<val<< std::endl;
      return;
    }
    table[i].head = table[i].head->next;
    delete temp;
    std::cout << "Se elimino el valor "<<val<< std::endl;
    return;
  }
  while (temp->next != nullptr) {
    if ((temp->next)->value==val){
      break;
    }
    temp = temp->next;
  }
  if (temp == table[i].tail) {
    temp->next = nullptr;
    tail = temp;
    delete temp;
    std::cout << "Se elimino el valor "<<val<< std::endl;
    return;
  }
  Vertex *aft = temp->next;
  temp->next = aft->next;
  delete aft;
  std::cout << "Se elimino el valor "<<val<< std::endl;
}

void HashTable::print(HashTable *table) {
  for (int i = 0; i < siz; i++) {
    if (table[i].head == nullptr) {
        std::cout << "_ ";
    }else{
      Vertex *temp = table[i].head;
      while (temp != nullptr) {
          std::cout << temp->value << "->";
        temp = temp->next;
      }
      delete temp;
    }
    std::cout << std::endl;
  }
}*/
