#include <stdio.h>
#include <time.h>

#define WIDTH 1920
#define HEIGHT 1080

void fill()
{
	srand(time(NULL));
	int i, j, k;
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			char esp = 32;
			for(k = 0; k < 3; k++)
			{
				int p = rand() % 256;
				printf("%d%c", p, esp);
				if(k == 2)
					esp = '\n';
			}
			
		}
	}
}
void init()
{
		printf("P3\n");
		printf("1920 1080\n");
		printf("255\n");
		fill();
		
}
int main()
{
	init();
	return 0;
}
