#include <Python.h>
#include <pythonrun.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    if (argc < 3) 
    {
        printf("Usage: exe_name python_source function_name\n");
        return 1;
    }

    // Initialize the Python Interpreter
    Py_Initialize();

    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));

    // Build the name object
    pName = PyString_FromString(argv[1]);
printf("0 = %s \n", argv[0]);
printf("1 = %s \n", argv[1]);
printf("2 = %s \n", argv[2]);

    // Load the module object
    pModule = PyImport_Import(pName);

printf("5\n");
    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);

printf("6\n");
    // pFunc is also a borrowed reference 
    pFunc = PyDict_GetItemString(pDict, argv[2]);

printf("7\n");
    if (PyCallable_Check(pFunc)) 
    {
        PyObject_CallObject(pFunc, NULL);
    } else 
    {
        PyErr_Print();
    }

printf("8\n");
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

    return 0;
}
