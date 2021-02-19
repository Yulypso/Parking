							/************************* Projet C - Parking *************************/
							/* ESIEA L3 Semestre 1 	-  année 2019/2020  -  Classe 34 			  */
							/* Groupe binome : Thierry KHAMPHOUSONE -  Amine TALEB 				  */
							/**********************************************************************/


/************************* Librairies *************************/
#include "main.h"


/************************* Tableaux statiques des coordonnées des places de parking voiture et bus *************************/
/************************* Numéro de place en fonction de l'indice du tableau pour les coordonnées Y et X *************************/
int car_place_Y[49]={27,24,21,18,15,12,9,27,27,24,24,21,21,18,18,15,15,12,12,9,9,27,27,24,24,21,21,18,18,15,15,12,12,9,9,27,27,24,24,21,21,18,18,15,15,12,12,9,9};
int car_place_X[49]={163,163,163,163,163,163,163,162,139,162,139,162,139,162,139,162,139,162,139,162,139,138,115,138,115,138,115,138,115,138,115,138,115,138,115,114,91,114,91,114,91,114,91,114,91,114,91,114,91};
int bus_place_Y[25]={25,25,21,21,17,17,13,13,9,9,25,25,21,21,17,17,13,13,9,9,25,21,17,13,9};
int bus_place_X[25]={87,58,87,58,87,58,87,58,87,58,57,28,57,28,57,28,57,28,57,28,27,27,27,27,27};


/************************* Chargement des fichiers textes contenant affichages des véhicules *************************/
void LOAD_VEHICLE() 
{
	/* bullet : Utilisé lorsque la voiture rentre en collision avec une autre, elle "expolose" avant de libérer le passage */
	FILE * bul = NULL;
	bul = fopen("./bullet/bullet.txt", "r");
	if(bul == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "bullet.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(bul);

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<5; j++)
		{
			bullet[i][j]= fgetc(bul);
		}
	}
	fclose(bul);

	/* car_left */
	FILE * cl = NULL;
	cl = fopen("./car/car_left.txt", "r");
	if(cl == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "car_left.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(cl);

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<5; j++)
		{
			car_left[i][j]= fgetc(cl);
		}
	}
	fclose(cl);

	/* car_right */
	FILE * cr = NULL;
	cr = fopen("./car/car_right.txt", "r");
	if(cr == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "car_right.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(cr);

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<5; j++)
		{
			car_right[i][j]= fgetc(cr);
		}
	}
	fclose(cr);

	/* car_up */
	FILE * cu = NULL;
	cu = fopen("./car/car_up.txt", "r");
	if(cu == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "car_up.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(cu);

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			car_up[i][j]= fgetc(cu);
		}
	}
	fclose(cu);

	/* car_down */
	FILE * cd = NULL;
	cd = fopen("./car/car_down.txt", "r");
	if(cd == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "car_down.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(cd);

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			car_down[i][j]= fgetc(cd);
		}
	}
	fclose(cd);

	/* bus_left */
	FILE * bl = NULL;
	bl = fopen("./bus/bus_left.txt", "r");
	if(bl == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "bus_left.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(bl);

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<7; j++)
		{
			bus_left[i][j]= fgetc(bl);
		}
	}
	fclose(bl);

	/* bus_right */
	FILE * br = NULL;
	br = fopen("./bus/bus_right.txt", "r");
	if(br == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "bus_right.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(br);

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<7; j++)
		{
			bus_right[i][j]= fgetc(br);
		}
	}
	fclose(br);

	/* bus_down */
	FILE * bd = NULL;
	bd = fopen("./bus/bus_down.txt", "r");
	if(bd == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "bus_down.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(bd);

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<6; j++)
		{
			bus_down[i][j]= fgetc(bd);
		}
	}
	fclose(bd);


	/* bus_bup */
	FILE * bup = NULL;
	bup = fopen("./bus/bus_up.txt", "r");
	if(bup == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier : %s ", "bus_up.txt");
		endwin();
		exit(EXIT_FAILURE);
	}
	rewind(bup);

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<6; j++)
		{
			bus_bup[i][j]= fgetc(bup);
		}
	}
	fclose(bup);
}


/************************* Initialisation du tableau d'ID : Utilisé pour donner des "plaques d'immatriculations" *************************/
/************************* aux voitures circulants dans la map. (Limitation à 100 voitures en circulation sur la map en même temps) *************************/
void Init_ID_TAB(int ID_TAB[100])
{
	for(int i=0; i<100; i++)
	{
		ID_TAB[i] = 0;
	}
}


/************************* Recherche d'une "plaque d'immatriculation" ID parmi les 100 proposées. Si on trouve une ID disponible *************************/
/************************* on la rend indisponible et on la retourne pour l'attribuer au véhicule *************************/
int Search_ADD_ID(int ID_TAB[100])
{
	int cpt = 0;
	int ID = -1;

	for(int i=0; i<100; i++)
	{
		if(ID_TAB[i] == 0)
		{
			ID = i;
			ID_TAB[i]=1; //on ajoute un ID à un vehicule
			return ID;
		}
		else
		{
			cpt++;
			if(cpt == 100)
				return -1; //plus d'ID possible, nombre de véhicule maximum
		}
	}
	return ID;
}


/************************* Retrait de la "plaque d'immatriculation" ID parmi les 100 proposées. L'ID est alors de nouveau disponible *************************/
/************************* Utilisation de cette fonction lorsqu'une voiture quitte la map *************************/
int Search_REMOVE_ID(int ID_TAB[100], int ID)
{
	ID_TAB[ID]=0; //on libere un ID dans le tableau des ID
	return ID;
}


/************************* Initialisation d'une file de type Liste* permettant de créer une liste de voiture *************************/
Liste* initfile(Liste* file)
{
	file = malloc(1*sizeof(file));
	file->premier = NULL;
	return file;
}


/************************* Ajout et initialisation de voiture/bus dans la file *************************/
void enfiler(Liste* file, int cpt_line, int cpt_col, int** Collider_map, char** map, int type, int direction, int y, int x, int ID) //type = 0 : voiture / = 1 : bus // direction == 0 : gauche // (y,x) fixé car départ toujours au meme endroit
{
	srand(time(NULL)); //permet d'obtenir un "vrai hasard" et non toujours le même à chaque démarrage du programme
	int TRESLONG = rand()%12; //variable permettant de choisir un temps de parking parmis les 12 
	int cas1=250;
	int cas2=450;
	int cas3=650;
	int cas4=850;
	int cas5=1050;
	int cas6=1250;
	int cas7=1450;
	int cas8=1650;
	int cas9=1850;
	int cas10=2050;
	int cas11=2250;
	int cas12 = 2450;

	Vehicle* nouveau = NULL; //déclaration d'un nouveau vehicule
	Vehicle* courant = NULL; //permet de se déplacer dans la liste
	nouveau = malloc(1*sizeof(Vehicle)); //allocation mémoire pour le véhicule

	nouveau->type = type; //type 0 = voiture | type 1 = bus

	nouveau->direction = direction; //direction 0 = gauche | direction 1 = haut | direction 2 = droite | direction 3 = bas 
									//direction 7 = arrêt gauche | direction 8 = arrêt haut | direction 9 = arrêt droite | direction 10 = arrêt bas
									//direction 5 = suppression voiture 
									//direction 11 = recul gauche | direction 12 = recul droite
									//direction 14 = arrêt droit (lors d'un recul) | direction 13 = arrêt gauche (lors d'un recul)
									//direction 17 = explosition de la voiture 

	nouveau->ID = ID; //attribution de l'ID

	nouveau->y = y;	//position sur l'axe verticale y

	nouveau->x = x; //position sur l'axe horizontale x

	nouveau->time_parking = 0; //temps de stationnement sur une place de parking 



	if(TRESLONG == 0)
		nouveau->time_parked = cas1; //temps de stationnement total (lorsque le temps de stationnement atteint le temps de stationnement total, la voiture sort)
	else if(TRESLONG == 1)
		nouveau->time_parked = cas2;
	else if(TRESLONG == 2)
		nouveau->time_parked = cas3;
	else if(TRESLONG == 3)
		nouveau->time_parked = cas4;
	else if(TRESLONG == 4)
		nouveau->time_parked = cas5;
	else if(TRESLONG == 5)
		nouveau->time_parked = cas6;
	else if(TRESLONG == 6)
		nouveau->time_parked = cas7;
	else if(TRESLONG == 7)
		nouveau->time_parked = cas8;
	else if(TRESLONG == 8)
		nouveau->time_parked = cas9;
	else if(TRESLONG == 9)
		nouveau->time_parked = cas10;
	else if(TRESLONG == 10)
		nouveau->time_parked = cas11;
	else if(TRESLONG == 11)
		nouveau->time_parked = cas12;

	nouveau->state = 1; //state 1 = actif | state 0 = inactif (ne répond plus aux directions de déplacements)

	nouveau->paytime = 0; //prix à payer en fonction du temps de stationnement total

	nouveau->color = 1+rand()%7; //attribution d'une couleur parmi 7 aléatoirement 

	nouveau->time_waiting = 0;
	nouveau->time_entry = 20; //pour le temps d'attente en entrant
	nouveau->time_exit = 40; //pour le temps d'attente avant la sortie
	nouveau->stupid_car = 0; //0: voiture normale, 1: mode accident

	courant = file->premier; //on place le vehicule courant en tête de liste avant de parcourir la liste

	if(file->premier == NULL)
	{
		file->premier =	nouveau;
	}
	else
	{
		while(courant->suivant != NULL)
		{
			courant = courant->suivant;
		}
		courant->suivant = nouveau; //ajout du nouveau véhicule dans la liste
	}
		nouveau->suivant = NULL;

	EDIT_COLLIDER_MAP(nouveau->y, nouveau->x, nouveau->direction, nouveau->type, cpt_line, cpt_col, Collider_map, map);
}


/************************* Retire le véhicule correspondant à tel ID de la liste *************************/
void retirer(Liste * file, int ID) //en paramètre, on a l'ID à retirer
{
	Vehicle* courant = NULL;
	Vehicle* av_courant = NULL;
	courant = file->premier;

	if(courant->ID == ID)
	{
		file->premier = courant->suivant;
		free(courant);
		ID_TAB[courant->ID]=0;
	}
	else
	{
		courant=courant->suivant;
		av_courant=file->premier;

		while(courant != NULL && courant->ID != ID)
		{ 
			av_courant = av_courant->suivant;
			courant = courant->suivant;
		}

		if(courant->ID == ID) //on cherche parmi la liste, le vehicule a retirer, si on le trouve on libère la mémoire et on libère l'ID
		{
			av_courant->suivant = courant->suivant;
			free(courant);
			ID_TAB[courant->ID] = 0;
		}
	}
}


/************************* après avoir press 'q' en cours de simulation, cette fonction permet une animation et de free la map et la file*************************/
void EXIT_MENU(int MaxY, int MaxX, int cpt_line, int cpt_col, Liste* file, char** map, int** Collider_map, int** draw_map) 
{
	int i = 1;
	while(i!=0)
	{
		clear();
		STARS(MaxY, MaxX);
		refresh();
		i++;
		if(i==3000)
		{
			i=0;
		}
	}

	for(int a=0; a<cpt_line; a++)
	{
		free(map[a]);
	}
	free(map);

	free(file);
	MAIN_MENU(MaxY, MaxX);
}



