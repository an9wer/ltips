/*
 * long int ftell(FILE *stream)
 */

#include <stdio.h>
#include <stdlib.h>
#include <main.h>

 int main(void)
{
    FILE *fp = fopen(TEST_FILE, "r");
    if (fp == NULL) goto error;

    int res = fseek(fp, 0L, SEEK_END);
    if (res != 0) goto error;
    
    long int len = ftell(fp);
    if (len == EOF) goto error;
    printf("file size: %d\n", len);

    fclose(fp);
    return EXIT_SUCCESS;

error:
    perror("Error");
    if (fp != NULL) fclose(fp);
    return EXIT_FAILURE;
}
