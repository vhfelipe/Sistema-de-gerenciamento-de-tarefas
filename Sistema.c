#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAREFAS 100
#define MAX_CAMPOS 4
#define TAM_CAMPO 50

// Declaração de todas as funções antes da main
void exibirMenu() {
    printf("\n=== Sistema de Gerenciamento de Tarefas ===\n");
    printf("1. Cadastrar Tarefa\n");
    printf("2. Listar Tarefas\n");
    printf("3. Editar Tarefa\n");
    printf("4. Excluir Tarefa\n");
    printf("5. Salvar Tarefas em Arquivo\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

void cadastrarTarefa(char tarefas[][MAX_CAMPOS][TAM_CAMPO], int *quantidade) {
    if (*quantidade >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido!\n");
        return;
    }
    
    printf("\n--- Cadastro de Tarefa ---\n");
    
    printf("Título: ");
    fgets(tarefas[*quantidade][0], TAM_CAMPO, stdin);
    tarefas[*quantidade][0][strcspn(tarefas[*quantidade][0], "\n")] = '\0';
    
    printf("Descrição: ");
    fgets(tarefas[*quantidade][1], TAM_CAMPO, stdin);
    tarefas[*quantidade][1][strcspn(tarefas[*quantidade][1], "\n")] = '\0';
    
    printf("Prioridade (Alta/Média/Baixa): ");
    fgets(tarefas[*quantidade][2], TAM_CAMPO, stdin);
    tarefas[*quantidade][2][strcspn(tarefas[*quantidade][2], "\n")] = '\0';
    
    printf("Status (Pendente/Em andamento/Concluído): ");
    fgets(tarefas[*quantidade][3], TAM_CAMPO, stdin);
    tarefas[*quantidade][3][strcspn(tarefas[*quantidade][3], "\n")] = '\0';
    
    (*quantidade)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas(char tarefas[][MAX_CAMPOS][TAM_CAMPO], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    
    printf("\n--- Lista de Tarefas ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nTarefa %d:\n", i+1);
        printf("Título: %s\n", tarefas[i][0]);
        printf("Descrição: %s\n", tarefas[i][1]);
        printf("Prioridade: %s\n", tarefas[i][2]);
        printf("Status: %s\n", tarefas[i][3]);
    }
}

void editarTarefa(char tarefas[][MAX_CAMPOS][TAM_CAMPO], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma tarefa cadastrada para editar.\n");
        return;
    }
    
    listarTarefas(tarefas, quantidade);
    
    int indice;
    printf("\nDigite o número da tarefa que deseja editar: ");
    scanf("%d", &indice);
    getchar(); // Limpar buffer
    
    if (indice < 1 || indice > quantidade) {
        printf("Índice inválido!\n");
        return;
    }
    
    indice--; // Ajustar para índice do array
    
    printf("\nEditando Tarefa %d:\n", indice+1);
    
    printf("Novo Título (%s): ", tarefas[indice][0]);
    fgets(tarefas[indice][0], TAM_CAMPO, stdin);
    tarefas[indice][0][strcspn(tarefas[indice][0], "\n")] = '\0';
    
    printf("Nova Descrição (%s): ", tarefas[indice][1]);
    fgets(tarefas[indice][1], TAM_CAMPO, stdin);
    tarefas[indice][1][strcspn(tarefas[indice][1], "\n")] = '\0';
    
    printf("Nova Prioridade (%s): ", tarefas[indice][2]);
    fgets(tarefas[indice][2], TAM_CAMPO, stdin);
    tarefas[indice][2][strcspn(tarefas[indice][2], "\n")] = '\0';
    
    printf("Novo Status (%s): ", tarefas[indice][3]);
    fgets(tarefas[indice][3], TAM_CAMPO, stdin);
    tarefas[indice][3][strcspn(tarefas[indice][3], "\n")] = '\0';
    
    printf("Tarefa editada com sucesso!\n");
}

void excluirTarefa(char tarefas[][MAX_CAMPOS][TAM_CAMPO], int *quantidade) {
    if (*quantidade == 0) {
        printf("Nenhuma tarefa cadastrada para excluir.\n");
        return;
    }
    
    listarTarefas(tarefas, *quantidade);
    
    int indice;
    printf("\nDigite o número da tarefa que deseja excluir: ");
    scanf("%d", &indice);
    getchar(); // Limpar buffer
    
    if (indice < 1 || indice > *quantidade) {
        printf("Índice inválido!\n");
        return;
    }
    
    indice--; // Ajustar para índice do array
    
    // Deslocar as tarefas posteriores para preencher o espaço
    for (int i = indice; i < *quantidade - 1; i++) {
        for (int j = 0; j < MAX_CAMPOS; j++) {
            strcpy(tarefas[i][j], tarefas[i+1][j]);
        }
    }
    
    (*quantidade)--;
    printf("Tarefa excluída com sucesso!\n");
}

void salvarTarefasEmArquivo(char tarefas[][MAX_CAMPOS][TAM_CAMPO], int quantidade) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Tarefa %d: %s - Descrição: %s - Prioridade: %s - Status: %s\n",
                i+1, tarefas[i][0], tarefas[i][1], tarefas[i][2], tarefas[i][3]);
    }
    
    fclose(arquivo);
    printf("Tarefas salvas no arquivo 'tarefas.txt' com sucesso!\n");
}

// Função principal
int main() {
    char tarefas[MAX_TAREFAS][MAX_CAMPOS][TAM_CAMPO] = {0};
    int quantidade = 0;
    int opcao;
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado
        
        switch(opcao) {
            case 1:
                cadastrarTarefa(tarefas, &quantidade);
                break;
            case 2:
                listarTarefas(tarefas, quantidade);
                break;
            case 3:
                editarTarefa(tarefas, quantidade);
                break;
            case 4:
                excluirTarefa(tarefas, &quantidade);
                break;
            case 5:
                salvarTarefasEmArquivo(tarefas, quantidade);
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 6);
    
    return 0;
}
