/* nuklear - 1.32.0 - public domain */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define GL3W_IMPLEMENTATION
#include "gl3w.h"

#include <GLFW/glfw3.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT


#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION
#include "nuklear.h"
#include "nuklear_glfw_gl3.h"
#include "nuklearWrappers.h"


/*
  This is built as an extension module solely so that setuptools builds
  the library instead of using a makefile.  This is dumb though, because
  I use ctypes to load the library by name a second time, wasting memory,
  albeit this is not a large library.

  I would like some ctypes/setuptools integration so that I may distribute
  c based libraries a little more easily, but I currently can't figure out
  how.
 */

#include <Python.h>

static PyMethodDef pynuklearMethods[] = {
                                         {{NULL, NULL, 0, NULL}}        /* Sentinel */
};

static struct PyModuleDef pynuklearmoduleGLFWOpenGL3 = {
    PyModuleDef_HEAD_INIT,
    "pynuklearcGLFWOpenGL3",   /* name of module */
    "", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    pynuklearMethods
};


static PyObject *pynuklearError;

PyMODINIT_FUNC
PyInit_pynuklearc(void)
{
    PyObject *m;

    m = PyModule_Create(&pynuklearmoduleGLFWOpenGL3);
    if (m == NULL)
        return NULL;

    pynuklearError = PyErr_NewException("pynuklear.error", NULL, NULL);
    Py_INCREF(pynuklearError);
    PyModule_AddObject(m, "error", pynuklearError);
    return m;
}
