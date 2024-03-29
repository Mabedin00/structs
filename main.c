#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct pokedex {char* pokemonName; int individualValue;};
void describePokemon(struct pokedex some);// Check your Pokemon's stats
struct pokedex catchPokemon(char* pokemonName); //Catch a pokemon, their IVs are random
void cheatEngine(struct pokedex* pokemon, int desiredValue); //Change your pokemon's IVs
void nameChange(struct pokedex* pokemon, char* newName); //Change your Pokemon's name

int main(){
    srand(time(NULL));
    struct pokedex pokemon0 = catchPokemon("Bulbasaur");
    describePokemon(pokemon0);
    cheatEngine(&pokemon0, 183);
    describePokemon(pokemon0);
    struct pokedex pokemon1 = catchPokemon("Pikachu");
    describePokemon(pokemon1);
    nameChange(&pokemon1, "Charmander");
    describePokemon(pokemon1);
}

void describePokemon(struct pokedex some ){
    printf("Your %s has an IV of %d, that's %f%% \n", some.pokemonName,
                                                      some.individualValue,
                                                     (some.individualValue / 183.0)* 100);
}

struct pokedex catchPokemon(char* pokemonName){
    struct pokedex newPokemon;
    strcpy(newPokemon.pokemonName, pokemonName);
    newPokemon.individualValue = rand() % 186;
    return newPokemon;
}

void cheatEngine(struct pokedex* pokemon, int desiredValue){
    pokemon->individualValue = desiredValue;
    printf("Gratz, you cheated and got a %s with an IV of %d, that's %f%% \n", pokemon->pokemonName,
                                                                          pokemon->individualValue,
                                                                          (desiredValue/ 183.0)* 100);
}
void nameChange(struct pokedex* pokemon, char* newName){
    printf("You changed your %s's name to %s \n", pokemon->pokemonName, newName);
    pokemon->pokemonName = newName;
}
