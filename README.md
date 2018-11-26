PyNuklear

Python bindings to the nuklear immediate-mode GUI library
https://github.com/vurtun/nuklear

Currently works on Linux and MacOS, with Python 3


Run Demos
=========

1. You may want to use a virtualenv.  Then "pip install -r requirements.txt".
2. "make"
3. Run Python.

For the OpenGL2 demo:

```python
import pynuklear.demo.glfw_opengl2.pyNuklearGLFWOpenGL2 as gl2Demo
gl2Demo.demo()
```

For the OpenGL3 demo:

```python
import pynuklear.demo.glfw_opengl3.pyNuklearGLFWOpenGL3 as gl3Demo
gl3Demo.demo()
```