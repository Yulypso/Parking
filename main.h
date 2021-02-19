/************************* Librairies ************************/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <ncurses.h> 
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <sox.h>

/************************* Structures ************************/
typedef struct Liste Liste;
typedef struct Vehicle Vehicle;

struct Liste //liste de véhicules
{
	Vehicle* premier;
};

typedef struct //structure décoration neige/étoile
{
	int x; 
	int y;
}snow;

struct Vehicle //structure véhicule
{
	int type; //0:voiture | 1:bus

	int direction;//direction 0 = gauche | direction 1 = haut | direction 2 = droite | direction 3 = bas 
			      //direction 7 = arrêt gauche | direction 8 = arrêt haut | direction 9 = arrêt droite | direction 10 = arrêt bas
			      //direction 5 = suppression voiture 
			      //direction 11 = recul gauche | direction 12 = recul droite
			      //direction 14 = arrêt droit (lors d'un recul) | direction 13 = arrêt gauche (lors d'un recul)
			      //direction 17 = explosition de la voiture 

	int ID; //ID d'une voiture (100 disponibles)
	int y; //coordonnée en y du véhicule
	int x; //coordonnée en x du véhicule
	int time_parking; //temps de stationnement courant (début à 0)
	int time_parked; //temps de stationnement total 
	int state; //0: inactif |  1: actif
	int paytime; //prix total à payer à la sortie 
	int color; //couleur de la voiture (7 disponibles)
	int time_entry; //temps d'attente totale à l'entrée (barrière)
	int time_exit; //temps d'attente totale à la sortie (barrière)
	int time_waiting; //temps d'attente courant à l'entrée/sortie
	int stupid_car; //état pour les voitures qui roulent en contre-sens 
	Vehicle* suivant; //pointeur vers le véhicule suivant dans la liste chaînée 
};


/************************* tableaux permettant de stocker les fichiers textes ************************/
char car_left[2][4];
char car_right[2][4];
char car_up[3][3];
char car_down[3][3];
char bus_left[3][6];
char bus_right[3][6];
char bus_bup[4][5];
char bus_down[4][5];
char bullet[2][4];

/************************* autres tableaux ************************/
snow flakeStop[65]; //tableau pour la décoration
int ID_TAB[100]; //tableau d'ID maximum (nombre de vehicule maximum)
int car_place[49]; //place de parking voiture
int bus_place[25]; //place de parking bus
int L, C; //position du click souris


/************************* Headers : fonctions utilisées ************************/
void ncurses_initialiser();
void ncurses_souris();
char key_pressed();
void colors();
int click_souris();
void STARS(int MaxY, int MaxX);
void LOAD_VEHICLE();
void Init_ID_TAB(int ID_TAB[100]);
int Search_ADD_ID(int ID_TAB[100]);
int Search_REMOVE_ID(int ID_TAB[100], int ID);
Liste* initfile(Liste* file);
void enfiler(Liste* file, int cpt_line, int cpt_col, int** Collider_map, char** map, int type, int direction, int y, int x, int ID);
void retirer(Liste * file, int ID);
void VALID_CHOICE(int MaxY, int MaxX);
void EXIT_MENU(int MaxY, int MaxX, int cpt_line, int cpt_col, Liste* file, char** map, int** Collider_map, int** draw_map);
void DISPLAY_BUTTON(int MaxY, int MaxX, int heure_de_pointe, int fluid_heavy, int instant_accident);
void SYMBOL_CONVERTER(char c);
int SIZE_FILE(char* file_name, int line_or_col);
void EDIT_COLLIDER_MAP(int VehicleY, int VehicleX, int direction, int type, int cpt_line, int cpt_col, int ** Collider_map, char **map);
void DISPLAY_COLLIDER_MAP(int cpt_line, int cpt_col, int ** Collider_map);
void DISPLAY_MAP(Liste* file, int cpt_line, int cpt_col, char **map, int start, int** draw_map);
void FILL_COLLIDER_MATRICE(int cpt_line, int cpt_col, char** Map, int ** Collider_map);
void FILL_MAP_MATRICE(int cpt_line, int cpt_col, char* file_name, char **map);
void FILL_DRAW_MATRICE(int cpt_line, int cpt_col, int** draw_map);
int VEHICLE_GO_RIGHT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
int VEHICLE_GO_LEFT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
int VEHICLE_GO_UP(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
int VEHICLE_GO_DOWN(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
int VEHICLE_GO_BACK_LEFT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
int VEHICLE_GO_BACK_RIGHT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
int VEHICLE_PARK(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
void TEST_GO_DOWN(Liste* file, int ** Collider_map, int ID);
void BALISE(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char ** map, int ID, int heure_de_pointe, int fluid_heavy, int instant_accident);
int FIND_DIRECTION(Liste* file, int ID);
void UPDATE(int MaxY, int MaxX, Liste * file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int** draw_map, int heure_de_pointe, int fluid_heavy, int instant_accident);
void INIT_UPDATE(int MaxY, int MaxX, int cpt_line, int cpt_col, Liste * file, int** Collider_map, char** map, int** draw_map, int fluid_heavy, int heure_de_pointe);
void SIMULATION(int MaxY, int MaxX);
void HOME_PAGE(int MaxY, int MaxX);
void MAIN_MENU(int MaxY, int MaxX);
void LANCEMENT_JEU();

