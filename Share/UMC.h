﻿// Universal Mutant Closer's Header - UMC.h 
// Created by Riatre(aka. 258921) @ 2010/08/13

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>
#include <tlhelp32.h>
#include <VersionHelpers.h>

    typedef enum _HOWTOCLOSE
    {
        DONT_CLOSE = 0,
        CLOSE_DIRECT,
        CLOSE_INJECT
    } HOWTOCLOSE, *LPHOWTOCLOSE;

    typedef HOWTOCLOSE(*CLOSECALLBACK)(LPCWSTR MutantName, ULONG NameLength);

    BYTE GetObjectTypeNumber(LPCWSTR ObjectName);
    BOOL RemoteCloseHandle(HANDLE hProcess, HANDLE hHandle);
    BOOL EnumerateAndCloseMutant(CLOSECALLBACK ShouldClose);

    HANDLE WINAPI OsCreateRemoteThread2(
        HANDLE hProcess,
        LPSECURITY_ATTRIBUTES lpThreadAttributes,
        SIZE_T dwStackSize,
        LPTHREAD_START_ROUTINE lpStartAddress,
        LPVOID lpParameter,
        DWORD dwCreationFlags,
        LPDWORD lpThreadId
        );

#ifdef __cplusplus
}
#endif