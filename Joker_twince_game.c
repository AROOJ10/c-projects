 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
 #include <ctype.h>
 
#define NUM_ROWS 5
#define NUM_COLS 5
#define NUM_PLAYERS 2

char visible_board[NUM_ROWS][NUM_COLS];
char hidden_board[NUM_ROWS][NUM_COLS];
int player1_score = 0;
int player2_score = 0;
int game_over = 0;
int turn;

void print_board();
void initialize_boards();
int is_valid_coordinate(char coordinate[2]);
void clear_screen();
void sleep_ms(int milliseconds);

int main() {
    srand(time(NULL));
    turn = rand() % NUM_PLAYERS;
    initialize_boards();

    while (game_over == 0) {
        printf("Player 1 score: %d\n", player1_score);
        printf("Player 2 score: %d\n", player2_score);

        print_board();

        char coordinate[2];
        int row_index1, col_index1, row_index2, col_index2;
        char card1, card2;

        // Player 1 or Player 2 turn
        printf("Player %d: Enter a coordinate (e.g. B3): ", turn + 1);
        while (1) {
            scanf("%s", coordinate);
            if (is_valid_coordinate(coordinate)) {
                row_index1 = coordinate[1] - '0';
                col_index1 = coordinate[0] - 'A';

                if (visible_board[row_index1][col_index1] == ' ') {
                    printf("This card has already been turned over. Please enter another coordinate.\n");
                } else {
                    card1 = hidden_board[row_index1][col_index1];
                    visible_board[row_index1][col_index1] = card1;
                    break;
                }
            } else {
                printf("Invalid coordinate entered. Please try again.\n");
            }
        }

        print_board();

        printf("Player %d: Enter another coordinate: ", turn + 1);
        while (1) {
            scanf("%s", coordinate);
            if (is_valid_coordinate(coordinate)) {
                row_index2 = coordinate[1] - '0';
                col_index2 = coordinate[0] - 'A';

                if (visible_board[row_index2][col_index2] == ' ') {
                    printf("This card has already been turned over. Please enter another coordinate.\n");
                } else if (hidden_board[row_index2][col_index2] == card1) {
                    printf("You have already turned this card over in the previous turn. Please try again.\n");
                } else {
                    card2 = hidden_board[row_index2][col_index2];
                    visible_board[row_index2][col_index2] = card2;
                    break;
                }
            } else {
                printf("Invalid coordinate entered. Please try again.\n");
            }
        }
  // Include this for the tolower() function

// Checking the combination of two cards
if (tolower(card1) == tolower(card2)) {  // Compare in a case-insensitive manner
    // If the cards match, remove them from the visible board
    visible_board[row_index1][col_index1] = ' ';
    visible_board[row_index2][col_index2] = ' ';

    // Update the score of the current player
    if (turn == 0) {
        player1_score++;  // Player 1 gets a point
    } else {
        player2_score++;  // Player 2 gets a point
    }
} else {
    // Show the board for 2 seconds before flipping the cards back
    print_board();
    sleep_ms(2000);

    // Flip cards back down
    visible_board[row_index1][col_index1] = '#';
    visible_board[row_index2][col_index2] = '#';

    clear_screen();
    // Switch to next player
    turn = (turn + 1) % NUM_PLAYERS;
}


        // Check if the game is over
        int finished = 1;
        for (int row = 0; row < NUM_ROWS; row++) {
            for (int col = 0; col < NUM_COLS; col++) {
                if (visible_board[row][col] != ' ') {
                    finished = 0;
                    break;
                }
            }
        }

        if (finished == 1) {
            printf("GAME OVER\n");
            if (player1_score > player2_score) {
                printf("Player 1 wins!\n");
            } else if (player2_score > player1_score) {
                printf("Player 2 wins!\n");
            } else {
                printf("Both players have equal scores.\n");
            }

            printf("Player 1 score: %d\n", player1_score);
            printf("Player 2 score: %d\n", player2_score);
            game_over = 1;
        }
    }

    return 0;
}

// Function to initialize the boards
void initialize_boards() {
    char current_letter = 'A';
    int num_squares = NUM_COLS * NUM_ROWS;
    char cards[num_squares];

    int index = 0;
    for (int i = 0; i < num_squares / 2; i++) {
        if (i == (num_squares / 2) - 1) {
            cards[index++] = '*';
            cards[index++] = '*';
            break;
        }
        cards[index++] = current_letter;
        cards[index++] = current_letter + 32; // Lowercase letter
        current_letter++;
    }
    if (num_squares % 2 != 0) {
        cards[index++] = '*';
    }

    // Fill hidden board with cards
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            visible_board[row][col] = '#';
            hidden_board[row][col] = '#';
        }
    }

    // Randomly place cards on the hidden board
    for (int i = 0; i < num_squares; i++) {
        while (1) {
            int rand_row = rand() % NUM_ROWS;
            int rand_col = rand() % NUM_COLS;
            if (hidden_board[rand_row][rand_col] == '#') {
                hidden_board[rand_row][rand_col] = cards[i];
                break;
            }
        }
    }
}

// Function to print the visible board
void print_board() {
    char letter = 'A';
    for (int col = 0; col < NUM_COLS; col++) {
        printf("   %c", letter);
        letter++;
    }
    printf("\n +");
    for (int col = 0; col < NUM_COLS; col++) {
        printf("---+");
    }
    printf("\n");

    for (int row = 0; row < NUM_ROWS; row++) {
        printf("%d|", row);
        for (int col = 0; col < NUM_COLS; col++) {
            printf(" %c |", visible_board[row][col]);
        }
        printf("\n +");
        for (int col = 0; col < NUM_COLS; col++) {
            printf("---+");
        }
        printf("\n");
    }
}

// Function to validate the coordinate input
int is_valid_coordinate(char coordinate[2]) {
    if (coordinate[0] >= 'A' && coordinate[0] < 'A' + NUM_COLS &&
        coordinate[1] >= '0' && coordinate[1] < '0' + NUM_ROWS) {
        return 1;
    }
    return 0;
}

// Function to clear the screen (for Unix-like systems)
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to pause for a specific number of milliseconds
void sleep_ms(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000) {
        // Busy-wait loop
    }
}
