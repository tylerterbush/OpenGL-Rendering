#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "rayCone.h"


////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayCone::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}

BoundingBox3D RayCone::setBoundingBox(void){
	Point3D p;
	p=Point3D(radius,height/2,radius);
	bBox=BoundingBox3D(center+p,center-p);
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayCone::drawOpenGL(int materialIndex){
    if(this->material->index != materialIndex){
        this->material->drawOpenGL();
    }
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glLoadIdentity();
    
    
    glTranslatef(center[0], center[1] - (height/2), center[2]);
    GLUquadricObj *cone = gluNewQuadric();
    gluQuadricNormals(cone, GLU_SMOOTH);
    gluQuadricOrientation(cone, GLU_OUTSIDE);
    GLint t = this->openGLComplexity;
    
    glRotatef(-90,1.0,0.0,0.0);
    gluCylinder(cone, this->radius, 0, this->height, t, t);
    glPopMatrix();
    gluDeleteQuadric(cone);
    
    //bottom disk
    glPushMatrix();
    glTranslatef(center[0], center[1] - this->height/2, center[2]);
    glRotatef(-90,1.0,0.0,0.0);
    GLUquadricObj *disk2 = gluNewQuadric();
    gluDisk(disk2, 0, radius, 50, 50);
    glPopMatrix();
    gluDeleteQuadric(disk2);
	return this->material->index;
}
