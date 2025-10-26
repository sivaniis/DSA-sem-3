#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* next;
};

struct node* createNode(int coef, int exp) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct node** poly, int coef, int exp) {
    if (coef == 0) return;
    struct node* newNode = createNode(coef, exp);

    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    struct node* temp = *poly;
    struct node* prev = NULL;

    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == exp) {
        temp->coef += coef;
        free(newNode);
        if (temp->coef == 0) { 
            if (prev == NULL) {
                *poly = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
        }
    } else {
        newNode->next = temp;
        if (prev != NULL)
            prev->next = newNode;
    }
}


void displayPoly(struct node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    struct node* temp = poly;
    while (temp != NULL) {
        if (temp->coef > 0 && temp != poly) printf("+");
        if (temp->exp == 0)
            printf("%d ", temp->coef);
        else if (temp->exp == 1)
            printf("%dx ", temp->coef);
        else
            printf("%dx^%d ", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}


struct node* addPoly(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node* p1 = poly1;
    struct node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coef, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coef, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coef + p2->coef;
            if (sum != 0) insertTerm(&result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}


struct node* multiplyPoly(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;

    for (struct node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (struct node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;
            insertTerm(&result, coef, exp);
        }
    }

    return result;
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* sum = NULL;
    struct node* product = NULL;

   
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 0);

    
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);
    printf("Sum: ");
    displayPoly(sum);

    product = multiplyPoly(poly1, poly2);
    printf("Product: ");
    displayPoly(product);

   

    return 0;
}

