#include <string>
#include<fstream>
#include <iostream>
#include "../include/matrix.hpp"

Matrix::Matrix(){
    nRows = 0;
    nCols = 0;
    m = new std::string*;
}

Matrix::Matrix(std::ifstream &myFile){
  m = new std::string*;
  std::string t;
  while(! (myFile >> t)){

    std::cout << t << std::endl;

  }
}

Matrix::Matrix(const Matrix& that){
  nRows = that.getRows()-1;
  nCols = that.getCols()-1;
  m = new std::string*[that.getRows()]; // Cria um array de ponteiros de rows posições
  for(int i = 0; i < that.getRows(); i++){
    m[i] = new std::string[that.getCols()]; // cria um array de doubles de cols posições

    for (int j = 0; j < that.getCols(); j++) {
      m[i][j] = that.get(i+1, j+1);
    }
  }
}

Matrix::~Matrix() {
  for(int i = 0; i<= nRows; i++){
    delete[] m[i]; // deleção de arrays de doubles
  }
  delete[] m; // deleção de array de pointers
}


std::string Matrix::get(int row, int col) const {
    if(row <= this->getRows() && col <= this->getCols() && !(nRows == 0 && nCols == 0)){
      return m[row-1][col-1];
    }
    else{
      throw "Erro";
    }
}
//
void Matrix::print() const {
  if(nRows == 0 && nCols == 0){
    std::cout << "Matriz vazia" << std::endl;
    return;
  }

  for(int i = 0; i <= this->nRows; i++){

    for (int j = 0; j <= this->nCols; j++) {
      std::cout << m[i][j] << "   ";
    }
    std::cout << '\n';
  }
}
