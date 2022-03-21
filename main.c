#include <stdio.h>
#include <stdbool.h>

struct Node {
    
    int value;
    struct Node* next;
     
    }; 
    
struct Node * head = NULL; 
    
void addNode (int val)
    {
        
        struct Node* temp = (struct Node*)malloc(sizeof (struct Node) );
        temp->value = val;
        temp->next = head;
        head = temp;
        
    }
    

void delNode (int pos)
{
    struct Node * temp = head;
    
    if (pos == 1)
    {
        head = temp->next;
        
        free (temp);
        
        return;
        }
    
int k;

for (k = 1; k < pos - 1 ; k++)
    temp = temp->next;

struct Node * temp2 = temp->next;
temp->next = temp2->next;

free(temp2);
        
 return;
    
    }
    
    
bool searchNodes (int val)
{
    struct Node* temp = head;
    
    while ( temp->next != NULL )
    {
        temp = temp->next;
        
        if (temp->value == val)
            return true;
        }
        
    return false;
    }


void printNodes()

{
    
    struct Node * temp = head;
    
    printf ("printing list items: ");
    
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp -> next;
        }
        
        printf("\n");
    
    }
    
    

int main(int argc, char **argv)
{
	int v [] = {4, 2, 9, 8, 9, 5};
    int k;
    
    for ( k = 0; k < sizeof(v)/sizeof (int); k++)
    {
        addNode(v[k]);
        }
        
     printNodes();   
     
    if ( searchNodes(2) )
        printf("Node found\n");
    else printf("Node not found\n");
    
    delNode(2);
    
    printNodes();
    
	return 0;
}
