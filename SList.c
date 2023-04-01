#include"SList.h"


pSList MakeNode(SListType x)
{
    pSList newnode=(pSList)malloc(sizeof(SList));
    if(newnode==NULL)
    {
        perror("malloc fail!");
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void PrintSL(pSList list)
{
    while(list!=NULL)
    {
        printf("%d\n",list->data);
        list=list->next;
    }
}

void PushSHead(pSList* phead,SListType x)
{
    pSList newnode=MakeNode(x);
    newnode->next=*(phead);
    *phead=newnode;
}

void PushSTail(pSList* phead,SListType x)
{
    pSList tmp=*phead;
    pSList newnode=MakeNode(x);
    if(*phead==NULL)
    {
        *phead=newnode;
        return;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;
}


pSList FindNode(pSList phead,SListType x)
{
    assert(phead);
    while(phead->data!=x)
    {
        phead=phead->next;
        if(phead==NULL)
        {
            printf("Not Find The Node!!!\n");
            return NULL;
        }
    }
    return phead;
}

void ChangeNode(pSList phead,SListType x,SListType y)
{
    pSList res=FindNode(phead,x);
    if(res!=NULL)
    {
        res->data=y;
    }
    else
        printf("Change Node Fail!!!\n");
}

void DelSHead(pSList* phead)
{
    assert(* phead&&phead);
    pSList tmp=*phead;
    (*phead)=(*phead)->next;
    free(tmp);
    tmp=NULL;
}

void DelSBack(pSList* phead)
{
    assert(*phead&&phead);
    pSList tmp=*phead;
    if(tmp->next==NULL)
    {
        free(tmp);
        *phead=tmp=NULL;
    }
    else
    {
        while((tmp)->next->next!=NULL)
        {
            tmp=tmp->next;
        }    
        free(tmp->next);
        tmp->next=NULL;
    }
}


void Destory(pSList* phead)
{
    assert(phead);
    pSList tmp=*phead;
    while(tmp)
    {
        tmp=tmp->next;
        free(*phead);
        *phead=tmp;
    }
}

//pos之前插入
void SListInsert(pSList* phead,pSList pos,SListType x)
{
    assert(phead&&pos);
    if(*phead==pos)
    {
        PushSHead(phead,x);
    }
    else
    {
        pSList tmp=*phead;
        while(tmp->next!=pos)
        {
            tmp=tmp->next;
            assert(tmp);
        }
        pSList newnode=MakeNode(x);
        newnode->next=tmp->next;
        tmp->next=newnode;
    }
}