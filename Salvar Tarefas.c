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
