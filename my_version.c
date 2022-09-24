/*
 * Filename: my_version.c
 * Description: Question 1
 * Date: May 18, 2022
 * Name: Daven Chohan
 */

#include <stdio.h>   // printf()

void main() {
    char temp;
    FILE *file;
    file = fopen("/etc/os-release", "r"); // Opening the first file
    if (file) { // if the file exists
        while ((temp = getc(file)) != EOF) { // checking if the temporary variable has reached the end of the file
            printf("%c",temp); // Printing every char in the file 1 at a time
        }
        fclose(file);
    }
    file = fopen("/proc/version", "r"); // Opening the second file
    if (file) {
        while ((temp = getc(file)) != EOF) { // checking if the temporary variable has reached the end of the file
            printf("%c",temp); // Printing every char in the file 1 at a time
        }
        fclose(file);
    }

    return;
}