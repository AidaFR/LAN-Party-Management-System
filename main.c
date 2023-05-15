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
        char *teamName;
        struct player *players;
        float ma;
        struct team* next;

    }; 
typedef struct team Team;
   // struct lista
    //{ struct team* val;
    //struct lista* next;

    //}

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
Team * findMin(Team *team_head){ //Functia pentru a gasi cel mai mic nod din lista
Team* minNode=team_head;
while(team_head!=NULL){
    if(team_head->ma < minNode->ma) minNode=team_head;
    team_head=team_head->next;
}
return minNode;
}
int main(int argc, char *argv[]){
    FILE *f_read, *f_cerinte, *r_out;
    int nr_teams;
    f_cerinte = fopen(argv[1],"r");
  if(f_cerinte==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    }
  r_out = fopen(argv[3],"w");
  if(r_out==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    }
    int x=0;
Team *team_head=NULL; 
for(int i=1;i<5;i++)
{fscanf(f_cerinte,"%d",&x);
if(x==1) if(i==1)
{
    f_read = fopen(argv[2],"r");
    if(f_read==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    }
    fscanf(f_read,"%d",&nr_teams);//citim nr de echipe
   // printf("%d",nr_teams); //getc(f_read) citeste endline
    getc(f_read);
    
    for(int i=0;i<nr_teams;i++){
        int nr_juc = 0;
        char nume_echipa[50];
        fscanf(f_read,"%d",&nr_juc);
        getc(f_read);
        fgets(nume_echipa, 50, f_read);
        

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

//fprintf(r_out,"%d\n",nr_teams);
while(team_head!=NULL){
    //fprintf(r_out,"%d ",team_head->nr_players);
    fprintf(r_out,"%s",team_head->teamName);
   // for(int i=0;i<team_head->nr_players;i++){
   //             fprintf(r_out,"%s ",team_head->players[i].firstName);
    //            fprintf(r_out,"%s ",team_head->players[i].secondName);
    //            fprintf(r_out,"%d\n",team_head->players[i].points);
   // }
    team_head=team_head->next;
}
}
else if(i==2)
{ 
int p=1;
while(p<nr_teams) p*=2;
p=p/2;
fprintf(r_out,"%d",p);
int count=0;//cate eliminari fac

while(team_head!=NULL){
    int sum=0;
    for(int i=0;i<team_head->nr_players;i++){
         sum+=team_head->players[i].points;
    }
    team_head->ma=sum/(team_head->nr_players);
    team_head=team_head->next;
}
while(count<nr_teams-p){ //cate eliminari fac
 
    count++;
}

}}
fclose(r_out);
    fclose(f_read);
    return 0;
}