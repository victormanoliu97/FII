#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>

void parcurg_recursiv(char *filename)
{
   struct stat stat_file;

   DIR *dir;

   struct dirent *dir_entry;

   if((dir=opendir(filename)) == NULL)
   {
      return;
   }

   while((dir_entry = readdir(dir)) != NULL)
   {
      stat(dir_entry->d_name, &stat_file);

      if(!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..") )
      {
         continue;
      }

      printf("%s\n",dir_entry->d_name);

      if(S_ISDIR(dir_entry->d_type))
      {
         parcurg_recursiv(dir_entry->d_name);
      }

   }

   closedir(dir);
}

int main(int argc, char *argv[])
{
   parcurg_recursiv(".");

   return 0;
}
