/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_52c.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fscanf_fwrite_52c_badSink(int count)
{
    {
        size_t i = 0;
        FILE *pFile = NULL;
        const char *filename = "output_bad.txt";
        pFile = fopen(filename, "w+");
        if (pFile == NULL)
        {
            exit(1);
        }
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation
         * This can cause a file to become very large */
        for (i = 0; i < (size_t)count; i++)
        {
            if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), pFile))
            {
                exit(1);
            }
        }
        if (pFile)
        {
            fclose(pFile);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fscanf_fwrite_52c_goodG2BSink(int count)
{
    {
        size_t i = 0;
        FILE *pFile = NULL;
        const char *filename = "output_bad.txt";
        pFile = fopen(filename, "w+");
        if (pFile == NULL)
        {
            exit(1);
        }
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation
         * This can cause a file to become very large */
        for (i = 0; i < (size_t)count; i++)
        {
            if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), pFile))
            {
                exit(1);
            }
        }
        if (pFile)
        {
            fclose(pFile);
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fscanf_fwrite_52c_goodB2GSink(int count)
{
    {
        size_t i = 0;
        FILE *pFile = NULL;
        const char *filename = "output_good.txt";
        /* FIX: Validate count before using it as the for loop variant to write to a file */
        if (count > 0 && count <= 20)
        {
            pFile = fopen(filename, "w+");
            if (pFile == NULL)
            {
                exit(1);
            }
            for (i = 0; i < (size_t)count; i++)
            {
                if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), pFile)) exit(1);
            }
            if (pFile)
            {
                fclose(pFile);
            }
        }
    }
}

#endif /* OMITGOOD */
