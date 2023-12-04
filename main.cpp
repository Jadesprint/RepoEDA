#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

const int TABLE_SIZE = 10;

class HashNode {
public:
    int key;
    string value;
    HashNode* next;

    HashNode(int key, string value) : key(key), value(value), next(nullptr) {}
};

int Part(vector<string>& arr, int start, int end) {
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

void QS(vector<string>& arr, int start, int end) {
    if (start < end) {
        int pivot = Part(arr, start, end);
        QS(arr, start, pivot - 1);
        QS(arr, pivot + 1, end);
    }
}

class HashMap {
private:
    HashNode** htable;

public:
    HashMap() {
        htable = new HashNode*[TABLE_SIZE]();
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode* entry = htable[i];
            while (entry != nullptr) {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
    }

    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void Insert(int key, string value) {
        int hash_val = HashFunc(key);
        HashNode* prev = nullptr;
        HashNode* entry = htable[hash_val];

        while (entry != nullptr) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new HashNode(key, value);
            if (prev == nullptr) {
                htable[hash_val] = entry;
            }
            else {
                prev->next = entry;
            }
        }
        else {
            entry->value = value;
        }
    }

    void Remove(int key) {
        int hash_val = HashFunc(key);
        HashNode* entry = htable[hash_val];
        HashNode* prev = nullptr;

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            cout << "No hay nada en la posición " << key << endl;
            return;
        }

        if (prev != nullptr) {
            prev->next = entry->next;
        }
        else {
            htable[hash_val] = entry->next;
        }

        delete entry;
        cout << "Elemento borrado exitosamente" << endl;
    }

    void DisplayHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* ptr = htable[i];
        if (ptr != nullptr) {
            cout << "Index " << i << ": ";

            while (ptr != nullptr) {
                cout << "(" << ptr->key << ", " << ptr->value << ")";
                ptr = ptr->next;

                if (ptr != nullptr) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
}

    int Search(int key) {
        bool flag = false;
        int hash_val = HashFunc(key);
        HashNode* entry = htable[hash_val];

        while (entry != nullptr) {
            if (entry->key == key) {
                cout << entry->value << " ";
                flag = true;
            }
            entry = entry->next;
        }

        if (!flag) {
            return -1;
        }

        return 0;
    }

    void QuickSort(int key) {
        vector<string> v;
        bool flag = false;
        int hash_val = HashFunc(key);
        HashNode* entry = htable[hash_val];

        cout << "Lista original\n";
        while (entry != nullptr) {
            if (entry->key == key) {
                cout << entry->value << " ";
                v.push_back(entry->value);
                flag = true;
            }
            entry = entry->next;
        }

        cout << endl;
        QS(v, 0, v.size() - 1);

        cout << "Lista ordenada\n";
        for (string element : v)
            cout << element << " ";

        cout << endl;

        if (!flag) {
            cout << "No hay nada en la posicion " << key << endl;
        }
    }
};

int main() {
    HashMap hash;
    int key;
    string value;
    int choice;
    int bandera = 1;

    do {
        cout << "\n----------------------" << endl;
        cout << "Aplicacion de contactos" << endl;
        cout << "----------------------" << endl;
        cout << "1. Insertar elemento a la tabla" << endl;
        cout << "2. Buscar elemento por llave" << endl;
        cout << "3. Borrar elemento por llave" << endl;
        cout << "4. Mostrar tabla" << endl;
        cout << "5. Ordenar listas" << endl;
        cout << "6. Salir" << endl;
        cout << "Tu opcion: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Inserta un elemento de la tabla: ";
            cin >> value;
            cout << "Inserta la llave para el elemento: ";
            cin >> key;
            hash.Insert(key, value);
            break;

        case 2:
            cout << "Inserta la llave del elemento buscado: ";
            cin >> key;
            cout << "Elemento en " << key << ": ";
            if (hash.Search(key) == -1) {
                cout << "No hay nada en la posición " << key << endl;
            }
            break;

        case 3:
            cout << "Ingresa la llave que deseas remover: ";
            cin >> key;
            hash.Remove(key);
            break;

        case 4:
            cout << "La tabla es: " << endl;
            hash.DisplayHash();
            break;

        case 5:
            cout << "Dame el índice para ordenar: ";
            cin >> key;
            hash.QuickSort(key);
            break;

        case 6:
            bandera = 0;
            break;

        default:
            cout << "\nSelecciona una opción válida\n";
        }

    } while (bandera);

    return 0;
}