/************************* Affichage des boutons en jeu *************************/
/************************* q : quitter *************************/
/************************* h : heure de pointe : permet de faire rentrer plus de voitures dans le parking (plus de chance)*************************/
/************************* g : non heure de pointe : permet de faire rentrer moins de voitures dans le parking (moins de chance) *************************/
void DISPLAY_BUTTON(int MaxY, int MaxX, int heure_de_pointe, int fluid_heavy, int instant_accident) 
{
	int i,j;

	/************************* Box exit *************************/
	for(i=0 ; i<=MaxY ; i++)					
	{
		attron(COLOR_PAIR(1)); 
  		mvprintw(MaxY-4, MaxX-23,"q: exit");
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-5 && j==MaxX-30)
			{
				move(MaxY-5, MaxX-30);
				addch(ACS_ULCORNER);
			}	
			if(i==MaxY-5 && j>MaxX-29 && j<MaxX-7)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-5 && j==MaxX-8)
			{
				mvaddch(MaxY-5, MaxX-8, ACS_URCORNER);
			}
		}
		for(j=0 ; j<=MaxX ; j++)				
		{	
			if(i==MaxY-4 && j==MaxX-30)
			{
				move(MaxY-4,MaxX-30);
				addch(ACS_VLINE);
			}
			if(i==MaxY-4 && j==MaxX-8)
			{
				mvaddch(MaxY-4, MaxX-8, ACS_VLINE);
			}
		}
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-3 && j==MaxX-30)
			{
				move(MaxY-3, MaxX-30);
				addch(ACS_LLCORNER);
			}
			if(i==MaxY-3 && j>MaxX-29 && j<MaxX-7)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-3 && j==MaxX-8)
			{	
				mvaddch(MaxY-3,MaxX-8,ACS_LRCORNER);
			}
		}
		attroff(COLOR_PAIR(1));
	}

	/************************* heure de pointe *************************/
	for(i=0 ; i<=MaxY ; i++)					
	{
		if(heure_de_pointe == 0)
		{
			attron(COLOR_PAIR(5));
		}
   		mvprintw(MaxY-4, MaxX-60,"g: heure_pointe=OFF");
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-5 && j==MaxX-62)
			{
				move(MaxY-5, MaxX-62);
				addch(ACS_ULCORNER);
			}	
			if(i==MaxY-5 && j>MaxX-61 && j<MaxX-39)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-5 && j==MaxX-40)
			{
				mvaddch(MaxY-5, MaxX-40, ACS_URCORNER);
			}
		}
		for(j=0 ; j<=MaxX ; j++)				
		{	
			if(i==MaxY-4 && j==MaxX-62)
			{
				move(MaxY-4,MaxX-62);
				addch(ACS_VLINE);
			}
			if(i==MaxY-4 && j==MaxX-40)
			{
				mvaddch(MaxY-4, MaxX-40, ACS_VLINE);
			}
		}
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-3 && j==MaxX-62)
			{
				move(MaxY-3, MaxX-62);
				addch(ACS_LLCORNER);
			}
			if(i==MaxY-3 && j>MaxX-61 && j<MaxX-39)
			{
				addch(ACS_HLINE);
			}
		
			if(i==MaxY-3 && j==MaxX-40)
			{	
				mvaddch(MaxY-3,MaxX-40,ACS_LRCORNER);
			}
		}
		if(heure_de_pointe == 0)
		{
			attroff(COLOR_PAIR(2));
		}
	}
	
	/************************* non heure de pointe *************************/
	for(i=0 ; i<=MaxY ; i++)					
	{
		if(heure_de_pointe == 1)
		{
			attron(COLOR_PAIR(5));
		}
	    mvprintw(MaxY-4, MaxX-91,"h: heure_pointe=ON");
		for(j=0 ; j<=MaxX ; j++)
		{	
			if(i==MaxY-5 && j==MaxX-94)
			{
				move(MaxY-5, MaxX-94);
				addch(ACS_ULCORNER);
			}	
			if(i==MaxY-5 && j>MaxX-93 && j<MaxX-71)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-5 && j==MaxX-72)
			{
				mvaddch(MaxY-5, MaxX-72, ACS_URCORNER);
			}
		}
		for(j=0 ; j<=MaxX ; j++)				
		{		
			if(i==MaxY-4 && j==MaxX-94)
			{
				move(MaxY-4,MaxX-94);
				addch(ACS_VLINE);
			}	
			if(i==MaxY-4 && j==MaxX-72)
			{
				mvaddch(MaxY-4, MaxX-72, ACS_VLINE);
			}
		}
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-3 && j==MaxX-94)
			{
				move(MaxY-3, MaxX-94);
				addch(ACS_LLCORNER);
			}	
			if(i==MaxY-3 && j>MaxX-93 && j<MaxX-71)
			{
				addch(ACS_HLINE);
			}	
			if(i==MaxY-3 && j==MaxX-72)
			{	
				mvaddch(MaxY-3,MaxX-72,ACS_LRCORNER);
			}
		}
		if(heure_de_pointe == 1)
		{
			attroff(COLOR_PAIR(5));
		}
	}

	/************************* accident instantanné *************************/
	/************************* permet de faire déplacer une voiture depuis l'entrée en contre-sens vers la gauche *************************/
	if(fluid_heavy == 1)
	{
		for(i=0 ; i<=MaxY ; i++)					
		{
			if(instant_accident == 1)
			{
				attron(COLOR_PAIR(6));
			}
	   		mvprintw(MaxY-4, MaxX-124,"f: inst_accident=ON");
			for(j=0 ; j<=MaxX ; j++)
			{	
				if(i==MaxY-5 && j==MaxX-126)
				{
					move(MaxY-5, MaxX-126);
					addch(ACS_ULCORNER);
				}	
				if(i==MaxY-5 && j>MaxX-125 && j<MaxX-103)
				{
					addch(ACS_HLINE);
				}
				if(i==MaxY-5 && j==MaxX-104)
				{
					mvaddch(MaxY-5, MaxX-104, ACS_URCORNER);
				}
			}
			for(j=0 ; j<=MaxX ; j++)				
			{		
				if(i==MaxY-4 && j==MaxX-126)
				{
					move(MaxY-4,MaxX-126);
					addch(ACS_VLINE);
				}	
				if(i==MaxY-4 && j==MaxX-104)
				{
					mvaddch(MaxY-4, MaxX-104, ACS_VLINE);
				}
			}
			for(j=0 ; j<=MaxX ; j++)
			{
				if(i==MaxY-3 && j==MaxX-126)
				{
					move(MaxY-3, MaxX-126);
					addch(ACS_LLCORNER);
				}	
				if(i==MaxY-3 && j>MaxX-125 && j<MaxX-103)
				{
					addch(ACS_HLINE);
				}	
				if(i==MaxY-3 && j==MaxX-104)
				{	
					mvaddch(MaxY-3,MaxX-104,ACS_LRCORNER);
				}
			}
			if(instant_accident == 1)
			{
				attroff(COLOR_PAIR(6));
			}
		}


		/************************* non accident instantannée *************************/

		for(i=0 ; i<=MaxY ; i++)					
		{
			if(instant_accident == 0)
			{
				attron(COLOR_PAIR(6));
			}
	  		mvprintw(MaxY-4, MaxX-156,"d: inst_accident=OFF");
			for(j=0 ; j<=MaxX ; j++)
			{	
				if(i==MaxY-5 && j==MaxX-158)
				{
					move(MaxY-5, MaxX-158);
					addch(ACS_ULCORNER);
				}	
				if(i==MaxY-5 && j>MaxX-157 && j<MaxX-135)
				{
					addch(ACS_HLINE);
				}
				if(i==MaxY-5 && j==MaxX-136)
				{
					mvaddch(MaxY-5, MaxX-136, ACS_URCORNER);
				}
			}
			for(j=0 ; j<=MaxX ; j++)				
			{		
				if(i==MaxY-4 && j==MaxX-158)
				{
					move(MaxY-4,MaxX-158);
					addch(ACS_VLINE);
				}	
				if(i==MaxY-4 && j==MaxX-136)
				{
					mvaddch(MaxY-4, MaxX-136, ACS_VLINE);
				}
			}
			for(j=0 ; j<=MaxX ; j++)
			{
				if(i==MaxY-3 && j==MaxX-158)
				{
					move(MaxY-3, MaxX-158);
					addch(ACS_LLCORNER);
				}	
				if(i==MaxY-3 && j>MaxX-157 && j<MaxX-135)
				{
					addch(ACS_HLINE);
				}	
				if(i==MaxY-3 && j==MaxX-136)
				{	
					mvaddch(MaxY-3,MaxX-136,ACS_LRCORNER);
				}
			}
			if(instant_accident == 0)
			{
				attroff(COLOR_PAIR(6));
			}
		}
	}
}	


/************************* Affichage des boutons choix du mode fluide ou chargé *************************/
void DISPLAY_START(int MaxY, int MaxX) 
{
	int i,j;
	/************************* bouton mode fluide *************************/
	for(i=0 ; i<=MaxY ; i++)					
	{
 	    mvprintw(MaxY-4, MaxX-27,"START FLUID MODE");
		for(j=0 ; j<=MaxX ; j++)
		{	
			if(i==MaxY-5 && j==MaxX-30)
			{
				move(MaxY-5, MaxX-30);
				addch(ACS_ULCORNER);
			}	
			if(i==MaxY-5 && j>MaxX-29 && j<MaxX-7)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-5 && j==MaxX-8)
			{
				mvaddch(MaxY-5, MaxX-8, ACS_URCORNER);
			}
		}
		for(j=0 ; j<=MaxX ; j++)				
		{	
			if(i==MaxY-4 && j==MaxX-30)
			{
				move(MaxY-4,MaxX-30);
				addch(ACS_VLINE);
			}
			if(i==MaxY-4 && j==MaxX-8)
			{
				mvaddch(MaxY-4, MaxX-8, ACS_VLINE);
			}
		}
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-3 && j==MaxX-30)
			{
				move(MaxY-3, MaxX-30);
				addch(ACS_LLCORNER);
			}
			if(i==MaxY-3 && j>MaxX-29 && j<MaxX-7)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-3 && j==MaxX-8)
			{	
				mvaddch(MaxY-3,MaxX-8,ACS_LRCORNER);
			}
		}
	}

	/************************* bouton mode chargé *************************/
	for(i=0 ; i<=MaxY ; i++)					
	{
    	mvprintw(MaxY-4, MaxX-59,"START HEAVY MODE");
		for(j=0 ; j<=MaxX ; j++)
		{	
			if(i==MaxY-5 && j==MaxX-62)
			{
				move(MaxY-5, MaxX-62);
				addch(ACS_ULCORNER);
			}	
			if(i==MaxY-5 && j>MaxX-61 && j<MaxX-39)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-5 && j==MaxX-40)
			{
				mvaddch(MaxY-5, MaxX-40, ACS_URCORNER);
			}
		}
		for(j=0 ; j<=MaxX ; j++)				
		{	
			if(i==MaxY-4 && j==MaxX-62)
			{
				move(MaxY-4,MaxX-62);
				addch(ACS_VLINE);
			}
			if(i==MaxY-4 && j==MaxX-40)
			{
				mvaddch(MaxY-4, MaxX-40, ACS_VLINE);
			}
		}
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY-3 && j==MaxX-62)
			{
				move(MaxY-3, MaxX-62);
				addch(ACS_LLCORNER);
			}
			if(i==MaxY-3 && j>MaxX-61 && j<MaxX-39)
			{
				addch(ACS_HLINE);
			}
			if(i==MaxY-3 && j==MaxX-40)
			{	
				mvaddch(MaxY-3,MaxX-40,ACS_LRCORNER);
			}
		}
	}
}


/************************* fonction permettant de convertir un char c en un caractère ncurses  *************************/
/************************* (ajout direct du caractère sur le terminal ncurses) *************************/
void SYMBOL_CONVERTER(char c)
{
	if(c == 'q')
		addch(ACS_ULCORNER);
	else if(c == 's')
		addch(ACS_LLCORNER);
	else if(c == 'd')
		addch(ACS_URCORNER);
	else if(c == 'f')
		addch(ACS_LRCORNER);
	else if(c == 'g')
		addch(ACS_LTEE);
	else if(c == 'h')
		addch(ACS_RTEE);
	else if(c == 'j')
		addch(ACS_BTEE);
	else if(c == 'k')
		addch(ACS_TTEE);
	else if(c == 'l')
		addch(ACS_HLINE);
	else if(c == 'w')
		addch(ACS_VLINE);
	else if(c == 'p')
		addch(ACS_PLUS);
	else if(c == 'M')
		addch(ACS_CKBOARD);
	else if(c == 'Z')
		addch(ACS_CKBOARD);
	else if(c == '$')
		addch(ACS_DIAMOND);
	else if(c == 'd')
		printw(" ");
	else
		printw("%c", c);
}


/************************* fonction qui retourne la taille en ligne et en colonne d'un fichier en paramètre *************************/
int SIZE_FILE(char* file_name, int line_or_col) //0: obtenir la valeur en ligne | 1: obtenir la valeur en colonne
{
	FILE * fic = fopen(file_name,"r");
	fseek(fic, 0, SEEK_SET); 
	int courant = 0;
	int cpt_col = 0;
	int cpt_line = 0;

	while((courant = fgetc(fic))!=EOF)
	{
		if(cpt_line == 0)
		{
			cpt_col++;
		}
		if(courant == '\n')
		{
			cpt_line++;
		}
	}
	fclose(fic);

	if(line_or_col == 0)
	{
		return cpt_line;
	}
	else if(line_or_col == 1)
	{
		return cpt_col;
	}
	return -1;
}


/************************* Permet de modifier la map de collision et l'affichage du terminal ncurses *************************/
/************************* Fonction utilisée à chaque déplacement pour mettre a jour l'affichage courant de la voiture/bus *************************/
/************************* et pour supprimer l'affichage précédent en remplacant par des caractères vides et des 0  *************************/
void EDIT_COLLIDER_MAP(int VehicleY, int VehicleX, int direction, int type, int cpt_line, int cpt_col, int ** Collider_map, char **map)
{
	if(type == 0) //type 0 : voiture
	{
		for(int i=0; i<cpt_line; i++) //on parcours toute la map entièrement
		{
			for(int j=0; j<cpt_col; j++)
			{
				if(VehicleY == i && VehicleX == j) //à la recherche de la position d'un véhicule 
				{
					if(direction == 0 || direction == 7) //déplacement gauche || arrêt gauche (voiture positionnée vers la gauche)
					{	
						for(int k=0; k<2; k++)
						{
							for(int l=0; l<4; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; //on ajoute 2 pour spécifier l'emplacement de la voiture sur la map de collision
								map[i+k][j+l] = car_left[k][l]; //on affiche l'affichage de la voiture gauche

								/* pour effacer à t+1 */
								Collider_map[i+k][j+4] = 0; //la voiture a avancé, on supprime son emplacement précédent (sa trace) sur la map de collision
								map[i+k][j+4] = ' '; //de même, on efface sur l'affichage terminal ncurses
							}
						}
					}

					if(direction == 17) //explosion voiture
					{	
						for(int k=0; k<2; k++)
						{
							for(int l=0; l<4; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bullet[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j+4] = 0; 
								map[i+k][j+4] = ' ';
							}
						}
						refresh();
					}

					if(direction == 12 || direction == 14)
					{
						for(int k=0; k<2; k++)
						{
							for(int l=0; l<4; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = car_right[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j+4] = 0; 
								map[i+k][j+4] = ' ';
							}
						}
					}

					if(direction == 1 || direction == 8) 
					{
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<3; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = car_up[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+3][j+l] = 0; 
								map[i+3][j+l] = ' ';
							}
						}
					}

					if(direction == 2 || direction == 9) 
					{
						for(int k=0; k<2; k++)
						{
							for(int l=0; l<4; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = car_right[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j-1] = 0; 
								map[i+k][j-1] = ' ';

							}
						}
					}

					if(direction == 11 || direction == 13)
					{
						for(int k=0; k<2; k++)
						{
							for(int l=0; l<4; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = car_left[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j-1] = 0; 
								map[i+k][j-1] = ' ';

							}
						}
					}

					if(direction == 3 || direction == 10)
					{
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<3; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = car_down[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i-1][j+l] = 0; 
								map[i-1][j+l] = ' ';
							}
						}
					}

					if(direction == 5) 
					{
						for(int k=0; k<2; k++)
						{
							for(int l=0; l<4; l++)
							{
								/* pour effacer à t */
								Collider_map[i+k][j+l] = 0; 
								map[i+k][j+l] = ' '; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j+4] = 0; 
								map[i+k][j+4] = ' ';
							}
						}
					}	
				}
			}
		}
	}
	/************************* de même pour le type de véhicule bus *************************/
	else if(type == 1) //type 1 = bus 
	{
		for(int i=0; i<cpt_line; i++)
		{
			for(int j=0; j<cpt_col; j++)
			{
				if(VehicleY == i && VehicleX == j)
				{
					if(direction == 0 || direction == 7) 
					{	
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<6; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bus_left[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j+6] = 0; 
								map[i+k][j+6] = ' ';
							}
						}
					}

					if(direction == 12 || direction == 14)
					{
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<6; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bus_right[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j+6] = 0; 
								map[i+k][j+6] = ' ';
							}
						}
					}

					if(direction == 1 || direction == 8)
					{
						for(int k=0; k<4; k++)
						{
							for(int l=0; l<5; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bus_bup[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+4][j+l] = 0; 
								map[i+4][j+l] = ' ';
							}
						}
					}

					if(direction == 2 || direction == 9) 
					{
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<6; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bus_right[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j-1] = 0; 
								map[i+k][j-1] = ' ';

							}
						}
					}

					if(direction == 11 || direction == 13)
					{
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<6; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bus_left[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j-1] = 0; 
								map[i+k][j-1] = ' ';

							}
						}
					}

					if(direction == 3 || direction == 10) 
					{
						for(int k=0; k<4; k++)
						{
							for(int l=0; l<5; l++)
							{
								/* pour ecrire à t */
								Collider_map[i+k][j+l] = 2; 
								map[i+k][j+l] = bus_down[k][l]; 

								/* pour effacer à t+1 */
								Collider_map[i-1][j+l] = 0; 
								map[i-1][j+l] = ' ';
							}
						}
					}

					if(direction == 5) 
					{
						for(int k=0; k<3; k++)
						{
							for(int l=0; l<6; l++)
							{
								/* pour effacer à t */
								Collider_map[i+k][j+l] = 0; 
								map[i+k][j+l] = ' '; 

								/* pour effacer à t+1 */
								Collider_map[i+k][j+6] = 0; 
								map[i+k][j+6] = ' ';
							}
						}
					}
				}
			}
		}
	}
}


