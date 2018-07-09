/*
注：这个list.h 是为了配合示例程序而建的，内容来自：linux/include/linux/list.h 和相关文件
*/
#include <stdio.h> 
#include <string.h>
#ifndef _LINUX_LIST_H
#define _LINUX_LIST_H
#define MAX_NAME_LEN 32
#define MAX_ID_LEN 10
 
struct list_head {
         struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define offsetof(TYPE, MEMBER) ((size_t)  &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})


static inline void INIT_LIST_HEAD(struct list_head *list)
{
        list->next = list;
        list->prev = list;
}

static inline void __list_add(struct list_head *new, struct list_head *prev,struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}


static inline void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}
 
 
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
        next->prev = prev;
        prev->next = next;
}
 
static inline void list_del(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->next = 0;
        entry->prev = 0;
}


#define prefetch(x) __builtin_prefetch(x)


//注：这里prefetch 是gcc的一个优化，也可以不要
#define list_for_each(pos, head) \
         for (pos = (head)->next; prefetch(pos->next), pos != (head); \
                 pos = pos->next)

#define list_entry(ptr, type, member) \
         container_of(ptr, type, member)

#endif
typedef struct stud
{
    struct list_head list;
    char name[MAX_NAME_LEN];
    char stu_number[MAX_ID_LEN];
}num_n_stu;

int main(void)
{
    struct list_head head;
    num_n_stu stu_1;
    num_n_stu stu_2;
    num_n_stu *entry;

    struct list_head *p;
    INIT_LIST_HEAD(&head);
    strcpy(stu_1.name,"lisi");
    strcpy(stu_1.stu_number,"10000000");

    strcpy(stu_2.name,"zhangsan");
    strcpy(stu_2.stu_number,"10000001");
    list_add(&stu_1.list,&head);
    list_add(&stu_2.list,&head);
    list_del(&stu_2.list);
    list_for_each(p,&head)
    {
        entry=list_entry(p,struct stud,list);
        printf("name: %s\n",entry->name);
        printf("stu_number: %s\n",entry->stu_number);
    }
    list_del(&stu_1.list);
    return 0;
}



