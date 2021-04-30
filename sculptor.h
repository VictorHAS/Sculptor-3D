#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <vector>

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

using namespace std;

struct Voxel
{
  float r, g, b;
  float a;
  bool isOn;
};

enum {
    XY,ZX,YZ
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
    * @param _nx : dimensao em x da escultura 3D (número de linhas)
    * @param _ny : dimensao em y da escultura 3D (númer de colunas)
    * @param _nz : dimensao em z da escultura 3D (número de planos)
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
    * @brief putBox :Enables all voxels in the range x∈[x0, x1], y∈[y0, y1], z∈[z0, z1] and assigns them the current drawing color
    * @param x0 : point 0 in x axis coordinate
    * @param x1 : point 1 in x axis coordinate
    * @param y0 : point 0 in y axis coordinate
    * @param y1 : point 1 in y axis coordinate
    * @param z0 : point 0 in z axis coordinate
    * @param z1 : point 1 in z axis coordinate
    */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
    * @brief cutBox : Disables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] and assigns them the current drawing color
    * @param x0 : point 0 in x axis coordinate
    * @param x1 : point 1 in x axis coordinate
    * @param y0 : point 0 in y axis coordinate
    * @param y1 : point 1 in y axis coordinate
    * @param z0 : point 0 in z axis coordinate
    * @param z1 : point 1 in z axis coordinate
    */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
    * @brief putSphere : Enables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] and assigns them the current drawing color
    * @param xcenter : x axis coordinate
    * @param ycenter : y axis coordinate
    * @param zcenter : z axis coordinate
    * @param radius : radius of sphere
    */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
    * @brief cutSphere : Disables all voxels that satisfy the equation of the sphere
    * @param xcenter : x axis coordinate
    * @param ycenter : y axis coordinate
    * @param zcenter : z axis coordinate
    * @param radius : radius of sphere
    */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
    * @brief putEllipsoid : Enables all voxels that satisfy the ellipsoid equation and assigns them the current drawing color
    * @param xcenter : x axis coordinate
    * @param ycenter : y axis coordinate
    * @param zcenter : z axis coordinate
    * @param rx : radius of ellipsoid in x
    * @param ry : radius of ellipsoid in y
    * @param rz : radius of ellipsoid in z
    */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
    * @brief cutEllipsoid : Disables all voxels that satisfy the ellipsoid equation
    * @param xcenter : x axis coordinate
    * @param ycenter : y axis coordinate
    * @param zcenter : z axis coordinate
    * @param rx : radius of ellipsoid in x
    * @param ry : radius of ellipsoid in y
    * @param rz : radius of ellipsoid in z
    */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
    * @brief getPlane : Return matrix 2D in type plane(XY,ZX,YZ)
    * @param position : slider value
    * @param type : plane type
    */
  vector<vector<Voxel>> getPlane(int position, int type);
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
