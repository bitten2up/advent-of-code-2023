#include <stdio.h>
#include <stdlib.h>

enum {
    ONE = 'o'+'n'+'e',
    TWO = 't'+'w'+'o',
    THREE = 't'+'h'+'r'+'e'+'e',
    FOUR = 'f'+'o'+'u'+'r',
    FIVE = 'f'+'i'+'v'+'e',
    SIX = 's'+'i'+'x',
    SEVEN = 's'+'e'+'v'+'e'+'n',
    EIGHT = 'e'+'i'+'g'+'h'+'t',
    NINE = 'n'+'i'+'n'+'e'
} dumbconversion;

int main()
{
    printf("%i", THREE);
    exit(0);
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
        if (i <= sizeof(buffer) - 3)
        {
            if (start == 0)
            {
                if (buffer[i] + buffer[i+1] + buffer[i+2] == ONE)
                {

                }
            }
        }
        if (buffer[i] == '\n')
        {
            //printf("%i\n", start+end);
            total += start+end;
            start = 0;
            end = 0;
        }
    }
    printf("Value is: %i\n", total);
    free(buffer);
    buffer = NULL;
    return 0;
}