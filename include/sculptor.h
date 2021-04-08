#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief Voxel struct:
     * Voxels (volume elements), equivalent to the pixels of digital images, but in 3 dimensions.
     * In Voxels it is possible to store information such as color and color opacity, necessary to idealize the elements of a sculpture.
     * @param r : red channel [0-1]
     * @param g : green channel [0-1]
     * @param b : blue channel [0-1]
     * @param alpha : opacity [0-1]
     * @param isOn : defines if the voxel is visible or not, 0 (disabled); 1 (enabled) 
 */

struct Voxel
{
  float r, g, b;
  float a;
  bool isOn;
};

/**
 * @brief Sculptor class:
 * The Sculptor class creates a dynamically allocated structure and provides methods for manipulating the pixels of a 3d array 
 */
class Sculptor
{
protected:
  /**
   * @brief v: matriz 3D alocada dinamicamente que armazena todos os voxels
   */
  Voxel ***v;
  /**
   * @brief nx: dimensao em x (numero de linhas)
   */
  int nx;
  /**
   * @brief ny: dimensao em y (numero de colunas)
   */
  int ny;
  /**
   * @brief nz: dimensao em z (numero de planos)
   */
  int nz;
  /**
   * @brief r: intensidade atual da cor vermelha, varia entre [0 - 1]
   */
  float r;
  /**
   * @brief g: intensidade atual da cor verde, varia entre [0 - 1]
   */
  float g;
  /**
   * @brief b: intensidade atual da cor azul, varia entre [0 - 1]
   */
  float b;
  /**
   * @brief a: intensidade atual da opacidade, varia entre [0 - 1]
   */
  float a;

public:
  /**
    * @brief Sculptor: Init Sculptor class
    * @param _nx : dimension in x (number of lines)
    * @param _ny : dimension in y (number of columns)
    * @param _nz : dimension in z (number of plans)
    */
  Sculptor(int _nx, int _ny, int _nz);
  /**
    * @brief ~Sculptor: Destructor of class Sculptor
    */
  ~Sculptor();
  /**
     * @brief setColor : Set color of the voxel
     * @param r : red channel [0-1]
     * @param g : green channel [0-1]
     * @param b : blue channel [0-1]
     * @param alpha : opacity [0-1]
     */
  void setColor(float r, float g, float b, float alpha);
  /**
    * @brief putVoxel : Enables the voxel at position (x, y, z) (making isOn = true) and assign it the current drawing color
    * @param x : x axis coordinate 
    * @param y : y axis coordinate 
    * @param z : z axis coordinate 
    */
  void putVoxel(int x, int y, int z);
  /**
    * @brief cutVoxel : Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
    * @param x : x axis coordinate 
    * @param y : y axis coordinate 
    * @param z : z axis coordinate 
    */
  void cutVoxel(int x, int y, int z);
  /**
    * @brief cleaner : Remove all hide blocks
    */
  void cleaner();
  /**
    * @brief writeOFF : Save the sculpture in the OFF format
    * @param filename : path to create file and name ex: /home/victor/sculptor.off
    */
  void writeOFF(char *filename);
};

#endif // SCULPTOR_H