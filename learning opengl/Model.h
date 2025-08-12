#pragma once

#include "Shader.h"      // your Shader class definition
#include <glad/glad.h>   // for OpenGL types and functions (GLuint, glGenBuffers, etc.)
#include <glad/glad.h>   // OpenGL GLuint, VAO, VBO, EBO, gl* functions
#include <glm/glm.hpp>   // glm::vec2, glm::vec3
#include <string>        // std::string
#include <vector>        // for std::vector
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "stb_image.h"
#include "Mesh.h"

using namespace std;

class Model {
public:
	Model(const char* path);
	void Draw(Shader& shader);

private:
	// model data
	vector<Mesh> meshes;
	string directory;
	vector<Texture> textures_loaded;

	void loadModel(string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};