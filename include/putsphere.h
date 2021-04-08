#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Enables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] 
 * @details A partir da classe PutEsphere, será escrito "putesphere" no arquivo de leitura da escultura dentre os valores: centro x, y, z e raio r.
 */
class PutSphere : public FiguraGeometrica
{
   int xcenter, ycenter, zcenter, radius;

public:
   /**
     * @brief Putsphere : Enables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] 
     * @param xcenter : x axis coordinate 
     * @param ycenter : y axis coordinate 
     * @param zcenter : z axis coordinate
     * @param radius : radius of sphere
     * @param r : red channel [0-256] 
     * @param g : green channel [0-256]
     * @param b : blue channel [0-256]
     * @param a : opacity [0-1]
     */
   PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
   /**
     * @brief ~PutSphere : Destructor of class PutSphere
     */
   ~PutSphere(){};
   /**
     * @brief draw : Makes a figure be drawn in Sculpture
     * @param s: Allocated sculpture that will receive the figure
     */
   void draw(Sculptor &s);
};

#endif // PUTSPHERE_H