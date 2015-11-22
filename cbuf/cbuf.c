/*
 * Filename: cbuf.c
 * Author: Volkan Salma
 * Created: 22.11.2015
 */

#include "cbuf.h"

/*
  Init the circular ring buffer
*/
void cbuf_init(CBUF *cbuf)
{
	int i;
	cbuf->head = 0;
	cbuf->tail = 0;
	cbuf->cnt = 0;

	/* empty the buffer */ 
	for (i = 0; i <  C_BUF_SIZE; i++){
		cbuf->buff[i] = (unsigned char)0;
	}
}

inline unsigned int cbuf_isempty(CBUF *cbuf)
{
	return (cbuf->cnt == 0);
}

inline unsigned int cbuf_isfull(CBUF *cbuf)
{
	return (cbuf->cnt >= C_BUF_SIZE);
}

inline unsigned int cbuf_cnt(CBUF *cbuf)
{
	return cbuf->cnt;
}

/*
 Push a char to circular ring buffer
 Warning: Caller is responsibe for checking whether 
 the c buff is full to avoid overwriting.
*/
inline void cbuf_push(CBUF *cbuf, unsigned char in)
{
	cbuf->buff[cbuf->head] = in;

	/* increase head by 1, if it excesses C_BUF_SIZE then 0 */
	cbuf->head = (cbuf->head + 1) & (C_BUF_SIZE - 1);
	cbuf->cnt++;
}

/*
 Pop a char from circular ring buffer
 Warning: Caller is responsibe for checking whether 
 the c buff is empty to avoid reading wrong data.
*/
inline unsigned char cbuf_pop(CBUF *cbuf)
{
	unsigned char tmp;
	tmp = cbuf->buff[cbuf->tail];

	/* increase tail by 1, if it excesses C_BUF_SIZE then 0 */
	cbuf->tail = (cbuf->tail + 1) & (C_BUF_SIZE - 1);
	cbuf->cnt--;

	return tmp;
}

/*
 Resets the ring buffer
*/
inline void cbuf_flush(CBUF *cbuf)
{
	cbuf_init(cbuf);
}
