#include"SList.h"

void test1()
{
    pSList list=NULL;
    PushSHead(&list,1);
    PushSHead(&list,2);
    PushSHead(&list,3);
    PushSHead(&list,4);
    PrintSL(list);
}

void test2()
{
    pSList list=NULL;
     PushSTail(&list,1);
     PushSTail(&list,2);
     PushSTail(&list,3);
     PushSTail(&list,4);
     PrintSL(list);
}

void test3()
{
    pSList list=NULL;
    pSList find=NULL;
    PushSTail(&list,1);
    PushSTail(&list,2);
    PushSTail(&list,3);
    PushSTail(&list,4);
    DelSBack(&list);
    DelSBack(&list);
    //DelSBack(&list);
    //PrintSL(list);
    SListType x=1;
    SListType new=100;
    PrintSL(list);

    pSList pos=FindNode(list,x);
    SListInsert(&list,pos,new);
    PrintSL(list);
}


int main()
{
    test3();
    return 0;
}