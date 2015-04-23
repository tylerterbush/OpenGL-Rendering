#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "rayBox.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayBox::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}
BoundingBox3D RayBox::setBoundingBox(void){
	bBox=BoundingBox3D(center-(length/2),center+(length/2));
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayBox::drawOpenGL(int materialIndex){
    if(this->material->index != materialIndex){
        this->material->drawOpenGL();
    }
    
    //front face
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(center[0] - length[0]/2, center[1] - length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] - length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] + length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] + length[1]/2, center[2] + length[2]/2);
    glEnd();
    
    //right face
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(center[0] + length[0]/2, center[1] - length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] - length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] + length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] + length[1]/2, center[2] - length[2]/2);
    glEnd();
    
    //back face
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(center[0] - length[0]/2, center[1] - length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] - length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] + length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] + length[1]/2, center[2] - length[2]/2);
    glEnd();
    
    //left face
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(center[0] - length[0]/2, center[1] - length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] - length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] + length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] + length[1]/2, center[2] - length[2]/2);
    glEnd();
    
    //bottom
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(center[0] - length[0]/2, center[1] - length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] - length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] - length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] - length[1]/2, center[2] - length[2]/2);
    glEnd();
    
    //top
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(center[0] - length[0]/2, center[1] + length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] + length[1]/2, center[2] + length[2]/2);
    glVertex3f(center[0] + length[0]/2, center[1] + length[1]/2, center[2] - length[2]/2);
    glVertex3f(center[0] - length[0]/2, center[1] + length[1]/2, center[2] - length[2]/2);
    glEnd();
    
	return this->material->index;
}
