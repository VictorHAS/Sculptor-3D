#include <iostream>
#include "sculptor.h"

using namespace std;

int main(void)
{
  Sculptor v(51, 51, 51);

  v.setColor(0, 1, 0, 1.0);
  v.putEllipsoid(22, 22, 22, 8, 8, 13);
  v.setColor(1, 0, 0, 0.5);
  v.putSphere(8, 8, 10, 9);
  v.cutSphere(4, 4, 5, 3);

  v.setColor(196, 20, 40, 0.8);
  v.putBox(30, 35, 30, 35, 30, 35);
  v.cutBox(30, 32, 30, 32, 30, 32);

  v.writeOFF((char *)"sculpture.off");
}

// Usage examples
//Sculptor v(120, 120, 120);
// v.setColor(1, 0, 0, 1.0);
// v.putVoxel(2, 2, 2);
// v.setColor(0, 1, 1, 0.2);
// v.cutVoxel(2, 2, 2);
// v.putVoxel(1, 2, 2);
// v.setColor(10, 20, 30, 0.8);
// v.putEllipsoid(80, -2, 40, 3, 1, 5); // (x, y, z, rx, ry, rz)
// v.setColor(196, 157, 40, 0.8);
// v.putSphere(8, 25, 10, 9);
// v.setColor(196, 20, 40, 0.8);
// v.putBox(8, 10, 1, 25, 8, 12);
// v.setColor(206, 212, 218, 0.8);
// v.putEllipsoid(9, 1, 10, 6, 3, 3);
