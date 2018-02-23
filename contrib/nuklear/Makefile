all: nuklearGLFWOpenGL3.so nuklearGLFWOpenGL2.so

nuklearGLFWOpenGL3.so: nuklear.h nuklear_glfw_gl3.h nuklearGLFWOpenGL3.c nuklearWrappers.h
	gcc -g -shared -fPIC -o nuklearGLFWOpenGL3.so  nuklearGLFWOpenGL3.c $(shell pkg-config --libs glfw3)

nuklearGLFWOpenGL2.so: nuklear.h nuklear_glfw_gl2.h nuklearGLFWOpenGL2.c nuklearWrappers.h
	gcc -g -shared -fPIC -o nuklearGLFWOpenGL2.so  nuklearGLFWOpenGL2.c $(shell pkg-config --libs glfw3) $(shell pkg-config --libs glew)
