#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include "vetor.h"

using namespace std;

// Definição das funções auxiliares

// Função para comparar valores (usada na ordenação da lista)
template <typename T> int compare(T n1, T n2) {
  // Checa se o valor anterior é maior que o posterior
  if (n1 < n2) {
    // Retorna 1 caso maior
    return -1;
  } else if (n1 == n2) {
    // Retorna 0 caso igual
    return 0;
  } else {
    // Retorna -1 caso menor
    return 1;
  }
}

// Função template para o menu
template <typename T>
void menu(Vetor<T> &vetor)
{
    int operacao = -1;
    while (operacao != 0)
    {
        cout << "\n----======= Escolha uma operação =======----\n";
        cout << "> 1. Adicionar\n";
        cout << "> 2. Remover\n";
        cout << "> 3. Mostrar\n";
        cout << "> 4. Ordenar\n";
        cout << "> 0. Sair\n";
        cout << "Operação: ";
        cin >> operacao;

        switch (operacao)
        {
        case 1:
            adicionar(vetor);
            break;
        case 2:
            remover(vetor);
            break;
        case 3:
            mostrar(vetor);
            break;
        case 4:
            ordenar(vetor);
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Operação inválida!\n";
            break;
        }
    }
}

// Função template para adicionar elementos
template <typename T>
void adicionar(Vetor<T> &vetor)
{
    T elemento;
    cout << "\nDigite o elemento a ser adicionado: ";
    cin >> elemento;
    vetor.add(elemento);
    cout << "Elemento adicionado com sucesso!\n";
}

// Função template para remover elementos
template <typename T>
void remover(Vetor<T> &vetor)
{
    int elemento;
    cout << "\nDigite o índice do elemento a ser removido: ";
    cin >> elemento;
    if (vetor.remove(elemento))
    {
        cout << "Elemento removido com sucesso!\n";
    }
    else
    {
        cout << "Elemento não encontrado!\n";
    }
}

// Função template para mostrar a lista
template <typename T>
void mostrar(Vetor<T> &vetor)
{
    cout << "Elementos do vetor ([Índice] valor):\n";
    vetor.show();
    
    cout << "Pressione Enter para sair...";
    cin.ignore(); // Ignora o caractere de nova linha pendente no buffer de entrada.
    cin.get();    // Espera o usuário pressionar Enter.
}


// Função template para ordenar elementos
template <typename T>
void ordenar(Vetor<T> &vetor)
{
    vetor.sort(*compare<T>);
    cout << "Vetor ordenado com sucesso!\n";
}


#endif