#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void usage(char *prog_name, char *file_name)
{
    printf("Usage: %s <data to add to %s>\n", prog_name, file_name);
    exit(0);
}

void fatal(char *); // A function for fatal errors
void *ec_malloc(unsigned int); // An error-checked malloc() wrapper

int main(int argc, char *argv[])
{
    int fd; // file descriptor
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);

    strcpy(datafile, "/tmp/notes");

    if(argc < 2){
        usage(argv[0], datafile);
    }

    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    strncat(buffer, "\n", 2); // Add a newline on the end

    // Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);

    if(fd == -1){
        fatal("in main() while opening file");
    }

    printf("[DEBUG] file descriptor is %d\n", fd);

    // Writing data
    if(write(fd, buffer, strlen(buffer)) == -1){
        fatal("in main() while writing buffer to file");
    }

    // Closing file
    if(close(fd) == -1){
        fatal("in main() while closinf file");
    }

    printf("Note has been saved\n");

    free(buffer);
    free(datafile);
}

// function to display an error message and the exit
void fatal(char *message)
{
    char error_message[100];

    strcpy(error_message, "[!!] Fatal Error ");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

// malloc() wrapper function
void *ec_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);

    if(ptr == NULL){
        fatal("in ec_malloc() on memory allocation");
    }
    
    return ptr;
}
