#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    STATE_INITIAL,
    STATE_I,
    STATE_IN,
    STATE_INT,
    STATE_F,
    STATE_FL,
    STATE_FLO,
    STATE_FLOA,
    STATE_FLOAT,
    STATE_UNACCEPTABLE
} State;

State transition(State currentState, char input) {
    switch (currentState) {
        case STATE_INITIAL:
            if (input == 'i') return STATE_I;
            if (input == 'f') return STATE_F;
            break;
        case STATE_I:
            if (input == 'n') return STATE_IN;
            break;
        case STATE_IN:
            if (input == 't') return STATE_INT;
            break;
        case STATE_F:
            if (input == 'l') return STATE_FL;
            break;
        case STATE_FL:
            if (input == 'o') return STATE_FLO;
            break;
        case STATE_FLO:
            if (input == 'a') return STATE_FLOA;
            break;
        case STATE_FLOA:
            if (input == 't') return STATE_FLOAT;
            break;
        default:
            break;
    }
    return STATE_UNACCEPTABLE;
}

bool isAcceptableType(const char* input) {
    State currentState = STATE_INITIAL;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        currentState = transition(currentState, input[i]);
    }

    return currentState == STATE_INT || currentState == STATE_FLOAT;
}

int main() {
    char input[100];

    printf("Enter a data type: ");
    scanf("%s", input);

    if (isAcceptableType(input)) {
        printf("Accepted\n");
    } else {
        printf("Unacceptable type\n");
    }

    return 0;
}
