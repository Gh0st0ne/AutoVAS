/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52c_badSink(HANDLE data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b_badSink(HANDLE data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52c_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52c_goodB2GSink(HANDLE data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b_goodB2GSink(HANDLE data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52c_goodB2GSink(data);
}

#endif /* OMITGOOD */
