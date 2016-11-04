//
//  main.cpp
//  CppNode
//
//  Created by YI on 16/11/3.
//  Copyright © 2016年 Sandro. All rights reserved.
//

#include <iostream>
using namespace std;

struct node
{
    int Data;
    node *next;
};

node *reverse(node *head){//单链表的逆序排列
    node *p,*q,*r;
    if (head ->next == NULL) {
        return head;
    }
    
    p = head -> next;
    q = p -> next;
    p -> next = NULL;
    
    while (q != NULL) {
        r = q -> next;
        q -> next = p;
        p = q;
        q = r;
    }
    head -> next = p;
    return head;
}

void dispList(node *L)//单链表的遍历
{
    node *p=L->next;//定义一个结点指针p指向头结点的下一个结点
    while(p){   //如果p不为空则循环
        printf("%d ",p->Data);
        p=p->next;//移动指针p遍历链表
    }
    printf("\n");
}

node *creatList(){//单链表的创建
    node *head = new node;
    node *p = head;
    for (int i = 0; i<10; i++) {
        node *q = new node;
        q -> Data = i;
        p ->next = q;
        p = q;
    }
    
    return head;
}

node *searchNode(node *head,int pos){//链表节点的查找
    node *p = head -> next;
    if (pos < 0) {
        printf("位置不正确\n");
        return NULL;
    }
    if (pos == 0){
        return head;
    }
    if (p == NULL) {
        printf("链表为空\n");
        return NULL;
    }
    while (--pos) {
        if ((p = p -> next) == NULL) {
            printf("超出链表范围\n");
            return  NULL;
        }
    }
    return p;
}

node *insertNode(node *head,int pos,int data){//单链表节点的插入
    node *item = NULL;
    node *p;
    item = new node;
    item -> Data = data;
    if (pos == 0) {
        item -> next = head ->next;
        head -> next = item;
        return head;
    }
    p = searchNode(head, pos);
    if (p != NULL) {
        item -> next = p -> next;
        p -> next = item;
    }
    return head;
}

node *deleteNode(node *head,int pos){//单链表结点的删除
    node *p = head -> next;
    if (p == NULL) {
        printf("链表为空\n");
        return NULL;
    }
    p = searchNode(head, pos -1);
    if (p != NULL && p -> next != NULL) {
        p -> next = p -> next -> next;
    } else {
        printf("超出范围\n");
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    node *head = creatList();//创建一个链表
    dispList(head);//遍历输出一个链表
    
    /*单链表结点的删除
    int pos = 0;
    while (cin>>pos) {
        deleteNode(head, pos);
        dispList(head);
    }
    */
    
    /*单链表节点的插入
    int data = 0;
    int pos = 0;
    while (cin>>pos>>data) {
        insertNode(head, pos, data);
        dispList(head);
    }
    */
    
    /*链表节点的查找
    int pos = 0;
    while (cin>>pos) {
        node *p = searchNode(head, pos);
        if (p == NULL) {
            
        } else {
            printf("-----%d=====>",p -> Data);
            cout<<p<<endl;
        }
    }
     */
    return 0;
}
