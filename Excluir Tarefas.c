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
