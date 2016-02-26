#include <iostream>

#include "Mesh.h"

Mesh::Mesh(const glm::vec3* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, const glm::vec3* normals)
    : drawCount_(numVertices)
{
    glGenVertexArrays(1, &vertexArrayObject_);
    glBindVertexArray(vertexArrayObject_);
    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers_);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers_[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW); //SINCE STATIC DATA IS BEING USED
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers_[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(normals[0]), normals, GL_STATIC_DRAW); //SINCE STATIC DATA IS BEING USED
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers_[INDEX_VB]); //element_array_buffer as it references data in another array
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(vertices[0]), &indices[0], GL_STATIC_DRAW); //STATIC DATA

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vertexArrayObject_);
}

void Mesh::Draw()
{
    glBindVertexArray(vertexArrayObject_);
    glDrawElements(GL_TRIANGLES, drawCount_, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
