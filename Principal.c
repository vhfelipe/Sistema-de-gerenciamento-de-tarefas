#include <stido.h>
#include <stlib.h>
#include <string.h>

#define MAX_TAREFAS 100


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
