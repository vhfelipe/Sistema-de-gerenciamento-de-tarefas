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
