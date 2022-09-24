/*
 * Filename: my_memory_util.c
 * Description: Question 3
 * Date: May 18, 2022
 * Name: Daven Chohan
 */

#include <stdio.h>   // printf()
#include <string.h>

void main() {
    char temp[100]; // Can read maximum 100 char for the name of the mem
    int mem; // int for how much mem the type is equal to
    char kb[5]; // just to hold the kb at the end of each line
    int total;
    int free;
    int buffers;
    int cached;
    int slab;
    float memUtil;
    FILE *file;

    file = fopen("/proc/meminfo", "r"); // Opening the file

    if (file) { // if the file exists
        while (fscanf(file, "%s %d %s", temp, &mem, kb) != EOF) { // checking if it has reached the end of the file and reading each line
            if (strcmp(temp, "MemTotal:") == 0) //checking if the current line is memtotal
            {
                total = mem;
            }
            else if (strcmp(temp, "MemFree:") == 0) //checking if the current line is memfree
            {
                free = mem;
            }
            else if (strcmp(temp, "Buffers:") == 0) //checking if the current line is buffers
            {
                buffers = mem;
            }
            else if (strcmp(temp, "Cached:") == 0) //checking if the current line is cached
            {
                cached = mem;
            }
            else if (strcmp(temp, "Slab:") == 0) //checking if the current line is slab
            {
                slab = mem;
            }
        }
        fclose(file);
    }
    memUtil = total - free - buffers - cached - slab; //Calculating the numerator
    memUtil = (memUtil/total)*100; //calculating the precent of memory utilization
    printf("%.2f\n", memUtil);
}