/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	//std::cout << "node added" << std::endl;
	//std::cout << "node added: " << (*((std::string*)(item))) << std::endl;
	//std::cout << "node added: " << (*(char*)(item)) <<  std::endl;
	node* tmp = new node; // Create a node
	tmp->data = item;
	tmp->priority = priority;
	tmp->link = NULL;
	int n = 0;
	if (front == NULL)
	{
		front = tmp;
	}
	else if (priority < front->priority)
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		node* current = front;
		while (current->link!=NULL && current->link->priority <= priority)
		{
			current = current->link;
			n++;
		}
		// at this point we will either be at our priority position
		// or end of list
		//std::cout << n << std::endl;
		tmp->link = current->link;
		current->link = tmp;
	}
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	/* Your code here */
	if(front == NULL)
	{
		return NULL;
	}
	else
	{
		/*node* tmp = front;
		front = front->link;
		return tmp->data;*/
		return front->data;
	}
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	/* Your code here */
	if(front == NULL)
	{
		return;
	}
	else
	{
		front = front->link;
	}
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
	//std::cout << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << std::endl;
	node* current = front;
	while(current != NULL)
	{
		std::cout<<current->priority<<" "<<(char*)current->data<<std::endl;
		current = current->link;
	}
}
	