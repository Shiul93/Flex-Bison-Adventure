#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static void set_speed(unsigned long bps,
                      unsigned int *n_bytes_interval,
                      unsigned long *microseconds)
{
	if (bps >= 8000) {
		/* x Bytes per 10 ms. */
		*n_bytes_interval = bps / 800;
		*microseconds = 10000;
	} else if (bps >= 800) {
		/* x Bytes per y µs. */
		*n_bytes_interval = (bps + 400) / 800;
		*microseconds = 8000000UL * *n_bytes_interval / bps;
	} else {
		/* 1 Byte per x µs. */
		*n_bytes_interval = 1;
		*microseconds = 8000000UL / bps;
	}
}

void sp(char txt[])
{
  unsigned long microseconds = 1000;
	struct timespec t;
	unsigned long bps = 600;
	unsigned int bytes_per_t= 3;
	int c;
	unsigned char debug = 0;
  int size = strlen(txt);
  int count = 0;


	set_speed(bps, &bytes_per_t, &microseconds);

	  t.tv_sec = microseconds / 1000000UL;
	  t.tv_nsec = microseconds * 1000;


	while (count<size) {




			fflush(stdout);

			nanosleep(&t, NULL);


		putchar(txt[count]);
    count = count +1;
	}
}
void ws(){printf(" ");}
//int main(int argc, char const *argv[]) {

//  char test[] = "bkajbdkbadaejrilgeligbaelbgiaergiuabeigbkfnb";
//  sp(test);
//  sp(test);
//  return 0;
//}
