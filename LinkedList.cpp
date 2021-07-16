#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
};

typedef struct deque {
	node* head;
	node* tail;
};

void print_deque(deque* d) {
	node* p = d->head;
	printf("[");
	while (p != NULL) {
		if (p->next == NULL) {
			printf("%d", p->data);
			break;
		}
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("]\n");
}

void insert_at_head(deque* d, int x) {
	node* n = (node*)malloc(sizeof(node));
	n->data = x;
	n->next = NULL;

	if (d->head == NULL) {
		d->head = n;
		d->tail = n;
	}
	else {
		n->next = d->head;
		d->head = n;
	}
}

void insert_at_tail(deque* d, int x) {
	node* n = (node*)malloc(sizeof(node));
	n->data = x;
	n->next = NULL;

	if (d->head == NULL) {
		d->head = n;
		d->tail = n;
	}
	else {
		d->tail->next = n;
		d->tail = n;
	}
}

void delete_at_head(deque* d) {
	if (d->head == NULL) {
		printf("Cannot delete from an empty list.\n");
	}
	else if (d->head->next == NULL) {
		free(d->head);
		d->head = NULL;
		d->tail = NULL;
	}
	else {
		node* p = d->head;
		d->head = d->head->next;
		free(p);
	}
}

void delete_at_tail(deque* d) {
	if (d->head == NULL) {
		printf("Cannot delete from an empty list.\n");
	}
	else if (d->head->next == NULL) {
		free(d->head);
		d->head = NULL;
		d->tail = NULL;
	}
	else {
		node* p = d->head;
		while (p->next != d->tail) {
			p = p->next;
		}
		p->next = NULL;
		free(d->tail);
		d->tail = p;
	}
}

int deque_sum(deque* d) {
	int sum = 0;
	node* p = d->head;
	while (p != NULL) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

void delete_second_element(deque* d) {
	if (d->head == NULL || d->head->next == NULL) {
		printf("The list is either empty or has only one element.\n");
	}
	else if (d->head->next->next == NULL) {
		node* p = d->head->next;
		d->head->next = p->next;
		d->tail = d->head;
		free(p);
	}
	else {
		node* p = d->head->next;
		d->head->next = p->next;
		free(p);
	}
}

int main() {
	deque* d = (deque*)malloc(sizeof(deque));
	d->head = NULL;
	d->tail = NULL;

	printf("Options:\n");
	printf("1) Insert at head.\n");
	printf("2) Insert at tail.\n");
	printf("3) Delete at head.\n");
	printf("4) Delete at tail.\n");
	printf("5) Print sum of deque.\n");
	printf("6) Delete second element.\n");
	printf("0) Exit.\n");

	while (true) {
		printf("Choose an option: ");
		int choice, x;
		scanf("%d", &choice);

		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			printf("Enter a number to insert at head: ");
			scanf("%d", &x);
			insert_at_head(d, x);
			print_deque(d);
		}
		else if (choice == 2) {
			printf("Enter a number to insert at tail: ");
			scanf("%d", &x);
			insert_at_tail(d, x);
			print_deque(d);
		}
		else if (choice == 3) {
			delete_at_head(d);
			print_deque(d);
		}
		else if (choice == 4) {
			delete_at_tail(d);
			print_deque(d);
		}
		else if (choice == 5) {
			int sum = deque_sum(d);
			printf("Sum of the list is: %d\n", sum);
			print_deque(d);
		}
		else if (choice == 6) {
			delete_second_element(d);
			print_deque(d);
		}
		else {
			printf("Invalid input, please try again.\n");
		}
	}

}
