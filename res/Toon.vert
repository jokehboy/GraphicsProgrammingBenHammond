#version 330

layout (location = 0) in vec3 Position;
layout (location = 2) in vec3 Normals;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

vec3 LightPosition = vec3(0, 10, 4);

out vec3 ViewVec;
out vec3 viewSpacePosition;
out vec3 normalViewSpace;

out float normalDotLight;
out vec3 ReflectVec;

void main()
{

	vec3 position = vec3(model * vec4(Position, 1.0));
	vec3 tnorm = mat3(transpose(inverse(model))) * Normals;

	viewSpacePosition = position;
	normalViewSpace = Normals;

	vec3 lightVec = normalize(LightPosition - position);
	ReflectVec = normalize(reflect(-lightVec, tnorm));
	ViewVec = normalize(-position);
	normalDotLight = (dot(lightVec, tnorm) + 1.0) * 0.5;

	gl_Position = projection * view * model * vec4(Position, 1.0);
}	
