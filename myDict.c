#include "/usr/include/python3.5m/Python.h"
#include <string.h>
#include "reverse_polish.h"


/*
 *  module functions define here
 *
 * */
static PyObject *myDic_showinfo(PyObject *self, PyObject *args);
static PyObject *myDic_reverse(PyObject *self, PyObject *args);

/************************************************************************************/

char buf[100] = "hello";

static PyMethodDef myDictMethods[] = {
    {
        "showinfo",
        myDic_showinfo,
        METH_VARARGS, 
        "test for string return"
    },
    {
        "reverse",
        myDic_reverse,
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

char* showinfo();
char* reverse(char* input);

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
myDic_reverse(PyObject *self, PyObject *args)
{
    char *str, *input;

    if(!PyArg_ParseTuple(args,"s", &input))
        return NULL;
    str = reverse(input);
    return Py_BuildValue("s", str);

}


PyMODINIT_FUNC
PyInit_myDict(void)
{
    return PyModule_Create(&myDict);
}

char* showinfo()
{
    buf[0] = 'y';
    return buf; 
}

char* reverse(char* input)
{
    if(process(input) == ERR)
    {
        char err[] = "input error";
        strcpy(output, err);
    }
    return output;
}



