#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void)
{

    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("./datasets/oncotex_pgm");

    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        printf ("%s\n", lsdir->d_name);
    }

    closedir(dir);

    return 0;

}