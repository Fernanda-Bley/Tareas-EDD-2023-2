
typedef struct node{
    struct node *next;
    int value;
} Node;

typedef struct list{
    Node *head;
    Node *tail;
    int size;
} List;

Node* init_node(int value);
List *createList();
void add(List *list, int value);
void delete(List *list, int value);
void printList(List *list);
void deleteList(List *list);
int search(List *list, int value);
void insertAt(List *list, int value, int pos);
void deleteAt(List *list, int pos);

