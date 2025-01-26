#include <iostream>
using namespace std;


class Node
{
    public:
    int index_of_row;
    int index_of_column;
    int number;
    Node *next;
};

void new_Node(Node **n, int index_of_row,int index_of_column, int number){
	Node *temp = *n;
    Node *r;
    if (temp == NULL)
    {
        temp = new Node();
        temp->index_of_row = index_of_row;
        temp->index_of_column = index_of_column;
        temp->number = number;
        temp->next = NULL;
        *n = temp;
    }
    
     else
    {
        while (temp->next != NULL)   
            temp = temp->next;
             
        r = new Node();
        r->index_of_row = index_of_row;
        r->index_of_column = index_of_column;
        r->number = number;
        r->next = NULL;
        temp->next = r;
    }
}
 
 
void printOutput(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->index_of_row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->index_of_column << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = start;
     
    while (ptr != NULL)
    {
        cout << ptr->number << " ";
        ptr = ptr->next;
    }
}   
    

int main()
{
    int i = 0;
    int input_matrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        };
Node *starting = NULL;
	while(i<4){
		int j=0;
		while(j<5){
			if (input_matrix[i][j] != 0)
                new_Node(&starting, i, j,input_matrix[i][j]);
            j++;
		}
		i++;
	}
	
    printOutput(starting);
 
    return 0;
}