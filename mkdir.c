###创建目录
#include<unistd.h> //access 头文件
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
int my_mkdir(char *path)
{
        char *tmp, *pos;
        int  sLen, i;
        tmp = strdup(path);
        pos = tmp;
        sLen = strlen(path);
        if (strncmp(pos, "/", 1) == 0) {
                pos += 1;
        } else if(strncmp(pos, "./", 2) == 0) {
                pos += 2;
        }
        for (; *pos != '\0'; ++pos) {
                printf("aa : %s\n", pos);
                if (*pos == '/') {
                        *pos = '\0';
                        
                        if (access(tmp, F_OK) == 0) {
                                *pos = '/';
                                continue;
                        }
                        
                        if (mkdir(tmp, 0755) != 0) {
                                free(tmp);
                                printf("mkdir error\n");
                                return -1;
                        }
                        
                        //printf("path : %s\n", tmp);
                        *pos = '/';
                }
                //printf("path : %s\n", tmp);
        }
        printf("if %s\n", tmp);
        if (*(pos - 1) != "/" && access(tmp, F_OK) != 0) {
                printf("ahhhahah\n");
                if (mkdir(tmp, 0755) != 0) {
                        free(tmp);
                        printf("mkdir error\n");
                        return -1;
                }
        }
        free(tmp);
        return 0;
}
int main()
{
        my_mkdir("./ewrwer/234234/yuiyui");
        //int a = mkdir("./ewrwer/eeeee", 0755);
        //printf("code : %d", a);
        return 0;
}
