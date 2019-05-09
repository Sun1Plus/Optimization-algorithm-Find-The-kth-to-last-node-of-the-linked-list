#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
}Node;

Node* find_kth_end(Node* head, int k)
{
	Node* probe = head;		//The front pointer, called probe pointer.
	Node* fixed = head;		//The middle pointer, called fixed pointer.
	Node* answer = head;	//The behind pointer, finally it will be the answer pointer.

	//This step assure the list is longer than k.
	for (int i = 0; i < k; i++)
	{
		//If the list is shorter than k, return the NULL.
		if (probe == NULL)
			return NULL;	
		probe = probe->next;
	}

	//Fixed pointer move to probe pointer.
	fixed = probe;

	while (1)
	{
		//The three pointers is k nodes' space each other. Then move forward iteratively.
		for (int i = 0; i < k; i++)
		{
			probe = probe->next;
			//If probe pointer arrives the end.
			if (probe == NULL)
			{
				//Now, the i's value is the offset, we need answer pointer to move the answer location.
				for (int j = 0; j <= i; j++)
				{
					answer = answer->next;
				}
				return answer;
			}
		}
		//The two pointers move forward, then it's a sub-question, we can solve it iteratively.
		answer = fixed;
		fixed = probe;
	}
	return NULL;
}

Node* create_list(int n)
{
	Node* head = NULL;
	Node* current, *future;
	int value = 0;
	head = (Node*)malloc(sizeof(Node));
	head->value = value++;
	current = head;

	for (int i = 0; i < n-1; i++)
	{
		future = (Node*)malloc(sizeof(Node));
		future->value = value++;
		current->next = future;
		current = future;
	}

	current->next = NULL;
	return head;
}

int main()
{
	int n = 30;		//It's for testing, n is the length of list.
	Node* head, *result;
	head = create_list(30);
	result = find_kth_end(head, 7);
	printf("%d", result->value);
	return 0;
}