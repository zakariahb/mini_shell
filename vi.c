#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>

// Enum for token types
typedef enum e_token_type {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_OUT,
    TOKEN_REDIRECT_IN,
    TOKEN_APPEND,
    TOKEN_HEREDOC,
    TOKEN_EOF
} t_token_type;

// Token structure
typedef struct s_token {
    t_token_type type;
    char *value;
} t_token;

// Function to create a token
t_token *create_token(t_token_type type, char *value) {
    t_token *token = malloc(sizeof(t_token));
    if (!token) return NULL; // Check for malloc failure
    token->type = type;
    token->value = strdup(value);
    if (!token->value) { // Check for strdup failure
        free(token);
        return NULL;
    }
    return token;
}

// Function to print a token (for debugging)
void print_token(t_token *token) {
    const char *type_names[] = {
        "WORD", "PIPE", "REDIRECT_OUT", "REDIRECT_IN", "APPEND", "HEREDOC", "EOF"
    };
    printf("Token { type: %s, value: '%s' }\n", type_names[token->type], token->value);
}

// Function to free a token
void free_token(t_token *token) {
    if (token) {
        if (token->value) free(token->value);
        free(token);
    }
}

// Lexer function
t_token **tokenize(char *input) {
    if (!input) return NULL; // Handle empty input

    t_token **tokens = malloc(100 * sizeof(t_token *));
    if (!tokens) return NULL; // Check for malloc failure

    int token_count = 0;

    while (*input) {
        // Skip whitespace
        if (isspace(*input)) {
            input++;
            continue;
        }

        // Handle special characters
        if (*input == '|') {
            tokens[token_count++] = create_token(TOKEN_PIPE, "|");
            input++;
        } else if (*input == '>') {
            if (*(input + 1) == '>') {
                tokens[token_count++] = create_token(TOKEN_APPEND, ">>");
                input += 2;
            } else {
                tokens[token_count++] = create_token(TOKEN_REDIRECT_OUT, ">");
                input++;
            }
        } else if (*input == '<') {
            if (*(input + 1) == '<') {
                tokens[token_count++] = create_token(TOKEN_HEREDOC, "<<");
                input += 2;
            } else {
                tokens[token_count++] = create_token(TOKEN_REDIRECT_IN, "<");
                input++;
            }
        } else {
            // Handle words (including quoted strings)
            char *start = input;
            int in_quotes = 0;
            char quote_char = 0;

            while (*input && (in_quotes || !isspace(*input) && !strchr("|><", *input))) {
                if (*input == '\'' || *input == '"') {
                    if (!in_quotes) {
                        in_quotes = 1;
                        quote_char = *input;
                    } else if (*input == quote_char) {
                        in_quotes = 0;
                    }
                }
                input++;
            }

            char *word = strndup(start, input - start);
            tokens[token_count++] = create_token(TOKEN_WORD, word);
            free(word);
        }
    }

    // Add EOF token
    tokens[token_count++] = create_token(TOKEN_EOF, "EOF");

    return tokens;
}

int main() {
	puts("hhhh");
    char *input = readline("shell> ");
	puts("hhhh");
    if (!input) {
        fprintf(stderr, "Error: Failed to read input.\n");
        return 1;
    }

    t_token **tokens = tokenize(input);
    if (!tokens) {
        fprintf(stderr, "Error: Failed to tokenize input.\n");
        free(input);
        return 1;
    }

    // Print tokens
    for (int i = 0; tokens[i]->type != TOKEN_EOF; i++) {
        print_token(tokens[i]);
    }

    // Free tokens
    for (int i = 0; tokens[i]->type != TOKEN_EOF; i++) {
        free_token(tokens[i]);
    }
    free(tokens);
    free(input);

    return 0;
}