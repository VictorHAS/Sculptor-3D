#include <iostream>
#include <vector>
#include <fstream>
#include "sculptor.h"
#include "filereader.h"
#include "figurageometrica.h"

using namespace std;

int main()
{
  Sculptor *sculptor;

  FileReader parser;

  vector<FiguraGeometrica *> figs;

  figs = parser.parse("input.txt");

  sculptor = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

  for (size_t i = 0; i < figs.size(); i++)
  {
    figs[i]->draw(*sculptor);
  }

  sculptor->writeOFF((char *)"sculpture.off");
  for (size_t i = 0; i < figs.size(); i++)
  {
    delete figs[i];
  }
  delete sculptor;
  return 0;
}