#pragma once

#include <vector>        // for std::vector
#include <glad/glad.h>   // for OpenGL types and functions (GLuint, glGenBuffers, etc.)
#include <string>        // std::string
#include <glad/glad.h>   // OpenGL GLuint, VAO, VBO, EBO, gl* functions
#include <glm/glm.hpp>   // glm::vec2, glm::vec3
#include "Shader.h"      // your Shader class definition

using namespace std;

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	string type;
	string path;
};

class Mesh {
public:
	// mesh data
	vector<Vertex>			vertices;
	vector<unsigned int>	indices;
	vector<Texture>			textures;

	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

	void Draw(Shader& shader);

private:
	// render data
	unsigned int VAO, VBO, EBO;

	void setupMesh();
};