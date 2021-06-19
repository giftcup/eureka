#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Tree
{
    char word[50];
    struct Tree *right;
    struct Tree *left;
    unsigned int frequency;
 }tree;

tree *createNode(); //Allocates space for every node
tree *fileToTree(FILE *, tree *); 
tree *addWordToTree(char *, tree *);
void printTree(FILE *, tree *node);
void freeMemory(tree *node);

int main()
{
    FILE *inFile = fopen("./complete - shakespeare.txt", "r");
    if(inFile == NULL)
    {
        printf("Couldn't open text");
        exit(1);
    }
    tree *root;
    root = fileToTree(inFile, root);
    FILE *counts =  fopen("./wordCount.txt", "a");
    if(counts == NULL)//checks if the file opened
    {
        printf("Was unable to open file\n");
    }
    fprintf(counts, "S/N\t\t%-20s\t\tFrequency\n", "Words");
    printTree(counts, root);
    freeMemory(root);
    fclose(inFile);
    fclose(counts);
return 0;
}

tree *createNode()
{
    return (tree*)malloc(sizeof(tree));
}
tree *fileToTree(FILE *inFile, tree *root)
{
    char inputString[50];
    char inputChar;
    int i = 0;
    bool isPreviousCharacterAnAlphaCharacter = false;//checks the validity of the word
    if(inFile == NULL)
        printf("Can't open file");
    else
    {
        while((inputChar = getc(inFile)) != EOF)
        {
                isPreviousCharacterAnAlphaCharacter = isalpha(inputString[i - 1]);
                //writing each character to the inputString
                if(isalpha(inputChar)) {
                    inputString[i] = tolower(inputChar);
                    i++;
                } else if(isPreviousCharacterAnAlphaCharacter && (inputChar == '\'' || inputChar == '-')) {
                    inputString[i] = inputChar;
                    i++;
                }
                //Adds the inputted string to the binary tree when a word has been terminated and starts reading the next string
                else if(i > 0) {
                    if(inputString[i - 1] == '-') 
                        i--;
                    inputString[i] = '\0';
                    root = addWordToTree(inputString, root);
                    i = 0;
                }    
        }
        if ( i > 0)
        {
            if(inputString[i - 1] == '-')
                i--;
            inputString[i] = '\0';
            root = addWordToTree(inputString, root);
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
    }
    else
    {
        //compares the word inputted character by character to the words in the tree
        int compare = strcmp (input, (currentNode -> word));
        //if inputString is greater than the string in the current node, the inputString is added to the right node
        if(compare > 0) 
        {
            currentNode -> right = addWordToTree(input, currentNode -> right);
        }
        //if inputString is less than the string in the current node, the inputString is added to the left node
        else if(compare < 0)
        {
            currentNode -> left = addWordToTree(input, currentNode -> left);
        }
        //if the inputted string is equal to the word in the current node, the frequency is incremented
        else
        {
            (currentNode -> frequency) ++;
        }
    }
    return currentNode;
}
//prints out the tree
void printTree(FILE *counts, tree *node)
{
    static int i=1;
    if (node != NULL)
    {
        printTree(counts, node->left);
        fprintf(counts, "%i\t\t%-20s\t\t%u\n", i++, node -> word, node ->frequency);
        //printf("\t\t%s\t%u\n", node -> word, node ->frequency);
        printTree(counts, node->right);
    }
}
//frees all allocated memory
void freeMemory(tree *node)
{
    if(node != NULL) {
        freeMemory(node -> left);
        freeMemory(node -> right);
        free(node);
    }
}