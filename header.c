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
         fprintf(iesire,"%s\n",team_head->teamName);
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
newNode->echipa1=team1;
newNode->echipa2=team2;
newNode->next = NULL ;

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

void displayQueue(Queue* q, FILE* iesire) {
    if (isEmpty(q)) {
        fprintf(iesire,"Coada este goală.\n");
        return;
    }
    
   Node* temp = q->front;
    
    //fprintf(iesire, "Coada: ");
    while (temp != NULL) {
        fprintf(iesire,"%s", temp->echipa1->teamName);
        for (int i = 0; i < (33 - strlen(temp->echipa1->teamName)); i++) {
            fprintf(iesire," ");
        }
        fprintf(iesire, "-");
        for (int i = 0; i < (33 - strlen(temp->echipa2->teamName)); i++) {
            fprintf(iesire," ");
        }
        fprintf(iesire,"%s", temp->echipa2->teamName);
        temp = temp->next;
           fprintf(iesire,"\n");
    }
    fprintf(iesire,"\n");
}

void afisareStivaCastigatori(Stiva *top, FILE* iesire){
    int ok=0;
    if(top->next==NULL) ok=1;
    while(top!=NULL){ 
         fprintf(iesire,"%s",top->echipa->teamName);
         for (int i = 0; i < (34 - strlen(top->echipa->teamName)); i++) 
              fprintf(iesire," ");
            fprintf(iesire, "-  ");
         fprintf(iesire,"%.2f\n",top->echipa->ma);

    top=top->next;}
    if(ok==0) fprintf(iesire, "\n"); 
    else return;
}


// functie pt a crea un nod în bst
Nod* createNode(Team* echipa) {
    Nod* newNode = (Nod*)malloc(sizeof(Nod));
    newNode->Ech = (Team*)malloc(sizeof(Team));
    newNode->Ech->teamName=(char*)malloc((strlen(echipa->teamName)+1)*sizeof(char));
    strcpy(newNode->Ech->teamName,echipa->teamName);
    newNode->Ech->ma = echipa->ma;
    newNode->left = newNode->right = NULL; 

    return newNode;
}
// inserez un nod in bst
Nod* insertNode(Nod* node, Team* team) {

    if (node == NULL) 
        return createNode(team);

    if (team->ma < node->Ech->ma) {
        // inseram in subarborele stang
        node->left = insertNode(node->left, team);
    } else if (team->ma > node->Ech->ma) {
        // inseram in subarborele drept
        node->right = insertNode(node->right, team);
    } else {

        int cmpResult = strcmp(team->teamName, node->Ech->teamName);
        if (cmpResult < 0) 
            node->left = insertNode(node->left, team);
           else 
                node->right= insertNode(node->right, team);
        
    }
//printf("INSERT: %s\n",node->Ech->teamName);
    return node;
}

void mutaStivaInBST(Stiva* winnersTop, Nod **root){
    if(winnersTop==NULL) return;
    *root=createNode(winnersTop->echipa);
    //printf("BST: %s\n", winnersTop->echipa->teamName);
    winnersTop=winnersTop->next;
  Team* Echipa = (Team*)malloc(sizeof(Team));
        while(winnersTop){
             Echipa=winnersTop->echipa;
            //printf("BST: %s\n", winnersTop->echipa->teamName);
        *root = insertNode(*root, Echipa);

       winnersTop=winnersTop->next;

     }


}
void inorderDescresc(Nod* node, FILE *iesire) {
    if (node == NULL) 
        return;
inorderDescresc(node->right,iesire);//parcurgem subarborele drept
 fprintf(iesire,"%s",node->Ech->teamName);

 for (int i = 0; i < (34 - strlen(node->Ech->teamName)); i++)  
     fprintf(iesire," ");
fprintf(iesire, "-  ");
fprintf(iesire,"%.2f\n",node->Ech->ma);

    // Parcurgem subarborele stâng
    inorderDescresc(node->left,iesire);

}
