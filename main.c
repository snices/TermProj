#include "buffer.h"
#include <stdlib.h>

void *producer(void *param){
	buffer_item item;

	while (true){
		sleep(rand()%60);
		item = rand();
		if (insert_item(item))
			fprintf(stderr,"Producer failed to produce.\n");
		else
			printf("Producer produced %d\n", item);
	}

}

void *consumer(void *param){
	buffer_item item;

	while(true){
		sleep(rand()%60);

		if(remove_item(&item))
			fprintf(stderr,"Consumer failed to consume.\n");
		else
			printf("Consumer consumed %d\n", item);
	}
}

int main(int argc, char *argv[]){
	int sleep, p_count, c_count;
	sscanf(argv[1], %d, &sleep);
	sscanf(argv[2], %d, &p_count);
	sscanf(argv[3], %d, &c_count);
	

return 0;
}
