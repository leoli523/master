#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<list.h>


/**************** add list.h函式 ****************
* 加入上面描述的linux/list.h的操作函式。
************************************************/

struct My_DATA {
    int Data_1;
    int Data_2;
    int Data_3;
    struct list_head list;

};
void print_List(struct list_head *head){
    struct list_head *listptr;
    struct My_DATA *entry;
 
    printf("\n*********************************************************************************\n");
    printf("(HEAD addr =  %p, next = %p, prev = %p)\n",head, head->next, head->prev);
    list_for_each(listptr, head) {
        entry = list_entry(listptr, struct My_DATA, list);
        printf("entry->Data_1= %d | list addr = %p | next = %p | prev = %p\n",
                entry->Data_1, 
                &entry->list, 
                entry->list.next,  
                entry->list.prev  );
    }
    printf("*********************************************************************************\n");
}
struct My_DATA *add_Node_tail(struct list_head *head){
    struct My_DATA *entry;
    entry=(struct My_DATA*)malloc(sizeof(struct My_DATA));
    list_add_tail( &entry->list,head);
    return entry;
}

struct My_DATA *add_Node(struct list_head *head){
    struct My_DATA *entry;
    entry=(struct My_DATA*)malloc(sizeof(struct My_DATA));
    list_add( &entry->list,head);
    return entry;
}


void remove_Node(struct My_DATA *entry){
    printf("\nremove: Data_1=%d (list %p, next %p, prev %p)\n",
            entry->Data_1,
            &entry->list,
            entry->list.next,
            entry->list.prev);

    list_del(&entry->list);
    free(entry); 
}

void free_List(struct list_head *head)
{
    struct list_head *listptr;
    struct My_DATA *entry;
 
    list_for_each(listptr, head) {
        entry = list_entry(listptr, struct My_DATA, list);
        printf("\nFree: entry->Data_1 = %d | list addr = %p | next = %p | prev = %p\n",
                        entry->Data_1,
                        &entry->list,
                        entry->list.next,
                        entry->list.prev);
 
        free(entry);
        entry=NULL;
    }
}
int main(int argc,char **argv){

    LIST_HEAD(HEAD);

    struct My_DATA *itemPtr_1 = add_Node(&HEAD);
    itemPtr_1->Data_1 = 100 ;
    struct My_DATA *itemPtr_2 = add_Node(&HEAD);
    itemPtr_2->Data_1 = 200 ;
    struct My_DATA *itemPtr_3 = add_Node(&HEAD);
    itemPtr_3->Data_1 = 300 ;
    struct My_DATA *itemPtr_4 = add_Node(&HEAD);
    itemPtr_4->Data_1 = 400 ;

    print_List(&HEAD);

    remove_Node(itemPtr_3);
    print_List(&HEAD);
    free_List(&HEAD);
}
