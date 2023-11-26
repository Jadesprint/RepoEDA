#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
const int TABLE_SIZE = 10;
class HashNode{
  public:
      int key;
      string value;
      HashNode* next;
      HashNode(int key, string value){
        this->key = key;
        this->value = value;
        this->next = NULL;
      }
};

int Part(vector<string> &arr, int start, int end) {

  string pivot = arr[end];
  int pIndex = start;
  for (int i = start; i < end; i++) {
    if (arr[i] <= pivot) {
      swap(arr[i], arr[pIndex]);
      pIndex++;
    }
  }
  swap(arr[pIndex], arr[end]);
  return pIndex;
}
void QS(vector<string> &arr, int start, int end) {

  if (start < end) {
    int pivot = Part(arr, start, end);
    QS(arr, start, pivot - 1);
    QS(arr, pivot + 1, end);
  }
}

class HashMap{
  private:
  HashNode** htable;
  public:
  void DisplayHash(){
    for (int i=0; i < TABLE_SIZE; i++){
      if (htable[i] != NULL){
        cout << "Index " << i << ": ";
      }
        HashNode* ptr = htable[i];
        while (ptr != NULL){
        cout << "(" << ptr->key << ", " << ptr->value << ")";
        ptr = ptr->next;
        if (ptr != NULL){ 
        cout << "->";}  
        else{
        cout << endl;}
        }

    }



  }
  HashMap(){
      htable = new HashNode*[TABLE_SIZE];
      for (int i = 0; i < TABLE_SIZE; i++){
          htable[i] = NULL;
  }
  }
  ~HashMap(){
      for (int i = 0; i < TABLE_SIZE; ++i){
          HashNode* entry = htable[i];
          while (entry != NULL){
              HashNode* prev = entry;
              entry = entry->next;
              delete prev;
              }
      }
      delete[] htable;
  }

  int HashFunc(int key){
      return key % TABLE_SIZE;
  }


  void Insert(int key, string value){
      int hash_val = HashFunc(key);
      HashNode* prev = NULL;
      HashNode* entry = htable[hash_val];
      while (entry != NULL){
          prev = entry;
          entry = entry->next;
      }
      if (entry == NULL){
          entry = new HashNode(key, value);
          if (prev == NULL){
              htable[hash_val] = entry;
          }
    else{
              prev->next = entry;
          }
      }
      else{
          entry->value = value;
      }
  }

  void Remove(int key){
      int hash_val = HashFunc(key);
      HashNode* entry = htable[hash_val];
      HashNode* prev = NULL;
      if (entry == NULL || entry->key != key){
        cout<<"No hay nada en  "<<key<<endl;
          return;
      }
      while (entry->next != NULL){
          prev = entry;
          entry = entry->next;
      }
      if (prev != NULL){
          prev->next = entry->next;
      }
      delete entry;
      cout<<"Elemento borrado"<<endl;
  }

  int Search(int key){
      bool flag = false;
      int hash_val = HashFunc(key);
      HashNode* entry = htable[hash_val];
      while (entry != NULL){
          if (entry->key == key){
              cout<<entry->value<<" ";
              flag = true;
          }
          entry = entry->next;
      }
      if (!flag){
          return -1;
      }
    }


  int QuickSort(int key){
      vector<string> v;
      bool flag = false;
      int hash_val = HashFunc(key);
      HashNode* entry = htable[hash_val];
      cout<<"Lista original\n";
      while (entry != NULL){
          if (entry->key == key){
              cout<< entry->value<<" ";
              v.push_back(entry->value);
              flag = true;
          }
          entry = entry->next;
      }
        cout << endl;
        QS(v, 0, v.size()-1);
        cout << endl;
        cout<<"Vector ordenado\n";
        for(string element:v)
        cout << element << " ";

      if (!flag){
          return -1;
      }
  }
};




int main(){
    HashMap hash;
    int key;
    string value;
    int choice;
    while(1){
        cout<<"\n----------------------"<<endl;
        cout<<"Aplicacion de contactos"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insertar elemento a la tabla"<<endl;
        cout<<"2.Buscar elemento por llave"<<endl;
        cout<<"3.Borrar elemento por llave"<<endl;
        cout<<"4. Mostra tabla"<<endl;
        cout <<"5. Ordenar listas"<< endl;
        cout<<"6.Salir"<<endl;
        cout<<"Tu opcion: ";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Inserta un elemento de la tabla: ";
            cin>>value;
            cout<<"Inserta la llave para el elemento: ";
            cin>>key;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"Inserta la llave del elemento buscado ";
            cin>>key;
            cout<<"Elemento en  "<<key<<" : ";
            if (hash.Search(key) == -1){
            cout<<"No hay nada en la posicion "<<key<<endl;
            }continue;
            break;
        case 3:
            cout<<"Ingresa la llave que deseas remover: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:

            cout<<"La tabla es: "<<endl;
            hash.DisplayHash();
            break;

        case 5:
            cout << "Dame el indice para ordenar: " << endl;
            cin >> key;
            hash.QuickSort(key);
            main();



        case 6:
            exit(1);

        default:
           cout<<"\nSelecciona una opcion valida\n";
        }

    }   
        return 0;


}
