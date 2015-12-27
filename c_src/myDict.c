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
static PyObject *myDict_insert(PyObject *self, PyObject *args);
static PyObject *myDict_modify_word(PyObject *self, PyObject *args);
static PyObject *myDict_search(PyObject *self, PyObject *args);
static PyObject *myDict_suggestword(PyObject *self, PyObject *args);

/************************************************************************************/

//extern RB_Node *const nil;
RB_Node **root;
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
    {
        "insert_word",
        myDict_insert,
        METH_VARARGS,
        "insert word"
    },
    {
        "modify_word",
        myDict_modify_word,
        METH_VARARGS,
        "modify word"
    },
    {
        "search_word",
        myDict_search,
        METH_VARARGS,
        "search word"
    },
    {
        "suggest_word",
        myDict_suggestword,
        METH_VARARGS,
        "suggest word"
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
myDict_search(PyObject *self, PyObject *args)
{
    char *en;  
    if(!PyArg_ParseTuple(args, "s", &en))
        return NULL;
    Word* word = search_word(en);


    if(word)
        return Py_BuildValue("[ss]", word->en, word->sentences);
    return Py_BuildValue("[]");
}
static PyObject *myDict_suggestword(PyObject *self, PyObject *args)
{
    char *en;  
    if(!PyArg_ParseTuple(args, "s", &en))
        return NULL;
    wordlist wlist = suggest_word(en);
    PyObject *result = Py_BuildValue("[]");
    PyObject *excet;
    if(wlist.word)
        excet = Py_BuildValue("[ss]", wlist.word->en,
                 wlist.word->sentences);
    else
        excet = Py_BuildValue("[]");
    PyList_Append(result, excet);
    wordlistnode *x = wlist.next; 
    while(x != NULL)
    {
        PyList_Append(result,
                Py_BuildValue("[ss]", x->word->en, 
                 x->word->sentences));
        x = x->next;
    }
    return result;
}
static PyObject *
myDict_modify_word(PyObject *self, PyObject *args)
{
    char *en, *sen; 
    if(!PyArg_ParseTuple(args, "ss", &en,  &sen))
        return NULL;
    if(modify_word(en,sen))
        return Py_BuildValue("s", "false");
    else
        return Py_BuildValue("s", "ture");
}
    

static PyObject *
myDict_insert(PyObject *self, PyObject *args)
{
    char *en, *sen;
    if(!PyArg_ParseTuple(args, "ss", &en,  &sen))
        return NULL;
    insert_word(en, sen);
    return Py_BuildValue("s", en);
    
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
PyInit_dic_tree(void)
{
    a = 100;
    root = initTree();
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
