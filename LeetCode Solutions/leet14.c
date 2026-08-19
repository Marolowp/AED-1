#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* criarNo (int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    if (newNode == NULL){
        printf("Não foi possivel alocar memoria");
        exit(1);
    }
    
    newNode -> val = val;
    newNode -> next = NULL;
    
    return newNode;
}
  
struct ListNode* mergedTwoLists (struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) return l2;
    if(l1 == NULL) return l1;

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            tail -> next = l1;
            l1 = l1 -> next;
        }
        else{
            tail -> next = l2;
            l2 = l2 -> next;
        }
        tail = tail -> next;
    } 

    if(l1 != NULL){
        tail -> next = l1;
    } 
    else {
        tail -> next = l2;
    }
    return dummy.next;
}

int main(){
    struct ListNode* l1 = criarNo(1);
    l1 -> next = criarNo(2);
    l1 -> next -> next = criarNo(4);

    struct ListNode* l2 = criarNo(1);
    l2 -> next = criarNo(3);
    l2 -> next -> next = criarNo(4);

    struct ListNode* result = mergedTwoLists(l1, l2);

    struct ListNode* temp = result;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}