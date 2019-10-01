/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_popen_68b.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: popen
 *    BadSink : Execute the wpopen function
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define BAD_OS_COMMAND L"cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
#define GOOD_OS_COMMAND L"c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
#define BAD_OS_COMMAND L"ls -la"
#define GOOD_OS_COMMAND L"/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

extern wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_68_badData;
extern wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE426_Untrusted_Search_Path__wchar_t_popen_68b_badSink()
{
    wchar_t * data = CWE426_Untrusted_Search_Path__wchar_t_popen_68_badData;
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the wpopen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE426_Untrusted_Search_Path__wchar_t_popen_68b_goodG2BSink()
{
    wchar_t * data = CWE426_Untrusted_Search_Path__wchar_t_popen_68_goodG2BData;
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the wpopen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

#endif /* OMITGOOD */
