nuklear.so: nuklear.h nuklear_glfw_gl3.h nuklear.c
	gcc -g -shared -fPIC -o nuklear.so  nuklear.c $(shell pkg-config --libs glfw3)
