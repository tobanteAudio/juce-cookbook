# Continuous Integration

Explaining the concepts of `continuous integration` and `continuous deployment` is far out of scope for this document, but TLDR: CI helps you find problems in your code faster. Every time you push to your version control server of choice (e.g. GitHub or GitLab) builds on various platforms start up. For example in my plug-in project modEQ, I have builds for Windows, macOS & Linux. Since all of the platforms are using different compilers I get different warnings on each. Fixing all those little things as you go will save you a lot of time compared to developing exclusively on one platform and then trying to release it for a additional platform at the end.

There are many CI services online for free if your project is publicly available on GitHub or other platforms. I will focus on `travis-ci` and `appveyor` because those to combined will cover all desktop platforms JUCE supports (Windows, macOS & Linux).
