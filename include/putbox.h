#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Class PutBox enables all voxels in the range x∈[x0, x1], y∈[y0, y1], z∈[z0, z1]
 */
class PutBox : public FiguraGeometrica
{
  int x0, x1, y0, y1, z0, z1;

public:
  /**
     * @brief PutBox : :Enables all voxels in the range x∈[x0, x1], y∈[y0, y1], z∈[z0, z1]
     * @param x0 : point 0 in x axis coordinate 
     * @param x1 : point 1 in x axis coordinate 
     * @param y0 : point 0 in y axis coordinate 
     * @param y1 : point 1 in y axis coordinate 
     * @param z0 : point 0 in z axis coordinate 
     * @param z1 : point 1 in z axis coordinate 
     * @param r : red channel [0-256] 
     * @param g : green channel [0-256]
     * @param b : blue channel [0-256]
     * @param a : opacity [0-1]
     */
  PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
  /**
     * @brief ~PutBox : Destructor of class PutBox
     */
  ~PutBox(){};
  /**
     * @brief draw : Makes a figure be drawn in Sculpture
     * @param s: Allocated sculpture that will receive the figure
     */
  void draw(Sculptor &s);
};

#endif // PUTBOX_H