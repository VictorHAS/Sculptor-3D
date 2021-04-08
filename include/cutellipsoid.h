#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Class CutEllipsoid disables all voxels that satisfy the ellipsoid equation
 */
class CutEllipsoid : public FiguraGeometrica
{
  int xcenter, ycenter, zcenter, rx, ry, rz;

public:
  /**
    * @brief CutEllipsoid : Defines elipse to be removed
    * @param xcenter : x axis coordinate 
    * @param ycenter : y axis coordinate 
    * @param zcenter : z axis coordinate
    * @param rx : radius of ellipsoid in x
    * @param ry : radius of ellipsoid in y
    * @param rz : radius of ellipsoid in z
    */
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
    * @brief ~CutEllipsoid : Destructor of class CutEllipsoid
    */
  ~CutEllipsoid(){};
  /**
    * @brief draw : Makes a figure be drawn in Sculpture
    * @param s: Allocated sculpture that will receive the figure
    */
  void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H