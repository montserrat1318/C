///*Instructions: Please, put this main file (main.c) in GDB, then insert another "new file" and put the file called "tree.h"; follow the instructions of the program. Thanks!*///
                                               ///Raul Chavez, explain me the hw6 (how it works and functions or possible manners of do it)///
#include <string.h> /// strstr ///
#include <ctype.h> /// isspace & tolower ///
#include <stdio.h>
#include <stdlib.h> /// malloc & free ///
#include "tree.h"

{
    
size_t nodeSize = sizeof(user13);           ///requesting memory for the users and passwords///
size_t pasNodeSize = sizeof(user13);             ///Credit for function"size_t": https://www.geeksforgeeks.org/size_t-data-type-c-language////
user13 *node = (user13 *)malloc(nodeSize);
user13 *passNode = (user13 *)malloc(pasNodeSize);
    
    
strcpy(node->username, username);
strcpy(node->password, password);
node->left = node->right = NULL;
    return node;
}

    void adding (user13 *node, char *chaine, char *password){
if (strcmp(chaine, node->username) > 0){
        if (node->right == NULL){
            node->right = newNode(chaine, password);
        }
        else{
            adding (node->right, chaine, password);
        }
    }
else{
        if (node->left == NULL){
            node->left = newNode(chaine, password);
        }
        else{
            adding (node->left, chaine, password);
        }
    }
}

    user13 *searchUserName(user13 *node, char *chaine){
if (node == NULL){
        return NULL;
    }
    if (strcmp(chaine, node->username) == 0){
        return node;
    }
    else if (strcmp(chaine, node->username) > 0){
        return searchUserName(node->right, chaine);
    }
    else{
        return searchUserName(node->left, chaine);
    }
}
    user13 * searchPassword(user13 *node, char *chaine, char *passw)
{
if (node == NULL) {
        return NULL;
    }
    if (strcmp(chaine, node ->username) == 0){
        if (strcmp(passw, node->password) == 0){
            *node ->username = NULL;
            *node ->password=NULL;
            return NULL;
        }
    }
    else if (strcmp(chaine, node->username) > 0){
        return searchPassword (node->right, chaine, passw);
    }
    else{
        return searchPassword (node->left, chaine, passw);
    }
}
    void order (user13 *node){    ///root part for the tree system///
if (node != NULL){
        order (node->left);
        printf("%s,", node->username);
        order (node->right);
    }
}

int main(int argc, char const *argv[]){   ///part for adding the following stuff: 1. The welcome part for starting the program system, 2. "user root", 3. user, 4. password///
    char user[LONGT_MAX_CHAINE];
    char pass[LONGT_MAX_CHAINE];
    user13 *root = NULL;
    printf("\nHey! Feel Welcome!\n\nPlease, creat your first user!\n");
     printf("Please, write down the user you would like to add:\n");
    fflush(stdin);
    scanf("%s", &user[0]);
    printf("Please, write down the password:\n");
    fflush(stdin);
    scanf("%s", &pass[0]);
    root = newNode(user,pass);
    int add = 0, delate = 0, ordering = 0;
    char option, d;
    
while ((d = getchar()) != EOF){
        
        printf("\n*Please insert the letter t, if you would like to add an user:\n*Please insert the letter h, if you would like to delate an user:\n*Please insert the letter i, if you would like to watch the users in alphabetic order:\n\n");
        fflush(stdin);
        scanf("%c", &option);
  switch (option){                   ///input the following letter for a certain action, such like an option to decide (delate,add user or ordering final users)///
        case 't': 
            add = 1;
            break;
        case 'h': 
            delate = 1;
            break;
        case 'i': 
            ordering = 1;
            break;
        default:
            printf("Ups, Sorry! This option is wrong or is not valide...");  ///default if someone introduce another charact invalid///
            break;
        }
  if (add != 0 || delate != 0 || ordering != 0){
      
            if (add == 1){
                char user[LONGT_MAX_CHAINE];
                char pass[LONGT_MAX_CHAINE];
                printf("Please, write down the user you would like to add:\n");
                fflush(stdin);
                scanf("%s", &user[0]);
                struct chaineNode *userPrompt = searchUserName(root, user);
                
            if (userPrompt != NULL){
                printf("\n\tUpss, sorry, BUT... '%s' that already exits in the system...\n", user);  ///repeat action of user in the system///
                }
                
            else{
                printf("Please, write down the password you would like to give to the user:\n");
                fflush(stdin);
                scanf("%s", &pass[0]);
                adding(root, user, pass);
                printf("\n\tCongrats! The user'%s' has been added satisfactorily\n", user);
                }
            }
            
  else if (delate == 1){                                                               ///for delating stuff action of a user///
                char user[LONGT_MAX_CHAINE];
                char pass[LONGT_MAX_CHAINE];
                printf("Please, write down the user you would like to delate:\n");
                fflush(stdin);
                scanf("%s", &user[0]);
                struct chaineNode *userPrompt = searchUserName(root, user);
  if (userPrompt != NULL){
                printf("Please, write down the password of the user to delate it:\n");
                fflush(stdin);
                scanf("%s", &pass[0]);
                struct chaineNode *userPrompt = searchPassword(root, user, pass);
  if (userPrompt == NULL){
                printf("\n\t The user has been delate it %s satisfactorily \n", user);
                    }
  else{
     printf("\tPlease, try again! Wrong Password\n");
                    }
                }
  else{
     printf("\n This user was not found in the system.\n");
                }
            }
  else if (ordering == 1){
      
                order(root);
                printf("\nPlease, press down ENTER to continue...\n");
                getchar();
            }
        }
    add = 0;
    delate = 0;
    ordering = 0;
    }

}
