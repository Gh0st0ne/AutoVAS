/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_popen_18.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-18.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sink: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"%WINDIR%\\system32\\cmd.exe /c dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"/bin/sh ls -la "
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_console_popen_18_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    goto source;
source:
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by reversing the blocks on the goto statement */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    goto source;
source:
    /* FIX: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

void CWE78_OS_Command_Injection__wchar_t_console_popen_18_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE78_OS_Command_Injection__wchar_t_console_popen_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__wchar_t_console_popen_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