/************************* Permet d'afficher la map de collision (utile uniquement lors du developpement) *************************/
void DISPLAY_COLLIDER_MAP(int cpt_line, int cpt_col, int ** Collider_map)
{
	move(0,0);
	for(int i=0; i<cpt_line; i++)
	{
		for(int j=0; j<cpt_col-1; j++)
		{
			printw("%d", Collider_map[i][j]);
		}
		printw("\n");
	}
}


/************************* Permet d'afficher la map *************************/
void DISPLAY_MAP(Liste* file, int cpt_line, int cpt_col, char **map, int start, int** draw_map)
{
	char c;
	Vehicle* courant = NULL;
	courant = file->premier;
	FILL_DRAW_MATRICE(cpt_line, cpt_col, draw_map); //initialisation de la matrice draw_map

	if(courant == NULL && courant == file->premier && start == 1) //start 1: permet l'affichage de la map avant le lancement d'un mode fluide/chargé (pas de voiture au début)
	{
		for(int a=0; a<cpt_line; a++)
		{
			for(int b=0; b<cpt_col; b++)
			{
				c = map[a][b]; //on parcours toute la map et on récupere le caractère associé aux indices de la map
				move(a,b); //on se déplace à la même position sur le terminal
				SYMBOL_CONVERTER(c); //on convertis le caracère récupéré en caractère ncurses
			}
		}
	}
	

	/************************* affichage des caractères à une position courante sur la map *************************/
	//De même, on parcours toute la map 
	for(int a=0; a<cpt_line; a++)
	{
		for(int b=0; b<cpt_col; b++)
		{
			while(courant != NULL) //tant qu'on n'a pas encore parcouru toute la liste des véhicules
			{   


				/************************* affichage des véhicules à une position courante sur la map *************************/
			    //si en parcourant la map on tombe sur les coordonnées de la position d'un véhicule et qu'on n'a pas encore affiché le caractère courant
				if(a == courant->y && b == courant->x && draw_map[a][b] ==0) 
				{
					//ces directions correspondent à un déplacement horizontal du véhicule sur la carte 
					if(courant->direction == 0 || courant->direction == 7 || courant->direction == 2 || 
					   courant->direction == 9 || courant->direction == 5 || courant->direction == 6 || 
					   courant->direction == 11 || courant->direction == 12 || courant->direction == 13 || courant->direction == 14)
					{
						if(courant->type == 0) //si c'est une voiture 
						{						
							for(int e=0; e<2; e++) //taille de la voiture en verticale
							{
								for(int d=0; d<4; d++) //taille de la voiture en horizontale
								{
									c=map[a+e][b+d]; //on récupère le caractère associé à toute la voiture 
									draw_map[a+e][b+d] = 1; //on spécifie sur la draw_map qu'on a déjà affiché la case (on n'affiche pas dans l'ordre de a et b de la boucle for)
									attron(COLOR_PAIR(courant->color)); //on ajoute la couleur associé à la couleur dans la structure de la voiture
									move(a+e,b+d); //on se déplace sur le terminal ncurses à la position du caractère à afficher
									SYMBOL_CONVERTER(c); //convertissage du caractère et affichage
									attroff(COLOR_PAIR(courant->color));
								}
							}
						}
						else if(courant->type == 1) //si c'est un bus : de même 
						{
							for(int e=0; e<3; e++)
							{
								for(int d=0; d<6; d++)
								{
									c=map[a+e][b+d];
									draw_map[a+e][b+d] = 1;
									attron(COLOR_PAIR(courant->color));
									move(a+e,b+d);
									SYMBOL_CONVERTER(c);
									attroff(COLOR_PAIR(courant->color));
								}
							}
						}
					}
					else if(courant->direction == 1 || courant->direction == 8 || courant->direction == 3 || courant->direction == 10)
					{
						//ces directions correspondent à un déplacement vertical du véhicule sur la carte
						if(courant->type == 0)
						{
							for(int f=0; f<3; f++)
							{
								for(int g=0; g<3; g++)
								{
									c=map[a+f][b+g];
									draw_map[a+f][b+g] = 1;
									attron(COLOR_PAIR(courant->color));
									move(a+f,b+g);
									SYMBOL_CONVERTER(c);
									attroff(COLOR_PAIR(courant->color));
								}
							}
						}
						else if(courant->type == 1)
						{
							for(int f=0; f<4; f++)
							{
								for(int g=0; g<5; g++)
								{
									c=map[a+f][b+g];
									draw_map[a+f][b+g] = 1;
									attron(COLOR_PAIR(courant->color));
									move(a+f,b+g);
									SYMBOL_CONVERTER(c);
									attroff(COLOR_PAIR(courant->color));
								}
							}
						}
					}
				}


				/************************* affichage des objets à une position courante sur la map *************************/
				else if(a != courant->y && b != courant->x && draw_map[a][b] == 0 && courant->suivant == NULL)
				{
					c=map[a][b];
					draw_map[a][b]=1;
					move(a,b);
					if(c != 'M') //correspond aux affichages lumineux vert/rouge des places de parking dans map.txt
					{
						/************************* affichage des bornes d'entrée en couleur à une position courante sur la map *************************/
						if(c =='Z') //correspond aux bornes sur la map.txt
						{
							attron(COLOR_PAIR(4));
							SYMBOL_CONVERTER(c); 
							attroff(COLOR_PAIR(4));	
						}
						/************************* affichage des particules d'une voiture explosion à une position courante sur la map *************************/
						else if(c =='*') //correspond aux particules de la voiture accidentée dans bullet.txt
						{
							attron(COLOR_PAIR(4));
							SYMBOL_CONVERTER(c); 
							attroff(COLOR_PAIR(4));	
						}
						/************************* affichage des autres caractères (vide) à une position courante sur la map *************************/
						else
						{
							SYMBOL_CONVERTER(c);
						}
					}
					else
					{
						for(int i=0; i<25; i++) //parcours de toutes les places de parkings pour les bus
						{
							if(a == bus_place_Y[i] && b == bus_place_X[i]) //si on atteint les coordonnées d'une place (Y,X)
							{
								if(bus_place[i]==1) //si la place de bus est occupée, on l'affiche en rouge 
								{
									//étant donnée que l'affichage lumineux pour les bus est de taille 3 en vertical
									attron(COLOR_PAIR(1));
									SYMBOL_CONVERTER(c); //on converti et affiche le caractère (1er de l'affichage lumineux)
									c=map[a+1][b]; //on se déplace dans la map verticalement pour afficher le caractere central de l'affichage lumineux
									move(a+1,b);
									SYMBOL_CONVERTER(c); 
									draw_map[a+1][b]=1;
									c=map[a+2][b]; //une seconde fois pour le dernier caractère de l'affichage lumineux
									move(a+2,b);
									SYMBOL_CONVERTER(c); 
									draw_map[a+2][b]=1; //on spécifie qu'on a bien déjà affiché cette case sur le terminal ncurses 
									attroff(COLOR_PAIR(1));
								}
								else if(bus_place[i]==0) //si la place de bus est libre, on l'affiche en vert
								{
									attron(COLOR_PAIR(3));
									SYMBOL_CONVERTER(c); 
									c=map[a+1][b];
									move(a+1,b);
									SYMBOL_CONVERTER(c); 
									draw_map[a+1][b]=1;
									c=map[a+2][b];
									move(a+2,b);
									SYMBOL_CONVERTER(c); 
									draw_map[a+2][b]=1;
									attroff(COLOR_PAIR(3));
								}
							}
						}

						for(int i=0; i<49; i++) //parcours de toutes les places de parkings pour les voitures 
						{
							if(a == car_place_Y[i] && b == car_place_X[i])
							{
								if(car_place[i]==1)
								{
									attron(COLOR_PAIR(1));
									SYMBOL_CONVERTER(c); 
									c=map[a+1][b];
									move(a+1,b);
									SYMBOL_CONVERTER(c); 
									draw_map[a+1][b]=1;
									attroff(COLOR_PAIR(1));
								}
								else if(car_place[i]==0)
								{
									attron(COLOR_PAIR(3));
									SYMBOL_CONVERTER(c); 
									c=map[a+1][b];
									move(a+1,b);
									SYMBOL_CONVERTER(c); 
									draw_map[a+1][b]=1;
									attroff(COLOR_PAIR(3));
								}
							}
						}
					}
				}
				courant = courant->suivant; 
			}
			courant = file->premier;
		}
	}	
}


/************************* remplissage et initialisation de la collider map *************************/
void FILL_COLLIDER_MATRICE(int cpt_line, int cpt_col, char** Map, int ** Collider_map)
{
	for(int i=0; i<cpt_line; i++)
	{
		for(int j=0; j<cpt_col; j++)
		{
			if(Map[i][j] != '\n')
			{
				if(Map[i][j] == ' ')
					Collider_map[i][j] = 0; //emplacement vide

				else if(Map[i][j] != ' ')
					Collider_map[i][j] = 1; //emplacement d'un mur	
			}
		}
	}
}


/************************* remplissage et initialisation de la map *************************/
void FILL_MAP_MATRICE(int cpt_line, int cpt_col, char* file_name, char **map)
{
	FILE * fic = fopen(file_name,"r");
	fseek(fic, 0, SEEK_SET); //remise au début du fichier

	//remplissage de la matrice
	for(int j=0; j<cpt_line; j++)
	{
		for(int k=0; k<cpt_col; k++)
		{
			map[j][k] = fgetc(fic);
		}	
	}
	fclose(fic);
}


/************************* modification des coordonnées pour se déplacer à droite et modification affichage *************************/
int VEHICLE_GO_RIGHT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			courant->x = (courant->x)+1;
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}


/************************* modification des coordonnées pour se déplacer à gauche en reculant et modification affichage *************************/
int VEHICLE_GO_BACK_LEFT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			courant->x = (courant->x)+1;
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}

/************************* modification des coordonnées pour se déplacer à gauche et modification affichage *************************/
int VEHICLE_GO_LEFT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			courant->x = (courant->x)-1;
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}


/************************* modification des coordonnées pour se déplacer à droite en reculant et modification affichage *************************/
int VEHICLE_GO_BACK_RIGHT(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			courant->x = (courant->x)-1;
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}


/************************* modification des coordonnées pour se déplacer en haut et modification affichage *************************/
int VEHICLE_GO_UP(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			courant->y = (courant->y)-1;
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}


/************************* modification des coordonnées pour se déplacer en bas et modification affichage *************************/
int VEHICLE_GO_DOWN(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			courant->y = (courant->y)+1;
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}

/************************* modification des coordonnées pour se garer et modification affichage *************************/
int VEHICLE_PARK(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int ID) //on donne l'ID de la voiture à déplacer
{
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			EDIT_COLLIDER_MAP(courant->y, courant->x, courant->direction, courant->type, cpt_line, cpt_col, Collider_map, map);
			return 1;
		}
		courant = courant->suivant;
	}
	return 0;
}


