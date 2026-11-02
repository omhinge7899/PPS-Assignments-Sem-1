#include <stdio.h>
#include <string.h>

void main() {
    int choice, n;
    char str1[100], str2[100], ch, sub[50];
    char *p;

    while (1) {
        printf("\n===== String Operations Menu =====\n");
        printf("1. Find length (strlen)\n");
        printf("2. Copy string (strcpy)\n");
        printf("3. Concatenate strings (strcat)\n");
        printf("4. Compare strings (strcmp)\n");
        printf("5. Find character (strchr)\n");
        printf("6. Find substring (strstr)\n");
        printf("7. Tokenize string (strtok)\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline

        switch (choice) {
        case 1:
            printf("Enter a string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Length = %d\n", (int)strlen(str1));
            break;

        case 2:
            printf("Enter a string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            strcpy(str2, str1);
            printf("Copied string = %s\n", str2);
            break;

        case 3:
            printf("Enter first string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter second string: ");
            fgets(str2, 100, stdin);
            str2[strcspn(str2, "\n")] = '\0';
            strcat(str1, str2);
            printf("Concatenated string = %s\n", str1);
            break;

        case 4:
            printf("Enter first string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter second string: ");
            fgets(str2, 100, stdin);
            str2[strcspn(str2, "\n")] = '\0';
            if (strcmp(str1, str2) == 0)
                printf("Strings are equal\n");
            else
                printf("Strings are not equal\n");
            break;

        case 5:
            printf("Enter a string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter a character to find: ");
            scanf("%c", &ch);
            getchar();
            p = strchr(str1, ch);
            if (p != NULL)
                printf("Character found at position %d\n", (int)(p - str1) + 1);
            else
                printf("Character not found\n");
            break;

        case 6:
            printf("Enter main string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter substring to find: ");
            fgets(sub, 50, stdin);
            sub[strcspn(sub, "\n")] = '\0';
            p = strstr(str1, sub);
            if (p != NULL)
                printf("Substring found at position %d\n", (int)(p - str1) + 1);
            else
                printf("Substring not found\n");
            break;

        case 7:
            printf("Enter a string (words separated by space): ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            p = strtok(str1, " ");
            while (p != NULL) {
                printf("Token: %s\n", p);
                p = strtok(NULL, " ");
            }
            break;

        case 8:
            printf("Enter a string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            for (n = 0; str1[n] != '\0'; n++)
                str1[n] = toupper(str1[n]);
            printf("Uppercase = %s\n", str1);
            break;

        case 9:
            printf("Enter a string: ");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            for (n = 0; str1[n] != '\0'; n++)
                str1[n] = tolower(str1[n]);
            printf("Lowercase = %s\n", str1);
            break;

        case 10:
            printf("Exiting program...\n");
            return;

        default:
            printf("Invalid choice! Please enter 1 to 10.\n");
        }
    }
}
