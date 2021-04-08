#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Class PutVoxel enables the voxel at position (x, y, z) with color (r,g,b,a)
 */
class PutVoxel : public FiguraGeometrica
{
   int x, y, z;

public:
   /**
    * @brief putVoxel : Enables the voxel at position (x, y, z)
    * @param x : x axis coordinate 
    * @param y : y axis coordinate 
    * @param z : z axis coordinate 
    * @param r : red channel [0-256] 
    * @param g : green channel [0-256]
    * @param b : blue channel [0-256]
    * @param a : opacity [0-1]
    */
   PutVoxel(int x, int y, int z, float r, float g, float b, float a);
   /**
     * @brief ~PutVoxel : Destructor of class PutVoxel
     */
   ~PutVoxel(){};
   /**
     * @brief draw : Makes a figure be drawn in Sculpture
     * @param s: Allocated sculpture that will receive the figure
     */
   void draw(Sculptor &s);
};

#endif // PUTVOXEL_H