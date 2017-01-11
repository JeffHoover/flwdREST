#include <Python.h>
#include <pythonrun.h>

void exec_pycode(const char* py_code);

int main(int argc, char *argv[])
{
        exec_pycode("print \"hello\"");
}

void exec_pycode(const char* py_code)
{
        Py_Initialize();
        PyRun_SimpleString(py_code);
        Py_Finalize();
}

