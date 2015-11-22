/*
 * Filename: main.c
 * Author: Volkan Salma
 * Created: 22.11.2015
 */
 
#include <stdio.h>

#include "cbuf.h"

/*
  Example usage for cbuf module 
*/
int main()
{
	CBUF my_cbuf;
	int i = 0;
	unsigned char data;

	cbuf_init(&my_cbuf);

	printf("is cbuff empty: %u\n", cbuf_isempty(&my_cbuf));
	printf("is cbuff full: %u\n", cbuf_isfull(&my_cbuf));
	printf("cbuff data cnt: %u\n", cbuf_cnt(&my_cbuf));

	/* push data example */
	for (i = 0; i < 260; i ++){

		/* !! caller is responsible for checking 
		 * whether the buffer is full */
		if (cbuf_isfull(&my_cbuf) != 1){
			cbuf_push(&my_cbuf, (unsigned char)i);
			printf("data pushed: %d\n", i);
		}
		else
		{
			printf("cbuff is full! data cnt: %u\n", cbuf_cnt(&my_cbuf));
		}
	}
	
	/* pop data example */
	for (i = 0; i < 260; i ++){

		/* !! caller is responsible for checking 
		 * whether the buffer is empty */
		if (cbuf_isempty(&my_cbuf) != 1){
			data = cbuf_pop(&my_cbuf);
			printf("data popped: %u\n", (unsigned int)data);
		}
		else
		{
			printf("cbuff is empty! data cnt: %u\n", cbuf_cnt(&my_cbuf));
		}
	}

	return 0;
}
