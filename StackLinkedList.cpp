#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
};

typedef struct Deque {
	node* head;
	node* tos;
};

typedef struct Stack {
	Deque* d;
};

Stack* init() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	Deque* d = (Deque*)malloc(sizeof(Deque));
	d->head = NULL;
	d->tos = NULL;
	s->d = d;
	return s;
}

void push(Stack* s, int x) {
	node* n = (node*)malloc(sizeof(node));
	n->data = x;
	n->next = NULL;

	if (s->d->head == NULL) {
		s->d->head = n;
		s->d->tos = n;
	}
	else {
		s->d->tos->next = n;
		s->d->tos = n;
	}
}

int pop(Stack* s) {
	if (s->d->head == NULL) {
		printf("Cannot pop from an empty stack.\n");
		return INT_MIN;
	}
	else if (s->d->head->next == NULL) {
		int x = s->d->head->data;
		free(s->d->head);
		s->d->head = NULL;
		s->d->tos = NULL;
		return x;
	}
	else {
		int x = s->d->tos->data;
		node* p = s->d->head;
		while (p->next != s->d->tos) {
			p = p->next;
		}
		free(s->d->tos);
		s->d->tos = p;
		s->d->tos->next = NULL;
		return x;
	}
}

void print_stack(Stack* s) {
	Stack* reverse = init();

	while (s->d->head != NULL) {
		push(reverse, pop(s));
	}

	printf("[");
	while (reverse->d->head != NULL) {
		if (reverse->d->head->next == NULL) {
			int x = pop(reverse);
			printf("%d", x);
			push(s, x);
			break;
		}
		int x = pop(reverse);
		printf("%d, ", x);
		push(s, x);
	}
	printf("]\n");
}

void print_reverse(Stack* s) {
	Stack* reverse = init();

	printf("[");
	while (s->d->head != NULL) {
		if (s->d->head->next == NULL) {
			int x = pop(s);
			printf("%d", x);
			push(reverse, x);
			break;
		}
		int x = pop(s);
		printf("%d, ", x);
		push(reverse, x);
	}
	printf("]\n");

	while (reverse->d->head != NULL) {
		push(s, pop(reverse));
	}
}

int main() {
	Stack* s = init();

	printf("Options:\n");
	printf("1) Push into stack.\n");
	printf("2) Pop from stack.\n");
	printf("3) Print reversed stack.\n");
	printf("0) Exit.\n");

	while (true) {
		printf("Choose an option: ");
		int choice, x;
		scanf("%d", &choice);

		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			printf("Enter an element to push in the stack: ");
			scanf("%d", &x);
			push(s, x);
			print_stack(s);
		}
		else if (choice == 2) {
			x = pop(s);
			if (x != INT_MIN) {
				printf("Popped element is: %d\n", x);
			}
			print_stack(s);
		}
		else if (choice == 3) {
			printf("Reversed Stack: ");
			print_reverse(s);
			printf("Original Stack: ");
			print_stack(s);
		}
		else {
			printf("Invalid choice, please try again.\n");
		}
	}
}