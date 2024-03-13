#include <stdio.h>
#include <string.h>

// Function to generate response based on user input
const char* generateResponse(const char* input) {
    const char* responses[] = {
        "Hello! How can I help you?",
        "I'm sorry, I didn't understand that.",
        "Could you please provide more information?",
        "That's interesting. Tell me more.",
        "I'm a simple AI. Please ask me questions.",
        "I'm still learning. Can you repeat that?",
        "I'm not sure what you mean. Can you clarify?"
    };
    int num_responses = sizeof(responses) / sizeof(responses[0]);

    // Simple logic to generate a response based on input length
    int input_length = strlen(input);
    int index = input_length % num_responses;

    return responses[index];
}

int main() {
    char input[100];

    printf("Welcome to the AI chatbot!\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // Remove trailing newline from fgets input

        // If user types "exit", exit the program
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Generate and display response
        printf("AI: %s\n", generateResponse(input));
    }

    return 0;
}

