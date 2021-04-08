#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/**
 * @brief FiguraGeometrica its a abstract class.
 * @details The class serves to represent geometrical figures in general, where each Class of each type of geometrical figure can be "drawn" in Sculpture.
 */
class FiguraGeometrica
{
protected:
  float r, g, b, a;

public:
  /**
     * @brief ~FiguraGeometrica : Destructor of class FiguraGeometrica
     */
  virtual ~FiguraGeometrica(){};
  /**
     * @brief draw : Makes a figure be drawn in Sculpture
     * @param s: Allocated sculpture that will receive the figure
     */
  virtual void draw(Sculptor &s) = 0;
  FiguraGeometrica();
};

#endif // FIGURAGEOMETRICA_H