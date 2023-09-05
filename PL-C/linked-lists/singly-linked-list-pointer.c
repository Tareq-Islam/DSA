#include <stdio.h>
#include <stdlib.h>

int counter = 1;

struct Student {
    int id;
    char name[100];
    int class;
    char address[500];
};

struct Node {
    struct Student student;
    struct Node *link;
};

/* Function prototype*/
struct Node *insertStudentIntoNode(struct Student student);
void printNode(struct Node *node);

int main() {
    struct Student std1 = {1, "Student 1", 5, "Student Address"};
    struct Node *n1 = insertStudentIntoNode(std1);

    struct Student std2 = {2, "Student 2", 2, "Student Address"};
    struct Node *n2 = insertStudentIntoNode(std2);

    struct Student std3 = {3, "Student 3", 7, "Student Address"};
    struct Node *n3 = insertStudentIntoNode(std3);

    n1->link = n2;
    n1->link->link = n3;
    printf("\n\n### Traversing Node ###\n\n");
    printNode(n1);
    return 0;
}

void printNode(struct Node *node) {



   if (node->link == NULL) {
         printf("Node-%d: {data: {id: %d, name: %s, class: %d, address: %s}, link: %d}\n\n", counter, node->student.id, node->student.name, node->student.class, node->student.address, 0);
         printf("\nNode are finished.\n\n");
    } else {
         printf("Node-%d: {data: {id: %d, name: %s, class: %d, address: %s}, link: %d}\n\n", counter, node->student.id, node->student.name, node->student.class, node->student.address, node->link->student.id);
        counter++;
        printNode(node->link);
    };

}



struct Node *insertStudentIntoNode(struct Student student) {
    printf("Insert Student: {id: %d, name: %s, class: %d, address: %s}\n", student.id, student.name, student.class, student.address);

    struct Node *createNode = malloc(sizeof(struct Node));

    if (createNode == NULL) return NULL;

    createNode->student = student;
    createNode->link = NULL;

    return createNode;
}
