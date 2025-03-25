#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 

void reverse_lines(const char *filename) {
    FILE *file = fopen(filename, "r"); // открыть файл
    if (!file) {
        perror("ошибка открытия файла");
        exit(EXIT_FAILURE);
    }

    
    char **lines = NULL; // массив хранения 
    size_t line_count = 0; 
    char buffer[MAX_LINE_LENGTH]; 

    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        lines = realloc(lines, sizeof(char *) * (line_count + 1)); 
        if (!lines) {
            perror("ошибка выделения памяти");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        lines[line_count] = strdup(buffer); // буфер 
        if (!lines[line_count]) {
            perror("ошибка выделения памяти");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        line_count++;
    }

    fclose(file); 

    
    file = fopen(filename, "w"); // запись
    if (!file) {
        perror("ошибка открытия файла для записи");
        exit(EXIT_FAILURE);
    }

    
    for (int i = line_count - 1; i >= 0; i--) { 
        fputs(lines[i], file); 
        free(lines[i]); 
    }

    free(lines); // освобождение памяти
    fclose(file); 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "использование: %s <путь_к_файлу>\n", argv[0]);
        return EXIT_FAILURE;
    }

    reverse_lines(argv[1]);

    return EXIT_SUCCESS;
}
