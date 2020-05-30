#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} ND;
typedef ND *NDPtr;

NDPtr createNewNode(int value);				  // create a Node
void insertToHead(NDPtr *head, NDPtr node);	  // insert node to First
void insertToMiddle(NDPtr *head, NDPtr node); // insert node to Middle
void insertToTail(NDPtr *head, NDPtr node);	  // insert node to Tail
void deleteFromHead(NDPtr *head);			  // delete node from head
void deleteFromMiddle(NDPtr *head);			  // delete node from middle
void deleteFromTail(NDPtr *head);			  // delete node from tail
NDPtr findTail(NDPtr head);					  // find Tail of List
NDPtr search(NDPtr head, int value);		  // search the value
void changeValue(NDPtr head);				  // change node's value to input
int isEmpty(NDPtr head);					  // 1 if Empty, 0 if not Empty
void printList(NDPtr head);					  // print All List
void instructions();						  // how to use this system
int getInput();								  // get input type int

int main() {
	NDPtr Head = NULL;
	int choose, end = 1, temp;
	while (end) {
		instructions();
		scanf("%d", &choose);
		switch (choose) {
			case 1:
				insertToHead(&Head, createNewNode(getInput()));
				break;
			case 2:
				insertToMiddle(&Head, createNewNode(getInput()));
				break;
			case 3:
				insertToTail(&Head, createNewNode(getInput()));
				break;
			case 4:
				deleteFromHead(&Head);
				break;
			case 5:
				deleteFromMiddle(&Head);
				break;
			case 6:
				deleteFromTail(&Head);
				break;
			case 7:
				temp = getInput();
				if (search(Head, temp))
					printf("%d found!\n", temp);
				else
					printf("%d not found!\n", temp);
				break;
			case 8:
				printList(Head);
				break;
			case 9:
				changeValue(Head);
				break;
			case 0:
				end = 0;
				break;
		}
	}
	printf("End of System");
	char str;
	scanf("\n%c", &str);
	return 0;
}

NDPtr createNewNode(int value) { // create a Node
	NDPtr temp = (NDPtr)malloc(sizeof(ND));
	if (temp) {
		temp->value = value;
		temp->next = NULL;
	}
	return temp;
}

void insertToHead(NDPtr *head, NDPtr node) { // change fisrt node to Node
	node->next = *head;
	*head = node;
	return;
}

void insertToMiddle(NDPtr *head, NDPtr node) {
	if (isEmpty(*head)) {
		printf("List is Empty!\n");
		free(node);
		return;
	}
	NDPtr temp = search(*head, getInput());
	if (!temp) {
		printf("Target Not Found!\n");
		free(node);
	}
	else {
		node->next = temp->next;
		temp->next = node;
	}
	return;
}

void insertToTail(NDPtr *head, NDPtr node) { // 맨 처음에 삽입이 안되는 문제가 있음
	if (isEmpty(*head))
		*head = node;
	else
		findTail(*head)->next = node;
	return;
}

void deleteFromHead(NDPtr *head) {
	if (isEmpty(*head)) {
		printf("List is Empty!\n");
		return;
	}
	NDPtr temp = *head;
	*head = temp->next;
	free(temp);
	return;
}

void deleteFromMiddle(NDPtr *head) {
	if (isEmpty(*head)) {
		printf("List is Empty!\n");
		return;
	}
	int a = getInput();
	if (search(*head, a)) {
		NDPtr temp = *head;
		if (temp->value == a) {
			deleteFromHead(head);
			return;
		}
		while (temp->next->value != a)
			temp = temp->next;
		NDPtr temp2 = temp->next;
		temp->next = temp2->next;
		free(temp2);
	}
	else
		printf("Target not Founded!\n");
	return;
}

void deleteFromTail(NDPtr *head) {
	if (isEmpty(*head)) {
		printf("List is Empty!\n");
		return;
	}
	NDPtr temp = *head;
	if (!temp->next) {
		free(temp);
		*head = NULL;
		return;
	}
	while (temp->next->next)
		temp = temp->next;
	NDPtr temp2 = temp->next;
	temp->next = NULL;
	free(temp2);
	return;
}

NDPtr findTail(NDPtr head) { // find Tail of list
	NDPtr temp = head;
	while (temp->next)
		temp = temp->next;
	return temp;
}

NDPtr search(NDPtr head, int value) { // find node with value in list
	NDPtr temp = head;
	while (temp && temp->value != value)
		temp = temp->next;
	return temp;
}

void changeValue(NDPtr head) {
	NDPtr temp = search(head, getInput());
	if (temp)
		temp->value = getInput();
	else
		printf("Can't find that value!\n");
	return;
}

int isEmpty(NDPtr head) { // 1 if Empty, 0 if not Empty
	if (head)
		return 0;
	else
		return 1;
}

void printList(NDPtr head) {
	NDPtr temp = head;
	if (isEmpty(head)) {
		printf("List is Empty!\n");
		return;
	}
	while (temp) {
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
	return;
}

void instructions() {
	printf("1 : 리스트 맨 앞에 삽입\n"
		"2 : 리스트 중간에 삽입\n"
		"3 : 리스트 맨 뒤에 삽입\n"
		"4 : 리스트 맨 앞 노드 삭제\n"
		"5 : 리스트 중간 노드 삭제\n"
		"6 : 리스트 맨 뒤 노드 삭제\n"
		"7 : 리스트 값 검색\n"
		"8 : 리스트 전체출력\n"
		"9 : 리스트 특정 값 수정\n"
		"0 : 종료\n"
		"Choose? ");
	return;
}

int getInput() {
	int temp;
	printf("Input a Data :: ");
	scanf("%d", &temp);
	return temp;
}