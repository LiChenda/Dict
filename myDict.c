#include "/usr/include/python3.5m/Python.h"
#include <string.h>
#include "RB_Tree.h"


/*
 *  module functions define here
 *
 * */
char* showinfo();
int getvalue();
void setvalue(int value);
static PyObject *myDic_showinfo(PyObject *self, PyObject *args);
static PyObject *myDict_getvalue(PyObject *self, PyObject *args);
static PyObject *myDict_setvalue(PyObject *self, PyObject *args);

/************************************************************************************/

extern RB_Node *const nil;
char buf[100] = "hello";

int a;

static PyMethodDef myDictMethods[] = {
    {
        "showinfo",
        myDic_showinfo,
        METH_VARARGS, 
        "test for string return"
    },
    {
        "getvalue",
        myDict_getvalue,
        METH_VARARGS,
        "usestac"
    },
    {
        "setvalue",
        myDict_setvalue,
        METH_VARARGS,
        "usestac"
    },
    {NULL, NULL, 0, NULL}
};
static struct PyModuleDef myDict = 
{
    PyModuleDef_HEAD_INIT,
    "myDict",
    NULL,
    -1,
    myDictMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

static PyObject *
myDict_setvalue(PyObject *self, PyObject *args)
{
    int value;
    if(!PyArg_ParseTuple(args, "i", &value))
        return NULL;
    setvalue(value);
    return Py_BuildValue("i", a);
}

    static PyObject *
myDic_showinfo(PyObject *self, PyObject *args)
{
    char* str;
    if(!PyArg_ParseTuple(args,""))
        return NULL;
    str = showinfo();
    return Py_BuildValue("s", str);
}


    static PyObject *
myDict_getvalue(PyObject *self, PyObject *args)
{
    if(!PyArg_ParseTuple(args,""))
        return NULL;
    return Py_BuildValue("i", a);
}


    PyMODINIT_FUNC
PyInit_myDict(void)
{
    a = 100;
    return PyModule_Create(&myDict);
}

int getvalue()
{
    return a;
}

char* showinfo()
{
    buf[0] = 'y';
    return buf; 
}

void setvalue(int value)
{
    a = value;
    return;
}
