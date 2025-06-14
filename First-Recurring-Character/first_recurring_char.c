#include <stdio.h>

int ft_strlen(char *str) {

    int len = 0;
    while (str[len])
        len++;
    return len;
}

int checkRecurrence(char dp[], char c) {

    int i = 0;
    while (dp[i]) {         // check previously stored characters 

        if (c == dp[i])
            return (1);     // character is recurring
        i++;
    }
    return 0;
}

// Time complextity: O(n^2)
char firstRecurringChar(char *str) {

    int len = ft_strlen(str);
    char dp[len];               // temporary array to track seen characters
    int j = 0;

    for (int i = 0; i < len; i++) {
        
        if (checkRecurrence(dp, str[i]))    // if character has seen return it
            return str[i];
        dp[j] = str[i];                     // otherwise, insert it to dp
        j++;
    }
    return '\0';            // return null if no character is recurring
}

int main() {

    char str[6] = "ABDCDC";

    printf("First recurring character is %c", firstRecurringChar(str));

    return 0;
}