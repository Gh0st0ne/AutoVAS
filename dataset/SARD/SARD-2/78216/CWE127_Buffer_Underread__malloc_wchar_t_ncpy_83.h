/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83.h
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    BadSink : Copy data to string using wcsncpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83
{

#ifndef OMITBAD

class CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83_bad
{
public:
    CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83_bad(wchar_t * dataCopy);
    ~CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83_bad();

private:
    wchar_t * data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83_goodG2B
{
public:
    CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83_goodG2B(wchar_t * dataCopy);
    ~CWE127_Buffer_Underread__malloc_wchar_t_ncpy_83_goodG2B();

private:
    wchar_t * data;
};

#endif /* OMITGOOD */

}
