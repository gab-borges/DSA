#include "linked_list.h"

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

List* removek (List *l, int val);
List* search (List *l, int k);
