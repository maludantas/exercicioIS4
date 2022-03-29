#include <stdio.h>
#include <stdlib.h>

struct queueNode{
  int arrivalTime;
  int burstTime;
  
  struct queueNode *next;
};

int isEmpty(struct queueNode *head){
  return head == NULL;
}

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

void dequeue(struct queueNode **head, struct queueNode **tail){
  struct queueNode *temp;

  temp = *head;
  *head = (*head)->next;

  if (*head == NULL){
    tail = NULL;
  }

  free(temp);
}

int main(void) {
  struct queueNode *head = NULL;
  struct queueNode *tail = NULL;
  struct queueNode *aux = head;

  aux = (struct queueNode*)malloc(sizeof(struct queueNode));

  int process_quant, process_quant1, quantum;
  int arrivalTime = 0, burstTime = 0, waitTime = 0, responseTime = 0, executionTime = 0;
  int i = 0, total = 0, count = 0;

  float waitTimeAverage = 0, responseTimeAverage = 0, executionTimeAverage= 0;

  scanf("%d %d", &process_quant, &quantum);

  while (i<process_quant){
    scanf("%d %d", &arrivalTime, &burstTime);
    enqueue(&head, &tail, arrivalTime, burstTime);
    i++;
  }

  process_quant1 = process_quant;
  while (process_quant1!=0){
    if (aux->burstTime <= quantum && aux->burstTime > 0){
      total = total+aux->burstTime;
      aux->burstTime = 0;
      count = 1;
    }

    else if (aux->burstTime > 0){
      aux->burstTime = aux->burstTime-quantum;
      total += quantum;
    }

    if (aux->burstTime == 0 && count == 1){
      waitTime += total - aux->arrivalTime - aux->arrivalTime;
      executionTime += total;
      responseTime += total - aux->arrivalTime;
      process_quant1--;
      count = 0;
    }

    if (aux->next == NULL){
      aux = head;
    }

    else if (head->next->arrivalTime <= total){
      aux = aux->next;
    }

    else{
      aux = head;
    }
  }

  waitTimeAverage = waitTime*1.0/process_quant;
  responseTimeAverage = responseTime*1.0/process_quant;
  executionTimeAverage = executionTime*1.0/process_quant;

  printf("\nRR %.1f %.1f %.1f", executionTimeAverage, responseTimeAverage, waitTimeAverage);
  
  return 0;
}