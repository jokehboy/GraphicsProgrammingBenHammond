#version 330
uniform vec3 modelColor;

float shadowColorFactor = 0.3;
float litColorFactor = 0.5;
vec3 shadowColor = vec3(0.2, 0, 0.12);
vec3 litColor = vec3(0.6, 0, 0);
in float normalDotLight;
in vec3 ReflectVec;
in vec3 ViewVec;


out vec4 result;

void main()
{
 vec3 overallShadowColor = min(shadowColor + shadowColorFactor * modelColor, 1.0);
 vec3 overallLitColor = min(litColor + litColorFactor * modelColor, 1.0);
 vec3 finalShadedColor = mix(overallShadowColor, overallLitColor, normalDotLight);

 vec3 normalizedReflection = normalize(ReflectVec);
 vec3 normalizedView = normalize(ViewVec);
 float spec = pow(max(dot(normalizedReflection, normalizedView), 0.0), 128);

 //8,32,64,128

 if (gl_FrontFacing)
 {
	result = vec4(min(finalShadedColor + spec, 1.0), 1.0);
 }
 else
 {
	result = vec4(1, 1, 1, 1);
 }

}
