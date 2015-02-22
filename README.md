About
===

This was the winning hack from [HackCWRU](http://hackcwru.com) 2015.
It is a challenging single-player survival game written in OpenGL.

Building
===

The build at this point is frail at best. I have gotten it to compile on
a VM running Ubuntu 14.04 and on a MacBook Air running Mavericks. It runs
on the Mac but seg faults on Ubuntu (I think this has something to with the
fact that it's running on a VM, but I'm looking into it). 
You may need to tweak some things to get this to build on your platform,
but generally it should work.

Dependencies
---

The following (which may have their own dependencies) are definitely needed
to build this project:

+ [OpenGL](https://www.opengl.org/)
+ [GLM](http://glm.g-truc.net) 0.9.6
+ [GLEW](http://glew.sourceforge.net) 1.12.0
+ [GLFW](http://www.glfw.org/) 3.1

If you want to use the CMake configuration included in this repo
(highly recommended), you will need [cmake](http://cmake.org) as well.
See CMakeLists.txt for the version number.

Build Commands
---

These commands should start in the root directory of the project.

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

If everything goes smoothly, you will have an executable called ```tale_of_two_circles```
in ```build```
