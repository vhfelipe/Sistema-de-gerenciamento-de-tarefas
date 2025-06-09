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
