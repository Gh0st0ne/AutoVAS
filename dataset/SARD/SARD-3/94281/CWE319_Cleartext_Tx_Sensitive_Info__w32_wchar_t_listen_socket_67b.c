/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: listen_socket Read the password using a listen socket (server side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

typedef struct _CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67_structType
{
    wchar_t * structFirst;
} CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67_structType;

#ifndef OMITBAD

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b_badSink(CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67_structType myStruct)
{
    wchar_t * password = myStruct.structFirst;
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        /* POTENTIAL FLAW: Using sensitive information that was possibly sent in plaintext over the network */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b_goodG2BSink(CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67_structType myStruct)
{
    wchar_t * password = myStruct.structFirst;
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        /* POTENTIAL FLAW: Using sensitive information that was possibly sent in plaintext over the network */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b_goodB2GSink(CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67_structType myStruct)
{
    wchar_t * password = myStruct.structFirst;
    {
        HCRYPTPROV hCryptProv = 0;
        HCRYPTHASH hHash = 0;
        HCRYPTKEY hKey = 0;
        char hashData[100] = HASH_INPUT;
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        do
        {
            BYTE payload[(100 - 1) * sizeof(wchar_t)]; /* same size as password except for NUL terminator */
            DWORD payloadBytes;
            /* Hex-decode the input string into raw bytes */
            payloadBytes = decodeHexWChars(payload, sizeof(payload), password);
            /* Wipe the hex string, to prevent it from being given to LogonUserW if
             * any of the crypto calls fail. */
            SecureZeroMemory(password, 100 * sizeof(wchar_t));
            /* Aquire a Context */
            if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
            {
                break;
            }
            /* Create hash handle */
            if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
            {
                break;
            }
            /* Hash the input string */
            if(!CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0))
            {
                break;
            }
            /* Derive an AES key from the hash */
            if(!CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey))
            {
                break;
            }
            /* FIX: Decrypt the password */
            if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes))
            {
                break;
            }
            /* Copy back into password and NUL-terminate */
            memcpy(password, payload, payloadBytes);
            password[payloadBytes / sizeof(wchar_t)] = L'\0';
        }
        while (0);
        if (hKey)
        {
            CryptDestroyKey(hKey);
        }
        if (hHash)
        {
            CryptDestroyHash(hHash);
        }
        if (hCryptProv)
        {
            CryptReleaseContext(hCryptProv, 0);
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
    }
}

#endif /* OMITGOOD */
