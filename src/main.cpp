#include <iostream>
#include <string>
#include <fstream>
#include "../include/queue.hpp"
#include "../include/matrix.hpp"
#include "../include/map.hpp"
#include "../include/robot.hpp"
#include "../include/base.hpp"
#include "../include/order.hpp"
#include "../include/robotArray.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  // Criação Objetos de Arquivos fornecidos pela Linha de Comando
  ifstream mapFile (argv[1]);
  ifstream orderFile(argv[2]);
  Map mapa(mapFile);
  mapa.print();
  cout<<mapa.move_to(9,9)<<endl;
  cout << mapa.destroy_alien(4,1) << endl;
  // Criação da Base
  // Base base(mapFile);
  // base.print_map();

  // Criação das ordens
  // Orders orders(orderFile, base);

  // Impressão recursos da Base
  // base.print_resources();

  return 0;
}
