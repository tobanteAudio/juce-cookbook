.PHONY: pdf clean stats format
default: pdf

PDF_NAME = JUCE-Cookbook.pdf
DIST_DIR = dist


.PHONY: pdf
pdf:
	mkdir -p $(DIST_DIR)
	gitbook pdf . $(DIST_DIR)/$(PDF_NAME)

.PHONY: html
html:
	mkdir -p $(DIST_DIR)
	gitbook build . $(DIST_DIR)/html

.PHONY: dev
dev:
	gitbook serve --debug

.PHONY: spellcheck
spellcheck:
	@which mdspell
	mdspell "chapters/**/*.md"
	mdspell README.md
	mdspell SUMMARY.md

.PHONY: spellcheck-report
spellcheck-report:
	@which mdspell
	mdspell -r "chapters/**/*.md"
	mdspell -r README.md
	mdspell -r SUMMARY.md

.PHONY: clean
clean:
	rm -rf $(DIST_DIR)
	rm -rf _book

.PHONY: stats
stats:
	cloc README.md SUMMARY.md chapters

.PHONY: format
format:
	find . -iname '*.h' -o -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
	
