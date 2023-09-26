#include <stdio.h>

void swap(int *a, int *b) {
    // Função para trocar dois elementos de posição
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    // Divide o vetor em duas partes em relação a um pivô
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    
    // Move elementos menores para a esquerda e maiores para a direita do pivô
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    // Ordena um vetor usando o algoritmo QuickSort
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
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

    quickSort(vetor, 0, n - 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
