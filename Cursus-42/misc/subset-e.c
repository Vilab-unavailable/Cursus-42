#include <stdio.h>

/*
    Affiche un sous-ensemble
*/
void printSubset(char* subset, int size) {
    printf("{");

    for (int i = 0; i < size; i++) {
        printf("%c", subset[i]);
        if (i < size - 1)
            printf(" ");
    }

    printf("}\n");
}

/*
    Fonction récursive pour générer et afficher les subsets
*/
void generateSubsets(char* arr, int n, int start,
                     char* temp, int tempSize) {
    int i;

    
    // 1️⃣ Afficher le sous-ensemble courant
    printSubset(temp, tempSize);

    // 2️⃣ Ajouter les éléments suivants un par un
    i = start;
    while (i < n)
    {
    
        // Ajouter arr[i] au subset courant
        temp[tempSize] = arr[i];

        // Appel récursif avec l'élément ajouté
        generateSubsets(arr, n, i + 1,
                        temp, tempSize + 1);
        i++;
    }
}

int main(void) {
    char arr[] = {'a', 'b', 'c'};
    int n = 3;

    // Tableau temporaire pour construire les subsets
    char temp[3];

    generateSubsets(arr, n, 0, temp, 0);

    return 0;
}
