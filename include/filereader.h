#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include "figurageometrica.h"
#include "sculptor.h"
#include <string>

/**
 * @brief Class FileReader is responsible for reading the *.txt file
 * @details The class is used to read the dimensions input file that contains the dimensions of the Sculpture in x, y and z. And you receive which type of figure should be drawn or deleted from the Sculpture, in each line of the * .txt file 
 */
class FileReader
{
   int dimx, dimy, dimz;
   float r, g, b, a;

public:
   /**
     * @brief FileReader : Standard constructor FileReader    
     */
   FileReader();
   std::vector<FiguraGeometrica *> parse(std::string filename);
   /**
     * @brief getDimx : X dimension of the Sculpture 
     */
   int getDimx();
   /**
     * @brief getDimy : Y dimension of the Sculpture
     */
   int getDimy();
   /**
     * @brief getDimz : Z dimension of the Sculpture
     */
   int getDimz();
};

#endif // FILEREADER_H