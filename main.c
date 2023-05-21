#include "header.h"


int main(int argc, char* argv[]){
    FILE *f_read, *f_cerinte, *r_out;
    int nr_teams;
    f_cerinte = fopen(argv[1],"r");
  if(f_cerinte==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    }
    f_read = fopen(argv[2],"r");
    if(f_read==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    }
  r_out = fopen(argv[3],"w");
  if(r_out==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    }
//fprintf(r_out,"buuup");
int x[5]={0};
Team *team_head=NULL; 
for(int i=1;i<=5;i++)
fscanf(f_cerinte,"%d",&x[i]);
    fscanf(f_read,"%d",&nr_teams);//citim nr de echipe
   // printf("%d",nr_teams); //getc(f_read) citeste endline
    getc(f_read);
    
    for(int i=0;i<nr_teams;i++){
        int nr_juc = 0;
        char nume_echipa[50];
        fscanf(f_read,"%d",&nr_juc);
        getc(f_read);
        fgets(nume_echipa, 50, f_read);
        nume_echipa[strlen(nume_echipa)-1]='\0';
        nume_echipa[strlen(nume_echipa)-1]='\0';
        if(nume_echipa[strlen(nume_echipa)-1]==' ')
        nume_echipa[strlen(nume_echipa)-1]='\0';
//printf("(%c)\n",nume_echipa[strlen(nume_echipa)-1]);

//printf("%d %s",nr_juc,nume_echipa);
        char aux[50];
        Team* newTeam = createTeam(nr_juc, nume_echipa);
            for(int j=0;j<nr_juc;j++){
                fscanf(f_read,"%s",aux);
                getc(f_read);
                newTeam->players[j].firstName=(char *) malloc((strlen(aux)+1)*sizeof(char));
                strcpy(newTeam->players[j].firstName,aux);
                 fscanf(f_read,"%s",aux);
                 newTeam->players[j].secondName=(char *) malloc((strlen(aux)+1)*sizeof(char));
                strcpy(newTeam->players[j].secondName,aux);
                  int puncte;
                 fscanf(f_read,"%d",&puncte);
                 newTeam->players[j].points=puncte;
            
        }
        addAtBeginning(&team_head, newTeam);
    }

//Team *team_head_aux=(Team*)malloc(sizeof(Team)); 
//team_head_aux=team_head;
//fprintf(r_out,"%d\n",nr_teams);
if(x[1]==1 && x[2]==0){
    afisareLista(team_head, r_out);
}
//if(x[1]==1 && x[2]==0){
//while(team_head_aux!=NULL){
                 //fprintf(r_out,"%d ",team_head->nr_players);
//fprintf(r_out,"%s",team_head_aux->teamName);
           // for(int i=0;i<team_head->nr_players;i++){
   //             fprintf(r_out,"%s ",team_head->players[i].firstName);
    //            fprintf(r_out,"%s ",team_head->players[i].secondName);
    //            fprintf(r_out,"%d\n",team_head->players[i].points);
   // }
 //team_head_aux=team_head_aux->next;
//}}
//fprintf(r_out,"/n");



int p=1,a=-1;
while(p<=nr_teams) {p*=2;a++;}
p=p/2;
//a--;
int count=0;//cate eliminari fac
Team *aux=(Team*)malloc(sizeof(Team));

aux=team_head;
while(aux!=NULL){ 
    int sum=0;
    for(int i=0;i<aux->nr_players;i++)
         {sum=sum+aux->players[i].points;
           //fprintf(r_out,"%d ",aux->players[i].points);
         }
        //fprintf(r_out,"\n");
   // fprintf(r_out,"%d\n",sum);
    float x=((1.0*sum)/(aux->nr_players));
    aux->ma=x;
   // fprintf(r_out,"%.2f\n",x);
    aux=aux->next;
}
   
   Team* prev=(Team*)malloc(sizeof(Team));
while(count<nr_teams-p){ 
Team* current=(Team*)malloc(sizeof(Team));
Team* minNode=findMin(team_head);

  current=team_head;
  prev=NULL;
  while(current!=NULL && current->ma!=minNode->ma){
    prev=current;
    current=current->next;}

  if(prev==NULL)  team_head=current->next;
  
        else
                 prev->next=current->next;

    free(current);

    count++;}

if(x[1]==1 && x[2]==1 &&x[3]==0){
afisareLista(team_head, r_out); 
}
//while(team_head!=NULL){
//fprintf(r_out,"%s",team_head->teamName);
 //   team_head=team_head->next;
//}


if(x[1]==1 && x[2]==1 &&x[3]==1 && x[4]==0){
//afisareLista(team_head, argv[3]);
//fprintf(r_out,"MA DUC LA MAMAIaaaaA "); 
//fprintf(r_out,"%d",a); 
//fprintf(r_out,"buup");
afisareLista(team_head, r_out);
fprintf(r_out,"\n");
Queue * q = createQueue();

    while(team_head!=NULL)
 {enQueue(q,team_head,team_head->next);
 team_head=team_head->next;
  team_head=team_head->next; 
 }

  Stiva* winnersTop=(Stiva*)malloc(sizeof(Stiva));
   Stiva* losersTop=(Stiva*)malloc(sizeof(Stiva));
int nr=1;
 while(nr<=a){
      fprintf(r_out,"--- ROUND NO:%d\n",nr); 
      displayQueue(q ,r_out);
winnersTop=NULL;
losersTop=NULL;
while (! isEmpty ( q )){
Node *node = deQueue(q);
    if (node != NULL) {
        Team *winningTeam = ( Team *) malloc ( sizeof ( Team ));
        winningTeam=node->echipa1;
        Team *losingTeam = ( Team *) malloc ( sizeof ( Team ));
        losingTeam=node->echipa2;

        if (winningTeam->ma >losingTeam->ma) {
            push(&winnersTop, winningTeam);
            push(&losersTop, losingTeam);
            winningTeam->ma++; // Adăugăm un punct echipei câștigătoare}
        }
    // } else if (winningTeam->ma == losingTeam->ma) {
    //     push(&winnersTop, winningTeam);
    //     push(&losersTop, losingTeam);
    //     winningTeam->ma++;

    // }
    else{

        push(&winnersTop, losingTeam); // Adăugăm în stivă echipa invinsă
        push(&losersTop, winningTeam); // Adăugăm în stivă echipa câștigătoare
        losingTeam->ma++; // Adăugăm un punct echipei câștigătoare
        }
    }
}
fprintf(r_out,"WINNERS OF ROUND NO:%d\n",nr); 
afisareStivaCastigatori(winnersTop,r_out);
deleteLosersStack(&losersTop);                  
moveToQueue(winnersTop, q);      

nr++;
}

}


fclose(r_out);
    fclose(f_read);
    return 0;
}