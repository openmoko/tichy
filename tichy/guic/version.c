/* Generated by Cython 0.9.6.14 on Mon Nov 17 17:50:05 2008 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)   PyInt_AsLong(o)
  #define PyNumber_Index(o)    PyNumber_Int(o)
  #define PyIndex_Check(o)     PyNumber_Check(o)
#endif
#if PY_VERSION_HEX < 0x02040000
  #define METH_COEXIST 0
#endif
#ifndef __stdcall
  #define __stdcall
#endif
#ifndef __cdecl
  #define __cdecl
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>


#ifdef __GNUC__
#define INLINE __inline__
#elif _WIN32
#define INLINE __inline
#else
#define INLINE 
#endif

typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n; int is_unicode;} __Pyx_StringTabEntry; /*proto*/



static int __pyx_skip_dispatch = 0;


/* Type Conversion Predeclarations */

#define __Pyx_PyBool_FromLong(b) ((b) ? (Py_INCREF(Py_True), Py_True) : (Py_INCREF(Py_False), Py_False))
static INLINE int __Pyx_PyObject_IsTrue(PyObject* x);
static INLINE PY_LONG_LONG __pyx_PyInt_AsLongLong(PyObject* x);
static INLINE unsigned PY_LONG_LONG __pyx_PyInt_AsUnsignedLongLong(PyObject* x);
static INLINE Py_ssize_t __pyx_PyIndex_AsSsize_t(PyObject* b);

#define __pyx_PyInt_AsLong(x) (PyInt_CheckExact(x) ? PyInt_AS_LONG(x) : PyInt_AsLong(x))
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))

static INLINE unsigned char __pyx_PyInt_unsigned_char(PyObject* x);
static INLINE unsigned short __pyx_PyInt_unsigned_short(PyObject* x);
static INLINE char __pyx_PyInt_char(PyObject* x);
static INLINE short __pyx_PyInt_short(PyObject* x);
static INLINE int __pyx_PyInt_int(PyObject* x);
static INLINE long __pyx_PyInt_long(PyObject* x);
static INLINE signed char __pyx_PyInt_signed_char(PyObject* x);
static INLINE signed short __pyx_PyInt_signed_short(PyObject* x);
static INLINE signed int __pyx_PyInt_signed_int(PyObject* x);
static INLINE signed long __pyx_PyInt_signed_long(PyObject* x);
static INLINE long double __pyx_PyInt_long_double(PyObject* x);
#ifdef __GNUC__
/* Test for GCC > 2.95 */
#if __GNUC__ > 2 ||               (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)) 
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else /* __GNUC__ > 2 ... */
#define likely(x)   (x)
#define unlikely(x) (x)
#endif /* __GNUC__ > 2 ... */
#else /* __GNUC__ */
#define likely(x)   (x)
#define unlikely(x) (x)
#endif /* __GNUC__ */
    
static PyObject *__pyx_m;
static PyObject *__pyx_b;
static PyObject *__pyx_empty_tuple;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static char * __pyx_cfilenm= __FILE__;
static char *__pyx_filename;
static char **__pyx_f;

static char __pyx_mdoc[] = "Define the version of the compiled c files\n\nWe can update this value any time we make some change in the C code\nthat require us to recompile before we can use guic.\n\nIt is just to make things clearer in case of errors.\n";

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations */



/* Implementation of version */


static PyObject *__pyx_int_1;

static PyObject *__pyx_n___version__;

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n___version__, "__version__"},
  {0, 0}
};

static struct PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initversion(void); /*proto*/
PyMODINIT_FUNC initversion(void) {
  /*--- Libary function declarations ---*/
  __pyx_init_filenames();
  /*--- Module creation code ---*/
  __pyx_m = Py_InitModule4("version", __pyx_methods, __pyx_mdoc, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; __pyx_clineno = __LINE__; goto __pyx_L1;};
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; __pyx_clineno = __LINE__; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; __pyx_clineno = __LINE__; goto __pyx_L1;};
  /*--- Intern code ---*/
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; __pyx_clineno = __LINE__; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; __pyx_clineno = __LINE__; goto __pyx_L1;};
  /*--- String init code ---*/
  /*--- Builtin init code ---*/
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; __pyx_clineno = __LINE__; goto __pyx_L1;}
  __pyx_skip_dispatch = 0;
  /*--- Global init code ---*/
  /*--- Function export code ---*/
  /*--- Type init code ---*/
  /*--- Type import code ---*/
  /*--- Function import code ---*/
  /*--- Execution code ---*/

  /* "/home/charlie/Work/tichy/tichy/guic/version.pyx":27
 * """
 * 
 * __version__ = 1             # <<<<<<<<<<<<<< 
 */
  if (PyObject_SetAttr(__pyx_m, __pyx_n___version__, __pyx_int_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 27; __pyx_clineno = __LINE__; goto __pyx_L1;}
  return;
  __pyx_L1:;
  __Pyx_AddTraceback("version");
}

