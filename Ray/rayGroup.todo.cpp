#include <stdlib.h>
#include <GL/glut.h>
#include "rayGroup.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayGroup::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}

BoundingBox3D RayGroup::setBoundingBox(void){
	Point3D* pList;
	BoundingBox3D tBBox;
	pList=new Point3D[sNum*2];
	for(int i=0;i<sNum;i++){
		tBBox=shapes[i]->setBoundingBox();
		pList[2*i  ]=tBBox.p[0];
		pList[2*i+1]=tBBox.p[1];
	}
	tBBox=BoundingBox3D(pList,sNum*2);
    
	delete[] pList;
	bBox=tBBox.transform(getMatrix());
	return bBox;
}

int StaticRayGroup::set(void){
	return 1;
}
//////////////////
// OpenGL stuff //
//////////////////
int RayGroup::getOpenGLCallList(void){
    int id = glGenLists(1);
    glNewList(id,GL_COMPILE);
    this->drawOpenGL(-1);
    glEndList();
    
	return id;
}

int RayGroup::drawOpenGL(int materialIndex){
    
    glMatrixMode(GL_MODELVIEW);
    if(this->openGLCallListID == 0){
        Matrix4D t = this->getMatrix();
        GLfloat t_matrix[16] = {t.operator()(0,0), t.operator()(0,1), t.operator()(0,2), t.operator()(0,3), t.operator()(1,0), t.operator()(1,1),
            t.operator()(1,2), t.operator()(1,3), t.operator()(2,0), t.operator()(2,1), t.operator()(2,2), t.operator()(2,3),
            t.operator()(3,0), t.operator()(3,1), t.operator()(3,2), t.operator()(3,3)};
    
        int lastMaterialIndexThatWeUsed = materialIndex;
        
        for(int i=0; i < sNum; i++){
            glPushMatrix();
            glMultMatrixf(t_matrix);
            lastMaterialIndexThatWeUsed = shapes[i]->drawOpenGL(lastMaterialIndexThatWeUsed);
            glPopMatrix();
        }
    
       // printf("Not call list \n");
    }
    else{
        //printf("Call List \n");
        glCallList(this->openGLCallListID);
    }
	return -1;
}

/////////////////////
// Animation Stuff //
/////////////////////
Matrix4D ParametrizedRayGroup::getInverseMatrix(void) {
    return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedRayGroup::getNormalMatrix(void) {
    return Matrix4D::IdentityMatrix();
}

Matrix4D ParametrizedEulerAnglesAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedClosestRotationAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedRotationLogarithmAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedQuaternionAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
