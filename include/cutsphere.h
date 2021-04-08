#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Class CutSphere Disables all voxels that satisfy the equation of the sphere;
 */
class CutSphere : public FiguraGeometrica
{
  int xcenter, ycenter, zcenter, radius;

public:
  /**
    * @brief Cutsphere : Disables all voxels that satisfy the equation of the sphere
    * @param xcenter : x axis coordinate 
    * @param ycenter : y axis coordinate 
    * @param zcenter : z axis coordinate
    * @param radius : radius of sphere
    */
  CutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
    * @brief ~CutSphere : Destructor of class CutSphere
    */
  ~CutSphere(){};
  /**
    * @brief draw : Makes a figure be drawn in Sculpture
    * @param s: Allocated sculpture that will receive the figure
    */
  void draw(Sculptor &s);
};

#endif // CUTSPHERE_H