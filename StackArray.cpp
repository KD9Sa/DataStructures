#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int* arr;
	int tos;
	int size;
};

Stack* init(int size) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = size;
	s->tos = 0;
	s->arr = (int*)malloc(sizeof(int) * size);
	return s;
}

void push(Stack* s, int x) {
	if (s->tos == s->size) {
		printf("Cannot push into a full stack.\n");
	}
	else {
		s->arr[s->tos] = x;
		s->tos += 1;
	}
}

int pop(Stack* s) {
	if (s->tos == 0) {
		printf("Cannot pop from an empty stack.\n");
		return INT_MIN;
	}
	else {
		int x = s->arr[s->tos - 1];
		s->tos -= 1;
		return x;
	}
}

void print_stack(Stack* s) {
	Stack* reverse = init(s->tos);

	while (s->tos != 0) {
		push(reverse, pop(s));
	}

	printf("[");
	while (reverse->tos != 0) {
		if (reverse->tos - 1 == 0) {
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
	Stack* reverse = init(s->tos);

	printf("[");
	while (s->tos != 0) {
		if (s->tos - 1 == 0) {
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

	while (reverse->tos != 0) {
		push(s, pop(reverse));
	}
}

int main() {
	printf("Enter size of the stack: ");
	int size;
	scanf("%d", &size);
	Stack* s = init(size);

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