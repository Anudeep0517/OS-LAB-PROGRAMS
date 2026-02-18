#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

int main()
{
    char d[100];
    int c, op;
    DIR *e;
    struct dirent *sd;

    printf("** MENU **\n");
    printf("1. Create directory\n");
    printf("2. Remove directory\n");
    printf("3. Read directory\n");
    printf("Enter your choice : ");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            printf("Enter directory name : ");
            scanf("%s", d);

            c = mkdir(d, 0777);
            if(c == -1)
                printf("Directory not created\n");
            else
                printf("Directory created\n");
            break;

        case 2:
            printf("Enter directory name : ");
            scanf("%s", d);

            c = rmdir(d);
            if(c == -1)
                printf("Directory not removed\n");
            else
                printf("Directory removed\n");
            break;

        case 3:
            printf("Enter directory name to open : ");
            scanf("%s", d);

            e = opendir(d);
            if(e == NULL)
                printf("Directory does not exist\n");
            else
            {
                printf("Directory contents:\n");
                while((sd = readdir(e)) != NULL)
                {
                    printf("%s\n", sd->d_name);
                }
                closedir(e);
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

