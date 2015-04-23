#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "rayCylinder.h"


////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayCylinder::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}

BoundingBox3D RayCylinder::setBoundingBox(void){
	Point3D p;
	p=Point3D(radius,height/2,radius);
	bBox=BoundingBox3D(center+p,center-p);
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayCylinder::drawOpenGL(int materialIndex){
    if(this->material->index != materialIndex){
        this->material->drawOpenGL();
    }
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glTranslatef(center[0], center[1] - (height/2), center[2]);
    GLUquadricObj *cylinder = gluNewQuadric();
    gluQuadricNormals(cylinder, GLU_SMOOTH);
    gluQuadricOrientation(cylinder, GLU_OUTSIDE);
    GLint t = this->openGLComplexity;
    
    glRotatef(-90,0,0,0);
    gluCylinder(cylinder, this->radius, this->radius, this->height, t, t);
    glPopMatrix();
    gluDeleteQuadric(cylinder);
    
    //top disk
    glPushMatrix();
    glTranslatef(center[0], center[1] + this->height/2, center[2]);
    glRotatef(-90,0,0,0);
    GLUquadricObj *disk1 = gluNewQuadric();
    gluQuadricNormals(dis1, GLU_SMOOTH);
    gluDisk(disk1, 0, radius, t, t);
    glPopMatrix();
    gluDeleteQuadric(disk1);
    
    //bottom disk
    glPushMatrix();
    glTranslatef(center[0], center[1] - this->height/2, center[2]);
    glRotatef(-90,0,0,0);
    GLUquadricObj *disk2 = gluNewQuadric();
    gluQuadricNormals(disk2, GLU_SMOOTH);
    gluDisk(disk2, 0, radius, t, t);
    glPopMatrix();
    gluDeleteQuadric(disk2);
    
	return this->material->index;
}
