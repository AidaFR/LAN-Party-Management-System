#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player
    {
        char* firstName;
        char* secondName;
        int points;
        struct player *next;
    };
typedef struct player Player;


struct team
    {           
        int nr_players;
        char *teamName;
        struct player *player_list;
        struct team* next;

    };
typedef struct team Team;

void addAtBeginningTeam ( Team ** team_head , int nr_juc, char* nume_echipa)
{
    Team* new_team = (Team*)malloc(sizeof(Team)); //aloca memorie pt noua echipa
        strcpy(new_team->teamName,nume_echipa);
        new_team->nr_players=nr_juc;
        new_team->next= *team_head;
        *team_head=new_team;
}

void addAtBeginningPlayer ( struct player ** player_head , char* prenume, char* nume, int puncte)
{
     struct player* new_player=(struct player*)malloc(sizeof(struct player));
     strcpy(new_player->firstName,prenume);
     strcpy(new_player->secondName,nume);
     new_player->points=puncte;
     new_player->next= *player_head;
     *player_head=new_player;
}
int main(){
    FILE *f_read;
    int nr_teams;
    f_read = fopen("/home/ayda/Desktop/PA/lan-party-02-checker/date/t1/d.in","r");
  if(f_read==NULL){
        printf("Eroare la deschiderea fisierului");
        exit(1);
    } 
  
    fscanf(f_read,"%d",&nr_teams);//citim nr de echipe
    printf("%d",nr_teams);
    
    getc(f_read);
    Team *team_head=NULL;
    for(int i=0;i<nr_teams;i++){
        int nr_juc;
        char *nume_echipa = (char*) malloc(50* sizeof(char));
        fscanf(f_read,"%d",&nr_juc);
        fscanf(f_read,"%s",nume_echipa);
        addAtBeginningTeam ( &team_head , nr_juc, nume_echipa);
        struct player* player_head=NULL;
        for(int j=0;j<nr_juc;j++){
            char nume[50],prenume[50];
            int puncte;
            fscanf(f_read,"%s%s",prenume,nume);
            fscanf(f_read,"%d",&puncte);
            addAtBeginningPlayer ( &player_head , prenume, nume, puncte);
        }

        

    }





    fclose(f_read);
    return 0;
}