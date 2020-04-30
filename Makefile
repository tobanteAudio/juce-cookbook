.PHONY: pdf clean stats format
default: pdf

# PDF
PDF_SOURCE = README.md
PDF_NAME = tobanteAudio-JUCE-Cookbook.pdf
PDF_OUTPUT_DIR = dist

# JUCE generated
BUILD_DIR = Builds
LIBRARY_DIR = JuceLibraryCode

# OpenGL
GL_BASIC_PATH = opengl/opengl-basic
GL_SHADER_PATH = opengl/opengl-shader
GL_MODEL_PATH = opengl/opengl-model

.PHONY: pdf
pdf:
	mkdir -p $(PDF_OUTPUT_DIR)
	gitbook pdf . $(PDF_OUTPUT_DIR)/$(PDF_NAME)

.PHONY: dev
dev:
	gitbook serve  --debug

.PHONY: clean
clean:
	rm -rf $(PDF_OUTPUT_DIR)
	rm -rf _book

.PHONY: stats
stats:
	cloc README.md SUMMARY.md chapters

.PHONY: format
format:
	find $(GL_BASIC_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	find $(GL_SHADER_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	find $(GL_MODEL_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i

