# exercicioIS4

## código

> Inputs: 
-quantidade de processos
-quantum usado
-momento de chegada do processo
-quantidade de tempo que leva pra ser processado

> funções:
- isEmpty (retorna 1 se head == NULL e 0 se head != NULL)

  int isEmpty(struct queueNode *head){
    return head == NULL;
  }
  
- enqueue (adiciona elementos na fila)

  void enqueue(struct queueNode **head, struct queueNode **tail, int arrivalTime, int burstTime){
  struct queueNode *new_process = (struct queueNode*)malloc(sizeof(struct queueNode));

    if (new_process != NULL){
      new_process->arrivalTime = arrivalTime;
      new_process->burstTime = burstTime;
      new_process->next = NULL;

      if (isEmpty(*head)){
        *head = new_process;
        *tail = new_process;
      }

      else{
        (*tail)->next = new_process;
        *tail = new_process;
      }
    }
  }

## makefile

> funções:
-compilar
-gerar o binário
-apagar o binário
