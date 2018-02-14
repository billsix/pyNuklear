PyNuklear

Python bindings to the nuklear immediate-mode GUI library
https://github.com/vurtun/nuklear



Dependencies
============

1. Python3
2. GLFW
3. Python3 OpenGL
4. Python3 NumPy


Run Demo
========

1. Add the directory which contains this file to your PYTHONPATH
2. To build nuklear as a shared library,  cd into contrib/nuklear/.  On Linux, "make".  On macOS, "make -f Makefile.osx"
3. To run on a system with OpenGL 2, execute "./demo/glfw_opengl2/pyNuklearGLFWOpenGL2.py"
4. To run on a system with OpenGL 3+, execute "./demo/glfw_opengl3/pyNuklearGLFWOpenGL3.py"
