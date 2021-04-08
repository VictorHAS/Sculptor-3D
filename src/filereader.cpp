#include "filereader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

FileReader::FileReader()
{
}

vector<FiguraGeometrica *> FileReader::parse(string filename)
{
  vector<FiguraGeometrica *> figure;
  ifstream file;
  stringstream ss;
  string s, command;

  file.open(filename.c_str());
  if (!file.is_open())
  {
    cout << "Error ao abrir o arquivo txt" << endl;
    exit(0);
  }

  while (file.good())
  {
    getline(file, s); // Read a line from stream into a string.
    ss.clear();       // [Re]sets the error state.
    ss.str(s);        // Setting a new buffer.
    ss >> command;    // Generic extractor for rvalue stream

    // sadly we can't use switch case with string in c++

    if (command.compare("dim") == 0)
    {
      ss >> dimx >> dimy >> dimz; // setting dimensions in (x,y,z)
    }
    else if (command.compare("putvoxel") == 0)
    {
      int x, y, z;
      ss >> x >> y >> z >> r >> g >> b >> a;
      figure.push_back(new PutVoxel(x, y, z, r, g, b, a));
    }
    else if (command.compare("cutvoxel") == 0)
    {
      int x, y, z;
      ss >> x >> y >> z;
      figure.push_back(new CutVoxel(x, y, z));
    }
    else if (command.compare("putbox") == 0)
    {
      int x0, x1, y0, y1, z0, z1;
      ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
      figure.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
    }
    else if (command.compare("cutbox") == 0)
    {
      int x0, x1, y0, y1, z0, z1;
      ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
      figure.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
    }
    else if (command.compare("putsphere") == 0)
    {
      int xcenter, ycenter, zcenter, radius;
      ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
      figure.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
    }
    else if (command.compare("cutsphere") == 0)
    {
      int xcenter, ycenter, zcenter, radius;
      ss >> xcenter >> ycenter >> zcenter >> radius;
      figure.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
    }
    else if (command.compare("putellipsoid") == 0)
    {
      int xcenter, ycenter, zcenter, rx, ry, rz;
      ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
      figure.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
    }
    else if (command.compare("cutellipsoid") == 0)
    {
      int xcenter, ycenter, zcenter, rx, ry, rz;
      ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
      figure.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
    }
  }
  return (figure);
}

int FileReader::getDimx()
{
  return dimx;
}

int FileReader::getDimy()
{
  return dimy;
}

int FileReader::getDimz()
{
  return dimz;
}