/************************* Emplacement de différentes balises sur la map : si une voiture atteint une balise *************************/
/************************* la voiture subi des changements d'état et se déplacera de manière différente *************************/
void BALISE(Liste* file, int cpt_line, int cpt_col, int ** Collider_map, char ** map, int ID, int heure_de_pointe, int fluid_heavy, int instant_accident)
{
	srand(time(NULL)); //definition d'un "vrai aléatoire"
	int zone = 0; //variable permettant l'aléatoire d'entrée
	Vehicle* courant = NULL;
	courant = file->premier;
	int detected = 0; //variable qui nous permet de savoir si une voiture courante a détecté un obstacle ou non

/************************* Parcours de la liste des véhicules *************************/
	while(courant != NULL) 
	{ 	
		if(courant->ID == ID)
		{
			/************************* Tests de collisions : haut *************************/
			if(courant->direction == 1 || courant->direction == 8)
			{
				if(courant->type == 0) //pour une voiture (taille plus petite)
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if((Collider_map[(courant->y)-1][(courant->x)+j] == 2)||(Collider_map[(courant->y)-2][(courant->x)+j] == 2))
							{
								detected++;
							}
						}
					}
				}
				else if(courant->type == 1) //pour un bus (taille plus grande)
				{
					for(int i=0; i<5; i++)
					{
						for(int j=0; j<4; j++)
						{
							if((Collider_map[(courant->y)-1][(courant->x)+j] == 2)||(Collider_map[(courant->y)-2][(courant->x)+j] == 2))
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->state = 0; //passage de la voiture à l'état inactif
				}
				else if(detected == 0)
				{
					courant->state = 1; //passage de la voiture à l'état actif 
				}
				detected = 0; //on remet la variable à 0
			}

			/************************* Tests de collisions : bas *************************/
			else if(courant->direction == 3 || courant->direction == 10)
			{
				if(courant->type == 0)
				{
					for(int i=0; i<3; i++)
					{	
						for(int j=0; j<3; j++)
						{
							if((Collider_map[(courant->y)+3][(courant->x)+j] == 2)||(Collider_map[(courant->y)+4][(courant->x)+j] == 2))
							{
								detected++;
							}
						}
					}
				}
				else if(courant->type == 1)
				{
					for(int i=0; i<5; i++)
					{	
						for(int j=0; j<4; j++)
						{
							if((Collider_map[(courant->y)+4][(courant->x)+j] == 2)||(Collider_map[(courant->y)+5][(courant->x)+j] == 2))
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->state = 0;
				}
				else if(detected == 0)
				{
					courant->state = 1;
				}
				detected = 0;
			}

			/************************* Tests de collisions : droite *************************/
			else if(courant->direction == 2 || courant->direction == 9 || courant->direction == 11 || courant->direction == 13)
			{
				if(courant->type == 0)
				{
					for(int i=0; i<2; i++)
					{
						for(int j=0; j<4; j++)
						{
							if((Collider_map[(courant->y)+i][(courant->x)+4] == 2)||(Collider_map[(courant->y)+i][(courant->x)+5] == 2))
							{
								detected++;
							}
						}
					}
				}
				else if(courant->type == 1)
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<6; j++)
						{
							if((Collider_map[(courant->y)+i][(courant->x)+6] == 2)||(Collider_map[(courant->y)+i][(courant->x)+7] == 2))
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->state = 0;
				}
				else if(detected == 0)
				{
					courant->state = 1;
				}
				detected = 0;
			}

			/************************* Tests de collisions : gauche *************************/
			else if(courant->direction == 0 || courant->direction == 7 || courant->direction == 12 || courant->direction ==14)
			{
				if(courant->type == 0)
				{
					for(int i=0; i<2; i++)
					{
						for(int j=0; j<4; j++)
						{
							if((Collider_map[(courant->y)+i][(courant->x)-1] == 2)||(Collider_map[(courant->y)+i][(courant->x)-2] == 2))
							{
								detected++;
							}
						}
					}
				}
				else if(courant->type == 1)
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<6; j++)
						{
							if((Collider_map[(courant->y)+i][(courant->x)-1] == 2)||(Collider_map[(courant->y)+i][(courant->x)-2] == 2))
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->state = 0;
				}
				else if(detected == 0)
				{
					courant->state = 1;
				}
				detected = 0;
			}

			if(courant->direction == 17)
			{
				courant->state=0;
			}

			/************************* Changement d'états des voitures *************************/
			if(courant->state == 0) //on désactive les voitures cela signifie qu'il y a eu une détection d'obstacle à vrai
			{
				if(courant->direction == 0) //si la direction était gauche, alors
				{
					courant->direction = 7; //la direction devient arrêt gauche

					/************************* Pour le mode collision *************************/
					/************************* une voiture "stupide" qui roule en contre-sens prend une valeur positive non nulle *************************/
					if(courant->stupid_car == 1 || courant->stupid_car == 2)
					{
						courant->direction = 0; //pour rentrer dans une voiture exprès
						courant->stupid_car++;
					}
				}

				if(courant->stupid_car >2 && courant->stupid_car <81) //permet de faire un "temps avant explosion" de la voiture
				{
						courant->stupid_car++;
				}
				if(courant->stupid_car == 40) 
				{
					system("play -q ./Sound/explosion.mp3 vol -1db&");
					courant->direction = 17; //état explositon de la voiture
					courant->stupid_car++;
				}
				if(courant->stupid_car == 80) 
				{
					courant->direction = 5; //état supression de la voiture 

					if(courant->y == 31 && courant->x == 82) 
					{
						FILL_COLLIDER_MATRICE(cpt_line, cpt_col, map, Collider_map);
						FILL_MAP_MATRICE(cpt_line, cpt_col, "map.txt", map);
					}
				}

				if(courant->direction == 1) //passage de haut à arrêt haut
					courant->direction = 8;
 
				if(courant->direction == 2) //passage de droite à arrêt droite
					courant->direction = 9;

				if(courant->direction == 3) //passage de bas à arrêt bas
					courant->direction = 10;

				if(courant->direction == 11) //passage de arrière gauche à arrêt arrière gauche
					courant->direction = 13;

				if(courant->direction == 12) //passage de arrère droit à arrêt arrière droit
					courant->direction = 14;

			}
			else if(courant->state == 1) //idem on passe de désactivé à activé 
			{
				if(courant->direction == 7)
					courant->direction = 0;

				if(courant->direction == 8)
					courant->direction = 1;

				if(courant->direction == 9)
					courant->direction = 2;

				if(courant->direction == 10)
					courant->direction = 3;

				if(courant->direction == 13)
					courant->direction = 11;

				if(courant->direction == 14)
					courant->direction = 12;
			}

			zone = rand()%6; //on ajoute une valeur aléatoire d'entrée dans le parking 


			/************************* Entrée du parking avec pas d'heure de pointe (1 chance sur 2 de rentrer) *************************/
			if(courant->y == 42 && courant->x == 141 && (zone == 0 || zone == 1 || zone == 3) && heure_de_pointe == 0)
			{
				/************************* Verification s'il y a déjà une voiture dans l'entrée avant de tourner *************************/
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<3; j++)
					{
						if(Collider_map[(courant->y)-1][(courant->x)+j] == 2 || Collider_map[(courant->y)-3][(courant->x)+j] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 7; //s'il y a une voiture, on reste à l'arret

				}
				else if(detected == 0)
				{
					if(courant->type == 0) //pour une voiture 
					{
						//on efface les traces après avancement
						Collider_map[(courant->y)][(courant->x)+3] = 0;
						map[(courant->y)][(courant->x)+3] = ' ';
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+1][(courant->x)+j] = 0;		
							map[(courant->y)+1][(courant->x)+j] = ' ';
						}
					}
					else if(courant->type == 1) //pour un bus
					{
						//on efface les traces après avancement
						for(int j=0; j<6; j++)
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;		
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
						for(int k=0; k<3; k++)
						{
							Collider_map[(courant->y)+k][(courant->x)+5] = 0;		
							map[(courant->y)+k][(courant->x)+5] = ' ';
						}
					}
					courant->y = (courant->y)-1;
					courant->direction = 1;
				}
				detected = 0; //remise à 0 de la variable detected
			}

			/************************* Entrée du parking avec pas d'heure de pointe (5 chance sur 6 de rentrer) *************************/
			else if(courant->y == 42 && courant->x == 141 && (zone == 0 || zone == 1 || zone == 3 || zone == 4 || zone == 5) && heure_de_pointe == 1)
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<3; j++)
					{
						if(Collider_map[(courant->y)-1][(courant->x)+j] == 2 || Collider_map[(courant->y)-2][(courant->x)+j] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 7;

				}
				else if(detected == 0)
				{
					if(courant->type == 0)
					{
						Collider_map[(courant->y)][(courant->x)+3] = 0;
						map[(courant->y)][(courant->x)+3] = ' ';
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+1][(courant->x)+j] = 0;		
							map[(courant->y)+1][(courant->x)+j] = ' ';
						}
					}
					else if(courant->type == 1)
					{
						for(int j=0; j<6; j++)
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;		
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
						for(int k=0; k<3; k++)
						{
							Collider_map[(courant->y)+k][(courant->x)+5] = 0;		
							map[(courant->y)+k][(courant->x)+5] = ' ';
						}
					}
					courant->y = (courant->y)-1;
					courant->direction = 1;
				}
				detected = 0;
			}

			/************************* Temps d'attente avant l'entrée du parking *************************/
			if(courant->y == 37 && courant->x == 141) //balise
			{
				courant->direction = 8;
				if(courant->time_waiting+15 == courant->time_entry) //1 temps avant pour ouvrir la barrière gauche
				{
					for(int j=0; j<3; j++)
					{
						map[(courant->y)-2][(courant->x)+j-1] = ' ';
					}
				}
				if(courant->time_waiting+5 == courant->time_entry) //1 temps avant pour ouvrir la barrièere droite
				{
					for(int j=0; j<3; j++)
					{
						map[(courant->y)-2][(courant->x)+j+4] = ' ';
					}
				}
				if(courant->time_waiting == courant->time_entry) //lorsque le véhicule a attendu suffisemment, on la fait entrer
				{
					courant->direction = 1;
				}
				else if(courant->time_waiting < courant->time_entry) //sinon le véhicule attend encore
				{
					courant->time_waiting++;
				}
			}

			
			/************************* Test avant d'avancer, si une voiture arrive par la gauche, on la cède, sinon on monte *************************/
			if(courant->y == 36 && courant->x == 141) //balise
			{
				for(int i=0; i<4; i++)
				{
					for(int j=0; j<9; j++)
					{
						if(Collider_map[(courant->y)+i-5][(courant->x)+j-5] == 2)
						{
							detected++;
						}
					}
				}
				for(int a=0; a<4; a++)
				{
					for(int b=0; b<4; b++)
					{
						if(Collider_map[(courant->y)+a-10][(courant->x)+b+8] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 8; //direction arrêt haut
				}
				else if(detected == 0)
				{
					courant->direction = 1; //direction haut
				}
				detected = 0;
			}

			
			/************************* Création de l'accident (mode chargé uniquement) *************************/
			if(courant->y == 31 && courant->x == 141 && courant->direction == 1 && fluid_heavy == 1) //balise
			{	
				unsigned long int accident = rand()%4294967295; //Tentative d'accident : on obtient un nombre au hasard 

				/************************* Bouton instant_accident : permet de tenter de créer un accident selon ses envies *************************/
				if(instant_accident == 1) 
				{
					accident = 96; //96 est divisble par 2, 6 et 8 ce qui valide immédiatement la conditon en dessous
				}

				/************************* Si le nombre tiré au hasard (ou pas) et qie la condition est validée *************************/
				if(accident%2 == 0 && accident%6 == 0 && accident%8 == 0)
				{
					if(courant->type == 0) //voiture 
					{
						for(int j=0; j<3; j++) //déplacement vers la gauche pour la voiture et on efface "les traces"
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
						courant->x = (courant->x)-1; 
						courant->time_parked = 100; //le temps de parking est inférieur à la valeur minimale (la voiture ne va pas se stationner et paie 0)
						//instant_accident = 0; 
						courant->stupid_car = 1; //la voiture devient "stupid_car" car elle roule en contre-sens
						courant->direction = 0; //direction gauche
					}
					else if(courant->type == 1) //bus
					{
						for(int j=0; j<5; j++)
						{
							Collider_map[(courant->y)+3][(courant->x)+j] = 0;
							map[(courant->y)+3][(courant->x)+j] = ' ';
						}
						courant->direction = 2; //droite (le bus ne peut pas créer d'accident)
					}
				}
				else if(accident%2 !=0 || accident%6 !=0 || accident%8 != 0) //si la variable à valeur aléatoire ne vérifie pas la condition
				{
					//déplacement en sens normal pour la voiture et le bus
					if(courant->type == 0)
					{
						for(int j=0; j<3; j++)
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
					}
					else if(courant->type == 1)
					{
						for(int j=0; j<5; j++)
						{
							Collider_map[(courant->y)+3][(courant->x)+j] = 0;
							map[(courant->y)+3][(courant->x)+j] = ' ';
						}
					}
					courant->direction = 2; //droite
				}

				/************************* Fermeture barrière : La voiture a passé le portail, il faut maintenant le refermer *************************/
				system("play -q ./Sound/entrance.mp3 vol -5db&");
				for(int j=0; j<8; j++) //pour fermer le portail ensuite
				{
					if(j!=4 || j!=3)
					{
						map[35][140+j] = '-';
					}
					if(j==4 || j==3)
					{
						map[35][140+j] = ' ';
					}
				}
			}

			/************************* Mode fluide *************************/
			if(courant->y == 31 && courant->x == 141 && courant->direction == 1 && fluid_heavy == 0) //balise
			{	
				if(courant->type == 0)
				{
					for(int j=0; j<3; j++)
					{
						Collider_map[(courant->y)+2][(courant->x)+j] = 0;
						map[(courant->y)+2][(courant->x)+j] = ' ';
					}
				}
				else if(courant->type == 1)
				{
					for(int j=0; j<5; j++)
					{
						Collider_map[(courant->y)+3][(courant->x)+j] = 0;
						map[(courant->y)+3][(courant->x)+j] = ' ';
					}
				}
				courant->direction = 2; //droite

				system("play -q ./Sound/entrance.mp3 vol -5db&");
				for(int j=0; j<8; j++) //pour fermer le portail ensuite
				{
					if(j!=4 || j!=3)
					{
						map[35][140+j] = '-';
					}
					if(j==4 || j==3)
					{
						map[35][140+j] = ' ';
					}
				}
			}
			

			/************************* Balise : passage de direction droite à haut *************************/
			if(courant->type == 0) //pour les voitures 
			{
				//détection d'obstacle
				if(courant->y == 31 && (courant->x)+2 == 174) 
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)-1][(courant->x)+j+1] == 2 || Collider_map[(courant->y)-2][(courant->x)+j+1] == 2 || Collider_map[(courant->y)-3][(courant->x)+j+1] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 9; //arrêt droite (on ne tourne pas a l'angle tout de suite, car une voiture s'y trouve au dessus)
					}
					else if(detected == 0)
					{
						Collider_map[(courant->y)][(courant->x)] = 0;
						map[(courant->y)][(courant->x)] = ' ';	
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+1][(courant->x)-3+j] = 0;
							map[(courant->y)+1][(courant->x)-3+j] = ' ';
						}
						courant->y = (courant->y)-1;
						courant->x = (courant->x)+1;
						courant->direction = 1; //direction haut
						detected = 0;
					}	
				}
			}
			else if(courant->type == 1) //pour les bus
			{
				if(courant->y == 31 && (courant->x)+2 == 174) 
				{
					for(int i=0; i<4; i++)
					{
						for(int j=0; j<5; j++)
						{
							if(Collider_map[(courant->y)-2][(courant->x)+j+1] == 2 || Collider_map[(courant->y)-3][(courant->x)+j+1] == 2 || Collider_map[(courant->y)-4][(courant->x)+j+1] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 9;
					}
					else if(detected == 0)
					{
						for(int j=0; j<6; j++)
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
						for(int k=0; k<3; k++)
						{
							Collider_map[(courant->y)+k][(courant->x)] = 0;
							map[(courant->y)+k][(courant->x)] = ' ';
						}
						courant->y = (courant->y)-1;
						courant->x = (courant->x)+1;
						courant->direction = 1;
						detected = 0;
					}
				}	
			}


			/************************* Balise : passage de direction haut à gauche *************************/
			if(courant->y == 4 && courant->x == 173) 
			{
				for(int i=0; i<2; i++)
				{
					for(int j=0; j<4; j++)
					{
						if(Collider_map[(courant->y)+i][(courant->x)-1] == 2 || Collider_map[(courant->y)+i][(courant->x)-2] == 2 || Collider_map[(courant->y)+i][(courant->x)-3] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 8; //arrêt haut
				}
				else if(detected == 0)
				{
					if(courant->type == 0) //pour les voitures
					{
						for(int j=0; j<3; j++) //on efface les "traces"
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
						courant->x = (courant->x)-1;
					}
					else if(courant->type == 1) //pour les bus
					{
						for(int j=0; j<5; j++) 
						{
							Collider_map[(courant->y)+3][(courant->x)+j] = 0;
							map[(courant->y)+3][(courant->x)+j] = ' ';
						}
						for(int k=0; k<4; k++) 
						{
							Collider_map[(courant->y)+k][(courant->x)+4] = 0;
							map[(courant->y)+k][(courant->x)+4] = ' ';
						}
						courant->x = (courant->x)-1;
					}
					courant->direction = 0; //direction gauche
				}
				detected = 0;
			}


			/************************* Balise parking place voiture : 2 et 3 ème rangée : passage de direction gauche à bas *************************/
			if(courant->type == 0) //pour les voitures
			{
				if(courant->y == 4 && courant->x == 150 && courant->time_parking == 0 && (zone == 2 || zone == 1)) //balise rangée b & c 
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)+i+2][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						Collider_map[(courant->y)+1][(courant->x)+3] = 0; //passage gauche vers bas
						map[(courant->y)+1][(courant->x)+3] = ' ';

						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						courant->direction = 3; //bas
					}
					detected = 0;
				}


				/************************* Balise parking place voiture : 4 et 5 ème rangée : passage de direction gauche à bas *************************/
				if(courant->y == 4 && courant->x == 126 && courant->time_parking == 0 && (zone == 3 || zone == 4 || zone == 5)) 
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)+i+2][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						Collider_map[(courant->y)+1][(courant->x)+3] = 0; //passage gauche vers bas
						map[(courant->y)+1][(courant->x)+3] = ' ';

						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						courant->direction = 3; //bas
					}
					detected = 0;
				}


				/************************* Balise parking place voiture : 6 et 7 ème dernière rangée : passage de direction gauche à bas *************************/
				if(courant->y == 4 && courant->x == 102 && courant->time_parking == 0 && (zone == 3 || zone == 1 || zone == 4 || zone == 6 || zone == 0 || zone == 5)) //balise rangée f et G
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)+i+2][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						Collider_map[(courant->y)+1][(courant->x)+3] = 0; //passage gauche vers bas
						map[(courant->y)+1][(courant->x)+3] = ' ';

						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						courant->direction = 3; //bas
					}
					detected = 0;
				}


				/************************* Balise angle haut-gauche de la map (pour les voitures): passage de direction gauche à bas *************************/
				if(courant->y == 4 && courant->x == 10)
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)+2][(courant->x)+j] == 2 || Collider_map[(courant->y)+3][(courant->x)+j] == 2 || Collider_map[(courant->y)+4][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						Collider_map[(courant->y)+1][(courant->x)+3] = 0; //passage gauche vers bas
						map[(courant->y)+1][(courant->x)+3] = ' ';		

						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}	
						courant->direction = 3;
					}
					detected = 0;
				}
			}
			else if(courant->type == 1) //pour les bus
			{

				/************************* Balise parking place bus : 1 et 2 ème rangée : passage de direction gauche à bas *************************/
				if(courant->y == 4 && courant->x == 71 && courant->time_parking == 0 && (zone == 2 || zone == 3 || zone == 4)) 
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<5; j++)
						{
							if(Collider_map[(courant->y)+i+3][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						for(int j=0; j<6; j++) //passage haut vers gauche
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						for(int k=0; k<3; k++) //passage haut vers gauche
						{
							Collider_map[(courant->y)+k][(courant->x)+5] = 0;
							map[(courant->y)+k][(courant->x)+5] = ' ';
						}
						courant->direction = 3;
					}
					detected = 0;
				}

				
				/************************* Balise parking place bus : 3 et 4 ème rangée : passage de direction gauche à bas *************************/
				if(courant->y == 4 && courant->x == 41 && courant->time_parking == 0 && (zone == 3 || zone == 4 || zone == 5 || zone == 6)) 
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<5; j++)
						{
							if(Collider_map[(courant->y)+i+3][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						for(int j=0; j<6; j++) //passage haut vers gauche
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						for(int k=0; k<3; k++) //passage haut vers gauche
						{
							Collider_map[(courant->y)+k][(courant->x)+5] = 0;
							map[(courant->y)+k][(courant->x)+5] = ' ';
						}
						courant->direction = 3;
					}
					detected = 0;
				}


				/************************* Balise angle haut-gauche de la map (pour les bus) : passage de direction gauche à bas *************************/
				if(courant->y == 4 && courant->x == 10)
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<5; j++)
						{
							if(Collider_map[(courant->y)+i+3][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}

					if(detected != 0)
					{
						courant->direction = 7;
					}
					else if(detected == 0)
					{
						for(int j=0; j<6; j++) //passage gauche vers bas
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						for(int k=0; k<3; k++) //passage haut vers gauche
						{
							Collider_map[(courant->y)+k][(courant->x)+5] = 0;
							map[(courant->y)+k][(courant->x)+5] = ' ';
						}
						courant->direction = 3;
					}
					detected = 0;
				}
			}


			/************************* Balise sorties des rangées 2 et 3 de parking (pour les voitures) : test obstacles *************************/
			/************************* En sortant des rangées, on vérifie si une voiture ne vient pas de notre droite avant de s'engager *************************/
			if((courant->y)+3 == 29 && courant->x == 150) //balise
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<9; j++)
					{
						if(Collider_map[(courant->y)+i+6][(courant->x)+j-5] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10;
				}
				else if(detected == 0)
					courant->direction = 3;
				detected = 0;
			}


			/************************* Balise sorties des rangées 4 et 5 de parking (pour les voitures) : test obstacles *************************/
			if((courant->y)+3 == 29 && courant->x == 126 ) //balise
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<9; j++)
					{
						if(Collider_map[(courant->y)+i+6][(courant->x)+j-5] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10;
				}
				else if(detected == 0)
				{
					courant->direction = 3;
				}
				detected = 0;
			}


			/************************* Balise sorties des rangées 6 et 7 (dernière) de parking (pour les voitures) : test obstacles *************************/
			if((courant->y)+3 == 29 && courant->x == 102) //balise
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<9; j++)
					{
						if(Collider_map[(courant->y)+i+6][(courant->x)+j-5] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10;
				}
				else if(detected == 0)
				{
					courant->direction = 3;
				}
				detected = 0;
			}


			/************************* Balise sorties des rangées 1 et 2 de parking (pour les bus) : test obstacles *************************/
			if((courant->y)+4 == 28 && courant->x == 71) //balise
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<11; j++)
					{
						if(Collider_map[(courant->y)+i+6][(courant->x)+j-5] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10;
				}
				else if(detected == 0)
				{
					courant->direction = 3;
				}
				detected = 0;
			}


			/************************* Balise sorties des rangées 3 et 4 de parking (pour les bus) : test obstacles *************************/
			if((courant->y)+4 == 28 && courant->x == 41) //balise
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<11; j++)
					{
						if(Collider_map[(courant->y)+i+6][(courant->x)+j-5] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10;
				}
				else if(detected == 0)
					courant->direction = 3;
				detected = 0;
			}

			
			/************************* Balise sortie des rangées 2/3/4/5/6/7 (pour les voitures) : passage de direction bas à droite *************************/
			if(((courant->y)+2 == 32 && courant->x == 150 )|| ((courant->y)+2 == 32 && courant->x == 126) || ((courant->y)+2 == 32 && courant->x == 102))
			{
				for(int i=0; i<2; i++)
				{
					for(int j=0; j<4; j++)
					{
						if(Collider_map[(courant->y)+i+1][(courant->x)+3] == 2 || Collider_map[(courant->y)+i+1][(courant->x)+4] == 2 || Collider_map[(courant->y)+i+1][(courant->x)+5] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10; //arrêt bas si un obstacle est détecté 
				}
				else if(detected == 0)
				{
					for(int g=0; g<3; g++)
					{
						Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
						map[(courant->y)][(courant->x)+g] = ' ';
					}
					for(int j=0; j<3; j++)
					{
						Collider_map[(courant->y)+j][(courant->x)] = 0;
						map[(courant->y)+j][(courant->x)] = ' ';
					}
					courant->y = (courant->y)+1;
					courant->direction = 2; //droite
				}
				detected =0;
			}


			/************************* Balise sortie des rangées 1/2/3/4 (pour les bus) : passage de direction bas à droite *************************/
			if(((courant->y)+2 == 32 && courant->x == 71) || ((courant->y)+2 == 32 && courant->x == 41))
			{	
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<6; j++)
					{
						if(Collider_map[(courant->y)+i+2][(courant->x)+7] == 2)
						{
							detected++;
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10;
				}
				else if(detected == 0)
				{
					for(int g=0; g<5; g++)
					{
						Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
						map[(courant->y)][(courant->x)+g] = ' ';
					}

					for(int j=0; j<4; j++)
					{
						Collider_map[(courant->y)+j][(courant->x)] = 0;
						map[(courant->y)+j][(courant->x)] = ' ';
					}
					courant->y = (courant->y)+1;	
					courant->direction = 2;
				}
				detected =0;
			}


			/************************* Balise bas-gauche de la map : passage de direction bas à droite *************************/
			if((courant->y)+2 == 32 && courant->x == 10)
			{
				if(courant->type == 0) //pour les voitures 
				{
					for(int i=0; i<2; i++)
					{
						for(int j=0; j<4; j++)
						{
							if(Collider_map[(courant->y)+i+1][(courant->x)+3] == 2 || Collider_map[(courant->y)+i+1][(courant->x)+4] == 2 || Collider_map[(courant->y)+i+1][(courant->x)+5] == 2)
							{
								detected++;
							}
						}
					}
				}
				else if(courant->type == 1) //pour les bus
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<6; j++)
						{
							if(Collider_map[(courant->y)+i+2][(courant->x)+7] == 2)
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 10; //arrêt bas car on a détecté une voiture
				}
				else if(detected == 0)
				{
					if(courant->type == 0) //pour les voitures
					{
						for(int g=0; g<3; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
							map[(courant->y)][(courant->x)+g] = ' ';
						}

						for(int j=0; j<3; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)] = 0;
							map[(courant->y)+j][(courant->x)] = ' ';
						}
						courant->y = (courant->y)+1;
					}
					else if(courant->type == 1) //pour les bus
					{
						for(int g=0; g<5; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
							map[(courant->y)][(courant->x)+g] = ' ';
						}

						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)] = 0;
							map[(courant->y)+j][(courant->x)] = ' ';
						}
						courant->y = (courant->y)+1;
					}
					courant->direction = 2; //direction droite : si aucun obstacle a été détecté 
				}
				detected = 0; //remise à 0 de detected
			}


			/************************* Balise sortie de parking (avant les bornes de paiement) : passage de direction droite à bas *************************/
			if(courant->y == 31 && (courant->x)+3 == 84 && courant->time_parking == courant->time_parked && courant->direction == 2) 
			{
				if(courant->type == 0) //pour les voitures 
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)+i+2][(courant->x)+1] == 2)
							{
								detected++;
							}
						}
					}
				}
				else if(courant->type == 1) //pour les bus
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<5; j++)
						{
							if(Collider_map[(courant->y)+i+3][(courant->x)+1] == 2)
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 9; //arrêt droite
				}
				else if(detected == 0)
				{
					if(courant->type == 0) //on efface les traces de la voiture
					{
						Collider_map[(courant->y)+1][(courant->x)] = 0; 
						map[(courant->y)+1][(courant->x)] = ' ';	
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						courant->x = (courant->x)+1;
					}
					else if(courant->type == 1)
					{
						for(int k=0; k<6; k++) //on efface les traces du bus
						{
							Collider_map[(courant->y)][(courant->x)+k] = 0;
							map[(courant->y)][(courant->x)+k] = ' ';
						}
						for(int j=0; j<3; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)] = 0;
							map[(courant->y)+j][(courant->x)] = ' ';
						}
						courant->x = (courant->x)+1;	
					}
					courant->direction = 3; //bas
				}
				detected = 0;
			}
				

			/************************* Balise sortie de parking en contre-sens (pour l'accident) : passage de direction gauche à bas *************************/
			if(courant->y == 31 && courant->x == 82 && courant->direction == 0) 
			{
				if(courant->type == 0)
				{
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							if(Collider_map[(courant->y)+i+2][(courant->x)+j] == 2)
							{
								detected++;
							}
						}
					}
				}
				if(detected != 0)
				{
					courant->direction = 7; //arrêt gauche si obstacle détecté
				}
				else if(detected == 0)
				{
					if(courant->type == 0)
					{
						Collider_map[(courant->y)+1][(courant->x)+3] = 0; //passage gauche vers bas
						map[(courant->y)+1][(courant->x)+3] = ' ';

						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)][(courant->x)+j] = 0;
							map[(courant->y)][(courant->x)+j] = ' ';
						}
						courant->direction = 3; //sinon direction bas 
					}
				}
				detected = 0;
			}


			/************************* Balise sortie de parking (aux bornes de paiement) : direction bas après un certain temps *************************/
			if((courant->y)+2 == 38 && courant->x == 82) //balise
			{	
				courant->direction = 10;
				if(courant->time_waiting == 20)
				{
					/************************* définition du prix à payer à la sortie *************************/
					courant->paytime = (courant->time_parked)/80; //prix = (temps de stationnement total)/80

/*	Table des cas et leurs valeurs */
/*  int cas1=250; (== environ 10 secondes)
	int cas2=450;
	int cas3=650;
	int cas4=850;
	int cas5=1050;
	int cas6=1250;
	int cas7=1450;
	int cas8=1650;
	int cas9=1850;
	int cas10=2050;
	int cas11=2250;
	int cas12=2450;
*/
					/************************* Prix à payer pour stationnement = 0 pour les voitures en contre-sens *************************/
					if(courant->paytime < 2)
					{ 
						//on affiche rien, le conducteur remet simplement le ticket de stationnement 
						map[36][68] = '0';//temps de stationnement (dizaine)
						map[36][69] = '0';//temps de stationnement (unité)

						map[37][68] = '0';//prix à payer (dizaine)
						map[37][69] = '0';//prix à payer (unité)
					}
					/************************* Prix à payer pour stationnement selon les N cas *************************/
					if(courant->paytime >= 2 && courant->paytime <4)
					{ 
						int e = (courant->paytime);
						int f = (courant->time_parked)/25; //temps en seconde : valeur minimale == 250 (cas1)
						//ici f == 10 donc : 
						int g= f-10; //pour accéder aux unités de la valeur totale, on retire le chiffre des dizaines

						map[36][68] = '1';
						map[36][69] = g+'0';

						map[37][68] = '0';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 4 && courant->paytime <6)
					{
						int e = (courant->paytime);
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-10;

						map[36][68] = '1';
						map[36][69] = g+'0';

						map[37][68] = '0';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 6 && courant->paytime <8)
					{
						int e = (courant->paytime);
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-20;

						map[36][68] = '2';
						map[36][69] = g+'0';

						map[37][68] = '0';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 9 && courant->paytime <11)
					{
						map[36][68] = '3';
						map[36][69] = '4';

						map[37][68] = '1';
						map[37][69] = '0';
					}
					if(courant->paytime >= 12 && courant->paytime <14)
					{
						int e = (courant->paytime)-10;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-40;

						map[36][68] = '4';
						map[36][69] = g+'0';

						map[37][68] = '1';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 14  && courant->paytime <16)
					{
						int e = (courant->paytime)-10;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-50;

						map[36][68] = '5';
						map[36][69] = g+'0';

						map[37][68] = '1';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 16 && courant->paytime <19)
					{
						int e = (courant->paytime)-10;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-50;

						map[36][68] = '5';
						map[36][69] = g+'0';

						map[37][68] = '1';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 19 && courant->paytime <21)
					{
						int e = (courant->paytime)-20;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-60;

						map[36][68] = '6';
						map[36][69] = g+'0';

						map[37][68] = '2';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 21 && courant->paytime <24)
					{
						int e = (courant->paytime)-20;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-70;

						map[36][68] = '7';
						map[36][69] = g+'0';

						map[37][68] = '2';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 24 && courant->paytime <26)
					{
						int e = (courant->paytime)-20;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-80;

						map[36][68] = '8';
						map[36][69] = g+'0';

						map[37][68] = '2';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 27 && courant->paytime <29)
					{
						int e = (courant->paytime)-20;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-90;

						map[36][68] = '9'; 
						map[36][69] = g+'0';

						map[37][68] = '2';
						map[37][69] = e+'0';
					}
					if(courant->paytime >= 29 && courant->paytime <31)
					{
						int e = (courant->paytime)-30;
						int f = (courant->time_parked)/25; //temps en seconde 
						int g= f-90;

						map[36][68] = '9';
						map[36][69] = g+'0';

						map[37][68] = '3';
						map[37][69] = e+'0';
					}
				}

				/************************* Temps d'attente pour ovurir le portail de sortie *************************/
				if(courant->time_waiting+5 == courant->time_exit) //ouverture de la barriere droite
				{
					for(int j=0; j<3; j++)
					{
						map[40][81+j] = ' ';
					}
				}
				if(courant->time_waiting+15 == courant->time_exit) //ouverture de la barriere gauche
				{
					for(int j=0; j<3; j++)
					{
						map[40][86+j] = ' ';
					}
				}
				if(courant->time_waiting == courant->time_exit)
				{
					courant->direction = 3; //direction bas (le véhicule quitte le parking)
				}
				else if(courant->time_waiting < courant->time_exit)
				{
					courant->time_waiting++;
				}
			}


			/************************* Balise sortie du parking (après paiement) : passage direction bas à gauche *************************/
			if((courant->y)+2 == 43 && courant->x == 82 && courant->direction == 3) //balise
			{	
				/* Pas de détection d'obstacle ici car sinon on a potentiellement une création d'embouteillage à la sortie du parking */
				/* Ce choix de notre part ne provoque pas d'accident */ 

				if(courant->type == 0) //pour les voitures
				{
					for(int g=0; g<3; g++) //on efface les traces
					{
						Collider_map[(courant->y)][(courant->x)+g] = 0;
						map[(courant->y)][(courant->x)+g] = ' ';
					}
					for(int j=0; j<4; j++)
					{
						Collider_map[(courant->y)+j][(courant->x)+2] = 0;
						map[(courant->y)+j][(courant->x)+2] = ' ';
					}	
					courant->y = (courant->y)+1;
					courant->x = (courant->x)-1;
				}
				else if(courant->type == 1)
				{
					for(int g=0; g<5; g++)
					{
						Collider_map[(courant->y)][(courant->x)+g] = 0;
						map[(courant->y)][(courant->x)+g] = ' ';
					}
					for(int j=0; j<4; j++)
					{
						Collider_map[(courant->y)+j][(courant->x)+4] = 0;
						map[(courant->y)+j][(courant->x)+4] = ' ';
					}
					courant->y = (courant->y)+1;
					courant->x = (courant->x)-1;
				}
				courant->direction = 0; // direction gauche


				/************************* (après paiement) : fermeture des barrières *************************/
				system("play -q ./Sound/exit.mp3 vol -1db&");
				for(int j=0; j<8; j++) //pour fermer le portail ensuite
				{
					if(j!=4 || j!=3)
					{
						map[40][81+j] = '-';
					}
					if(j==4 || j==3)
					{
						map[40][81+j] = ' ';
					}
				}
			}


			/************************* Places de parking voitures : Première rangée tout à gauche *************************/
			int aleaGD = rand()%6; //aleaGD permet de savoir si la voiture va se garer à droite ou à gauche, 
								   //ici il n'y a que a gauche possible donc a droite == ne se gare pas
			if(courant->type == 0)
			{
				int a =0;
				for(int i=0; i<7; i++) //pour les 7 premières place de la 1ere rangée de parking voiture
				{
					aleaGD = rand()%10; 
					a = a+3;
					//time_parking permet d'identifier une voiture qui s'est déjà garée ou pas 
					//la place (30, 173) correspond à la toute première place située le plus en bas a droite 
					//la variable a : permet d'effectuer ces conditions sur les 6 autres places en décalant les valeurs des coordonnées

					/************************* On entre dans la place de parking voiture et défini la place comme occupée *************************/
					if(courant->y == 30-a && courant->x == 173 && car_place[i] == 0 && courant->time_parking ==0 && aleaGD == 1) 
					{
						for(int j=0; j<3; j++) //passage direction haut vers gauche (on efface la trace)
						{
							Collider_map[(courant->y)+2][(courant->x)+j] = 0;
							map[(courant->y)+2][(courant->x)+j] = ' ';
						}
						courant->direction = 0; //direction gauche
						courant->x = (courant->x)-1;
						car_place[i] = 1;
					}

					/************************* On s'arrête dans la place de parking voiture *************************/
					if(courant->y == 30-a && courant->x == 165) 
					{
						courant->direction = 7; //arrêt gauche

						/************************* Si la voiture a terminé son stationnement : il fait marche arrière pour sortir *************************/
						if(courant->time_parking == courant->time_parked)
						{
							for(int i=0; i<8; i++)
							{
								for(int j=0; j<5; j++)
								{
									if(Collider_map[(courant->y)+i-2][(courant->x)+j+7] == 2)
									{
										detected++;
									}
								}
							}
							if(detected != 0)
							{
								courant->direction = 13; //arrêt marche arrière vers la droite
							}
							else if(detected == 0)
							{
								courant->direction = 11; //marche arrière vers la droite
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}

					/************************* définie la palce de parking comme libre *************************/
					if(courant->y == 30-a && courant->x == 172 && courant->time_parking != 0) 
					{
						car_place[i] = 0;
					}

					/************************* Verification avant de sortie de marche arriere droite vers direction haut *************************/
					if(courant->y == 30-a && (courant->x)+2 == 174 && courant->time_parking != 0) 
					{
						for(int i=0; i<3; i++)
						{
							for(int j=0; j<3; j++)
							{
								if(Collider_map[(courant->y)+i-3][(courant->x)+j] == 2)
								{
									detected++;
								}
							}
						}
						if(detected != 0)
						{
							courant->direction = 13; //arrêt
						}
						else if(detected == 0)
						{
							Collider_map[(courant->y)][(courant->x)] = 0;
							map[(courant->y)][(courant->x)] = ' ';
							for(int j=0; j<4; j++)
							{
								Collider_map[(courant->y)+1][(courant->x)-3+j] = 0;
								map[(courant->y)+1][(courant->x)-3+j] = ' ';
							}
							courant->y = (courant->y)-1;
							courant->x = (courant->x)+1;
							courant->direction = 1; //direction haut
						}
						detected = 0;
					}
				}
				a=0;

				/************************* Même chose pour les autres rangées de voitures *************************/
				int c = 0;
				int e = 0;
				for(int i=7; i<49; i+=2) //pour les 42 autres places 
				{
					aleaGD = rand()%2;	
/************************* On entre dans la place de parking voiture rangée 3, 5 et 7[côté gauche] *************************/
					if((courant->y)+2 == 28-c && courant->x == 150-e && car_place[i+1] == 0 && courant->time_parking ==0 && aleaGD == 1) //balise place 1 //timeparked pour voir s'il veut partir ou rentrer
					{
						for(int g=0; g<3; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0;
							map[(courant->y)][(courant->x)+g] = ' ';
						}
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)+2] = 0;
							map[(courant->y)+j][(courant->x)+2] = ' ';
						}
						courant->y = (courant->y)+1;
						courant->x = (courant->x)-1;
						courant->direction = 0; //gauche
						car_place[i+1] = 1;
					}

					/************************* On s'arrête dans la place de parking voiture *************************/
					if(courant->y == 27-c && courant->x == 141-e) //balise place 1
					{
						courant->direction = 7; //arrêt gauche

						/************************* Si la voiture a terminé son temps de stationnement *************************/
						if(courant->time_parking == courant->time_parked)
						{
							/************************* Test si une voiture occupe déja la voie de sortie *************************/
							for(int i=0; i<8; i++)
							{
								for(int j=0; j<4; j++)
								{
									if(Collider_map[(courant->y)+i-5][(courant->x)+j+7] == 2)
									{
										detected++;
									}
								}
							}
							/************************* Test si une voiture sort de la place en face en même temps *************************/
							for(int i=0; i<2; i++)
							{
								for(int j=0; j<11; j++)
								{
									if(Collider_map[(courant->y)+i][(courant->x)+j+4] == 2)
									{
										detected++;
									}
								}
							}
							if(detected != 0)
							{
								courant->direction = 13; //arrêt	
							}
							else if(detected == 0)
							{
								courant->direction = 11; //marche arrière
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}


					/************************* Même chose : Test si une voiture sort de la place en face en même temps : 2eme test pour dire qui sort en premier *************************/
					if(courant->y == 27-c && courant->x == 142-e && courant->direction == 11 && courant->time_parking == courant->time_parked) //balise place 1
					{
						if(courant->time_parking == courant->time_parked)
						{
							for(int i=0; i<8; i++)
							{
								for(int j=0; j<4; j++)
								{
									if(Collider_map[(courant->y)+i-5][(courant->x)+j+6] == 2)
									{
										detected++;
									}
								}
							}
							for(int i=0; i<2; i++)
							{
								for(int j=0; j<10; j++)
								{
									if(Collider_map[(courant->y)+i][(courant->x)+j+4] == 2)
									{
										detected++;
									}
								}
							}
							if(detected != 0)
							{
								courant->direction = 13;		
							}
							else if(detected == 0)
							{
								courant->direction = 11;
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}
					/************************* On libère la place *************************/
					else if(courant->y == 27-c && courant->x == 149-e && courant->time_parking != 0) 
					{
						car_place[i+1] = 0;
					}

					/************************* Balise : on recule, sort de la place et on va vers le bas *************************/
					if(courant->y == 27-c && ((courant->x)+3 == 152-e) && (courant->time_parking == courant->time_parked) && courant->direction == 11) 
					{
						for(int i=0; i<3; i++)
						{
							for(int j=0; j<3; j++)
							{
								if(Collider_map[(courant->y)+i+2][(courant->x)+j+1] == 2)
								{
									detected++;
								}
							}
						}
						if(detected != 0)
						{
							courant->direction = 13;
						}
						else if(detected == 0)
						{
							Collider_map[(courant->y)+1][(courant->x)] = 0; //passage droite vers bas
							map[(courant->y)+1][(courant->x)] = ' ';	
							for(int j=0; j<4; j++)
							{
								Collider_map[(courant->y)][(courant->x)+j] = 0;
								map[(courant->y)][(courant->x)+j] = ' ';
							}	
							courant->x = (courant->x)+1;					
							courant->direction = 3; //bas
						}
						detected = 0;
					}


/************************* On entre dans la place de parking voiture rangée 2, 4 et 6 [côté droit] *************************/
				 	if((courant->y)+2 == 28-c && courant->x == 150-e && car_place[i] == 0 && courant->time_parking ==0 && aleaGD == 0) 
					{
						for(int g=0; g<3; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
							map[(courant->y)][(courant->x)+g] = ' ';
						}
						for(int j=0; j<3; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)] = 0;
							map[(courant->y)+j][(courant->x)] = ' ';
						}
						courant->y = (courant->y)+1;
						courant->x = (courant->x)+1;		
						courant->direction = 2; //droite
						car_place[i] = 1;
					}

					/************************* On s'arrête dans la place de parking voiture *************************/
					else if(courant->y == 27-c && courant->x == 157-e) //balise place 1
					{
						courant->direction = 9; //arrêt droit

						/************************* Si la voiture a terminé son temps de stationnement *************************/
						if(courant->time_parking == courant->time_parked)
						{
							/************************* Test pour savoir si un voiture circule dans la voie du milieu *************************/
							for(int i=0; i<6; i++)
							{
								for(int j=0; j<4; j++)
								{
									if(Collider_map[(courant->y)+i-5][(courant->x)+j-7] == 2)
									{
										detected++;
									}
								}
							}
							/************************* Test pour savoir si une voiture sors en face ou pas *************************/
							for(int i=0; i<2; i++)
							{
								for(int j=0; j<11; j++)
								{
									if(Collider_map[(courant->y)+i][(courant->x)+j-12] == 2)
									{
										detected++;
									}
								}
							}
							if(detected != 0)
							{
								courant->direction = 14;
							}
							else if(detected == 0)
							{
								courant->direction = 12;
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}

					/************************* On libère la place de parking *************************/
					else if(courant->y == 27-c && courant->x == 151-e && courant->time_parking != 0) 
					{
						car_place[i] = 0;
					}

					/************************* Balise sortie de place : passage direction marche arrière gauche à bas *************************/
					if(courant->y == 27-c && courant->x == 150-e && courant->time_parking != 0 && courant->direction == 12) 
					{
						for(int i=0; i<3; i++)
						{
							for(int j=0; j<3; j++)
							{
								if(Collider_map[(courant->y)+i+3][(courant->x)+j] == 2)
								{
									detected++;
								}
							}
						}
						if(detected != 0)
						{
							courant->direction = 14;
						}
						else if(detected == 0)
						{
							for(int j=0; j<4; j++)
							{
								Collider_map[(courant->y)][(courant->x)+j] = 0;
								map[(courant->y)][(courant->x)+j] = ' ';
							}
							Collider_map[(courant->y)+1][(courant->x)+3] = 0;
							map[(courant->y)+1][(courant->x)+3] = ' ';		
							courant->direction = 3; //bas
						}
						detected = 0;
					}
					c = c+3;
					if(c == 21) //lorsqu'on a testé pour toute une rangée 
					{
						c = 0; //on retourne à la premiere place le plus en bas
						if(e != 48)
							e = e+24; //et on décale d'une rangée entière
					}
				}
				c=0;
			}

/************************* Places de parking Bus : Rangée 2 et 4 [gauche] (même principe que pour les voitures) *************************/
			else if(courant->type == 1)
			{
			    int v = 0;
				int g = 0;
				for(int i=0; i<20; i+=2) //pour les 20 premères places de bus
				{
					aleaGD = rand()%2;							
					if((courant->y)+2 == 26-v && courant->x == 71-g && bus_place[i+1] == 0 && courant->time_parking ==0 && aleaGD == 1) 
					{
						/************************* Balise : passage direction bas à gauche pour se stationner dans la place *************************/
						for(int g=0; g<5; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0;
							map[(courant->y)][(courant->x)+g] = ' ';
						}
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)+4] = 0;
							map[(courant->y)+j][(courant->x)+4] = ' ';
						}
						courant->y = (courant->y)+1;
						courant->x = (courant->x)-1;
						courant->direction = 0; //gauche
						bus_place[i+1] = 1; //on définie la place comme occupée
					}

					/************************* On s'arrête dans la place de stationnement *************************/
					if(courant->y == 25-v && courant->x == 60-g) //balise place 1
					{
						courant->direction = 7; //arrêt gauche

						/************************* Si la voiture a terminé son temps de stationnement *************************/
						if(courant->time_parking == courant->time_parked)
						{
							/************************* On teste si une voiture roule dans la voie de sortie ou pas *************************/
							for(int i=0; i<8; i++)
							{
								for(int j=0; j<5; j++)
								{
									if(Collider_map[(courant->y)+i-6][(courant->x)+j+11] == 2)
									{
										detected++;
									}
								}
							}

							/************************* On teste si une voiture sort en même temps en face ou pas *************************/
							for(int i=0; i<3; i++)
							{
								for(int j=0; j<13; j++)
								{
									if(Collider_map[(courant->y)+i][(courant->x)+j+6] == 2)
									{
										detected++;
									}
								}
							}

							if(detected != 0)
							{
								courant->direction = 13;	
							}
							else if(detected == 0)
							{
								courant->direction = 11;
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}

					/************************* On teste si une voiture sort en même temps en face ou pas en décalage : pour dire qui sort en premier *************************/
					if(courant->y == 25-v && courant->x == 61-g && courant->time_parking == courant->time_parked) //balise place 1
					{
						courant->direction = 13; //arrêt gauche
						if(courant->time_parking == courant->time_parked)
						{
							/************************* On teste si une voiture roule dans la voie de sortie ou pas *************************/
							for(int i=0; i<8; i++)
							{
								for(int j=0; j<4; j++)
								{
									if(Collider_map[(courant->y)+i-5][(courant->x)+j+8] == 2)
									{
										detected++;
									}
								}
							}

							/************************* On teste si une voiture sort en même temps en face ou pas *************************/
							for(int i=0; i<3; i++)
							{
								for(int j=0; j<12; j++)
								{
									if(Collider_map[(courant->y)+i][(courant->x)+j+6] == 2)
									{
										detected++;
									}
								}
							}

							if(detected != 0)
							{
								courant->direction = 13;	

							}
							else if(detected == 0)
							{
								courant->direction = 11;
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}

					/************************* On libère la place de stationnemnet *************************/
					if(courant->y == 25-v && courant->x == 69-g && courant->time_parking == courant->time_parked) 
					{
						bus_place[i+1] = 0;
					}

					/************************* On teste si une voiture est située en dessous de nous ou pas, sinon accident *************************/
					if(courant->y == 25-v && (courant->x)+3 == 73-g && courant->time_parking != 0) 
					{
						for(int i=0; i<4; i++)
						{
							for(int j=0; j<4; j++)
							{
								if(Collider_map[(courant->y)+i+3][(courant->x)+j+1] == 2)
								{
									detected++;
								}
							}
						}
						if(detected != 0)
						{
							courant->direction = 13;
						}
						else if(detected == 0)
						{
							for(int k=0; k<6; k++)
							{
								Collider_map[(courant->y)][(courant->x)+k] = 0;
								map[(courant->y)][(courant->x)+k] = ' ';
							}
							for(int j=0; j<3; j++)
							{
								Collider_map[(courant->y)+j][(courant->x)] = 0;
								map[(courant->y)+j][(courant->x)] = ' ';
							}
							courant->x = (courant->x)+1;					
							courant->direction = 3; //bas
						}
						detected = 0;
					}

/************************* Places de parking Bus : Rangée 1 et 3 [droite] (même principe que pour les voitures) *************************/
					/************************* On entre dans la place de stationnement *************************/
					if((courant->y)+3 == 27-v && courant->x == 71-g && bus_place[i] == 0 && courant->time_parking ==0 && aleaGD == 0) //balise place 1 //timeparked pour voir s'il veut partir ou rentrer
					{
						for(int g=0; g<5; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
							map[(courant->y)][(courant->x)+g] = ' ';
						}	
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)] = 0;
							map[(courant->y)+j][(courant->x)] = ' ';
						}
						courant->y = (courant->y)+1;
						courant->direction = 2; //droite
						bus_place[i] = 1; //definition de la place de parking comme occupée
					}

					/************************* On stationne dans la place de stationnement *************************/
					if(courant->y == 25-v && courant->x == 80-g) //balise place 1
					{
						courant->direction = 9; //arrêt droite

						/************************* Si la voiture a atteint son temps de stationnement *************************/
						if(courant->time_parking == courant->time_parked)
						{
							/************************* On teste si une voiture roule déjà sur la voie du milieu *************************/
							for(int i=0; i<10; i++)
							{
								for(int j=0; j<4; j++)
								{
									if(Collider_map[(courant->y)+i-7][(courant->x)+j-8] == 2)
									{
										detected++;
									}
								}
							}

							/************************* On teste si une voiture sort en face en même temps ou pas  *************************/
							for(int i=0; i<3; i++)
							{
								for(int j=0; j<14; j++)
								{
									if(Collider_map[(courant->y)+i][(courant->x)+j-14] == 2)
									{
										detected++;
									}
								}
							}
							if(detected != 0)
							{
								courant->direction = 14;
							}
							else if(detected == 0)
							{
								courant->direction = 12;
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}

					/************************* On libère la place de stationnement *************************/
					if(courant->y == 25-v && courant->x == 79-g && courant->time_parking != 0) 
					{
						bus_place[i] = 0;
					}

					/************************* Balise : Passage de direction recul à bas *************************/
					if(courant->y == 25-v && (courant->x) == 71-g && courant->time_parking != 0 && courant->direction == 12) 
					{
						for(int i=0; i<4; i++)
						{
							for(int j=0; j<4; j++)
							{
								if(Collider_map[(courant->y)+i+3][(courant->x)+j] == 2)
								{
									detected++;
								}
							}
						}
						if(detected != 0)
						{
							courant->direction = 14;
						}
						else if(detected == 0)
						{
							for(int k=0; k<6; k++)
							{
								Collider_map[(courant->y)][(courant->x)+k] = 0;
								map[(courant->y)][(courant->x)+k] = ' ';
							}
							for(int j=0; j<3; j++)
							{
								Collider_map[(courant->y)+j][(courant->x)+5] = 0;
								map[(courant->y)+j][(courant->x)+5] = ' ';
							}
							courant->direction = 3; //bas
						}
						detected = 0;
					}
					v = v+4;
					if(v == 20) //après une rangée
					{
						v = 0; //on repart à la place la plus en bas
						g = g+30; //on décale d'une rangée
					}
				}
				v=0;
			

/************************* Places de parking Bus : Rangée 5 (dernière rangée) [droite] (même principe que pour les voitures) *************************/
				int s =0;
				for(int i=20; i<25; i++)
				{
					aleaGD = rand()%4;
					s = s+4;

					/************************* On entre dans la place de stationnement *************************/
					if((courant->y)+3 == 31-s && courant->x == 10 && bus_place[i] == 0 && courant->time_parking ==0 && aleaGD == 1) 
					{
						for(int g=0; g<5; g++)
						{
							Collider_map[(courant->y)][(courant->x)+g] = 0; //passage bas vers droite
							map[(courant->y)][(courant->x)+g] = ' ';
						}	
						for(int j=0; j<4; j++)
						{
							Collider_map[(courant->y)+j][(courant->x)] = 0;
							map[(courant->y)+j][(courant->x)] = ' ';
						}
						courant->y = (courant->y)+1;
						courant->direction = 2; //droite
						bus_place[i] = 1;
					}

					/************************* On s'arrête dans la place de stationnement *************************/
					if(courant->y == 29-s && courant->x == 20) 
					{
						courant->direction = 9; //arrêt gauche

						/************************* si le véhicule a atteint le temps maximum de stationnement *************************/
						if(courant->time_parking == courant->time_parked)
						{
							/************************* On teste si un véhicule roule déjà dans la voie du milieu *************************/
							for(int i=0; i<12; i++)
							{
								for(int j=0; j<4; j++)
								{
									if(Collider_map[(courant->y)+i-7][(courant->x)+j-10] == 2)
									{
										detected++;
									}
								}
							}
							if(detected != 0)
							{
								courant->direction = 14;
							}
							else if(detected == 0)
							{
								courant->direction = 12;
							}
							detected = 0;
						}
						else
							courant->time_parking++;
					}

					/************************* On libère la place de stationnemnent *************************/
					if(courant->y == 29-s && courant->x == 18 && courant->time_parking != 0) 
					{
						bus_place[i] = 0;
					}

					/************************* On teste si un véhicule est situé en dessous, sinon accident *************************/
					if(courant->y == 29-s && courant->x == 10 && courant->time_parking == courant->time_parked && courant->direction == 12) /////////////////////////EN TEST 
					{
						for(int i=0; i<4; i++)
						{
							for(int j=0; j<5; j++)
							{
								if(Collider_map[(courant->y)+i+3][(courant->x)+j] == 2)
								{
									detected++;
								}
							}
						}
						if(detected != 0)
						{
							courant->direction = 14; //arrêt marche arriere
						}
						else if(detected == 0)
						{
							for(int k=0; k<6; k++)
							{
								Collider_map[(courant->y)][(courant->x)+k] = 0;
								map[(courant->y)][(courant->x)+k] = ' ';
							}
							for(int j=0; j<3; j++)
							{
								Collider_map[(courant->y)+j][(courant->x)+5] = 0;
								map[(courant->y)+j][(courant->x)+5] = ' ';
							}
							courant->direction = 3; //bas
						}
						detected = 0;
					}
				}
				s=0;
			}
			
/////////////suppression voiture////////////
			if(courant->y == 42 && courant->x == 1) //balise de sortie (suppression de voiture)
			{
				courant->direction = 5; //suppr gauche
			}
		}
		courant = courant->suivant;
	}
}


