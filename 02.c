#include <stdio.h>
#include <string.h>

int main() {
    
    int transitionTable[][2] = {
        {1, -1}, // State 0: Starting state, transition to state 1 on input 0, else invalid (-1)
        {1, 2},  // State 1: Transition to state 1 on input 0, transition to state 2 on input 1
        {1, -1}  // State 2: Transition to state 1 on input 0, else invalid (-1)
    };
    
    // 0: initial state
    // 1: final state
    // -1: trap state
    // 2: intermidiate

    int currentState = 0;
    char inputString[100];
    
    printf("Enter a string: ");
    scanf("%s", inputString);
    
    int inputLength = strlen(inputString);
    
    for (int i = 0; i < inputLength; i++) {
        char currentInput = inputString[i];

        // inital phase string start with 0
        if(i==0){
            if(currentInput=='0') currentState=1;
            else currentState=-1;
        }
        else{
            if(currentInput=='0') currentState=1;
            else currentState=2;
        }
        

        if (currentState == -1) {
            printf("Invalid string\n");
            return 0;
        }
    }
    
    // Check if the final state is 2 (accepting state)
    if (currentState == 1) {
        printf("Accepted\n");
    } else {
        printf("Not accepted\n");
    }
    
    return 0;
}

