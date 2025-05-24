#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void visualize(char **lines, int length) {
    system("clear");
    for (int i = 0; i < length; i++) {
        printf("%s\n", lines[i]);
    }
    usleep(550000);
}

void bubble_sort(char **lines, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (strlen(lines[j]) > strlen(lines[j + 1])) {
                char *temp = lines[j];
                lines[j] = lines[j + 1];
                lines[j + 1] = temp;
                visualize(lines, length);
            }
        }
    }
}

void insertion_sort(char **lines, int length) {
    for (int i = 1; i < length; i++) {
        char *key = lines[i];
        int j = i - 1;
        while (j >= 0 && strlen(lines[j]) > strlen(key)) {
            lines[j + 1] = lines[j];
            j--;
            visualize(lines, length);
        }
        lines[j + 1] = key;
        visualize(lines, length);
    }
}

void selection_sort(char **lines, int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < length; j++) {
            if (strlen(lines[j]) < strlen(lines[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char *temp = lines[i];
            lines[i] = lines[min_idx];
            lines[min_idx] = temp;
            visualize(lines, length);
        }
    }
}

void heapify(char **lines, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strlen(lines[left]) > strlen(lines[largest])) {
        largest = left;
    }
    if (right < n && strlen(lines[right]) > strlen(lines[largest])) {
        largest = right;
    }

    if (largest != i) {
        char *temp = lines[i];
        lines[i] = lines[largest];
        lines[largest] = temp;
        visualize(lines, n);
        heapify(lines, n, largest);
    }
}

void heap_sort(char **lines, int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(lines, length, i);
    }
    for (int i = length - 1; i >= 0; i--) {
        char *temp = lines[0];
        lines[0] = lines[i];
        lines[i] = temp;
        visualize(lines, i + 1);
        heapify(lines, i, 0);
    }
}

int partition(char **lines, int low, int high) {
    char *pivot = lines[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (strlen(lines[j]) < strlen(pivot)) {
            i++;
            char *temp = lines[i];
            lines[i] = lines[j];
            lines[j] = temp;
            visualize(lines, high + 1);
        }
    }
    char *temp = lines[i + 1];
    lines[i + 1] = lines[high];
    lines[high] = temp;
    visualize(lines, high + 1);
    return (i + 1);
}

void quick_sort_rec(char **lines, int low, int high) {
    if (low < high) {
        int pi = partition(lines, low, high);
        quick_sort_rec(lines, low, pi - 1);
        quick_sort_rec(lines, pi + 1, high);
    }
}

void quick_sort(char **lines, int length) {
    quick_sort_rec(lines, 0, length - 1);
}

void shell_sort(char **lines, int length) {
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            char *temp = lines[i];
            int j;
            for (j = i; j >= gap && strlen(lines[j - gap]) > strlen(temp); j -= gap) {
                lines[j] = lines[j - gap];
                visualize(lines, length);
            }
            lines[j] = temp;
            visualize(lines, length);
        }
    }
}

int get_choice(int min, int max) {
    char buffer[100];
    int choice;
    printf("Algorithms available:\n");
    printf("1) Bubble sort\n");
    printf("2) Insertion sort\n");
    printf("3) Selection sort\n");
    printf("4) Heap sort\n");
    printf("5) Quick sort\n");
    printf("6) Shell sort\n");

    while (1) {
        printf("Enter Algorithm Number (%d-%d): ", min, max);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Input Error, Try again\n");
            continue;
        }
        if (sscanf(buffer, "%d", &choice) != 1) {
            printf("Input Error, enter number\n");
            continue;
        }
        if (choice < min || choice > max) {
            printf("Number is out of range\n");
            continue;
        }
        break;
    }
    return choice;
}

int main(void) {
    char *lines[] = {
        "----",
        "---",
        "-----",
        "--------",
        "------",
        "-------",
        "--",
        "-"
    };
    int len = sizeof(lines) / sizeof(lines[0]);
    int choice = get_choice(1, 6);

    printf("Original:\n");
    visualize(lines, len);

    switch(choice) {
        case 1: bubble_sort(lines, len); break;
        case 2: insertion_sort(lines, len); break;
        case 3: selection_sort(lines, len); break;
        case 4: heap_sort(lines, len); break;
        case 5: quick_sort(lines, len); break;
        case 6: shell_sort(lines, len); break;
    }

    printf("Sorted:\n");
    visualize(lines, len);

    return 0;
}

