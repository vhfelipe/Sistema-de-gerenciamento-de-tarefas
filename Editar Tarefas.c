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
