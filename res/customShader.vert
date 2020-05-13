#version 440

layout (location=0) in vec3 Position;
layout (location=2) in vec3 Normals;

out vec3 normal;
out vec4 position;
out vec3 modelDirection;

in mat4 model;


void main()
{
	normal = Normals;

	mat4 modelMatrix = model;
	mat4 inverseModelMatrix =  inverse(modelMatrix);


}