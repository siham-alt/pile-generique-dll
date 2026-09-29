#pragma once
#include <stdexcept>
#include <string>

#ifdef PILEDLL_EXPORTS
    #define PILE_API __declspec(dllexport)
#else
    #define PILE_API __declspec(dllimport)
#endif

template <typename T>
class PILE_API Stack {   
     T* tableau;
    int capacite, taille;
    void redimensionner(int nouvelleCapacite) {
        T* nouveau = new T[nouvelleCapacite];
        for (int i = 0; i < taille; i++) nouveau[i] = tableau[i];
        delete[] tableau;
        tableau = nouveau;
        capacite = nouvelleCapacite;
    }
public:
    Stack(int capaciteInitiale = 4) : capacite(capaciteInitiale), taille(0) {
        if (capacite <= 0) capacite = 1;
        tableau = new T[capacite];
    }
    ~Stack() { delete[] tableau; }
    void push(const T& element) {
        if (taille == capacite) redimensionner(capacite * 2);
        tableau[taille++] = element;
    }
    T pop() {
        if (isEmpty()) throw std::out_of_range("Pile vide.");
        T element = tableau[--taille];
        if (taille > 0 && taille == capacite / 4) redimensionner(capacite / 2);
        return element;
    }
    T& top() {
        if (isEmpty()) throw std::out_of_range("Pile vide.");
        return tableau[taille - 1];
    }
    bool isEmpty() const { return taille == 0; }
    int getSize() const { return taille; }
    int getCapacity() const { return capacite; }
};

// Côté client : on annonce que ces instances viennent de la DLL
#ifndef PILEDLL_EXPORTS
extern template class PILE_API Stack<int>;
extern template class PILE_API Stack<double>;
extern template class PILE_API Stack<char>;
extern template class PILE_API Stack<std::string>;
#endif
