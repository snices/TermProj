#include buffer.h

/* the buffer */
buffer_item buffer[BUFFER_SIZE]={0};

int insert_item(buffer_item item){
	int i;
	for( i = 0; i<BUFFER_SIZE; i++){
		if(buffer[i]== 0){
			buffer[i]=item;
			return 0;
		}
	}
return -1;
}
int remove_item(buffer_item *item){
	int i;
	for( i = BUFFER_SIZE-1; i>=0; i--){
		if(buffer[i]!=0){
			item=buffer[i];
			buffer[i]=0;
			return 0;
		}
	}
return -1;
}
