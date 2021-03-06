#pragma once

#include "xe/MeshData.hpp"
#include <vector>
#include <iostream>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Paddle
{
public:
	Paddle();
	void setPosition(glm::vec3 position);
	void translate(glm::vec3 translation);
	glm::mat4 matrix() const;
	glm::vec3 position() const { return _position; }
	float depth() const { return 1.0f; }
	float width() const { return 4.0f; }
	bool goingLeft() const { return _goingLeft; }
	bool goingRight() const { return _goingRight; }
	void goingLeft(bool val) { _goingLeft = val; }
	void goingRight(bool val) { _goingRight = val; }

	static xe::MeshData getMeshData();

private:
	void updateMatrix();

	glm::vec3 _position;
	glm::mat4 _matrix;

	bool _goingLeft;
	bool _goingRight;
};
