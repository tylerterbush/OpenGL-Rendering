#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rayTriangle.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
void RayTriangle::initialize(void){
}
double RayTriangle::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}
BoundingBox3D RayTriangle::setBoundingBox(void){
	Point3D pList[3];
	pList[0]=v[0]->position;
	pList[1]=v[1]->position;
	pList[2]=v[2]->position;
	bBox=BoundingBox3D(pList,3);
	for(int i=0;i<3;i++){
		bBox.p[0][i]-=RAYEPS;
		bBox.p[1][i]+=RAYEPS;
	}
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayTriangle::drawOpenGL(int materialIndex){
    if(this->material->index != materialIndex){
        this->material->drawOpenGL();
        //printf("MAT \n");
    }
    else{
        //printf("NO MAT \n");
    }
    glBegin(GL_TRIANGLES);
    
    float first[3] = {this->v[0]->normal[0],this->v[0]->normal[1],this->v[0]->normal[2]};
    glNormal3fv(first);
    glTexCoord2f(this->v[0]->texCoordinate[0], this->v[0]->texCoordinate[1]);
    glVertex3f(this->v[0]->position[0],this->v[0]->position[1],this->v[0]->position[2]);
    
    float second[3] = {this->v[1]->normal[0],this->v[1]->normal[1],this->v[1]->normal[2]};
    glNormal3fv(second);
    glTexCoord2f(this->v[1]->texCoordinate[0], this->v[1]->texCoordinate[1]);
    glVertex3f(this->v[1]->position[0],this->v[1]->position[1],this->v[1]->position[2]);
    
    float third[3] = {this->v[2]->normal[0],this->v[2]->normal[1],this->v[2]->normal[2]};
    glNormal3fv(third);
    glTexCoord2f(this->v[2]->texCoordinate[0], this->v[2]->texCoordinate[1]);
    glVertex3f(this->v[2]->position[0],this->v[2]->position[1],this->v[2]->position[2]);
    
    glEnd();
    
    //draw the back face of the triangle as well so we dont have to use no-cull mode
    glBegin(GL_TRIANGLES);
    
    float first1[3] = {this->v[0]->normal[0],this->v[0]->normal[1],this->v[0]->normal[2]};
    glNormal3fv(first1);
    glTexCoord2f(this->v[0]->texCoordinate[0], this->v[0]->texCoordinate[1]);
    glVertex3f(this->v[0]->position[0],this->v[0]->position[1],this->v[0]->position[2]);
    
    float third1[3] = {this->v[2]->normal[0],this->v[2]->normal[1],this->v[2]->normal[2]};
    glNormal3fv(third1);
    glTexCoord2f(this->v[2]->texCoordinate[0], this->v[2]->texCoordinate[1]);
    glVertex3f(this->v[2]->position[0],this->v[2]->position[1],this->v[2]->position[2]);
    
    float second1[3] = {this->v[1]->normal[0],this->v[1]->normal[1],this->v[1]->normal[2]};
    glNormal3fv(second1);
    glTexCoord2f(this->v[1]->texCoordinate[0], this->v[1]->texCoordinate[1]);
    glVertex3f(this->v[1]->position[0],this->v[1]->position[1],this->v[1]->position[2]);
    
    
    glEnd();
	return this->material->index;
}
