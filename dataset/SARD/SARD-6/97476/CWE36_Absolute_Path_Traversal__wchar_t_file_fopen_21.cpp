/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_file_fopen_21.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-21.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Full path and file name
 * Sink: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#define FOPEN _wfopen
#else
#define FOPEN fopen
#endif

namespace CWE36_Absolute_Path_Traversal__wchar_t_file_fopen_21
{

#ifndef OMITBAD

/* The static variable below is used to drive control flow in the source function */
static int badStatic = 0;

static wchar_t * badSource(wchar_t * data)
{
    if(badStatic)
    {
        {
            /* Read input from a file */
            size_t dataLen = wcslen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (FILENAME_MAX-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgetws(data+dataLen, (int)(FILENAME_MAX-dataLen), pFile) == NULL)
                    {
                        printLine("fgetws() failed");
                        /* Restore NUL terminator if fgetws fails */
                        data[dataLen] = L'\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    return data;
}

void bad()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    badStatic = 1; /* true */
    data = badSource(data);
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, L"wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
    ;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* The static variables below are used to drive control flow in the source functions. */
static int goodG2B1Static = 0;
static int goodG2B2Static = 0;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
static wchar_t * goodG2B1Source(wchar_t * data)
{
    if(goodG2B1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
#ifdef _WIN32
        /* FIX: Use a fixed, full path and file name */
        wcscat(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Use a fixed, full path and file name */
        wcscat(data, L"/tmp/file.txt");
#endif
    }
    return data;
}

static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    goodG2B1Static = 0; /* false */
    data = goodG2B1Source(data);
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, L"wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
    ;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
static wchar_t * goodG2B2Source(wchar_t * data)
{
    if(goodG2B2Static)
    {
#ifdef _WIN32
        /* FIX: Use a fixed, full path and file name */
        wcscat(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Use a fixed, full path and file name */
        wcscat(data, L"/tmp/file.txt");
#endif
    }
    return data;
}

static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    goodG2B2Static = 1; /* true */
    data = goodG2B2Source(data);
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, L"wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
    ;
}

void good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE36_Absolute_Path_Traversal__wchar_t_file_fopen_21; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
