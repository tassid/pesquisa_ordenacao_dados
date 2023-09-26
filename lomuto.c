#include <stdio.h>

// Função para trocar dois elementos de posição no vetor
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que escolhe o último elemento como pivô e rearranja os elementos menores à esquerda e maiores à direita
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhendo o último elemento como pivô
    int i = low - 1; // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função de ordenação QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Encontra o pivô
        quickSort(arr, low, pi - 1); // Ordena os elementos antes do pivô
        quickSort(arr, pi + 1, high); // Ordena os elementos após o pivô
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

    quickSort(vetor, 0, n - 1); // Chama a função QuickSort para ordenar o vetor

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
