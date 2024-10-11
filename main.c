#include <stdio.h>
#include "morpion.c"

int main() {
    char board[9];

    initializeBoard(board);

    int player_input;

    for (int tour = 0; tour < 9; tour++) {
        printBoard(board);
        printf("Entrez un numéro de case (1-9) : ");
        scanf("%d", &player_input);

        // Vérifier si l'entrée est dans la plage valide
        if (player_input < 1 || player_input > 9 || board[player_input - 1] == 'X' || board[player_input - 1] == 'O') {
            printf("Entrée invalide. Veuillez entrer un numéro valide entre 1 et 9.\n");
            tour--;
            continue;
        }

        // Calculer le déplacement
        int move = player_input - 1;

        // Mettre à jour le tableau
        board[move] = (tour % 2 == 0) ? 'X' : 'O';

        // Vérification des victoires : lignes
        if (board[0] == board[1] && board[1] == board[2] || // Ligne du haut
            board[3] == board[4] && board[4] == board[5] || // Ligne du milieu
            board[6] == board[7] && board[7] == board[8] || // Ligne du bas
            board[0] == board[3] && board[3] == board[6] || // Colonne de gauche
            board[1] == board[4] && board[4] == board[7] || // Colonne du milieu
            board[2] == board[5] && board[5] == board[8] || // Colonne de droite
            board[0] == board[4] && board[4] == board[8] || // Diagonale gauche-droite
            board[2] == board[4] && board[4] == board[6]) { // Diagonale droite-gauche
            printBoard(board);
            printf("Un joueur a gagné!\n");
            return 0;
        }

        // Vérification de match nul
        int match_nul = 1;
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                match_nul = 0;
                break;
            }
        }
        if (match_nul) {
            printBoard(board);
            printf("Match nul!\n");
            return 0;
        }
    }

    // Afficher le tableau final
    printBoard(board);
    printf("Match nul!\n");

    return 0;
}
