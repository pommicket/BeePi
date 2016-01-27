#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int msPer;
int speakerMode;


void speakerNote(int freq)
{
    int i;
    int samples = 8*msPer;
    for (i = 0; i < samples; i++)
    {
	putchar((int)(256*sin(freq*i)));
    }
}

int playNote(char i)
{
    int freq;
    switch(i)
    {
    case '0':
	freq = 247;
	break;
    case '1':
	freq = 262;
	break;
    case '2':
	freq = 294;
	break;
    case '3':
	freq = 330;
	break;
    case '4':
	freq = 349;
	break;
    case '5':
	freq = 392;
	break;
    case '6':
	freq = 440;
	break;
    case '7':
	freq = 494;
	break;
    case '8':
	freq = 523;
	break;
    case '9':
	freq = 587;
	break;
    default:
	return 0;
	break;
    }
    int retval;
    if (!speakerMode)
    {
	char* command = malloc(256);
	sprintf(command, "beep -f %d -l %d", freq, msPer);
	retval = system(command);
	free(command);
    }
    else
    {
	speakerNote(freq);
	retval = 0;
    }
    return retval;
}

int eq(char* b1, char* b2)
{
    int i;
    if (strlen(b1) != strlen(b2))
	return 0;
    for (i = 0; i < strlen(b1); i++)
	if (b1[i] != b2[i])
	    return 0;
    return 1;
}

int main(int argc, char** argv)
{
    int i;
    speakerMode = 0;
    int speakerModeIndex = 0;
    for (i = 0; i < argc; i++)
    {
	if (eq(argv[i], "--speaker"))
	{
	    speakerMode = 1;
	    speakerModeIndex = i;
	}
    }
    
    msPer = 200;
    if (argc > (1+speakerMode))
    {
	if (eq(argv[1], "--help"))
	{
	    printf("Usage: beepi <length per note in ms>\n");
	    return 0;
	}

	if ((!speakerMode) || speakerModeIndex == 2) 
	    msPer = atoi(argv[1]);
	else if (speakerModeIndex == 1)
	    msPer = atoi(argv[2]);
	
    }
    
    
    
    
    FILE* fp;
    fp = fopen("pi.txt", "r");
    int sz;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char* buffer = malloc(100000);
    fread(buffer, sz, 1, fp);
    fclose(fp);

    for (i = 0; i < strlen(buffer); i++)
	if (playNote(buffer[i]))
	    return 0;
    
}
