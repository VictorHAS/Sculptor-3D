#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Class PutEllipsoid enables all voxels that satisfy the ellipsoid equation and assigns them the current drawing color
 */
class PutEllipsoid : public FiguraGeometrica
{
  int xcenter, ycenter, zcenter, rx, ry, rz;

public:
  /**
    * @brief PutEllipsoid : Enables all voxels that satisfy the ellipsoid equation
    * @param xcenter : x axis coordinate 
    * @param ycenter : y axis coordinate 
    * @param zcenter : z axis coordinate
    * @param rx : radius of ellipsoid in x
    * @param ry : radius of ellipsoid in y
    * @param rz : radius of ellipsoid in z
    * @param r : red channel [0-256] 
    * @param g : green channel [0-256]
    * @param b : blue channel [0-256]
    * @param a : opacity [0-1]
    */
  PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
  /**
     * @brief ~PutEllipsoid : Destructor of class PutEllipsoid
     */
  ~PutEllipsoid(){};
  /**
     * @brief draw : Makes a figure be drawn in Sculpture
     * @param s: Allocated sculpture that will receive the figure
     */
  void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H