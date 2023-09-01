/* This program Traversing Node */

#include <stdio.h>
#define NODE_SIZE 12

int START = 0;
char INFO[NODE_SIZE];
int LINK[NODE_SIZE];
int counter = 0;
struct Node {
    char data;
    int next;
};

/* Main Function */
void main() {
    printf("### Node List Traversing ####\n\n");
    init();
    printf("\nPlease Enter a start point = ");
    scanf("%d", &START);
    printf("\n");

    printf("Node Start = %d \n", START);
    traversing(START);

}
/* Initialize */
void init() {
    INFO[3] = 'O';  LINK[3] = 6;
    INFO[4] = 'T';  LINK[4] = 0;
    INFO[6] = 'D';  LINK[6] = 11;
    INFO[7] = 'X';  LINK[7] = 10;
    INFO[9] = 'N';  LINK[9] = 3;
    INFO[10] = 'I'; LINK[10] = 4;
    INFO[11] = 'E'; LINK[11] = 7;

    int i;
    printf("INFO: ");
    for(i = 1; i <= NODE_SIZE; i++) {
        printf("%d=",i);
        char data = INFO[i];
        if (data == NULL) {
            printf("NULL, ");
        } else {
            printf("%c, ", data);
        };

    }
     printf("\n\n");

     int j;
    printf("LINK: ");
    for(j = 1; j <= NODE_SIZE; j++) {
        printf("%d=", j);
        int data = LINK[j];
        if (data == NULL) {
            printf("0, ");
        } else {
            printf("%d, ", data);
        };

    }

      printf("\n\n");
}


int traversing(int start) {
    if (start == 0) {
        printf("\nNode list are finished.\n");
    } else {
        char data = INFO[start];
        int pointer = LINK[start];

        if (data == NULL) {
            printf("\nNode are not found.\n");
        } else {
            printf("\nINFO[%d], LINK[%d]: ", start, start);
            printNode(data, pointer);
            traversing(pointer);
        }

    }
}


void printNode(char data, int nextpointer) {
    counter += 1;
    struct Node node;
    node.data = data;
    node.next = nextpointer;
    printf("Node %d = { Data: %c, Next: %d }\n", counter, node.data, node.next);
};


