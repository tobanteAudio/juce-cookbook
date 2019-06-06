.PHONY: pdf format
default: pdf

# OPENGL
OPENGL_BASIC_PATH = opengl/opengl-basic/Source
OPENGL_SHADER_PATH = opengl/opengl-shader/Source

pdf:
	mdpdf README.md

stats:
	@cloc README.md $(OPENGL_BASIC_PATH) $(OPENGL_SHADER_PATH)

format:
	@find $(OPENGL_BASIC_PATH) -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	@find $(OPENGL_SHADER_PATH) -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
