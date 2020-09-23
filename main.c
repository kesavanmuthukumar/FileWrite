#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

DataWrite(FILE *filePtr)
{
    char inputStr[1000];
    char flag[5];
    char flagStr[]= "yes";
    char temp;
    do
    {
      printf("Enter the string:\n");
      scanf("%c",&temp);
      fgets(inputStr, 1000, stdin);
      fputs(inputStr, filePtr);
      printf("Do you want write more yes/no :");
      scanf("%s",flag);

    }while(strcmp(flag, "yes") == 0);

  fclose(filePtr);
}

void main()
{

    int fileFormat;
    FILE* fp;
    char inputStr[1000];
    char filePath[256];
    char temp;

    printf("Which file mode you are going to choose:\n");
    printf("1.Create new file or Open Existing file with overwrite mode.\n");
    printf("2.Create new file or Open Existing file append mode.\n");

    scanf("%d", &fileFormat);
    if (fileFormat < 1 || fileFormat > 2)
    {
        printf("wrong file format\n");
        return 0;
    }
    printf("Enter file path: \n");
    scanf("%c",&temp);
    scanf("%[^\n]%*c", filePath);

    switch (fileFormat)
    {
    case 1:
        fp = fopen(filePath, "w");
        if (fp == NULL)
        {
            printf("Couldn't open file");
            return 0;
        }
        DataWrite(fp);
        break;

    case 2:
        fp = fopen(filePath, "a");
        if (fp == NULL)
        {
            printf("Couldn't open file");
            return 0;
        }
        DataWrite(fp);
        break;
    }

    getch();
}
