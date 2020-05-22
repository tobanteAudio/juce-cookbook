# Unit Tests

## Catch2

- [github.com/catchorg/Catch2](https://github.com/catchorg/Catch2)
- [Example Project: tobanteAudio/juce-6-demo](https://github.com/tobanteAudio/juce-6-demo)

### Include Catch2

```cmake
option(YOURPLUGIN_BUILD_TESTS "Build the unit tests with Catch2" ON)

if(YOURPLUGIN_BUILD_TESTS)
    list (APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/Catch2/contrib")
    enable_testing()
    add_subdirectory(3rd_party/Catch2 EXCLUDE_FROM_ALL)
    include(CTest)
    include(Catch)
endif()
```

### Write Test

#### main

We need to write a custom main for Catch, since we need to initialize & shutdown JUCE.

```cpp
#include "JuceHeader.h"

#define CATCH_CONFIG_RUNNER
#include "catch2/catch.hpp"

int main(int argc, char* argv[])
{
    juce::initialiseJuce_GUI();
    int result = Catch::Session().run(argc, argv);
    juce::shutdownJuce_GUI();
    return result;
}
```

#### processor

Simple tests checking the plug-in name & if a mono bus layout is supported.

```cpp
#include "catch2/catch.hpp"

#include "YourProcessor.hpp"

TEST_CASE("processor: Name", "[processor]")
{
    auto processor = YourProcessor {};
    REQUIRE(processor.getName() == juce::String {"Plugin Name"});
}


TEST_CASE("processor: BusesLayoutSupportMono", "[processor]")
{
    auto processor     = YourProcessor {};
    auto layout        = juce::AudioProcessor::BusesLayout {};
    layout.inputBuses  = juce::AudioChannelSet::mono();
    layout.outputBuses = juce::AudioChannelSet::mono();

    REQUIRE(processor.isBusesLayoutSupported(layout));
}

```

### Link against SharedCode

Link the unit test target to the shared code of your plug-in.

```cmake
juce_add_plugin(YourPlugin ...)

# ...

if(YOURPLUGIN_BUILD_TESTS)
    add_executable(YourPlugin_Tests)
    target_sources(YourPlugin_Tests PRIVATE Source/main_test.cpp)
    catch_discover_tests(YourPlugin_Tests)
    target_link_libraries(YourPlugin_Tests PRIVATE YourPlugin Catch2::Catch2)
endif()
```

### CTest

After building run `ctest` inside your build directory.

```sh
cd $CMAKE_BUILD_DIR
ctest -C Release # Release build
ctest -C Debug   # Debug build
```

## JUCE Unit Tests

- [API Documentation](https://docs.juce.com/master/classUnitTest.html)
- [Example](https://github.com/juce-framework/JUCE/blob/master/examples/Utilities/UnitTestsDemo.h)
- How to run them in a plug-in build
