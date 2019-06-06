.PHONY: pdf format
default: pdf

# OPENGL
GL_BASIC_PATH = opengl/opengl-basic/Source
GL_SHADER_PATH = opengl/opengl-shader/Source
GL_MODEL_PATH = opengl/opengl-model/Source

pdf:
	mdpdf README.md

stats:
	@cloc README.md $(GL_BASIC_PATH) $(GL_SHADER_PATH) $(GL_MODEL_PATH)

format:
	@find $(GL_BASIC_PATH) -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	@find $(GL_SHADER_PATH) -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	@find $(GL_MODEL_PATH) -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
