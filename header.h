#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player
    {
        char* firstName;
        char* secondName;
        int points;
    };
typedef struct player Player;

struct team
    {           
        int nr_players;
        char* teamName;
        Player* players;
        float ma;
        struct team* next;

    }; 
typedef struct team Team;
Team* createTeam(int nr_players, char* teamName);
void addAtBeginning(Team** head, Team* newTeam);
void afisareLista(Team *team_head, FILE* iesire);
Team* findMin(Team* team_head);

struct Elem {
Team* echipa1;
Team* echipa2;
struct Elem* next ;
};
typedef struct Elem Node ;

struct Q 
    {
        Node *front ,*rear;
    };
typedef struct Q Queue ;
Queue * createQueue ();
void enQueue ( Queue *q , Team* team1, Team* team2);
int isEmpty ( Queue * q );
Node* deQueue ( Queue * q );

struct elem {
Team* echipa;
struct elem * next ;
};
typedef struct elem Stiva ;

void push ( Stiva** top, Team* echipa);
void deleteLosersStack(Stiva** losersTop);    
void moveToQueue(Stiva* winnersTop, Queue* q); 
void displayQueue(Queue* q, FILE* iesire);      
void afisareStivaCastigatori(Stiva* top, FILE* iesire);

struct el
    {           
        Team* Ech;
        struct el* left;
        struct el* right;
        int height;

    }; 
typedef struct el Nod;
Nod* createNode(Team* echipa);
Nod* insertNode(Nod* node, Team* team);
void mutaStivaInBST(Stiva* winnersTop, Nod** root);
//void inorderDescresc(Nod* node, FILE *iesire); //, Nod** avlRoot);
//int max ( int a , int b );
//Nod * RightRotation ( Nod * z );
//Nod* insertNodeAVL(Nod* node, Team* team);
void inorderDescresc(Nod* node, FILE* iesire); //, Nod** avlRoot);
//void getLevel2Teams(Nod* node, FILE *iesire);
void freeStack(Stiva** stack);
void freeQueue ( Queue * q );
void freeList(Team** head);