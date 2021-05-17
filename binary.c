#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Tree
{
    char word[50];
    struct Tree *right;
    struct Tree *left;
    unsigned int frequency;
}tree;

tree *fileToTree(FILE *, tree *);
tree *addWordToTree(char *, tree *);

int main()
{
    FILE *inFile = fopen("./texts.txt", "r");
    tree *root = NULL;
    root -> left = NULL;
    root -> right = NULL;
    root -> frequency = 0;
    root = fileToTree(inFile, root);
    fclose(inFile);
return 0;
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