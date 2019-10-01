/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_console_53c.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: console Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE114_Process_Control__w32_char_console_53d_badSink(char * data);

void CWE114_Process_Control__w32_char_console_53c_badSink(char * data)
{
    CWE114_Process_Control__w32_char_console_53d_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE114_Process_Control__w32_char_console_53d_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_char_console_53c_goodG2BSink(char * data)
{
    CWE114_Process_Control__w32_char_console_53d_goodG2BSink(data);
}

#endif /* OMITGOOD */
