#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100  // Максимальная длина слова
#define MAX_WORDS 1000    // Максимальное количество слов в файле

int compare(const void* a, const void* b) {
    return strlen(*(const char**)a) - strlen(*(const char**)b);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];  // Массив для хранения слов
    int n = 0;  // Количество слов в файле

    // Открываем файл для чтения
    FILE* fp_in = fopen("input.txt", "r");
    if (fp_in == NULL) {
        printf("Error open input.txt\n");
        return 1;
    }

    // Считываем слова в массив
    while (fscanf(fp_in, "%s", words[n]) == 1) {
        n++;
        if (n == MAX_WORDS) {
            printf("Превышено максимальное количество слов в файле\n");
            return 1;
        }
    }

    // Закрываем файл для чтения
    fclose(fp_in);

    // Сортируем массив по длине слов
    qsort(words, n, sizeof(words[0]), compare);

    // Открываем файл для записи
    FILE* fp_out = fopen("output.txt", "w");
    if (fp_out == NULL) {
        printf("Error open output.txt\n");
        return 1;
    }

    // Записываем отсортированный массив в файл
    for (int i = 0; i < n; i++) {
        fprintf(fp_out, "%s\n", words[i]);
    }

    // Закрываем файл для записи
    fclose(fp_out);

    printf("Words are written successfuly %d in output.txt\n", n);

    return 0;
}
