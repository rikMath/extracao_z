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
        //
        // // Destrutor
        ~Matrix();
        //
        //
        // // Getters
        int getRows() const{return nRows+1;}; //função inline
        int getCols() const{return nCols+1;}; //função inline
        std::string get(int row, int col) const;
        //
        // // Variados
        void print() const;
};

#endif
