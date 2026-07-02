#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]){
    const char *path = (argc > 1) ? argv[1] : ".";

    DIR *dir = opendir(path);
    if(!dir){
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        if(entry->d_name == '.') continue;
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    

    // printf("%s\n", path);
    return 0;
}