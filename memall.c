#include <stdio.h>
#include <stdlib.h>
typedef struct Block 
{
    int size;
    int free;           
    int process_id;     
    struct Block* next;
} Block;
Block* createBlock(int size) 
{
    Block* newBlock = (Block*)malloc(sizeof(Block));
    newBlock->size = size;
    newBlock->free = 1;
    newBlock->process_id = -1;
    newBlock->next = NULL;
    return newBlock;
}
void printBlocks(Block* head) 
{
    printf("\nMemory Blocks:\n");
    printf("Block#\tSize\tStatus\t\tProcess\n");
    int i = 1;
    for (Block* curr = head; curr != NULL; curr = curr->next, i++) 
    {
        printf("%d\t%d\t%s\t\t", i, curr->size, curr->free ? "Free" : "Allocated");
        if (!curr->free)
            printf("P%d", curr->process_id);
        else
            printf("-");
        printf("\n");
    }
    printf("\n");
}
void splitBlock(Block* block, int size) 
{
    if (block->size > size) 
    {
        Block* newBlock = createBlock(block->size - size);
        newBlock->next = block->next;
        block->next = newBlock;
        block->size = size;
    }
}
Block* firstFit(Block* head, int size, int pid) 
{
    Block* curr = head;
    while (curr != NULL) 
    {
        if (curr->free && curr->size >= size) 
        {
            splitBlock(curr, size);
            curr->free = 0;
            curr->process_id = pid;
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
Block* bestFit(Block* head, int size, int pid) 
{
    Block* curr = head;
    Block* best = NULL;
    while (curr != NULL) 
    {
        if (curr->free && curr->size >= size) 
        {
            if (best == NULL || curr->size < best->size) 
            {
                best = curr;
            }
        }
        curr = curr->next;
    }
    if (best != NULL) 
    {
        splitBlock(best, size);
        best->free = 0;
        best->process_id = pid;
    }
    return best;
}
Block* worstFit(Block* head, int size, int pid) 
{
    Block* curr = head;
    Block* worst = NULL;
    while (curr != NULL) 
    {
        if (curr->free && curr->size >= size) 
        {
            if (worst == NULL || curr->size > worst->size) 
            {
                worst = curr;
            }
        }
        curr = curr->next;
    }
    if (worst != NULL) 
    {
        splitBlock(worst, size);
        worst->free = 0;
        worst->process_id = pid;
    }
    return worst;
}
void mergeFreeBlocks(Block* head) 
{
    Block* curr = head;
    while (curr != NULL && curr->next != NULL) 
    {
        if (curr->free && curr->next->free) 
        {
            curr->size += curr->next->size;
            Block* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } 
        else
        {
            curr = curr->next;
        }
    }
}
void deallocate(Block* head, int pid) 
{
    Block* curr = head;
    int found = 0;
    while (curr != NULL) {
        if (!curr->free && curr->process_id == pid) 
        {
            curr->free = 1;
            curr->process_id = -1;
            found = 1;
        }
        curr = curr->next;
    }
    if (found) 
    {
        mergeFreeBlocks(head);
        printf("Process P%d memory freed.\n", pid);
    } 
    else 
    {
        printf("Process P%d not found.\n", pid);
    }
}
int main() 
{
    int numBlocks, i;
    printf("Enter number of memory blocks: ");
    scanf("%d", &numBlocks);
    Block* head = NULL;
    Block* tail = NULL;
    printf("Enter sizes of memory blocks:\n");
    for (i = 0; i < numBlocks; i++) 
    {
        int size;
        scanf("%d", &size);
        Block* block = createBlock(size);
        if (head == NULL) 
        {
            head = block;
            tail = block;
        } 
        else 
        {
            tail->next = block;
            tail = block;
        }
    }
    int choice;
    printf("Choose allocation strategy:\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    scanf("%d", &choice);
    int pid = 1;
    while (1) 
    {
        printf("\n1. Allocate memory for process\n2. Deallocate process memory\n3. Print memory blocks\n4. Exit\n");
        printf("Enter choice: ");
        int opt;
        scanf("%d", &opt);
        if (opt == 1) 
        {
            int reqSize;
            printf("Enter memory required for process P%d: ", pid);
            scanf("%d", &reqSize);

            Block* allocated = NULL;
            if (choice == 1)
                allocated = firstFit(head, reqSize, pid);
            else if (choice == 2)
                allocated = bestFit(head, reqSize, pid);
            else if (choice == 3)
                allocated = worstFit(head, reqSize, pid);
            else
                printf("Invalid strategy.\n");

            if (allocated != NULL) 
            {
                printf("Memory allocated to process P%d.\n", pid);
                pid++;
            } 
            else 
            {
                printf("No sufficient memory available for process P%d.\n", pid);
            }
        }
        else if (opt == 2) 
        {
            int freePid;
            printf("Enter process ID to deallocate: ");
            scanf("%d", &freePid);
            deallocate(head, freePid);
        }
        else if (opt == 3) 
        {
            printBlocks(head);
        }
        else if (opt == 4) 
        {
            break;
        }
        else 
        {
            printf("Invalid option.\n");
        }
    }
    Block* curr = head;
    while (curr != NULL) 
    {
        Block* temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("Program terminated.\n");
    return 0;
}
