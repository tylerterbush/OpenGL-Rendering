#include <math.h>
#include <GL/glut.h>
#include "rayDirectionalLight.h"
#include "rayScene.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RayDirectionalLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
Point3D RayDirectionalLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
int RayDirectionalLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	return 0;
}
Point3D RayDirectionalLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}

//////////////////
// OpenGL stuff //
//////////////////
void RayDirectionalLight::drawOpenGL(int index){
    GLfloat directional_values[4] = {-this->direction[0], -this->direction[1], -this->direction[2], 0.0};
    GLfloat color_values[4] = {this->color[0], this->color[1], this->color[2], 1.0};
    glLightfv(GL_LIGHT0 + index, GL_POSITION, directional_values);
    
    glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, color_values);
    glLightfv(GL_LIGHT0 + index, GL_AMBIENT, color_values);
    glLightfv(GL_LIGHT0 + index, GL_EMISSION, color_values);
    glLightfv(GL_LIGHT0 + index, GL_SPECULAR, color_values);
    glEnable(GL_LIGHT0 + index);
}