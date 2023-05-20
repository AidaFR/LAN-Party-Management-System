#include "header.h"

Team* createTeam(int nr_players, char* teamName) {

    Team* newTeam = (Team*)malloc(sizeof(Team));
    newTeam->nr_players = nr_players;
    newTeam->teamName=(char*)malloc((strlen(teamName)+1)*sizeof(char));
    strcpy(newTeam->teamName,teamName);
    newTeam->players = (Player*)malloc(nr_players * sizeof(Player));
    newTeam->next = NULL;
    return newTeam;
}
   
void addAtBeginning(Team** head, Team* newTeam) {
    newTeam->next = *head;
    *head = newTeam;
}
void afisareLista(Team *team_head, FILE* iesire){
    while(team_head!=NULL){ 
         fprintf(iesire,"%s",team_head->teamName);
    team_head=team_head->next;}
}

Team * findMin(Team *team_head){ //Functia pentru a gasi nodul cu valoarea minima din lista
Team* minNode=(Team*)malloc(sizeof(Team));
minNode=team_head;
while(team_head!=NULL){
    if(team_head->ma < minNode->ma) minNode=team_head;
    team_head=team_head->next;
}
return minNode;
}

Queue * createQueue (){
Queue * q =( Queue *) malloc ( sizeof ( Queue ));
if ( q == NULL ) return NULL ;
q->front =q->rear = NULL ;
return q ;
}

void enQueue ( Queue *q , Team* team1, Team* team2){
    Node * newNode =( Node *) malloc ( sizeof ( Node ));
newNode ->echipa1=team1;
newNode ->echipa2=team2;
newNode ->next = NULL ;

if (q ->rear == NULL ) 
    q ->rear= newNode; 
else {
(q -> rear ) ->next = newNode ;
(q -> rear )= newNode ;
}
if (q ->front == NULL ) 
q ->front =q ->rear ;
}

int isEmpty ( Queue * q ){
return (q -> front == NULL );
}

Node* deQueue ( Queue * q ) {
    if(isEmpty(q)) return NULL;
Node * temp; 
temp=q->front;
q->front=q->front->next;
 if (q->front == NULL)  //cazul in care coada are un singur nod
        q->rear = NULL;
    temp->next = NULL;

    return temp;
}

void push ( Stiva ** top , Team* echipa) {
Stiva* newTeam =( Stiva *) malloc ( sizeof ( Stiva ));
newTeam->echipa =echipa;
newTeam-> next =*top ;
* top = newTeam;
}

void deleteLosersStack(Stiva** losersTop){
    Stiva * temp ;
while ((* losersTop )!= NULL ){ 
    temp =* losersTop ;
    * losersTop =(* losersTop ) -> next ;
    free ( temp );}

}

Team* pop ( Stiva** winnersTop ) {
if ( *winnersTop==NULL) return  NULL ;
Stiva * temp =(* winnersTop );  //malloc peste tot
Team* aux = temp -> echipa ;
* winnersTop =(* winnersTop ) -> next ;
free ( temp );
return aux ;
}

void moveToQueue(Stiva *winnersTop, Queue *q) {
while(winnersTop!=NULL ){
    Team* ech1=pop(&winnersTop);
    Team*ech2=pop(&winnersTop);
    enQueue(q,ech1,ech2);

}
}


//     Node *newNode = NULL;  // Noul nod pentru coadă
//     Node *lastNode = NULL;  // Ultimul nod din coadă

//     while (count < 2 && !isEmptyStack(s)) {
//         Team *team = pop(s);  // Extrage o echipă din vârful stivei
//         Node *tempNode = (Node *)malloc(sizeof(Node));  // Creează un nou nod

//         tempNode->echipa1 = team;
//         tempNode->echipa2 = NULL;
//         tempNode->next = NULL;

//         if (newNode == NULL) {
//             newNode = tempNode;
//             lastNode = tempNode;
//         } else {
//             lastNode->echipa2 = tempNode->echipa1;
//             lastNode->next = tempNode;
//             lastNode = tempNode;
//         }

//         count++;
//     }

//     if (newNode != NULL) {
//         if (q->front == NULL) {
//             q->front = newNode;
//             q->rear = lastNode;
//         } else {
//             q->rear->next = newNode;
//             q->rear = lastNode;
//         }
//     }
// }
