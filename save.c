//seven
//s24949897@gmail.com

#include <unistd.h>
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <windows.h>
#include <shlobj.h>
#include <wchar.h>


int count_folders(const char *path) {
    int folder_count = 0;
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char fullpath[PATH_MAX];

    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            sprintf(fullpath, "%s/%s", path, ent->d_name);
            if (stat(fullpath, &st) == 0 && S_ISDIR(st.st_mode)) { 
                if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) { 
                    folder_count++;
                }
            }
        }
        closedir(dir);
    } else {
        fprintf(stderr, "Could not open directory %s\n", path);
        exit(EXIT_FAILURE);
    }

    return folder_count;
}










void copy_file(char* source_file, char* dest_file) {
    HANDLE source, dest;
    char buffer[1024];
    DWORD bytes_read, bytes_written;

    source = CreateFile(source_file, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    dest = CreateFile(dest_file, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    while (ReadFile(source, buffer, sizeof(buffer), &bytes_read, NULL) && bytes_read > 0) {
        WriteFile(dest, buffer, bytes_read, &bytes_written, NULL);
    }

    CloseHandle(source);
    CloseHandle(dest);
}

void copy_folder(char* source_folder, char* dest_folder) {
    WIN32_FIND_DATA find_data;
    HANDLE find_handle;
    char source_path[256], dest_path[256];

    snprintf(source_path, sizeof(source_path), "%s/*", source_folder);

    find_handle = FindFirstFile(source_path, &find_data);
    if (find_handle == INVALID_HANDLE_VALUE) {
        printf("Failed to open directory %s.\n", source_folder);
        return;
    }

    do {
        if (strcmp(find_data.cFileName, ".") == 0 || strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source_folder, find_data.cFileName);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_folder, find_data.cFileName);

        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            CreateDirectory(dest_path, NULL);
            copy_folder(source_path, dest_path);
        } else {
            copy_file(source_path, dest_path);
        }
    } while (FindNextFile(find_handle, &find_data));

    FindClose(find_handle);
}








int main(int argc, char *argv[]) {
    char cwd[1024];
    char path[1024];
    char str[32];


 TCHAR desktop[1024];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, 0, desktop))) {
    }

    strcat(desktop, "\\");
    getcwd(cwd, sizeof(cwd));   
    sprintf(path, "%s%s", desktop, basename(cwd));
    strcat(path, "_CheckPoint");  
    if (access(path, F_OK) != 0) {  
        if(mkdir(path) == -1) {    
            perror("Error creating 0000");
            exit(EXIT_FAILURE);
        }
    } 




    

   


int folder_count = count_folders(path);




        
        strcat(path, "\\");

        sprintf(path, path, basename(cwd)); 

        sprintf(str, "%d", folder_count);
        strcat(path, basename(cwd));
        strcat(path, "_");
        strcat(path, str);


        
        if(mkdir(path) == -1) {
            perror("Error creating 000");
            exit(EXIT_FAILURE);
        }


        copy_folder(cwd, path);



if (argc > 1) {
    char *file_name = "CheckPoint.txt";
    char full_path[256];
    FILE *file;

    sprintf(full_path, "%s\\%s", path, file_name);

    file = fopen(full_path, "w+");
    if (file == NULL) {
        return 1;
    }

    char message[256] = "";
    for (int i = 1; i < argc; i++) {
        strcat(message, argv[i]);
        if (i < argc - 1) {
            strcat(message, " ");
        }
    }

    fprintf(file, "#####################################################################################\n\n%s\n\n#####################################################################################", message);
    fclose(file);
}


  




    return 0;
}
