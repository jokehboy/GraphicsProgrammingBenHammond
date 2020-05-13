#version 400

layout (location =0) in vec3 VertexPosition;
layout (location =2) in vec3 VertexNormal;

uniform mat4 transform;

out vec3 vNorm; //normal view space
out vec4 vPos; //view space position

void main()
{
	vNorm = VertexNormal;
	vPos = transform * vec4(VertexPosition,1.0);
	gl_Position = transform * vec4(VertexPosition,1.0);
}