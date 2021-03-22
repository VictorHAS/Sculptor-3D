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

// Enables all voxels in the range x∈[x0, x1], y∈[y0, y1], z∈[z0, z1] and assigns them the current drawing color
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  for (int z = z0; z <= z1; z++)
  { // traversing plans
    for (int y = y0; y <= y1; y++)
    { // traversing columns
      for (int x = x0; x <= x1; x++)
      { //traversing lines

        putVoxel(x, y, z); // enables voxel
      }
    }
  }
}

// Disables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] and assigns them the current drawing color
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  for (int z = z0; z <= z1; z++)
  {
    for (int x = x0; x <= x1; x++)
    {
      for (int y = y0; y <= y1; y++)
      {
        cutVoxel(x, y, z); // disables voxel
      }
    }
  }
}

// Enables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] and assigns them the current drawing color
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  double distance;
  for (int z = 0; z <= nz; z++)
  {
    for (int y = 0; y <= ny; y++)
    {
      for (int x = 0; x <= nz; x++)
      {
        distance = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);
        if (distance <= pow(radius, 2))
        {
          putVoxel(x, y, z);
        }
      }
    }
  }
}

// Disables all voxels that satisfy the equation of the sphere
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  double distance;
  for (int z = 0; z <= nz; z++)
  {
    for (int y = 0; y <= ny; y++)
    {
      for (int x = 0; x <= nx; x++)
      {
        distance = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);
        if (distance <= pow(radius, 2))
        {
          cutVoxel(x, y, z);
        }
      }
    }
  }
}

// Enables all voxels that satisfy the ellipsoid equation and assigns them the current drawing color
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
  double distance;
  if (rx == 0)
  {
    for (int z = 0; z <= nz; z++)
    {
      for (int y = 0; y <= ny; y++)
      {
        distance = (pow(y - ycenter, 2) / pow(ry, 2)) + (pow(z - zcenter, 2) / pow(rz, 2));
        if (distance <= 1)
        {
          putVoxel(xcenter, y, z);
        }
      }
    }
  }
  else if (ry == 0)
  {
    for (int z = 0; z <= nz; z++)
    {
      for (int x = 0; x <= nx; x++)
      {
        distance = (pow(x - xcenter, 2) / pow(rx, 2)) + (pow(z - zcenter, 2) / pow(rz, 2));
        if (distance <= 1)
        {
          putVoxel(x, ycenter, z);
        }
      }
    }
  }
  else if (rz == 0)
  {
    for (int x = 0; x <= nx; x++)
    {
      for (int y = 0; x <= ny; y++)
      {
        distance = (pow(x - xcenter, 2) / pow(rx, 2)) + (pow(y - ycenter, 2) / pow(ry, 2));
        if (distance <= 1)
        {
          putVoxel(x, y, zcenter);
        }
      }
    }
  }
  else
  {
    for (int z = 0; z <= nz; z++)
    {
      for (int y = 0; y <= ny; y++)
      {
        for (int x = 0; x <= ny; x++)
        {
          distance = (pow(x - xcenter, 2) / pow(rx, 2)) + (pow(y - ycenter, 2) / pow(rz, 2)) + (pow(z - zcenter, 2) / pow(rz, 2));
          if (distance <= 1)
          {
            putVoxel(x, y, z);
          }
        }
      }
    }
  }
}

// Disables all voxels that satisfy the ellipsoid equation
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
  double distance;
  if (rx == 0)
  {
    for (int z = 0; z <= nz; z++)
    {
      for (int y = 0; y <= ny; y++)
      {
        distance = pow(y - ycenter, 2) / pow(ry, 2) + pow(z - zcenter, 2) / pow(rz, 2);
        if (distance <= 1)
        {
          cutVoxel(xcenter, y, z);
        }
      }
    }
  }
  else if (ry == 0)
  {
    for (int z = 0; z <= nz; z++)
    {
      for (int x = 0; x <= nx; x++)
      {
        distance = pow(x - xcenter, 2) / pow(rx, 2) + pow(z - zcenter, 2) / pow(rz, 2);
        if (distance <= 1)
        {
          cutVoxel(x, ycenter, z);
        }
      }
    }
  }
  else if (rz == 0)
  {
    for (int x = 0; x <= nx; x++)
    {
      for (int y = 0; x <= ny; y++)
      {
        distance = pow(x - xcenter, 2) / pow(rx, 2) + pow(y - ycenter, 2) / pow(ry, 2);
        if (distance <= 1)
        {
          cutVoxel(x, y, zcenter);
        }
      }
    }
  }
  else
  {
    for (int z = 0; z <= nz; z++)
    {
      for (int x = 0; x <= nx; x++)
      {
        for (int y = 0; y <= ny; y++)
        {
          distance = pow(x - xcenter, 2) / pow(rx, 2) + pow(y - ycenter, 2) / pow(rz, 2) + pow(z - zcenter, 2) / pow(rz, 2);
          if (distance <= 1)
          {
            cutVoxel(x, y, z);
          }
        }
      }
    }
  }
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
  cout << "Hide blocks removed: " << removedBlocksCount << endl;
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
    cout << "Arquivo.OFF salvo!" << endl;
    f.close();
  }
}