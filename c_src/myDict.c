#include <string.h>

#include "RB_Tree.h"
#include "python/Python.h"


/*
 *  module functions define here
 *
 * */
char* showinfo();
int getvalue();
void setvalue(int value);
static PyObject *myDict_insert(PyObject *self, PyObject *args);
static PyObject *myDict_modify_word(PyObject *self, PyObject *args);
static PyObject *myDict_search(PyObject *self, PyObject *args);
static PyObject *myDict_suggestword(PyObject *self, PyObject *args);

/************************************************************************************/

RB_Node **root;


static PyMethodDef myDictMethods[] = {
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



    PyMODINIT_FUNC
PyInit_dic_tree(void)
{
    root = initTree();
    return PyModule_Create(&myDict);
}

