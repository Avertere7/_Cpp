#ifndef TORUS_H
#define TORUS_H

#include <GL/glew.h>

#include "lightprogram.h"
#include "movablemodel.h"
#include "lightablemodel.h"
#include "materialmodel.h"
#include "texturemodel.h"
#include "indexmodel.h"
#include "matma.h"

class Torus: public IndexModel, public TextureModel, public MovableModel, public LightableModel, public MaterialModel{
 public:
    Torus(GLfloat init_velocity=10, GLfloat init_angle=0);
    void SetMaterialPrim(const Material & material){material_prim_ = material;}
    void SetMaterialPrimPri(const Material & material){material_prim_pri_ = material;}
    void SetInitAngle(GLfloat angle){angle_= angle;}
    void SetVelocity(GLfloat velocity){velocity_= velocity;}
    void Initialize(int n, int m, GLfloat R, GLfloat r);
    void Draw(const LightProgram & program) const;
    void Move(GLfloat delta_t);
    void SpeedUp();
    void SlowDown();
    void ToggleAnimated();
    void SetTexturePrim(GLuint t){texture_prim_ = t;}
    void SetTexturePrimPri(GLuint t){texture_prim_pri_ = t;}
 private:
    int n_; // mesh parameter
    int m_; // mesh parameter

    Mat4 model_matrix_prim_;
    Mat3 normal_matrix_prim_;
	Material material_prim_;

    Mat4 model_matrix_prim_pri_;
    Mat3 normal_matrix_prim_pri_;
    Material material_prim_pri_;

	GLuint texture_prim_;
    GLuint texture_prim_pri_;

    GLfloat R; //big radius
    GLfloat r; //small radius

    GLfloat angle_;
    GLfloat velocity_;
    bool animated_;

};

#endif // TORI_H
