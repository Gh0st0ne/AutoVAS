/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_08.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

namespace CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_08
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    if(staticReturnsTrue())
    {
        data = NULL;
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    }
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second staticReturnsTrue() to staticReturnsFalse() */
static void goodB2G1()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    if(staticReturnsTrue())
    {
        data = NULL;
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    }
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Deallocate the memory using free() */
        free(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    if(staticReturnsTrue())
    {
        data = NULL;
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    }
    if(staticReturnsTrue())
    {
        /* FIX: Deallocate the memory using free() */
        free(data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first staticReturnsTrue() to staticReturnsFalse() */
static void goodG2B1()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Allocate memory from the heap using new */
        data = new TwoIntsClass;
    }
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete data;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    if(staticReturnsTrue())
    {
        /* FIX: Allocate memory from the heap using new */
        data = new TwoIntsClass;
    }
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete data;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
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

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_08; /* so that we can use good and bad easily */

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
