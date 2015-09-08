#ifndef __BASE_H__
#define __BASE_H__

#ifdef __cplusplus
extern "C" 
{
#endif

#include <ntifs.h>
#include <ntddk.h>

#ifdef __cplusplus
}
#endif

//=====================================================================================//
//Name: KSYSTEM_SERVICE_TABLE �� KSERVICE_TABLE_DESCRIPTOR					           //
//                                                                                     //
//Descripion: �������� SSDT �ṹ for 32										  	   //
//            				                            						       //
//=====================================================================================//
typedef struct _KSYSTEM_SERVICE_TABLE
{
	PULONG  ServiceTableBase;					// SSDT (System Service Dispatch Table)�Ļ���ַ
	PULONG  ServiceCounterTableBase;			// ���� checked builds, ���� SSDT ��ÿ�����񱻵��õĴ���
	ULONG   NumberOfService;					// �������ĸ���, NumberOfService * 4 ����������ַ��Ĵ�С
	PVOID   ParamTableBase;						// SSPT(System Service Parameter Table)�Ļ���ַ  
} KSYSTEM_SERVICE_TABLE, *PKSYSTEM_SERVICE_TABLE;

typedef struct _KSERVICE_TABLE_DESCRIPTOR
{
	KSYSTEM_SERVICE_TABLE   ntoskrnl;			// ntoskrnl.exe �ķ�����
	KSYSTEM_SERVICE_TABLE   win32k;				// win32k.sys �ķ�����(GDI32.dll/User32.dll ���ں�֧��)
	KSYSTEM_SERVICE_TABLE   notUsed1;
	KSYSTEM_SERVICE_TABLE   notUsed2;
} KSERVICE_TABLE_DESCRIPTOR, *PKSERVICE_TABLE_DESCRIPTOR;


#define MAX_SYSTEM_SERVICE_NUMBER                 1024
#define MAX_SEARCH_FUNTION_NUMBER				  4096

__declspec(dllimport) KSERVICE_TABLE_DESCRIPTOR KeServiceDescriptorTable; 

#endif	// __BASE_H__
