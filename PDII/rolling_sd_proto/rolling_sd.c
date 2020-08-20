#include <stdio.h>
#include "ring_buffer.h"

int main()
{
	double* space = malloc(sizeof(double) * 5);
	cbuf_handle_t circ_buff = circular_buf_init(space, 5);
	circular_buf_put(circ_buff, 1);
	circular_buf_put(circ_buff, 2);
	circular_buf_put(circ_buff, 3);
	circular_buf_put(circ_buff, 4);
	circular_buf_put(circ_buff, 5);
	for(int i = 0; i < 5; ++i)
	{
		printf("%f ", space[i]);
	}
	printf("%\n");
	circular_buf_put(circ_buff, 6);
	for(int i = 0; i < 5; ++i)
	{
		printf("%f\n", space[i]);
	}

	circular_buf_free(circ_buff);
	return 0;
}

