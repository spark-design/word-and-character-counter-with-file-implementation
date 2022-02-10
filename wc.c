#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>


// get wordcount 
int wordcount(char space[],int totalwords){
    // initialize variables
    int i;
    
    // Count number of words
    for(i = 0;space[i] != '\0'; i++)
    {
    	if(space[i] == ' ' || space[i] == '\n' || space[i] == '\t')
    	{
    		totalwords++;
    	}
    }
    printf("words: %d\n", totalwords);
    
return totalwords;
}

// get character count
int charcount(char space[]){
    int totalchars = 0;
    int i;
    // Count number of chars
    for(i = 0;space[i] != '\0'; i++)
    {
        if(space[i] != ' ' && space[i] != '\n' && space[i] != '\t')
        {	
        	totalchars++;
        }
    }
    printf("chars: %d\n", totalchars);
    
return totalchars;
}


// open and read file, either counting word or char count
int readtext(int type, char space[],char fileName[]){
    int fd = open(fileName, O_RDONLY);
    // read until EOF
    int words = 0;
    while (1) {
    int rdVals; // initialize int to read file
    rdVals = read(fd,space,20);
    if(rdVals == 0)
    	break;
    if (rdVals == -1) // print out error message if read can't work
    {
    	perror("read");
    	exit(EXIT_FAILURE);
    }
    printf("%s", space);
    if(type == 1){
    	int words = wordcount(space, 0);
    }
    
    if(type == 0){
    	int words = charcount(space);
    }
   }
return words;
}


 int main(int argc, char *argv[])
{   
    int r;
    int words = 0;
    int chars = 0;
    char space[100];
    
    // if just ./wc is given, take in strings and find word and char count and output when user is done.
    if(argc == 1){
    scanf("%[^\n]%*c", space);
    words = wordcount(space, 1);
    chars = charcount(space);
    }
    
    
    if(argc == 4){
    
    opterr = 0;
    while ((r = getopt(argc, argv, "if:wc")) != -1)
    {
       switch(r){
	case 'w':
	words = readtext(1, space,argv[3]);
	break;
	case 'c':
	chars = readtext(0, space,argv[3]);
	break;
	}
   }
  }
   
    
return 0;  
}

