/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_72a.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-72a.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE476_NULL_Pointer_Dereference__class_72
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(vector<TwoIntsClass *> dataVector);

void bad()
{
    TwoIntsClass * data;
    vector<TwoIntsClass *> dataVector;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    /* Put data in a vector */
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    badSink(dataVector);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<TwoIntsClass *> dataVector);

static void goodG2B()
{
    TwoIntsClass * data;
    vector<TwoIntsClass *> dataVector;
    {
        TwoIntsClass * tmpData = new TwoIntsClass;
        tmpData->intOne = 0;
        tmpData->intOne = 0;
        /* FIX: Initialize data */
        data = tmpData;
    }
    /* Put data in a vector */
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    goodG2BSink(dataVector);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<TwoIntsClass *> dataVector);

static void goodB2G()
{
    TwoIntsClass * data;
    vector<TwoIntsClass *> dataVector;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    goodB2GSink(dataVector);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE476_NULL_Pointer_Dereference__class_72; /* so that we can use good and bad easily */

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
