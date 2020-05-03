# Setup

## Project Types

- [Official JUCE: Choosing the right Projucer template for your application ](https://docs.juce.com/master/tutorial_choosing_projucer_template.html)

## Project Management

If you have multiple projects on your machine that use JUCE, you get to a problem where you update to a new release and now you have to check all of your projects if they still compile & work. Using git submodules solves this problem. You essentially have a copy of JUCE for each of your projects and the exact version is saved in your git history. Know updating to new JUCE version can be done on a per project basis.

```sh
cd $PROJECT_ROOT
mkdir 3rd_party
git submodule add https://github.com/juce-framework/JUCE 3rd_party/JUCE

# optional
cd 3rd_party/JUCE
git checkout juce6
```

### Projucer

- Update module paths to new location
- Make sure it's done for each exporter

### CMake

- Update path in `add_subdirectory`
