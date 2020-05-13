#version 400
layout (location = 0) in vec3 Position;
layout (location = 2) in vec3 Normal;

out vec4 position;
out vec3 normalDirection;

uniform mat4 modelMatrix;
uniform mat4 transform;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	position = vec4(Position,1.0);

	mat4 modelMatrixTest = modelMatrix;
	mat4 modelMatrixInverseTest = inverse(modelMatrixTest);

	normalDirection = normalize(vec3(vec4(Normal,0.0) * modelMatrixInverseTest));

	gl_Position = transform *vec4(position);

}