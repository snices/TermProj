#include "buffer.h"

/* the buffer */
buffer_item buffer[BUFFER_SIZE];
sem_t mutex;

int init_buff(){
	int i;
	sem_init(&mutex, 0, 1);
	for (i = 0; i < BUFFER_SIZE; i++){
		buffer[i]=0;
	}
return 0;
}

int insert_item(buffer_item item){
	int i;
	sem_wait(&mutex);
	for( i = 0; i<BUFFER_SIZE; i++){
		if(buffer[i]== 0){
			buffer[i]=item;
			sem_post(&mutex);
			return 0;
		}
	}
sem_post(&mutex);
return -1;
}

int remove_item(buffer_item *item){
	int i=0;
	sem_wait(&mutex);
	if(buffer[i]!=0){
		*item=buffer[i];
		buffer[i]=0;
		while(buffer[i+1]!=0){
			buffer[i]=buffer[i+1];
			buffer[i+1]=0;
			i++;
		}
	sem_post(&mutex);
	return 0;
	}
sem_post(&mutex);
return -1;
}
