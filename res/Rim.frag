#version 400

out vec4 color;

uniform mat4 u_pm; //Uniform projection matrix
uniform mat4 u_vm; //Uniform view matrix

in vec3 vNorm;
in vec4 vPos;

void main()
{
	vec3 n = normalize(mat3(u_vm) * vNorm);
	vec3 p = vec3(u_vm * vPos);
	vec3 v = normalize(-p);
	float vdn = 1.0 - max(dot(v,n),0.0);

	color.a = 1.0;
	color.rgb = vec3(smoothstep(0.6,1.0,vdn));
	

}