#include <iostream>
#include <string>

using namespace std;

#ifndef _CLASS_VETOR_
#define _CLASS_VETOR_

/*
  Definição da classe Vetor, uma lista encadeada com tipo de dados abstrato.
*/

template <typename T> class Vetor {
private:
  // Estrutura de um nó (node) da lista, contém o dado do tipo T (abstrato) e uma referência para o nó seguinte
  struct node {
    T data;
    node *next;
  };

  // Ponteiro para o nó no inicio da lista
  node *head;

  // Ponteiros para nodes temporários, usados para auxiliar funções
  node *current;
  node *temp;

  // Tamanho da lista
  int n_size;

public:
  // Construtor padrão
  Vetor();
  // Destrutor padrão
  ~Vetor();
  // Retorna o tamanho da lista
  int size();
  // Adiciona um elemento a lista
  bool add(T i_);
  // Remove um elemento da lista
  bool remove(int i);
  // Imprime a lista
  void show();
  // Retorna o elemento no índice i (inutilizado)
  T at(int i);
  // Ordena a lista
  bool sort(int (*funcCompara)(T data1, T data2));
};

template <typename T> Vetor<T>::Vetor() {
  // Inicializa os ponteiros e o tamanho
  head = nullptr;
  current = nullptr;
  temp = nullptr;
  n_size = 0;
}

template <typename T> Vetor<T>::~Vetor() {
  // Remove todos os nós da lista
  while (head != nullptr) {
    remove(0);
  }
}

// Retorna o tamanho
template <typename T> int Vetor<T>::size() { return n_size; }

template <typename T> bool Vetor<T>::add(T i_) {
  try {
    // Cria um novo nó com o dado obtido
    node *n = new node;
    n->next = NULL;
    n->data = i_;

    // Checa se o novo node será o primeiro da lista
    if (head != NULL) {
      // Caso não seja, percorre a lista até o final e adiciona o nó
      current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = n;
    } else {
      // Caso seja, atribui esse nó ao ponteiro 'head'
      head = n;
    }
    // Incrementa o tamanho
    n_size++;
    return true;

  } catch (...) {
    return false;
  }
}

template <typename T> bool Vetor<T>::remove(int i) {
  try {
    // Checa se o índice é válido
    if (i >= this->size()) {
      throw runtime_error("Valor de índice inválido");
    }

    node *temp = nullptr;
 
    // Se o nó sendo removido for o primeiro da lista, faz com que 'head' seja o próximo nó
    if (i == 0) {
      temp = head;
      head = head->next;
      delete temp;

      n_size--;
      return true;
    }
    
    // Percorre a lista até encontrar o nó desejado
    current = head;
    while (i > 1) {
      current = current->next;
      i--;
    }
    // Remove o nó
    temp = current->next;
    current->next = current->next->next;
    delete temp;

    // Diminui o tamanho
    n_size--;
    return true;
  } catch (runtime_error e) {
    return false;
  }
}

template <typename T> void Vetor<T>::show(){
  // Percorre toda lista imprimindo cada nó
  current = head;
  int count = 0;
  while (current != NULL) {
    if (current->next != NULL){
      cout << "[" << count << "] " << current->data << " -> ";
    } else {
      cout << "[" << count << "] " << current->data << endl;
    }
    
    current = current->next;
    count++;
  }
}

template <typename T> T Vetor<T>::at(int i) {
  if (i >= this->size()) {
    throw runtime_error("Valor de índice inválido");
  }
  current = head;
  while (i > 0) {
    current = current->next;
    i--;
  }
  T pivot = current->data;
  current = nullptr;
  return pivot;
}

template <typename T>
bool Vetor<T>::sort(int (*funcCompara)(T data1, T data2)) {
  // Bubblesort para ordenar a lista
  for (int i = 0; i < this->size(); i++) {
    for (int j = 1; j < this->size() - i; j++) {
      if (funcCompara(this->at(j - 1), this->at(j)) > 0) {
        current = head;
        for (int l = 0; l < j - 1; l++) {
          current = current->next;
        }
        T pivot = current->data;
        current->data = current->next->data;
        current->next->data = pivot;
      }
    }
  }
  return true;
}

#endif