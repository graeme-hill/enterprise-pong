#pragma once

class StandardMaterial
{
public:
	StandardMaterial(std::string name) :
		_shader(name),
		_mvp(0)
	{ }

	ShaderParameter &mvp() { return _mvp; }
	Shader &shader() { return _shader; }

private:
	Shader _shader;
	ShaderParameter _mvp;
};
