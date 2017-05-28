#pragma once

#include "xe/File.hpp"

class StandardMaterial
{
public:
	StandardMaterial(std::string name) :
		_shader(
			xe::File::readVertShaderText(name),
			xe::File::readFragShaderText(name)),
		_mvp(_shader, "mvp")
	{ }

	P::ShaderParameter &mvp() { return _mvp; }
	P::Shader &shader() { return _shader; }

private:
	P::Shader _shader;
	P::ShaderParameter _mvp;
};
