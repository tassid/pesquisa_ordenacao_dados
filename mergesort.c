#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subvetores ordenados em um único vetor ordenado
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria subvetores temporários
    int L[n1], R[n2];

    // Copia dados para os subvetores L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mescla os subvetores temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função de ordenação MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontra o ponto médio do vetor
        int m = l + (r - l) / 2;

        // Ordena a primeira metade
        mergeSort(arr, l, m);

        // Ordena a segunda metade
        mergeSort(arr, m + 1, r);

        // Mescla as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, n - 1); // Chama a função MergeSort para ordenar o vetor

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
