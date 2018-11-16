#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
#include "buffer.h"

void *produce(void *param);
void *consume(void *param);

sem_t full, empty;

int main(int argc, char *argv[]){
	int s_time, p_count, c_count, i;

	sscanf(argv[1], "%d", &s_time);
	sscanf(argv[2], "%d", &p_count);
	sscanf(argv[3], "%d", &c_count);

	pthread_t producer[p_count];
	pthread_t consumer[c_count];

	init_buff();
	sem_init(&full, 0, 0);
	sem_init(&empty,0,BUFFER_SIZE);

	for(i = 0; i < p_count; i++){
		if(pthread_create(&producer[i], NULL, produce, NULL)){
			fprintf(stderr, "Error creating producer.\n");
			return 1;
		}
	}

	for(i = 0; i < c_count; i++){
		if(pthread_create(&consumer[i], NULL, consume, NULL)){
			fprintf(stderr, "Error creating consumer.\n");
			return 1;
		}
	}

	sleep(s_time);

	for(i=0; i<p_count; i++){
		pthread_cancel(producer[i]);
	}

	for(i=0;i<c_count; i++){
		pthread_cancel(consumer[i]);
	}

return 0;
}

void *produce(void *param){
	buffer_item item;
	while (1){
		sleep(rand()%10);
		sem_wait(&empty);
		sem_post(&full);
		item = rand();
		if (insert_item(item))
			fprintf(stderr,"Producer failed to produce.\n");
		else
			printf("Producer produced %d\n", item);
		sem_post(&empty);
		sem_wait(&full);
	}
}

void *consume(void *param){
	buffer_item item;
	while(1){
		sleep(rand()%10);
		sem_wait(&empty);
		sem_post(&full);
		if(remove_item(&item))
			fprintf(stderr,"Consumer failed to consume.\n");
		else
			printf("Consumer consumed %d\n", item);
		sem_post(&empty);
		sem_wait(&full);
	}
}
