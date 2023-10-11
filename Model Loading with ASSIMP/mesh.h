#pragma once

#include <string>
#include <vector>
#include "shader_s.h"
#include <glm/glm/glm.hpp>

// Today I Learned:
// structs have sequential memory
/*
* Thanks to this useful property we can directly pass 
* a pointer to a large list of Vertex structs as the buffer's data
* and they translate perfectly to what glBufferData expects as its argument
* (see the setupMesh() function)
*/ 

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
	std::string path;
};


class Mesh 
{
public:
	//mesh data
	std::vector<Vertex>			vertices;
	std::vector<unsigned int>   indices;
	std::vector<Texture>		textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void Draw(Shader& shader);

private:
	// render data
	unsigned int VAO, VBO, EBO;
	void setupMesh(); // initializes the buffers

};

	