/************************* Fonction qui permet de toruver dans la file : le véhicule ainsi que sa direction *************************/
int FIND_DIRECTION(Liste* file, int ID) 
{ 	
	int direction = -1;
	Vehicle* courant = NULL;
	courant = file->premier;

	while(courant != NULL)
	{ 
		if(courant->ID == ID)
		{
			direction = courant->direction;
			return direction;
		}
		courant = courant->suivant;
	}
	return direction;
}


/************************* Fonction update qui est appelée pour effectuer des mises à jour de positions des véhicules/barrieres ... *************************/
void UPDATE(int MaxY, int MaxX, Liste * file, int cpt_line, int cpt_col, int ** Collider_map, char **map, int** draw_map, int heure_de_pointe, int fluid_heavy, int instant_accident)
{
	int In_Process = 0;
	curs_set(FALSE);
	int nb_vide = 0;

	for(int i=0; i<100; i++) //parcours de chaque véhicules
	{	
		if(ID_TAB[i] == 1) //si on trouve un véhicule en circulation sur la map
		{
			/************************* On cherche si ces véhicules ont atteint des balises ou pas pour changer leur états *************************/
			BALISE(file, cpt_line, cpt_col, Collider_map, map, i, heure_de_pointe, fluid_heavy, instant_accident); //pour la voiture i, on teste sa position

			/************************* Les états on été modifié dans la fonction BALISE, maintenant on récupère la direction du véhicule *************************/
			int direction = FIND_DIRECTION(file, i);


			/************************* Selon les directions, on applique ces fonctions qui permettent de modifier les coordonnées des véhicules *************************/
			if(In_Process == 0)
			{
				if(direction == 0)
				{
					In_Process = VEHICLE_GO_LEFT(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				if(direction == 1)
				{
					In_Process = VEHICLE_GO_UP(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				if(direction == 2)
				{
					In_Process = VEHICLE_GO_RIGHT(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				if(direction == 3)
				{
					In_Process = VEHICLE_GO_DOWN(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				if(direction == 5)//SUPRESSION
				{
					In_Process = VEHICLE_GO_LEFT(file, cpt_line, cpt_col, Collider_map, map, i); //supression par la droite sur little_map.txt (mettre gauche sur map.txt)
					retirer(file, i); //fonctionnel
				}
				if(direction == 7 || direction == 8 || direction == 9 || direction == 10 || direction == 13 || direction == 14 || direction == 17) //arret gauche/haut/droite/bas
				{
					In_Process = VEHICLE_PARK(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				if(direction == 11)
				{
					In_Process = VEHICLE_GO_BACK_LEFT(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				if(direction == 12)
				{
					In_Process = VEHICLE_GO_BACK_RIGHT(file, cpt_line, cpt_col, Collider_map, map, i);
				}
				In_Process = 0;
			}
		}
		else
			nb_vide++;
	}

	
	erase(); //permet un rafraichissement de l'affichage en effaçant l'affichage au temps t
	DISPLAY_MAP(file, cpt_line, cpt_col, map, 0, draw_map); //on réaffiche sur le terminal ncurses les véhicules au temps t+1
	STARS(MaxY, MaxX); //décoration : étoiles ou neige
	DISPLAY_BUTTON(MaxY, MaxX, heure_de_pointe, fluid_heavy, instant_accident); //permet l'affichage des boutons (descriptif des boutons)

	//Aide au développement : cela permet d'afficher le tableau des 100 voitures actifs/non actifs sur la map en temps réel

	/*move(48, 3);
	for(int i=0; i<100; i++)
	{
		printw("%d | ", ID_TAB[i]);
		if(i==24)
			move(49,3);
		if(i==49)
			move(50,3);
		if(i==74)
			move(51,3);
		if(i==99)
			move(52,3);
	}*/

	//Aide au développement : cela permet d'afficher la map de collision
	//DISPLAY_COLLIDER_MAP(cpt_line, cpt_col, Collider_map);
}


/************************* Fonction d'initialisation de l'update *************************/
/************************* Elle permet d'appeler update a des moments précis en fonction d'un compteur/timer *************************/
/************************* Elle permet aussi d'ajouter des voitures dans la file en appelant la fonction d'ajout *************************/
void INIT_UPDATE(int MaxY, int MaxX, int cpt_line, int cpt_col, Liste * file, int** Collider_map, char** map, int** draw_map, int fluid_heavy, int heure_de_pointe)
{
	system("pkill play");
	system("play -q ./Sound/ingame.mp3 repeat 99 vol -8db&");
	int ID = -1; //initialisation de la variable ID 
	int a = 0; //compteur pour ralentir l'affichage en mode fluide
	int b = 0; //compter pour ralentir l'affichage en mode chargé
	int done = 0; //variable qui permet de quitter la boucle while au moment de quitter la simulation
	int i=0;
	int cpt =0;
	int instant_accident = 0; //permet de créer une tentative d'accident en appuyant sur 'f' : (=1)

	timeout(0);

		srand(time(NULL));
		int random = 0; //permet d'obtenir soit une voiture, soit un bus
		int big_small = 0; //0: voiture et 1: bus
		int entreeRandom = 0; //permet de faire rentrer les voitures dans la map en décalé
		int spawnRandom = 0; //permet de faire apparaitre les voitures à des moments décalé

		/************************* boucle while infinie tant qu'on ne quitte pas la simulation *************************/
		while(done != 1)
		{
			random = rand()%3; 
			entreeRandom = rand()%5;
			spawnRandom = rand()%2;

			/************************* définition des types de véhicules *************************/
			if(random == 0 || random == 1)
			{
				big_small = 0;
			}
			else if(random == 2)
			{
				big_small = 1;
			}

/************************* Mode fluide *************************/
			/************************* On fait entrer moins de voitures *************************/
			if(a==0 && (entreeRandom == 0 || entreeRandom == 1 || entreeRandom == 2) && fluid_heavy == 0)  //3 voitures : a%5 == 0 && a<11 //a%10==0 && a<1000
			{
				ID = -1;
				/************************* On vérifie qu'une voiture n'est pas déjà sur le lieu d'apparition des voitures *************************/
				if(Collider_map[42][188] !=2)
				{
					ID = Search_ADD_ID(ID_TAB);	//on cherche si un ID est disponible
					if(ID != -1) //test s'il y a un ID possible, on a donc un véhicule
					{
						/************************* Ajout d'une voiture dans la file et donc dans la map en circulation *************************/
						//enfiler une voiture, paramètres : ... | type de véhicule | direction gauche | y=1 | x=0 | ID depart : 41, 199
						enfiler(file, cpt_line, cpt_col, Collider_map, map, big_small, 0, 42, 188, ID); 

						//permet de retirer le bug d'affichage appliquée à la derniere voiture crée, on détruit la voiture directement
						enfiler(file, cpt_line, cpt_col, Collider_map, map, 0, 5, 0, 196, -1); 
					}
				}
				a=0;
				b=0;
			}

/************************* Mode chargé *************************/
			/************************* On fait entrer moins de voitures *************************/
			else if(b==0 && fluid_heavy == 1) 
			{
				ID = -1;
				/************************* On vérifie qu'une voiture n'est pas déjà sur le lieu d'apparition des voitures *************************/
				if(Collider_map[42][188] !=2)
				{
					ID = Search_ADD_ID(ID_TAB); //on cherche si un ID est disponible
					if(ID != -1) //test s'il y a un ID possible, on a donc un véhicule
					{
						/************************* Ajout d'une voiture dans la file et donc dans la map en circulation *************************/
						//enfiler une voiture, paramètres : ... | type de véhicule | direction gauche | y=1 | x=0 | ID depart : 41, 199
						enfiler(file, cpt_line, cpt_col, Collider_map, map, big_small, 0, 42, 188, ID); 

						//permet de retirer le bug d'affichage appliquée à la derniere voiture crée, on détruit la voiture directement
						enfiler(file, cpt_line, cpt_col, Collider_map, map, 0/*big_small*/, 5, 0, 196, -1); 
					}
				}	
				b=0;
				a=0;
			}

			a++;
			i++;
			b++;
			if(spawnRandom == 0)
				a = a%15040;
			else if(spawnRandom == 1)
				a = a%16000;
			else if(spawnRandom == 2)
				a = a%18000;

			if(spawnRandom == 0)
				b = b%15040;
			else if(spawnRandom == 1)
				b = b%11030;
			else if(spawnRandom == 2)
				b = b%9600;


			if(i == 4000)
			{
				/************************* Appel de la fonction UPDATE *************************/
				UPDATE(MaxY, MaxX, file, cpt_line, cpt_col, Collider_map, map, draw_map, heure_de_pointe, fluid_heavy, instant_accident);
				i=0;
			}

			/************************* Gestion des entrée au clavier *************************/
			int c = getch(); 
			switch(c)
			{
				/************************* Pour quitter *************************/
				case 'q':
					system("play -q ./Sound/click.mp3 vol -5db&");
					for(int i=0; i<100; i++) //on vide les files
					{
						if(ID_TAB[i] == 1)
						{
							retirer(file, i);
							cpt++;
						}else if(ID_TAB[i] == 0)
						{
							cpt++;
						}
					}

					if(cpt == 100)
						done = 1;
					clear();
					erase();
					refresh();
					EXIT_MENU(MaxY, MaxX, cpt_line, cpt_col, file, map, Collider_map, draw_map); // RETURN MENU dans le jeu  		
					break;					
				
				/************************* Pour activer le mode Heure de pointe *************************/
				case 'h':
					system("play -q ./Sound/click.mp3 vol -5db&");
					heure_de_pointe = 1; //HEURE DE POINTE ACTIVE
					refresh();
					break;

				/************************* Pour déactiver le mode Heure de pointe *************************/
				case 'g':
					system("play -q ./Sound/click.mp3 vol -5db&");
					heure_de_pointe = 0; //HEURE DE POINTE DESACTIVE
					refresh();
					break;

				/************************* Pour activer l'instant_accident *************************/
				case 'f':
					if(fluid_heavy == 1)
						system("play -q ./Sound/click.mp3 vol -5db&");
					instant_accident = 1;
					refresh();
					break;

				/************************* Pour désactiver l'instant_accident *************************/
				case 'd':
					if(fluid_heavy == 1)
						system("play -q ./Sound/click.mp3 vol -5db&");
					instant_accident = 0;
					refresh();
					break;

				/************************* Par défault on continue la boucle while *************************/
				default:
					break;
			}
			refresh();
		}
}


/************************* Initialisation de la matrice draw *************************/
/************************* cette matrice permet de savoir si oui ou non on a déjà "dessiné" la case *************************/
/************************* 0 : pas encore affiché | 1 : déja affiché  *************************/
void FILL_DRAW_MATRICE(int cpt_line, int cpt_col, int** draw_map)
{
	for(int i=0; i<cpt_line; i++)
	{
		for(int j=0; j<cpt_col; j++)
		{
			draw_map[i][j] = 0;
		}
	}
}


/************************* Lancement de la simulation : on arrive à la sélection du mode fluide ou chargé *************************/
void SIMULATION(int MaxY, int MaxX)
{
	int heure_de_pointe = 0; 
	/************************* Initialisation du tableau ID *************************/
	Init_ID_TAB(ID_TAB); 

	int cpt_line = 0;
	int cpt_col = 0;

	/************************* Chargement des fichiers voitures *************************/
	LOAD_VEHICLE();

	/************************* on cherche le nb de lignes et nb colonnes *************************/
	cpt_line = SIZE_FILE("map.txt", 0);
	if(cpt_line == -1)
		printw("ERROR IN FUNCTION SIZE_FILE");
	cpt_col = SIZE_FILE("map.txt", 1); //idem column
	if(cpt_col == -1)
		printw("ERROR IN FUNCTION SIZE_FILE");

	/************************* Création de la matrice map *************************/
	char** map = NULL;
	map = malloc(cpt_line*sizeof(char*));
	for(int i=0; i<cpt_line; i++)
	{
		map[i]=malloc(cpt_col*sizeof(char));
	}
	
	/************************* Création de la matrice map de colliion *************************/
	int** Collider_map = NULL;
	Collider_map = malloc(cpt_line*sizeof(int*));
	for(int j=0; j<cpt_line; j++)
	{
		Collider_map[j]=malloc(cpt_col*sizeof(int));
	}

	/************************* Création de la matrice draw map *************************/
	int** draw_map = NULL;
	draw_map = malloc(cpt_line*sizeof(int*));
	for(int k=0; k<cpt_line; k++)
	{
		draw_map[k]=malloc(cpt_col*sizeof(int));
	}
	
	/************************* Initialisation des matrices *************************/
	FILL_MAP_MATRICE(cpt_line, cpt_col, "map.txt", map); //on remplis la matrice map 
	FILL_COLLIDER_MATRICE(cpt_line, cpt_col, map, Collider_map); //on remplis la matrice Collider_map à partir de la matrice map 
	FILL_DRAW_MATRICE(cpt_line, cpt_col, draw_map);

	Liste * file = NULL; //création de la file de voiture 
	file = initfile(file);

	Init_ID_TAB(car_place); //on met toutes les places voiure libres (0)
	Init_ID_TAB(bus_place); //on met toutes les places bus libres (0)

	DISPLAY_MAP(file, cpt_line, cpt_col, map, 1, draw_map);
	DISPLAY_START(MaxY, MaxX); //affichage du bouton pour quitter la simulation
	
	while(click_souris() == 0) //le click souris bloque l'animation
	{
		if(BUTTON1_CLICKED)
		{
			/*FLUID MODE*/
			if (L >= MaxY-5 && L <= MaxY-3) //coordonnée du bouton pour quitter la simulation
			{
				if(C >= MaxX-30 && C <= MaxX-8)  
				{
					system("play -q ./Sound/click.mp3 vol -5db&");
					INIT_UPDATE(MaxY, MaxX, cpt_line, cpt_col, file, Collider_map, map, draw_map, 0, heure_de_pointe);
  				}
			}	
			/*HEAVY MODE*/
			if (L >= MaxY-5 && L <= MaxY-3) //coordonnée du bouton pour quitter la simulation
			{
				if(C >= MaxX-62 && C <= MaxX-40)  
				{
					system("play -q ./Sound/click.mp3 vol -5db&");
					INIT_UPDATE(MaxY, MaxX, cpt_line, cpt_col, file, Collider_map, map, draw_map, 1, heure_de_pointe);
  				}
			}	
		}
	}
}


/************************* Affichage du menu *************************/
void HOME_PAGE(int MaxY, int MaxX) 
{
	int i,j;
	
	STARS(MaxY, MaxX);
	for(i=0 ; i<=MaxY ; i++)					
	{
	//BOX PARKING PROJECT
    mvprintw(MaxY/8+1,MaxX/2-7,"PARKING PROJECT");
		for(j=0 ; j<=MaxX ; j++)
		{
			
			if(i==MaxY/8 && j==MaxX/2-11)
			{
				move(MaxY/8, MaxX/2-11);
				addch(ACS_ULCORNER);
			}	
	
			if(i==MaxY/8 && j>MaxX/2-11 && j<MaxX/2+11)
			{
				addch(ACS_HLINE);
			}

			if(i==MaxY/8 && j==MaxX/2+11)
			{
				addch(ACS_URCORNER);
			}
		}
	
		for(j=0 ; j<=MaxX ; j++)				
		{	
			if(i==MaxY/8+1 && j==MaxX/2-11)
			{
				move(MaxY/8+1,MaxX/2-11);
				addch(ACS_VLINE);
			}
	
			if(i==MaxY/8+1 && j==MaxX/2+11)
			{
				move(MaxY/8+1, MaxX/2+11);
				addch(ACS_VLINE);
			}
		}

		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY/8+2 && j==MaxX/2-11)
			{
				move(MaxY/8+2, MaxX/2-11);
				addch(ACS_LLCORNER);
			}
			
			if(i==MaxY/8+2 && j>MaxX/2-11 && j<MaxX/2+11)
			{
				addch(ACS_HLINE);
			}
		
			if(i==MaxY/8+2 && j==MaxX/2+11)
			{	
				move(MaxY/8+2, MaxX/2+11);
				addch(ACS_LRCORNER);
			}
		}

	//Box LEAVE THE GAME
	mvprintw(MaxY/8+6, MaxX/2-6, "LEAVE THE GAME");
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY/8+5 && j==MaxX/2-9)
			{
				move(MaxY/8+5,MaxX/2-9);
				addch(ACS_ULCORNER);	
			}
		
			if(i==MaxY/8+5 && j>MaxX/2-9 && j<MaxX/2+9)
			{
				addch(ACS_HLINE);
			}

			if(i==MaxY/8+5 && j==MaxX/2+9)
			{
				addch(ACS_URCORNER);
			}
		}
	
		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY/8+6 && j==MaxX/2-9)
			{
				move(MaxY/8+6,MaxX/2-9);
				addch(ACS_VLINE);
			}

			if(i==MaxY/8+6 && j==MaxX/2+9)
			{
				move(MaxY/8+6,MaxX/2+9);
				addch(ACS_VLINE);
			}

		}

		for(j=0 ; j<=MaxX ; j++)
		{
			if(i==MaxY/8+7 && j==MaxX/2-9)
			{
				move(MaxY/8+7,MaxX/2-9);
				addch(ACS_LLCORNER);
			}

			if(i==MaxY/8+7 && j>MaxX/2-9 && j<MaxX/2+9)
			{
				addch(ACS_HLINE);
			}

			if(i==MaxY/8+7 && j==MaxX/2+9)	
			{
				addch(ACS_LRCORNER);
			}
		}
	}
}


/************************* Position des clicks souris sur le menu *************************/
void MAIN_MENU(int MaxY, int MaxX)
{
	system("pkill play");
	system("play -q ./Sound/menu.mp3 repeat 99 vol -1db&");
	int flag=0; 

	HOME_PAGE(MaxY, MaxX); //affichage du menu

//HOME_MENU
	while (flag == 0)
  	{
		click_souris();
		//mvprintw(50, 0, "Vous avez cliqué sur la position (%d, %d)", (L), (C));

		if (L <= MaxY/8+2 && L >= MaxY/8) 					//SIMULATION
		{
			if (C >= MaxX/2-11 && C <= MaxX/2+11) 
			{
				system("play -q ./Sound/click.mp3 vol -5db&");
				flag=1;
				clear();
				SIMULATION(MaxY, MaxX);
  			}
		}

		if (L <= MaxY/8+7 && L >= MaxY/8+5) 				//LEAVE THE GAME
		{
			if(C >= MaxX/2-9 && C <= MaxX/2+9)  
			{
				system("play -q ./Sound/click.mp3 vol -5db&");
				system("pkill play");
				flag=1;
				endwin();
				clear();
				exit(0);
  			}
		}
	}
}


/************************* Fonction lancement jeu qui appelle le menu principal *************************/
void LANCEMENT_JEU()
{
	int MaxX, MaxY;		
	getmaxyx(stdscr, MaxY, MaxX); //permet d'obtenir la taille maximale de l'écran en Y et X

	MAIN_MENU(MaxY, MaxX);
	
}


/************************* Fonction principale ************************/
int main(int argc, char const *argv[])
{
	system("clear");
	ncurses_initialiser();  //Initialisation de ncurses
	colors();  //Initialisation des couleurs 
    ncurses_souris(); //Initialisation de la souris
    LANCEMENT_JEU();
    endwin(); // Suspendre la session ncurses et restaurer le terminal
	return 0;
}
