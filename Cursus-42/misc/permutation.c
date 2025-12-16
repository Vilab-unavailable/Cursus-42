#include <stdlib.h>
#include <stdbool.h>

/*
 * Fonction récursive de backtracking
 */
void backtrack(
    int* nums,
    int numsSize,
    int* current,          // permutation en cours
    bool* used,             // éléments déjà utilisés
    int depth,              // profondeur actuelle
    int** result,           // tableau de résultats
    int* returnSize         // nombre total de permutations
) {
    // Cas de base : permutation complète
    if (depth == numsSize) {
        // Allocation mémoire pour une nouvelle permutation
        result[*returnSize] = malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnSize)++;
        return;
    }

    // Essayer chaque nombre
    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            // Choisir nums[i]
            used[i] = true;
            current[depth] = nums[i];

            // Appel récursif
            backtrack(nums, numsSize, current, used, depth + 1, result, returnSize);

            // Annuler le choix (backtracking)
            used[i] = false;
        }
    }
}

/*
 * Fonction principale demandée par LeetCode
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Nombre maximal de permutations = n!
    int maxPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        maxPermutations *= i;
    }

    // Allocation du tableau de résultats
    int** result = malloc(maxPermutations * sizeof(int*));

    // Tableau temporaire pour construire une permutation
    int* current = malloc(numsSize * sizeof(int));

    // Tableau pour suivre les éléments utilisés
    bool* used = calloc(numsSize, sizeof(bool));

    *returnSize = 0;

    // Lancer le backtracking
    backtrack(nums, numsSize, current, used, 0, result, returnSize);

    // Chaque permutation a la même taille
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    // Libération mémoire temporaire
    free(current);
    free(used);

    return result;
}
