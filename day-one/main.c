#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
    const char* ONE = "one";
    const char* TWO = "two";
    const char* THREE = "three";
    const char* FOUR = "four";
    const char* FIVE = "five";
    const char* SIX = "six";
    const char* SEVEN = "seven";
    const char* EIGHT = "eight";
    const char* NINE = "nine";
    FILE* input = fopen("test.txt", "r");

    fseek(input, 0L, SEEK_END);
    int inputsize = ftell(input);
    rewind(input);
    
    char* buffer = calloc(1, inputsize+1);

    if (buffer == NULL)
	{
		fclose(input);
		free(buffer);
		fputs("mem alloc failed\n", stderr);
		exit(1);
	}
    if (1 != fread(buffer,inputsize, 1, input))
	{
		fclose(input);
        free(buffer);
		fputs("read failed, or file is blank\n", stderr);
        exit(1);
	}
    fclose(input);
    int start, end, total;
    start = end = total = 0;
    for (int i = 0; i <= inputsize; i++)
    {
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            if (start == 0)
                start = (buffer[i] - '0')*10;
            end = buffer[i] - '0';
        }
        else {
        if (i+2 <= inputsize)
        {
            
            if (strncmp(&buffer[i], ONE, 3) == 0)
            {
                if (start == 0)
                {
                    start = 10;
                }
                end = 1;
            }
            //printf("%i:%i\n", buffer[i] + buffer[i+1] + buffer[i+2], TWO);
            else if (strncmp(&buffer[i], TWO, 3) == 0)
            {
                if (start == 0)
                {
                    start = 20;
                }
                end = 2;
            }
            else if (strncmp(&buffer[i], "six", 3) == 0)
            {
                if (start == 0)
                {
                    start = 60;
                }
                end = 6;
            }
        }
        if (i+3 <= inputsize)
        {
            if (strncmp(&buffer[i], FOUR, 3) == 0)
            {
                if (start == 0)
                {
                    start = 40;
                }
                end = 4;
            }
            if (strncmp(&buffer[i], FIVE, 3) == 0)
            {
                if (start == 0)
                {
                    start = 50;
                }
                end = 5;
            }
            if (strncmp(&buffer[i], NINE, 3) == 0)
            {
                if (start == 0)
                {
                    start = 90;
                }
                end = 9;
            }
        }
        if (i+4 <= inputsize)
        {
            //printf("test:%i:%i\n", buffer[i] + buffer[i+1] + buffer[i+2] + buffer[i+3] + buffer[i+4], THREE);
            if (strncmp(&buffer[i], THREE, 4) == 0)
            {
                if (start == 0)
                {
                    start = 30;
                }
                end = 3;
            }
            if (strncmp(&buffer[i], SEVEN, 4) == 0)
            {
                if (start == 0)
                {
                    start = 70;
                }
                end = 7;
            }
            if (strncmp(&buffer[i], EIGHT, 4) == 0)
            {
                if (start == 0)
                {
                    start = 80;
                }
                end = 8;
            }
        }

        if (buffer[i] == '\n')
        {
            printf("%i\n", start+end);
            total += start+end;
            start = 0;
            end = 0;
        }
    }}
    printf("Value is: %i\n", total);
    free(buffer);
    buffer = NULL;
    return 0;
}