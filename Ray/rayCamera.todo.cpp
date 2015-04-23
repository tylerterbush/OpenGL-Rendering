#include <GL/glut.h>
#include <math.h>
#include "rayCamera.h"



//////////////////
// OpenGL stuff //
//////////////////
void RayCamera::drawOpenGL(void){
   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(this->position[0], this->position[1], this->position[2], this->direction[0] + this->position[0],
              this->direction[1] + this->position[1], this->direction[2] + this->position[2], this->up[0], this->up[1], this->up[2]);
}
void RayCamera::rotateUp(Point3D center,float angle){
    angle /= 10;
    this->direction = this->direction + this->up * tan(angle);
    this->direction = this->direction.unit();
    this->up = this->right.crossProduct(this->direction);
    this->up = this->up.unit();
}
void RayCamera::rotateRight(Point3D center,float angle){
    angle /= 10;
    this->direction = this->direction + this->right * -tan(angle);
    this->direction = this->direction.unit();
    this->right = this->direction.crossProduct(this->up);
    this->right = this->right.unit();
}
void RayCamera::moveForward(float dist){
    if(signbit(dist)){
        this->position = this->position + (this->direction * -Point3D(.05,.05,.05));
    }
    else{
        this->position = this->position + (this->direction * Point3D(.05,.05,.05));
    }
}
void RayCamera::moveRight(float dist){
    if(signbit(dist)){
        this->position = this->position + (this->right * -Point3D(.05,.05,.05));
    }
    else{
        this->position = this->position + (this->right * Point3D(.05,.05,.05));
    }
}
void RayCamera::moveUp(float dist){
    if(signbit(dist)){
        this->position = this->position + (this->up * -Point3D(.05,.05,.05));
    }
    else{
        this->position = this->position + (this->up * Point3D(.05,.05,.05));
    }
}
