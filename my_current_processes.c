/*
 * Filename: my_current_processes.c
 * Description: Question 2
 * Date: May 18, 2022
 * Name: Daven Chohan
 */

#include <stdio.h>   // printf()
#include <dirent.h> // for reading directory
#include <ctype.h> // isdigit()

void main() {
    struct dirent *readProc; //used to read the directory
    DIR *proc = opendir("/proc"); // open the directory
    while (proc) {
        readProc = readdir(proc); // read directory
        if (readProc != NULL) //if the directory is read properly
        {
            if (isdigit(readProc->d_name[0])) //only print sub-directories with a numeric name
            {
                printf("%s\n",readProc->d_name); //print
            }
        } else {
            closedir(proc);
            return;
        }
    }
    printf("%s","\nFailed to open directory /proc"); // This should never happen, just added in case an error occurs
    closedir(proc);
    return;
}