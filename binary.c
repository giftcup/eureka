#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Tree
{
    char word[50];
    struct Tree *right;
    struct Tree *left;
    unsigned int frequency;
}tree;

tree *createNode();
tree *fileToTree(FILE *, tree *);
tree *addWordToTree(char *, tree *);
void printTree(tree *node);
void freeMemory(tree *node);

int main()
{
    FILE *inFile = fopen("./texts.txt", "r");
    tree *root;
    root = createNode();
    root -> left = NULL;
    root -> right = NULL;
    root = fileToTree(inFile, root);
    printTree(root);
    freeMemory(root);
    fclose(inFile);
return 0;
}

tree *createNode()
{
    return (tree*)malloc(sizeof(tree));
}
tree *fileToTree(FILE *inFile, tree *root)
{
    char input[50];
    if(inFile == NULL)
        printf("Can't open file");
    else
    {
        while(fscanf(inFile, "%s", input) != EOF)
        {
            printf("%s\n", input);
            root = addWordToTree(input, root);
        }
    }
    return root;
}
tree *addWordToTree(char *input, tree *currentNode)
{
    if (currentNode == NULL)
    {
        currentNode = createNode();
        strcpy((currentNode -> word), input);
        currentNode -> right = NULL;
        currentNode -> left = NULL;
        currentNode -> frequency = 1;
        return currentNode;
    }
    int compare = strcmp (input, (currentNode -> word));
    if(compare > 0)
    {
        currentNode -> right = addWordToTree(input, currentNode -> right);
    }
    else if(compare < 0)
    {
        currentNode -> left = addWordToTree(input, currentNode -> left);
    }
    else
    {
        currentNode -> frequency ++;
    }
    return currentNode;
}
void printTree(tree *node)
{
    FILE *counts =  fopen("./wordCount.txt", "w");
    if(counts == NULL)
    {
        printf("Was unable to open file\n");
    }
    int i=0;
    while (node != NULL)
    {
        printTree(node->left);
        fprintf(counts, "%i\t\t%s\t%u\n", i, node -> word, node ->frequency);
        printTree(node->right);
        i++;
    }
}
void freeMemory(tree *node)
{
    freeMemory(node -> left);
    freeMemory(node -> right);
    free(node);
}