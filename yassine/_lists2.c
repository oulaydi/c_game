#include "shell.h"

/**
 * var_to_node - adds a variable at the end
 * of a str_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
str_var *var_to_node(str_var **head, int lvar, char *val, int lval)
{
	str_var *new, *temp;

	new = malloc(sizeof(str_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
 * free_var_list - frees a str_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_var_list(str_var **head)
{
	str_var *temp;
	str_var *curr;

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
