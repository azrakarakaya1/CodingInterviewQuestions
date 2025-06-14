// Find first recurring character with hash table approach

#include <stdio.h>

// Time complexity: O(n)
char firstRecurringChar(char *str) {

    int seen[256] = {0};    // 256 possible characters in ASCII initialized all 0s
    unsigned char c;

    for (int i = 0; str[i]; i++) {

        c = str[i];         // ensure index stays in range 0-255  
        if (seen[c] == 1)    
            return str[i];  // first recurring character found

        seen[c] = 1;        // mark character as seen
    }
    return '\0';            // return null if no character is recurring
}

int main() {

    char str[6] = "ABDCDC";

    printf("First recurring character is %c", firstRecurringChar(str));

    return 0;
}