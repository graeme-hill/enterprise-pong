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

	xe::TShaderParameter &mvp() { return _mvp; }
	xe::TShader &shader() { return _shader; }

private:
	xe::TShader _shader;
	xe::TShaderParameter _mvp;
};
