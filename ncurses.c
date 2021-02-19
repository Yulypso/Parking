#include "main.h"

/************************* fonctions associée à la bibliothèque Ncurses ************************/

/************************* initialisation de Ncurses ************************/
void ncurses_initialiser() 
{
  initscr();	        // Démarre le mode ncurses 
  start_color();
  cbreak();	        	// Pour les saisies clavier (desac. mise en buffer)
  noecho();             // Désactive l'affichage des caractères saisis 
  keypad(stdscr, TRUE);	// Active les touches spécifiques 
  refresh();            // Met a jour l'affichage */
  curs_set(FALSE);      // Masque le curseur */
}


/************************* Initialisation/détection de souris pour le click souris ************************/
void ncurses_souris() 
{
	if(!mousemask(ALL_MOUSE_EVENTS, NULL)) // Vérification de l'initialisation d'une souris
	{
		endwin();
    	fprintf(stderr, "Erreur lors de l'initialisation de la souris.\n");
    	exit(EXIT_FAILURE);
	}

	if(has_mouse() != TRUE) // Vérification de la détection d'une souris
	{
    	endwin();
    	fprintf(stderr, "Aucune souris n'est détectée.\n");
    	exit(EXIT_FAILURE);
	}
}


/************************* récupération entrée clavier ************************/
char key_pressed() 
{
	struct termios oldterm, newterm;
	int oldfd;
	char c, result = 0;
	tcgetattr (STDIN_FILENO, &oldterm);
	newterm = oldterm;
	newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
	oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
	c = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
	fcntl (STDIN_FILENO, F_SETFL, oldfd);

	if (c != EOF) 
	{
		ungetc(c, stdin);
		result = getchar();
	}
	return result;
}


/************************* définition des couleurs dans le terminal Ncurses ************************/
void colors() 
{
  	if(has_colors() == FALSE) 
	{
    		endwin();
    		fprintf(stderr, "Le terminal ne scuporte pas les couleurs.\n");
    		exit(EXIT_FAILURE);
  	}
  	
	start_color();
  	
	init_color(COLOR_RED, 1000, 100, 100);
	init_color(COLOR_BLUE, 1000, 400, 300); //ORANGE
	init_color(COLOR_BLACK, 10, 10, 100);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_GREEN, 100, 1000, 100);
	init_color(COLOR_CYAN, 50, 1000, 1000);
	init_color(COLOR_MAGENTA, 1000, 230, 520); 
	init_color(COLOR_YELLOW, 1000, 800, 0); /*(== BLACK)*/

    assume_default_colors(COLOR_WHITE, COLOR_BLACK);
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
}


/************************* Récupération click souris ************************/
int click_souris()
{
	MEVENT event ;
	int ch;

	while((ch = getch()) != KEY_F(1)) 
	{
    	switch(ch) 
    	{
			case KEY_F(2): // Quitte la boucle
				return 1;

      		case KEY_MOUSE:
        		if(getmouse(&event) == OK)  
				{
	  				C = event.x;
	  				L = event.y;
	  				//refresh();
	  				//mvprintw(50, 0, "Vous avez cliqué sur la position (%2d, %2d)", L, C);
	  				if(event.bstate & BUTTON1_CLICKED)
	  				{ 
	    				return 0;
	  				}
				}
    	}
 	 }
  return 0;
}

