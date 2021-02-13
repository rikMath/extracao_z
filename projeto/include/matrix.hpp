#include <iostream>
#include <string>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:

        std::string** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();
        Matrix(std::ifstream &myFile);
        Matrix(const Matrix& that);


        // // Destrutor
        ~Matrix();


        // // Getters e Setters
        inline int getRows() const{return nRows+1;};
        inline int getCols() const{return nCols+1;};
        std::string get(int row, int col) const;

        void set(int row, int col, std::string value);

        // Operadores
        std::string* operator[] (int);

        // // Variados
        void print() const;
};

#endif
