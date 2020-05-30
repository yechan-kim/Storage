#include <stdio.h>
#include <stdlib.h>
#define ERR -99999

// making stack using linked list

typedef struct Node
{
	int key;
	struct Node *next;
} ND;

// function that creates new node
// returns pointer of new node
ND *createNewNode(int value)
{
	ND *temp = (ND *)malloc(sizeof(ND));
	if (!temp)
	{ // defensive coding
		return NULL;
	}
	temp->key = value;
	return temp; // node return
}

// insert new node to linked list
// return 0 if successfully inserted, else return 1
int insert(ND **head, int value)
{
	ND *temp = createNewNode(value);
	if (!temp) // can't create new node
		return 1;
	ND *cur = *head,
	   *pre = NULL;
	if (!*head)
	{ // no node in linked list
		*head = temp;
		return 0;
	}
	while (cur) // find tail of linked list
		pre = cur, cur = cur->next;
	pre->next = temp; // link new node to the tail of linked list
	return 0;
}

int delete (ND **head)
{
	if (!(*head))
	{ // no node in linked list
		printf("No node!");
		return ERR;
	}
	else if (!(*head)->next)
	{ // only 1 node in linked list
		ND *temp = *head;
		*head = NULL; // no node in linked list
		int retval = temp->key;
		free(temp);	   // delete node
		return retval; // return node's key value
	}
	ND *pre = NULL,
	   *cur = *head;
	while (cur->next) // find tail of linked list
		pre = cur, cur = cur->next;
	ND *temp = cur;	  // tail of linked list
	pre->next = NULL; // cut link
	int retval = temp->key;
	free(temp); // delete node
	return retval;
}

int main()
{
	ND *head = NULL; // head of linked list
	/*
	using some code
	*/
	return 0;
}