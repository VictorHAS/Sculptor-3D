#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Class CutVoxel disables the voxel at the (x, y, z) position
 */
class CutVoxel : public FiguraGeometrica
{
   int x, y, z;

public:
   /**
     * @brief CutVoxel : Disables the voxel at the (x, y, z) position
     * @param x : x axis coordinate 
     * @param y : y axis coordinate 
     * @param z : z axis coordinate 
     */
   CutVoxel(int x, int y, int z);
   /**
     * @brief ~CutVoxel : Destructor of class CutVoxel
     */
   ~CutVoxel(){};
   /**
     * @brief draw :  Makes a figure be drawn in Sculpture
     * @param s: Allocated sculpture that will receive the figure
     */
   void draw(Sculptor &s);
};

#endif // CUTVOXEL_H