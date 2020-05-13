//Version number
#version 400
//Layout Qualifer
layout( location = 0 ) out vec4 fragcolor;

uniform sampler2D diff;
in vec2 TextureCoords;

void main()
{
    fragcolor = texture2D(diff,TextureCoords);
}