#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char titre[50];
    char auteur[50];
    float prix;
    int quantiter;
} livre;

// Check if the strings are equal 
int strEqual(char firstStr[50], char secondStr[50]){
    if (strlen(firstStr) != strlen(secondStr)) {
        return 0;
    }

    for (int i = 0; firstStr[i] != '\0' && secondStr[i] != '\0'; i++) {
        if (tolower(firstStr[i]) != tolower(secondStr[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to display the menu
void menu() {
    printf("\n*********** Menu ***********\n");
    printf("1. Ajouter un ou plusieurs livres\n");
    printf("2. Modifier un livre\n");
    printf("3. Supprimer un livre\n");
    printf("4. Rechercher un livre\n");
    printf("5. Trier les livres\n");
    printf("6. Afficher les statistiques\n");
    printf("0. Exit...\n");
    printf("******************************\n");
}

// Function to add a book
void ajouterLivre(livre livres[], int *numberLivres) {
    int selectedMethod;
    printf("\n1. Ajouter un seul livre\n");
    printf("2. Ajouter plusieurs livres\n");
    printf("=> ");
    scanf("%d", &selectedMethod);

    if (selectedMethod == 1) {
        printf("\n=== Ajout d'un nouveau livre ===\n");

        printf("Titre du livre: ");
        scanf(" %49[^\n]", livres[*numberLivres].titre);

        printf("Auteur du livre: ");
        scanf(" %49[^\n]", livres[*numberLivres].auteur);

        printf("Prix du livre: ");
        scanf("%f", &livres[*numberLivres].prix);

        printf("Quantite du livre: ");
        scanf("%d", &livres[*numberLivres].quantiter);

        (*numberLivres)++;
        printf("\nLe livre a ete ajoute avec succes!\n");
    } else if (selectedMethod == 2) {
        int numLivre;
        printf("\nCombien de livres voulez-vous ajouter? : ");
        scanf("%d", &numLivre);

        for (int i = 0; i < numLivre; i++) {
            printf("\n=== Ajout du livre numero %d ===\n", i + 1);

            printf("Titre du livre: ");
            scanf(" %49[^\n]", livres[*numberLivres].titre);

            printf("Auteur du livre: ");
            scanf(" %49[^\n]", livres[*numberLivres].auteur);

            printf("Prix du livre: ");
            scanf("%f", &livres[*numberLivres].prix);

            printf("Quantite du livre: ");
            scanf("%d", &livres[*numberLivres].quantiter);

            (*numberLivres)++;
        }
        printf("\nTous les livres ont ete ajoutes avec succes!\n");
    } else {
        printf("\nOption invalide. Veuillez reessayer.\n");
    }
}

// Function to display all books
void afficherLivres(livre livres[], int *numberLivres) {
    if (*numberLivres > 0) {
        for (int i = 0; i < *numberLivres; i++) {
            printf("********** Le livre numero %d **********\n", i + 1);
            printf("Titre: %s\n", livres[i].titre);
            printf("Auteur: %s\n", livres[i].auteur);
            printf("Prix: %.2f\n", livres[i].prix);
            printf("Quantite: %d\n", livres[i].quantiter);
            printf("***********************************\n");
        }
    } else {
        printf("\nAucun livre disponible\n");
    }
}

// Function to modify a book
void modifierLivre(livre livres[], int *numberLivres) {
    afficherLivres(livres, numberLivres);
    if (*numberLivres > 0) {
        char searchTitre[50];
        printf("\nEntrer le titre du livre que vous voulez modifier: ");
        scanf(" %[^\n]", searchTitre);

        for (int i = 0; i < *numberLivres; i++) {

            if (strEqual(livres[i].titre, searchTitre)) {
                printf("\nLivre trouve : \n");
                printf("Titre: %s\n", livres[i].titre);
                printf("Auteur: %s\n", livres[i].auteur);
                printf("Prix: %.2f\n", livres[i].prix);
                printf("Quantite: %d\n", livres[i].quantiter);

                int chosenStep;
                printf("\n********** Sous-menu **********\n");
                printf("1. Modifier le titre\n");
                printf("2. Modifier l'auteur\n");
                printf("3. Modifier le prix\n");
                printf("4. Modifier la quantite\n");
                printf("5. Modifier tous\n");
                printf("=> ");
                scanf("%d", &chosenStep);

                switch (chosenStep) {
                case 1:
                    printf("Entrez le nouveau titre: ");
                    scanf(" %[^\n]", livres[i].titre);
                    break;
                case 2:
                    printf("Entrez le nouvel auteur: ");
                    scanf(" %[^\n]", livres[i].auteur);
                    break;
                case 3:
                    printf("Entrez le nouveau prix: ");
                    scanf("%f", &livres[i].prix);
                    break;
                case 4:
                    printf("Entrez la nouvelle quantite: ");
                    scanf("%d", &livres[i].quantiter);
                    break;
                case 5:
                    printf("Entrez le nouveau titre: ");
                    scanf(" %[^\n]", livres[i].titre);
                    printf("Entrez le nouvel auteur: ");
                    scanf(" %[^\n]", livres[i].auteur);
                    printf("Entrez le nouveau prix: ");
                    scanf("%f", &livres[i].prix);
                    printf("Entrez la nouvelle quantite: ");
                    scanf("%d", &livres[i].quantiter);
                    break;
                default:
                    printf("Option non valide.\n");
                    break;
                }

                printf("\nLe livre a ete modifie avec succes!\n");
                return;
            }
        }
        printf("\nAucun livre correspondant trouve.\n");
    }
}

// Function to search for a book
void rechercherLivre(livre livres[], int *numberLivres) {

    afficherLivres(livres, numberLivres);

    if (*numberLivres > 0) {
        char searchTitre[50];
        printf("\nEntrer le titre du livre que vous voulez rechercher: ");
        scanf(" %[^\n]", searchTitre);

        for (int i = 0; i < *numberLivres; i++) {
            if (strEqual(livres[i].titre, searchTitre)) {
                printf("\nLivre trouve: \n");
                printf("Titre: %s\n", livres[i].titre);
                printf("Auteur: %s\n", livres[i].auteur);
                printf("Prix: %.2f\n", livres[i].prix);
                printf("Quantite: %d\n", livres[i].quantiter);
                return;
            }
        }
        printf("\nAucun livre correspondant trouve.\n");
    } else {
        printf("\nAucun livre disponible.\n");
    }
}

// Function to delete a book
void supprimerLivre(livre livres[], int *numberLivres) {
    if (*numberLivres > 0) {
        char searchTitre[50];
        printf("\nEntrer le titre du livre que vous voulez supprimer: ");
        scanf(" %[^\n]", searchTitre);

        for (int i = 0; i < *numberLivres; i++) {
            if (strEqual(livres[i].titre, searchTitre)) {
                printf("\nLivre trouve: \n");
                printf("Titre: %s\n", livres[i].titre);
                printf("Auteur: %s\n", livres[i].auteur);
                printf("Prix: %.2f\n", livres[i].prix);
                printf("Quantite: %d\n", livres[i].quantiter);

                char confirm;
                printf("\nÊtes-vous sûr de vouloir supprimer ce livre (y/n) ? ");
                scanf(" %c", &confirm);

                if (tolower(confirm) == 'y') {
                    for (int j = i; j < (*numberLivres) - 1; j++) {
                        livres[j] = livres[j + 1];
                    }
                    (*numberLivres)--;
                    printf("\nLe livre a ete supprime avec succes!\n");
                } else {
                    printf("\nSuppression annulee.\n");
                }
                return;
            }
        }
        printf("\nAucun livre correspondant trouve.\n");
    } else {
        printf("\nAucun livre disponible.\n");
    }
}

// Function to swap two books
void swapLivres(livre *a, livre *b) {
    livre temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort
void trierLivres(livre livres[], int numberLivres) {
    int choice, ascending;

    printf("\nTrier par:\n");
    printf("1. Titre\n");
    printf("2. Auteur\n");
    printf("3. Prix\n");
    printf("4. Quantite\n");
    printf("=> ");
    scanf("%d", &choice);

    printf("\nOrdre:\n1. Croissant\n2. Decroissant\n=> ");
    scanf("%d", &ascending);

    for (int i = 0; i < numberLivres - 1; i++) {
        for (int j = i + 1; j < numberLivres; j++) {
            int shouldSwap = 0;

            switch (choice) {
                case 1: // Titre
                    shouldSwap = (ascending == 1) ? strcmp(livres[i].titre, livres[j].titre) > 0 : strcmp(livres[i].titre, livres[j].titre) < 0;
                    break;
                case 2: // Auteur
                    shouldSwap = (ascending == 1) ? strcmp(livres[i].auteur, livres[j].auteur) > 0 : strcmp(livres[i].auteur, livres[j].auteur) < 0;
                    break;
                case 3: // Prix
                    shouldSwap = (ascending == 1) ? livres[i].prix > livres[j].prix : livres[i].prix < livres[j].prix;
                    break;
                case 4: // Quantite
                    shouldSwap = (ascending == 1) ? livres[i].quantiter > livres[j].quantiter : livres[i].quantiter < livres[j].quantiter;
                    break;
                default:
                    printf("Choix invalide.\n");
                    return;
            }

            if (shouldSwap) {
                swapLivres(&livres[i], &livres[j]);
            }
        }
    }

    printf("\nLes livres ont été triés avec succès!\n");
}


// Function to display statistics
void afficherStatistiques(livre livres[], int numberLivres) {
    int totalQuantite = 0;
    float totalPrix = 0;

    for (int i = 0; i < numberLivres; i++) {
        totalQuantite += livres[i].quantiter;
        totalPrix += livres[i].prix;
    }

    printf("\n********** Statistiques **********\n");
    printf("Nombre total de livres: %d\n", numberLivres);
    printf("Quantite totale de tous les livres: %d\n", totalQuantite);
    if (numberLivres > 0) {
        printf("Prix moyen des livres: %.2f\n", totalPrix / numberLivres);
    } else {
        printf("Aucun livre disponible\n");
    }
    printf("**********************************\n");
}

int main() {
    livre livres[100];
    int numberLivres = 0;
    int step;

    while (1) {
        menu();
        printf("\nQuel etape voulez-vous choisir ? : ");
        scanf("%d", &step);

        switch (step) {
        case 1:
            ajouterLivre(livres, &numberLivres);
            break;
        case 2:
            modifierLivre(livres, &numberLivres);
            break;
        case 3:
            supprimerLivre(livres, &numberLivres);
            break;
        case 4:
            rechercherLivre(livres, &numberLivres);
            break;
        case 6:
            afficherStatistiques(livres, numberLivres);
            break;
        case 0:
            printf("\nAu revoir!\n");
            exit(0);
        default:
            printf("\nOption non valide. Veuillez reessayer.\n");
        }
    }

    return 0;
}

