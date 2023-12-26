#version 410 core

in vec3 fNormal;
in vec4 fPosEye;
in vec2 fTexCoords;


out vec4 fColor;

//lighting
uniform	vec3 lightPos;
uniform	vec3 lightColor;

uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;

vec3 ambient;
float ambientStrength = 0.2f;
vec3 diffuse;
vec3 specular;
float specularStrength = 0.5f;
float shininess = 32.0f;
float constant = 1.0f;
float linear = 0.0045f;
float quadratic = 0.0075f;

void computeLightComponents()
{		
	vec3 cameraPosEye = vec3(0.0f);
	
	vec3 normalEye = normalize(fNormal);	
	
	vec3 lightDirN = normalize(lightPos - fPosEye.xyz);
	
	vec3 viewDirN = normalize(cameraPosEye - fPosEye.xyz);

	float dist = length(lightPos - fPosEye.xyz);
	float att = 1.0f / (constant + linear * dist + quadratic * (dist * dist));	
		
	vec3 halfVector = normalize(lightDirN + viewDirN);
	ambient =att * ambientStrength * lightColor;
	
	diffuse = att * max(dot(normalEye, lightDirN), 0.0f) * lightColor;
	
	vec3 reflection = reflect(-lightDirN, normalEye);
	float specCoeff = pow(max(dot(viewDirN, halfVector), 0.0f), shininess);
	specular = att * specularStrength * specCoeff * lightColor;
}

void main() 
{
	computeLightComponents();

	ambient *= texture(diffuseTexture, fTexCoords).rgb;
	diffuse *= texture(diffuseTexture, fTexCoords).rgb;	
	specular *= texture(specularTexture, fTexCoords).rgb;

	vec3 color = min((ambient + diffuse) + specular, 1.0f);
    
    fColor = vec4(color, 1.0f);
}
