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
        "search_word",
        myDict_search,
        METH_VARARGS,
        "search word"
    },
    {
        "suggest_word",
        myDict_suggestword,
        METH_VARARGS,
        "search word"
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

    //return Py_BuildValue("s", (*root)->word->ch);

    if(word)
        return Py_BuildValue("[sss]", word->en, word->ch, word->sentences);
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
        excet = Py_BuildValue("[sss]", wlist.word->en,
                wlist.word->ch, wlist.word->sentences);
    else
        excet = Py_BuildValue("[]");
    PyList_Append(result, excet);
    wordlistnode *x = wlist.next; 
    while(x != NULL)
    {
        PyList_Append(result,
                Py_BuildValue("[sss]", x->word->en, 
                    x->word->ch, x->word->sentences));
        x = x->next;
    }
    return result;
}
    

static PyObject *
myDict_insert(PyObject *self, PyObject *args)
{
    char *en, *ch, *sen;
    if(!PyArg_ParseTuple(args, "sss", &en, &ch, &sen))
        return NULL;
//    printf("%p\n", *root);
    insert_word(en, ch, sen);
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
PyInit_myDict(void)
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
