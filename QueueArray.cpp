#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int* arr;
	int size;
	int front;
	int rear;
};

Queue* init(int size) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->arr = (int*)malloc(sizeof(int) * size);
	q->size = size;
	q->front = 0;
	q->rear = 0;
	return q;
}

void enqueue(Queue* q, int x) {
	if (q->rear == q->size) {
		printf("Cannot enqueue in a full queue.\n");
	}
	else {
		q->arr[q->rear] = x;
		q->rear += 1;
	}
}

int dequeue(Queue* q) {
	if (q->rear == q->front) {
		printf("Cannot dequeue from an empty queue.\n");
		return INT_MIN;
	}
	else {
		int x = q->arr[q->front];
		q->front += 1;
		if (q->front == q->rear) {
			q->front = 0;
			q->rear = 0;
		}
		return x;
	}
}

void print_queue(Queue* q) {
	printf("[");
	for (int i = 0; i < q->front; i++) {
		printf(" ,");
	}
	for (int i = q->front; i < q->rear; i++) {
		if (i == q->rear - 1) {
			printf("%d", q->arr[i]);
			break;
		}
		printf("%d, ", q->arr[i]);
	}
	printf("]\n");
}

int main() {
	printf("Enter size of the queue: ");
	int size;
	scanf("%d", &size);
	Queue* q = init(size);

	printf("Options:\n");
	printf("1) Enqueue in the queue.\n");
	printf("2) Dequeue from the queue.\n");
	printf("0) Exit.\n");

	while (true) {
		printf("Choose an option: ");
		int choice, x;
		scanf("%d", &choice);

		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			printf("Enter an element to enqueu in the queue: ");
			scanf("%d", &x);
			enqueue(q, x);
			print_queue(q);
		}
		else if (choice == 2) {
			x = dequeue(q);
			if (x != INT_MIN) {
				printf("Deleted element is: %d\n", x);
			}
			print_queue(q);
		}
		else {
			printf("Invalid input, please try again.\n");
		}
	}
}