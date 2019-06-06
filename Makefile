.PHONY: pdf clean stats format
default: pdf

# PDF
PDF_SOURCE = README.md
PDF_NAME = tobanteAudio-JUCE-Cookbook.pdf
PDF_OUTPUT_DIR = dist

# JUCE generated
BUILD_DIR = Builds
LIBRARY_DIR = JuceLibraryCode

# Animation
ANIMATION_PATH = animation

# OpenGL
GL_BASIC_PATH = opengl/opengl-basic
GL_SHADER_PATH = opengl/opengl-shader
GL_MODEL_PATH = opengl/opengl-model

pdf:
	@mkdir -p $(PDF_OUTPUT_DIR)
	@mdpdf $(PDF_SOURCE) $(PDF_OUTPUT_DIR)/$(PDF_NAME)

clean:
	@rm -rf $(PDF_OUTPUT_DIR)

	@rm -rf $(ANIMATION_PATH)/$(BUILD_DIR)
	@rm -rf $(GL_BASIC_PATH)/$(BUILD_DIR)
	@rm -rf $(GL_SHADER_PATH)/$(BUILD_DIR)
	@rm -rf $(GL_MODEL_PATH)/$(BUILD_DIR)

	@rm -rf $(ANIMATION_PATH)/$(LIBRARY_DIR)
	@rm -rf $(GL_BASIC_PATH)/$(LIBRARY_DIR)
	@rm -rf $(GL_SHADER_PATH)/$(LIBRARY_DIR)
	@rm -rf $(GL_MODEL_PATH)/$(LIBRARY_DIR)

stats:
	@cloc README.md $(ANIMATION_PATH) $(GL_BASIC_PATH) $(GL_SHADER_PATH) $(GL_MODEL_PATH)

format:
	@find $(ANIMATION_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	@find $(GL_BASIC_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	@find $(GL_SHADER_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	@find $(GL_MODEL_PATH)/Source -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
