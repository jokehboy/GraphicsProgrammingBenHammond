#version 400

layout(location= 0) in vec3 Position;
layout(location= 2) in vec3 Normals;


out vec3 normal;
uniform mat4 transform;

void main()
{
	normal = vec3(transform*vec4(Normals,0.0));
	gl_Position = transform * vec4(Position,1.0);

}
