#include <stdio.h>
#include <string.h>

int countOnes(char* binaryString) {
    int length = strlen(binaryString);
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (binaryString[i] == '1') {
            count++;
        }
    }
    
    return count;
}

int main() {
    char binaryString[100];
    
    printf("Enter a binary string: ");
    scanf("%s", binaryString);
    
    int onesCount = countOnes(binaryString);
    
    if (onesCount % 2 == 0) {
        printf("The number of 1's is even.\n");
    } else {
        printf("The number of 1's is odd.\n");
    }
    
    return 0;
}

