#define LONGT_MAX_CHAINE 10    ///I get based on a code for implement the binary tree data structure in ANSI C where the data of each node or branch will be a string.///
                             ///Credit. https://parzibyte.me/blog/2021/01/13/c-arbol-binario-cadenas////
typedef struct chaineNode{
        char username[LONGT_MAX_CHAINE];
        char password[LONGT_MAX_CHAINE];
   
   
        struct chaineNode *left;
        struct chaineNode *right;
}       user13;


user13 *newNode(char username[LONGT_MAX_CHAINE], char password[LONGT_MAX_CHAINE])

