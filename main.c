#include <stdio.h>
#include <stdlib.h>

int collatz(unsigned int number) {
    int steps = 0;
    while (number != 1) {
        if (number % 2 == 0) {
            number = number / 2;
        } else {
            number = 3 * number + 1;
        }
        steps++;
    }
    return steps;
}

int random_number(int MIN, int MAX) {
    return (rand() % (MAX - MIN + 1)) + MIN;
}

int main(int argc, char *argv[]) {
   if (argc != 4) {
      printf("Usage: %s <N> <MIN> <MAX>\n", argv[0]);
      return 1;
   }
   
   int number = atoi(argv[1]);
   int MIN_value = atoi(argv[2]);
   int MAX_value = atoi(argv[3]);

    printf("Random Number, Steps\n");

    for (int i = 0; i < number; i++) {
        int random = random_number(MIN_value, MAX_value);
        int steps = collatz(random);
        printf("%u, %d\n", random, steps);
    }

    return 0;
}

