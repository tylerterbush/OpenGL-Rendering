#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySphere.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RaySphere::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}
BoundingBox3D RaySphere::setBoundingBox(void){
	Point3D p=Point3D(radius,radius,radius);
	bBox=BoundingBox3D(center+p,center-p);
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RaySphere::drawOpenGL(int materialIndex){
    if(this->material->index != materialIndex){
        this->material->drawOpenGL();
    }
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(center[0],center[1],center[2]);
    GLUquadric *quad = gluNewQuadric();
    GLdouble r = radius;
    //GLint slices,stacks;
    //slices = stacks = 1000;
    GLint t = this->openGLComplexity;
    
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricDrawStyle(quad, GLU_FILL);
    //float specReflection[] = {this->material->specular[0], this->material->specular[1], this->material->specular[2], 1.0f };
    //glMaterialfv(GL_FRONT, GL_SPECULAR, specReflection);
    //glMateriali(GL_FRONT, GL_SHININESS, this->material->specularFallOff);
    
    gluSphere(quad, radius, t, t);
    glPopMatrix();
    gluDeleteQuadric(quad);
    
	return this->material->index;
}
