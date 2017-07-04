#include <stdio.h>
#include <stdlib.h>

int getfilesize(char *filePath){

    FILE *fp;
    int fileSize;

    fp = fopen(filePath, "r");
    if(!fp)
    {
        printf("Cannot open %s", filePath);
        return 0;
    }

    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);

    fclose(fp);

    return fileSize;

}


void main(){

    printf("%d",getfilesize("/tftpboot/ECB1200.bin"));
    /* measure by file size */
    //return ((fileSize * 80) / (6886400)) + 1;
    //return (fileSize / 45846);

}
