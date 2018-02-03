PyNuklear

Python bindings to the nuklear immediate-mode GUI library
https://github.com/vurtun/nuklear



Dependencies
============

1. Python3
2. GLFW
3. Python3 OpenGL
4. Python3 NumPy


Run OpenGL3 Demo
================

1. Add the directory which contains this file to your PYTHONPATH
2. Build nuklear as a shared library.  cd into contrib/nuklear/.  On Linux, "make".  On macOS, "make -f Makefile.osx"
3. Execute "./demo/glfw_opengl2/pyNuklearGLFWOpenGL2.py" for the OpenGL 2 version
4. Execute "./demo/glfw_opengl3/pyNuklearGLFWOpenGL3.py" for the OpenGL 3+ version
