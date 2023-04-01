#include<stdio.h>
#include<stdlib.h>  
#include<assert.h>


typedef int SListType;

typedef struct SList
{
    SListType data;
    struct SList* next;
}SList,*pSList;


pSList MakeNode(SListType x);
void PrintSL(pSList list);

void PushSHead(pSList* phead,SListType x);
void PushSTail(pSList* phead,SListType x);
pSList FindNode(pSList phead,SListType x);
void ChangeNode(pSList phead,SListType x,SListType y);
void DelSHead(pSList* phead);
void DelSBack(pSList* phead);
void Destory(pSList* phead);
void SListInsert(pSList* phead,pSList pos,SListType x);
