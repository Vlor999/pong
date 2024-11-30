#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>

#define MVNT 5

int mouvement_joueur1 = 0;
int mouvement_joueur2 = 0;

// Fonction pour configurer le terminal en mode brut
void setRawMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);        // Récupérer les attributs du terminal
    t.c_lflag &= ~(ICANON | ECHO);     // Désactiver le mode canonique et l'écho
    tcsetattr(STDIN_FILENO, TCSANOW, &t); // Appliquer les nouveaux attributs
}

// Fonction pour restaurer le terminal en mode normal
void resetRawMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void detect1(void* arg)
{
    char c;
    printf("Appuyez sur les flèches ou les touches z, q, s, d (CTRL+C pour quitter) :\n");

    while (1) 
    {
        c = getchar();  // Lire un caractère
        if (c == '\033') 
        {          // Détection d'une séquence d'échappement
            getchar();              // Ignorer le caractère '['
            c = getchar();          // Lire le troisième caractère
            switch (c) 
            {
                case 'A':
                    mouvement_joueur1 = -MVNT;
                    break;
                case 'B':
                    mouvement_joueur1 = MVNT;
                    break;
            }
        } 
        else 
        {
            switch (c)
            {
                case 'z':
                    mouvement_joueur2 = -MVNT;
                    break;
                case 's':
                    mouvement_joueur2 = MVNT;
                    break;
                default:
                    detect1(arg);
                    break;
            }
        }
    }
    return;
}
