/*
 * Filename: cbuf.h
 * Author: Volkan Salma
 * Created: 22.11.2015
 */
 
#ifndef CBUF_H
#define CBUF_H

#define C_BUF_SIZE	256 	/* must be a power of 2 */ 

typedef struct
{
	unsigned char buff[C_BUF_SIZE];
	unsigned int head;
	unsigned int tail;
	unsigned int cnt;
}CBUF;

void cbuf_init(CBUF *cbuf);

inline unsigned int cbuf_isempty(CBUF *cbuf);

inline unsigned int cbuf_isfull(CBUF *cbuf);

inline unsigned int cbuf_cnt(CBUF *cbuf);

inline void cbuf_push(CBUF *cbuf, unsigned char in);

inline unsigned char cbuf_pop(CBUF *cbuf);

inline void cbuf_flush(CBUF *cbuf);

#endif
