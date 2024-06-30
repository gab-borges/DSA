#include "singly_linked_list.h"

/* */
List* create () {
	return NULL;
}

/* */
void print (List *l) {
	List *t;
	for (t = l; t != NULL; t = t->next)
		printf ("%d ", t->data);

	printf ("\n");
}

/* */
void destroy (List *l) {
	while (l != NULL) {
		List *t = l->next;
		free (l);
		l = t;
	}
}

/* */
List* insert_front (List *l, int val) {
	List *node = (List *) malloc (sizeof(List));
	node->data = val;
	node->next = l;

	return (node);
}

/* */
List* insert_back (List *l, int val) {
	List *node = (List *) malloc (sizeof(List));
	node->data = val;
	node->next = NULL;

	if (l == NULL)
		return node;

	List *t;
	for (t = l; t->next != NULL; t = t->next) {}
	t->next = node;
	
	return (l);
}

/* */
List* remove_value (List *l, int val) {
	if (l == NULL)
		return (NULL);

	if (l->data == val) {
		List *result = l->next;
		free (l);
		return (result);
	}

	List *t, *prev = l;
	for (t = l; t != NULL; prev = t, t = t->next)
		if (t->data == val) {
			prev->next = t->next;
			free (t);
		}
	
	return (l);
}

/* */
List* remove_k (List *l, int k) {
	if (l == NULL)
		return (NULL);
	
	if (k == 0) {
		List *result = l->next;
		
		free (l);
		
		return (result);
	}

	int cont = 0;
	List *prev = l;

	List *t;
	for (t = l; t != NULL; prev = t, t = t->next, cont++) {
		if (cont == k) {
			prev->next = t->next;
			free (t);
			break;
		}
	}

	return (l);
}

/* */
List* search (List *l, int val) {
	List *t;
	for (t = l; t != NULL; t = t->next)
		if (t->data == val)
			return (t);

	return (NULL);
}
