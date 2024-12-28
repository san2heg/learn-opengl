#version 330 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;

    float emissionStrength;
    float emissionOffset;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform mat4 view;

uniform Material material;
uniform Light light;

in vec3 Normal;
in vec3 FragPos;
in vec3 LightPos;
in vec2 TexCoords;

out vec4 FragColor;
  
void main()
{
    // ambient lighting
    vec3 ambient = vec3(texture(material.diffuse, TexCoords)) * light.ambient;

    // diffuse lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(view * vec4(light.position, 1.0)) - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = (diff * vec3(texture(material.diffuse, TexCoords))) * light.diffuse;

    // specular lighting
    vec3 viewDir = normalize(-FragPos); // we're in view space, so the camera is at the origin (0,0,0)
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = (spec * vec3(texture(material.specular, TexCoords))) * light.specular;

    // emission lighting
    vec3 emission = material.emissionStrength * vec3(texture(material.emission, vec2(TexCoords.s, TexCoords.t + material.emissionOffset)));

    vec3 result = ambient + diffuse + specular + emission;
    FragColor = vec4(result, 1.0);
} 