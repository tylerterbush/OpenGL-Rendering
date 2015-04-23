#include "rayScene.h"
#include <GL/glut.h>
#include <math.h>


///////////////////////
// Ray-tracing stuff //
///////////////////////

Point3D RayScene::Reflect(Point3D v,Point3D n){
	return Point3D();
}

int RayScene::Refract(Point3D v,Point3D n,double ir,Point3D& refract){
	return 0;
}

Ray3D RayScene::GetRay(RayCamera* camera,int i,int j,int width,int height){
	return Ray3D();
}

Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	return Point3D();
}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void){
    if(this->tex != NULL){
        printf("Tex \n");
        glBindTexture(GL_TEXTURE_2D, this->tex->openGLHandle);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glEnable(GL_TEXTURE_2D);
    }
    else{
        glDisable(GL_TEXTURE_2D);
    }
    
    GLfloat mat_diffuse[4] = {this->diffuse[0], this->diffuse[1], this->diffuse[2], 1.0};
    GLfloat mat_ambient[4] = {this->ambient[0], this->ambient[1], this->ambient[2], 1.0};
    GLfloat mat_specular[4] = {this->specular[0], this->specular[1], this->specular[2], 1.0};
    GLfloat mat_emissive[4] = {this->emissive[0], this->emissive[1], this->emissive[2], 1.0};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);
    glMaterialf(GL_FRONT, GL_SHININESS, this->specularFallOff);
    
    
    
}
void RayTexture::setUpOpenGL(void){
    glGenTextures(1,&this->openGLHandle);
    glBindTexture(GL_TEXTURE_2D, this->openGLHandle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST);
    
    gluBuild2DMipmaps(GL_TEXTURE_2D,GL_RGBA,this->img->width(),this->img->height(),GL_RGBA,GL_UNSIGNED_BYTE,&this->img->pixel(0,0));
}
