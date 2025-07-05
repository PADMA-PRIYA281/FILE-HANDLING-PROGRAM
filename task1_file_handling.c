#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot open file for writing!\n");
        return;
    }
    char data[1000];
    printf("Enter data to write to the file:\n");
    getchar(); // clear newline from previous input
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    printf("Data written successfully.\n");
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf(" File does not exist or cannot be opened!\n");
        return;
    }
    printf(" File Contents:\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n End of file.\n");
    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf(" Cannot open file for appending!\n");
        return;
    }
    char data[1000];
    printf("➕ Enter data to append to the file:\n");
    getchar(); // clear newline
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    printf(" Data appended successfully.\n");
    fclose(fp);
}

int main() {
    char filename[100];
    int choice;

    printf(" Enter file name (with .txt extension): ");
    scanf("%s", filename);

    do {
        printf("\n====== File Handling Menu ======\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Append to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(filename); break;
            case 2: writeFile(filename); break;
            case 3: readFile(filename); break;
            case 4: appendFile(filename); break;
            case 5: printf(" Exiting program. Goodbye!\n"); break;
            default: printf(" Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

