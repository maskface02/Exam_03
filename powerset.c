#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    int target = atoi(argv[1]);
    int n = argc - 2;
    int *numbers = NULL;

    if (n > 0) {
        numbers = (int *)malloc(n * sizeof(int));
        if (numbers == NULL) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            numbers[i] = atoi(argv[i + 2]);
        }
    }

    unsigned int total_subsets = 1u << n;
    for (unsigned int bitmask = 0; bitmask < total_subsets; bitmask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (bitmask & (1u << i)) {
                sum += numbers[i];
            }
        }

        if (sum == target) {
            int first = 1;
            for (int i = 0; i < n; i++) {
                if (bitmask & (1u << i)) {
                    if (first) {
                        printf("%d", numbers[i]);
                        first = 0;
                    } else {
                        printf(" %d", numbers[i]);
                    }
                }
            }
            printf("\n");
        }
    }

    if (numbers) {
        free(numbers);
    }

    return 0;
}
