// Transform.cpp: implementation of the Transform class.
#include<iostream>
#include "Transform.h"
#define DtoR(degree) (pi*degree/180)
mat3 normal_mat3 = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
mat3 vechelp(const vec3& axis)
{
	return mat3(axis[0] * axis, axis[1] * axis, axis[2] * axis);
}
mat3 OrthogonalMatrix(const vec3& axis)
{
	return glm::transpose(mat3(0, -axis[2], axis[1], axis[2], 0, -axis[0], -axis[1], axis[0], 0));
}
//Please implement the following functions:
// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
	mat3 rmat = glm::cos(DtoR(degrees))*normal_mat3+(1-glm::cos(DtoR(degrees)))*vechelp(axis)+glm::sin(DtoR(degrees))*OrthogonalMatrix(axis);//return matrix
	return rmat;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	mat3 rmat3 = rotate(degrees, up);
	eye = rmat3 * eye;
	std::cout << "x:" << eye[0] << "y" << eye[1] << "z" << eye[2] << std::endl;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	vec3 cross_vec = glm::normalize(glm::cross( up,eye));
	mat3 rmat3 = rotate(degrees, cross_vec);
	eye = rmat3 * eye;
	up = glm::transpose(glm::inverse(rmat3))*up;
	/*eye = mat3(1, 0, 0, 0, 0, -1, 0, 1, 0)*eye;
	up = vec3(0, 0, -1);*/
	std::cout<<"x:" << eye[0]<<" y:"<<eye[1]<<" z:"<<eye[2]<<"up:"<<up[0]<<" "<<up[1]<<" "<<up[2]<<std::endl;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}