#ifndef BUFFER_H_
#define BUFFER_H_

#include <semaphore.h>
/* buffer.h */
typedef int buffer_item;
#define BUFFER_SIZE 5

int init_buff();
int insert_item(buffer_item item);
int remove_item(buffer_item *item);

#endif // BUFFER_H_
