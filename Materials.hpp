#pragma once

#include "xe/File.hpp"

class StandardMaterial
{
public:
	StandardMaterial(std::string name) :
		_shader(
			xe::File::readVertShaderText(name),
			xe::File::readFragShaderText(name)),
		_mvp(0)
	{ }

	ShaderParameter &mvp() { return _mvp; }
	Shader &shader() { return _shader; }

private:
	Shader _shader;
	ShaderParameter _mvp;
};