static char *__pyx_filenames[] = {
  "version.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
    while (t->p) {
        *t->p = PyString_InternFromString(t->s);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    if (__pyx_clineno) {
        py_funcname = PyString_FromFormat( "%s (%s:%u)", funcname, __pyx_cfilenm, __pyx_clineno);
    }
    else {
        py_funcname = PyString_FromString(funcname);
    }
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        __pyx_empty_tuple,  /*PyObject *consts,*/
        __pyx_empty_tuple,  /*PyObject *names,*/
        __pyx_empty_tuple,  /*PyObject *varnames,*/
        __pyx_empty_tuple,  /*PyObject *freevars,*/
        __pyx_empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

/* Type Conversion Functions */

static INLINE Py_ssize_t __pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject* x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}

static INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   if (x == Py_True) return 1;
   else if (x == Py_False) return 0;
   else return PyObject_IsTrue(x);
}

static INLINE PY_LONG_LONG __pyx_PyInt_AsLongLong(PyObject* x) {
    if (PyInt_CheckExact(x)) {
        return PyInt_AS_LONG(x);
    }
    else if (PyLong_CheckExact(x)) {
        return PyLong_AsLongLong(x);
    }
    else {
        PY_LONG_LONG val;
        PyObject* tmp = PyNumber_Int(x); if (!tmp) return (PY_LONG_LONG)-1;
        val = __pyx_PyInt_AsLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static INLINE unsigned PY_LONG_LONG __pyx_PyInt_AsUnsignedLongLong(PyObject* x) {
    if (PyInt_CheckExact(x)) {
        long val = PyInt_AS_LONG(x);
        if (unlikely(val < 0)) {
            PyErr_SetString(PyExc_TypeError, "Negative assignment to unsigned type.");
            return (unsigned PY_LONG_LONG)-1;
        }
        return val;
    }
    else if (PyLong_CheckExact(x)) {
        return PyLong_AsUnsignedLongLong(x);
    }
    else {
        PY_LONG_LONG val;
        PyObject* tmp = PyNumber_Int(x); if (!tmp) return (PY_LONG_LONG)-1;
        val = __pyx_PyInt_AsUnsignedLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}


static INLINE unsigned char __pyx_PyInt_unsigned_char(PyObject* x) {
    if (sizeof(unsigned char) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        unsigned char val = (unsigned char)long_val;
        if (unlikely((val != long_val)  || (long_val < 0))) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to unsigned char");
            return (unsigned char)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE unsigned short __pyx_PyInt_unsigned_short(PyObject* x) {
    if (sizeof(unsigned short) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        unsigned short val = (unsigned short)long_val;
        if (unlikely((val != long_val)  || (long_val < 0))) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to unsigned short");
            return (unsigned short)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE char __pyx_PyInt_char(PyObject* x) {
    if (sizeof(char) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        char val = (char)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to char");
            return (char)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE short __pyx_PyInt_short(PyObject* x) {
    if (sizeof(short) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        short val = (short)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to short");
            return (short)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE int __pyx_PyInt_int(PyObject* x) {
    if (sizeof(int) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        int val = (int)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to int");
            return (int)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE long __pyx_PyInt_long(PyObject* x) {
    if (sizeof(long) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        long val = (long)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to long");
            return (long)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed char __pyx_PyInt_signed_char(PyObject* x) {
    if (sizeof(signed char) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed char val = (signed char)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed char");
            return (signed char)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed short __pyx_PyInt_signed_short(PyObject* x) {
    if (sizeof(signed short) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed short val = (signed short)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed short");
            return (signed short)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed int __pyx_PyInt_signed_int(PyObject* x) {
    if (sizeof(signed int) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed int val = (signed int)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed int");
            return (signed int)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed long __pyx_PyInt_signed_long(PyObject* x) {
    if (sizeof(signed long) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed long val = (signed long)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed long");
            return (signed long)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE long double __pyx_PyInt_long_double(PyObject* x) {
    if (sizeof(long double) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        long double val = (long double)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to long double");
            return (long double)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}