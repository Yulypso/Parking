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

typedef struct Liste Liste;
typedef struct Vehicle Vehicle;

struct Liste
{
	Vehicle* premier;
};

typedef struct
{
	int x; 
	int y;
}snow;

struct Vehicle
{
	int type;
	int direction;
	int ID;
	int y;
	int x;
	int time_parking;
	int time_parked;
	int state; //0: inactif |  1: actif
	int paytime;
	int color;
	int displayed;
	int time_entry;
	int time_exit;
	int time_waiting;
	Vehicle* suivant;
};


//lire chaque image dans un tableau//
char car_left[2][4];
char car_right[2][4];
char car_up[3][3];
char car_down[3][3];
char bus_left[3][6];
char bus_right[3][6];
char bus_bup[4][5];
char bus_down[4][5];

//char* map;
snow flakeStop[65];
int ID_TAB[100]; //tableau d'ID maximum (nombre de vehicule maximum)

int car_place[49];


int bus_place[25];

int L, C;

void ncurses_initialiser();
void ncurses_souris();
char key_pressed();
void colors();
int click_souris();
void STARS(int MaxY, int MaxX);
int UPDATE_SNOWFLAKES(int MaxY, int MaxX);
int SNOWFLAKES(int MaxY, int MaxX);
void LOAD_VEHICLE();
void Init_ID_TAB(int ID_TAB[100]);
int Search_ADD_ID(int ID_TAB[100]);
int Search_REMOVE_ID(int ID_TAB[100], int ID);
Liste* initfile(Liste* file);
void enfiler(Liste* file, int cpt_line, int cpt_col, int** Collider_map, char** map, int type, int direction, int y, int x, int ID);
void retirer(Liste * file, int ID);
void VALID_CHOICE(int MaxY, int MaxX);
void EXIT_MENU(int MaxY, int MaxX, int cpt_line, int cpt_col, char** map, int** Collider_map, int** draw_map);
void DISPLAY_EXIT(int MaxY, int MaxX, int fluid_heavy);
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
int VEHICLE_PARK(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID);
void TEST_GO_DOWN(Liste* file, int ** Collider_map, int ID);
void BALISE(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char ** map, int ID, int heure_de_pointe);
int FIND_DIRECTION(Liste* file, int ID);
void UPDATE(int MaxY, int MaxX, Liste * file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int** draw_map, int heure_de_pointe);
void INIT_UPDATE(int MaxY, int MaxX, int cpt_line, int cpt_col, Liste * file, int** Collider_map, char** map, int** draw_map, int fluid_heavy, int heure_de_pointe);
void SIMULATION(int MaxY, int MaxX, char** map, int ** Collider_map, int ** draw_map, Liste* file, int cpt_line, int cpt_col);
void HOME_PAGE(int MaxY, int MaxX);
void MAIN_MENU(int MaxY, int MaxX, int cpt_line, int cpt_col, char** map, int** Collider_map, int** draw_map);
void LANCEMENT_JEU();

