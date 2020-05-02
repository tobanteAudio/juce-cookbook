# Tools

## compiler

- warnings are your friend
- clang from source
- cross platform different warnings
- old versions in distros

## clang-format

Automatic formatting of source code. A must have in my option. It doesn't matter what configuration you pick, the goal is for your complete code base to look as similar as possible.

```sh
# Formats all files with endings .h .hpp .cpp inplace (overrides).
find . -iname '*.h' -o -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
```

## clang-tidy

Static analysis tool. Takes a lot of CPU to run, but finds a lot of valid issuses.

## compiler-explorer

[https://godbolt.org](https://godbolt.org/)

Online compiler. Great for testing small code snippets. Does not currently have `JUCE` installed unfortunately.

## coverage

- gcc + gcov & lcov
- clang + llvm-profdata & llvm-cov

## Makefile/Scripts

I usally wrap all the common commands in a Makefile. Just to save some typing.

```make
CONFIG ?= Release
BUILD_DIR ?= build
GENERATOR ?= Ninja

.PHONY: config
config:
	cmake -S. -B$(BUILD_DIR) -G$(GENERATOR) -DCMAKE_BUILD_TYPE=$(CONFIG)

.PHONY: build
build:
	cmake --build $(BUILD_DIR) --config $(CONFIG)

.PHONY: test
test:
	cd $(BUILD_DIR) && ctest -C $(CONFIG)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: format
format:
	find . -iname '*.h' -o -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
```
