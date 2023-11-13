#include "shell.h"

/**
 * add_sepa_to_end - adds a separator found at the end
 * of a sepa_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
sepa_list *add_sepa_to_end(sepa_list **head, char sep)
{
	sepa_list *new, *temp;

	new = malloc(sizeof(sepa_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sepa_list - frees a sepa_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sepa_list(sepa_list **head)
{
	sepa_list *temp;
	sepa_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_to_end - adds a command line at the end
 * of a line_list_s.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list_s *add_line_to_end(line_list_s **head, char *line)
{
	line_list_s *new, *temp;

	new = malloc(sizeof(line_list_s));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list_s - frees a line_list_s
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list_s(line_list_s **head)
{
	line_list_s *temp;
	line_list_s *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
