#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySpotLight.h"


////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RaySpotLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
Point3D RaySpotLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
int RaySpotLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	return 0;
}
Point3D RaySpotLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}

//////////////////
// OpenGL stuff //
//////////////////
void RaySpotLight::drawOpenGL(int index){
    GLfloat spot_direction[4] = {this->direction[0], this->direction[1], this->direction[2], 1.0};
    GLfloat position_values[4] = {this->location[0], this->location[1], this->location[2], 1.0};
    GLfloat color_values[4] = {this->color[0], this->color[1], this->color[2], 1.0};
    glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, color_values);
    glLightfv(GL_LIGHT0 + index, GL_POSITION, position_values);
    glLightfv(GL_LIGHT0 + index, GL_SPOT_DIRECTION, spot_direction);
    
    //need to set attenuation values
    glLightf(GL_LIGHT0 + index, GL_CONSTANT_ATTENUATION, this->constAtten);
    glLightf(GL_LIGHT0 + index, GL_LINEAR_ATTENUATION, this->linearAtten);
    glLightf(GL_LIGHT0 + index, GL_QUADRATIC_ATTENUATION, this->quadAtten);
    
    //set cutoff angle value. Initially at 180. Needs to be between 0-90
    glLightf(GL_LIGHT0 + index, GL_SPOT_EXPONENT, this->dropOffRate);
    glLightf(GL_LIGHT0 + index, GL_SPOT_CUTOFF, this->cutOffAngle * (180.0/3.1415));
    
    
    glEnable(GL_LIGHT0 + index);
}