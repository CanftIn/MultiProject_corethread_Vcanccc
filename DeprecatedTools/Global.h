/************************************************************************/
/* Global.h
*/
/************************************************************************/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "FastLock.h"


#define CAPI_SUCCESS	0
#define CAPI_FAILED		1



typedef unsigned int UINT;


/*
 *	�ڵ�ṹ
 */
typedef struct SINGLENODE_st
{
	struct SINGLENODE_st* pNext;
	void* pData;
}SINGLENODE, *PSINGLENODE;

typedef struct DOUBLENODE_st
{
	struct DOUBLENODE_st* pNext;
	struct DOUBLENODE_st* pPrev;
	void* pData;
}DOUBLENODE;

typedef struct DOUBLELIST_ST
{
	DOUBLENODE* pHead;
	DOUBLENODE* pTail;
	DOUBLENODE* pCur;
	UINT		uCount;
}DOUBLELIST;




/**ͨ�����������ͷź���

	@param void* pData -Ҫ�ͷŵ�����	
	@return	 -��
*/
typedef void(*DESTROYFUNC)(void* pData);



/**	ͨ���������ݱȽϺ���

@param	void *pData1 -Ҫ�Ƚϵĵ�1������
@param	void *pData2 -Ҫ�Ƚϵĵ�2������
@return	INT - С��0��ʾpData1С��pData2, ����0��ʾpData1����pData2,
����0��ʾpData1����pData2
*/
typedef INT(*COMPAREFUNC)(void* pData1, void* pData2);



/*ͨ���������ݵı���ִ�к���

	@param	void *pData - Ҫ����������ָ��
	@return	void - ��
 */
typedef void(*TRAVERSEFUNC)(void *pData);

/**	ͨ���������ݵı���ִ�к���

@param	void *pData - Ҫ����������ָ��
@return	void - ��
*/
typedef INT(*VISITFUNC)(void *pData);

/**	ͨ�����ݿ�������

@param	void *pData - Ҫ����������
@return	void * - �ɹ����ؿ��������ݣ�ʧ�ܷ���NULL
*/
typedef void *(*COPYFUNC)(void *pData);

/**	�����ϣֵ�Ļص�����

@param  void *pKey - Ҫ�����ϣֵ�Ĺؼ���
@param  UINT uBucketNum - ��ϣ���е�BUCKET�����С
@return UINT - ���ؼ�����Ĺ�ϣֵ��һ��������ϣ��BUCKET�����±ꡣ
*/
typedef UINT(*HASHFUNC)(void *pKey, UINT uBucketNum);






#define		EVENT		HANDLE

#define EventCreate()	CreateEvent(NULL, TRUE, FALSE, NULL)










#endif
































