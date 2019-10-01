/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84.h
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84
{

#ifndef OMITBAD

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_bad
{
public:
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_bad(wchar_t * passwordCopy);
    ~CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_bad();

private:
    wchar_t * password;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_goodG2B
{
public:
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_goodG2B(wchar_t * passwordCopy);
    ~CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_goodG2B();

private:
    wchar_t * password;
};

#endif /* OMITGOOD */

}
