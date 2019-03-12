#ifndef TEXTUREMODEL_H
#define TEXTUREMODEL_H

#include <GL/glew.h>

class TextureModel{
public:
    void SetTextureUnit(GLuint t){texture_unit_=t;}
    void SetTexture(GLuint t){texture_ = t;}
    void SetTextureSunSlonce(GLuint y){texture_sun_slonce_ = y;}
    void SetTextureMoon(GLuint u){texture_moon_ = u;}
protected:
    GLuint texture_unit_;
    GLuint texture_;
    GLuint texture_sun_slonce_;
    GLuint texture_moon_;
};

#endif // TEXTUREMODEL_H
