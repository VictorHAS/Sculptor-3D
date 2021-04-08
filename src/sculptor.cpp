#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Init Sculptor class
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
  nx = _nx;
  ny = _ny;
  nz = _nz;

  // Check if lines,columns and plans are >= 0
  if (nx <= 0 || ny <= 0 || nz <= 0)
  {
    nx = ny = nz = 0;
  }

  v = new Voxel **[nx];
  for (int i = 0; i < nx; ++i)
  {
    v[i] = new Voxel *[ny];
    for (int j = 0; j < ny; ++j)
    {
      v[i][j] = new Voxel[nz];
    }
  }
}

// Destructor of class Sculptor
Sculptor::~Sculptor()
{
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::setColor(float red, float green, float blue, float alpha)
{
  r = red;
  g = green;
  b = blue;
  a = alpha;
}

// Enables the voxel at position (x, y, z) (making isOn = true) and assign it the current drawing color
void Sculptor::putVoxel(int x, int y, int z)
{

  v[x][y][z].isOn = true;
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
}

//Disables the voxel in position (x, y, z) (making isOn = false)
void Sculptor::cutVoxel(int x, int y, int z)
{
  v[x][y][z].isOn = false;
}

void Sculptor::cleaner()
{

  int removedBlocksCount = 0;
  for (int x = 1; x < nx - 1; x++)
  {
    for (int y = 1; y < ny - 1; y++)
    {
      for (int z = 1; z < nz - 1; z++)
      {
        if (v[x][y][z].isOn && v[x + 1][y][z].isOn && v[x - 1][y][z].isOn && v[x][y + 1][z].isOn && v[x][y - 1][z].isOn && v[x][y][z + 1].isOn && v[x][y][z - 1].isOn)
        {
          cutVoxel(x, y, z);
          removedBlocksCount++;
        }
      }
    }
  }
  cout << "Blocos ocultos removidos: " << removedBlocksCount << endl;
}

void Sculptor::writeOFF(char *filename)
{
  ofstream f;
  int total = 0;
  int aux = 0;
  float lado = 0.5;
  f.open(filename);

  if (f.is_open())
  {
    cout << "Aguarde...Salvando o arquivo OFF.\n";
  }
  else
  {
    cout << "Arquivo OFF nao foi aberto\n";
    exit(1);
  }

  f << "OFF\n";

  cleaner();

  for (int x = 0; x < nx; x++)
  {
    for (int y = 0; y < ny; y++)
    {
      for (int z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn)
        {
          total++;
        }
      }
    }
  }

  f << total * 8 << " " << total * 6 << " " << 0 << endl;

  for (int x = 0; x < nx; x++)
  {
    for (int y = 0; y < ny; y++)
    {
      for (int z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn)
        {
          f << x - lado << " " << y + lado << " " << z - lado << endl;
          f << x - lado << " " << y - lado << " " << z - lado << endl;
          f << x + lado << " " << y - lado << " " << z - lado << endl;
          f << x + lado << " " << y + lado << " " << z - lado << endl;
          f << x - lado << " " << y + lado << " " << z + lado << endl;
          f << x - lado << " " << y - lado << " " << z + lado << endl;
          f << x + lado << " " << y - lado << " " << z + lado << endl;
          f << x + lado << " " << y + lado << " " << z + lado << endl;
        }
      }
    }
  }

  total = 0;

  for (int x = 0; x < nx; x++)
  {
    for (int y = 0; y < ny; y++)
    {
      for (int z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn)
        {
          f << 4 << " " << aux + 0 << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " " << v[x][y][z].r << " "
            << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
          f << 4 << " " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " " << v[x][y][z].r << " "
            << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
          f << 4 << " " << aux + 0 << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " " << v[x][y][z].r << " "
            << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
          f << 4 << " " << aux + 0 << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " " << v[x][y][z].r << " "
            << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
          f << 4 << " " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " " << v[x][y][z].r << " "
            << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
          f << 4 << " " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " " << v[x][y][z].r << " "
            << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
          aux += 8;
        }
      }
    }
  }

  if (f.is_open())
  {
    cout << "Arquivo OFF salvo!" << endl;
    f.close();
  }
}