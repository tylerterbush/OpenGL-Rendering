#include <math.h>
#include <GL/glut.h>
#include "rayPointLight.h"
#include "rayScene.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RayPointLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
Point3D RayPointLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
int RayPointLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	return 0;
}
Point3D RayPointLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}


//////////////////
// OpenGL stuff //
//////////////////
void RayPointLight::drawOpenGL(int index){
    GLfloat directional_values[4] = {this->location[0], this->location[1], this->location[2], 1.0};
    GLfloat color_values[4] = {this->color[0], this->color[1], this->color[2], 1.0};
    
    //need to set attenuation values
    glLightf(GL_LIGHT0 + index, GL_CONSTANT_ATTENUATION, this->constAtten);
    glLightf(GL_LIGHT0 + index, GL_LINEAR_ATTENUATION, this->linearAtten);
    glLightf(GL_LIGHT0 + index, GL_QUADRATIC_ATTENUATION, this->quadAtten);
    glLightfv(GL_LIGHT0 + index, GL_POSITION, directional_values);
    
    glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, color_values);
    glLightfv(GL_LIGHT0, GL_AMBIENT, color_values);
    glLightfv(GL_LIGHT0, GL_EMISSION, color_values);
    glLightfv(GL_LIGHT0, GL_SPECULAR, color_values);
    glEnable(GL_LIGHT0 + index);
}