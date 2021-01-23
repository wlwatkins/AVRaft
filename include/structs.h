#pragma once

typedef struct {
  int min;
  int max;
  int step;
} Limits_t;

typedef struct {
  const char** items;     // Tableau de choix du menu
  const uint8_t nbItems;  // Nombre de choix possibles
  int* params;     // Tableau de choix du menu
  const uint8_t nbParams;  // Nombre de choix possibles
  Limits_t* limits;     // Tableau de choix du menu
  void (*callbackFnct)(uint8_t menuItemSelected); // Pointeur sur fonction pour gérer le choix de l'utilisateur
} Menu_t;

