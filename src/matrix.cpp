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
  std::string t;
  int count = 0, rows, cols;
  int current_line = 0;
  bool start = false;
  while(getline(myFile, t)){

    if(count == 0){
      rows = std::stoi(t.substr(0, t.find(" ")));
      cols = std::stoi(t.substr(t.find(" ")+1, t.length()));
      nRows=rows-1;
      nCols=cols-1;
      count++;
    }

    else{
      if(!start){
        m = new std::string*[rows]; // Cria um array de ponteiros de rows posições
        for(int i = 0; i < rows; i++){
          m[i] = new std::string[cols]; // cria um array de doubles de cols posições

        }
        start = true;
      }


      for (int i = 0; i < 2*cols; i++) {
        if (i%2 != 1){
          m[current_line][i/2] = t[i];
        }

      }
      current_line++;
    }

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
  // std::cout << "entrando destrutor matrix" << std::endl;
  for(int i = 0; i<= nRows; i++){
    delete[] m[i]; // deleção de arrays de doubles
  }
  delete[] m; // deleção de array de pointers
  // std::cout << "saindo destrutor matrix" << std::endl;
}


std::string Matrix::get(int row, int col) const {
    if(row <= this->getRows() && col <= this->getCols() && !(nRows == 0 && nCols == 0)){
      return m[row-1][col-1];
    }
    else{
      throw "Erro";
    }
}

void Matrix::set(int row, int col, std::string value) {
  this->m[row-1][col-1] = value;
}

std::string* Matrix::operator[] (int pos){
  return m[pos];
}

void Matrix::print() const {
  if(nRows == 0 && nCols == 0){
    std::cout << "Matriz vazia" << std::endl;
    return;
  }

  for(int i = 0; i <= this->nRows; i++){

    for (int j = 0; j <= this->nCols; j++) {
      std::cout << m[i][j] << " ";
    }
    std::cout << '\n';
  }
}
