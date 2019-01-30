#include <stdio.h>
#include <string.h>

#define WIDTH 1920
#define HEIGHT 1080

const int green[3] = {1, 151, 0};
const int white[3] = {255, 255, 255};
const int red[3] = {233, 0, 0};
const int brown[3] = {139, 69, 16};

void fill()
{
	int i, j, k;
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			if(i < HEIGHT / 3)
			{	
				if(j < WIDTH / 3)
					printf("%d %d %d ", green[0], green[1], green[2]);
				else if(j >= WIDTH / 3 && j <= 2 * WIDTH / 3)
					printf("%d %d %d ", white[0], white[1], white[2]);
				else
					printf("%d %d %d ", red[0], red[1], red[2]);
			}
			else if(i > 2 * HEIGHT / 3)
			{
				if(j < WIDTH / 3)
					printf("%d %d %d ", green[0], green[1], green[2]);
				else if(j >= WIDTH / 3 && j <= 2 * WIDTH / 3)
					printf("%d %d %d ", white[0], white[1], white[2]);
				else
					printf("%d %d %d ", red[0], red[1], red[2]);
			}
			else
			{
				if(j < WIDTH / 3)
				printf("%d %d %d ", green[0], green[1], green[2]);
				else if(j >= WIDTH / 3 && j <= 2 * WIDTH / 3)
					printf("%d %d %d ", brown[0], brown[1], brown[2]);
				else
					printf("%d %d %d ", red[0], red[1], red[2]);
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
