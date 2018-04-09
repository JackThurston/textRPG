// ConsoleRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;



string randEnemy();
int randEnemyHP();
int enemyDamageNum();
int enemiesTurnNum();
int playerDamageNum();
int critStrikeChance();
int enemyLootDrop();



	int main()
	{

		// EXTRA NEEDED VARIABLES
		int loop = 1;
		int loopTown = 1;
		int playerChoiceCounter = 0;
		int critStrikeChnaceNum = 0;
		bool playerInShop = false;
		bool inCombat = false;			
		bool inTown = true;
		int buyAmmount;
		//Player Stats etc
		double playerHealth = 100;
		int playerGold = 10000;
		int playerDamage = 1;		// Min damage 5 max damage 25
		int healthPotions = 3;
		bool playerHasHealthPotions = true;
		int healthPotionsHeal = 25;
		int playerChoice;
		bool playerChoiceNotValid = true;
		string playerName = "Player";
		//Enemy Stats etc
		int enemiesTurn;

		int enemyHealth;		// Enemy health between 100 and 200
		int enemyDamage = 1;		// min damage 1 max damage 15

		// Text map for future use
   //cout << "####################\t" << "####################\n"
		//<< "#" << "                  "     "#\t" << "#" << "                  ""#\n"
		//<< "#                  #\t" << "#                  #\n"
		//<< "#                  #\t" << "#                  #\n"
		//<< "#                  #\t" << "#                  #\n"
		//<< "####################\t" << "####################\n";

		// NOTES TO SELF
		// Try to change the text map based on if statements to adjust the size of the #'s correctly
		// EX. if(playerHealth == 100) so it can space everything for 3 numbers
		// then if(playerHealth < 100 && playerHealth > 10) so you can change the size for 2 numbers instead and same for 1 number
		// do the same for the names based on which enemy is picked



		//Random enemy Generation
		
		string enemies[3] = { "One boney mother fucker", "A 4chan white knight", "A wanna be dank 12 year old from /r/DankMemes" };
		string randEnemies;

		//----------------

		bool running = true;

		/* To do list
		
		1. add a shop
		2. add where the player gets gold per defeated enemy
		3. make the game a infinite loop till player dies
		4. after infinite loop is made allow the player to choose to go to the shop to buy gear etc
		5. impliment weapons and armour into the game with booleans ex playerHasIronSword and if statements if player has item
		6. possibly add a inventory later *idk how so search it*
		7. Dont forget once armour and swords are added to make spells etc if you want them in the game
		*/

		cout << "This crappy text adventure RPG was made by --Jack Thurston-- AKA --Yoobs-- ENJOY!!\n\n" << endl;

		while (running) {
			
			
			while (inCombat) {
				while (loop == 1) {

					randEnemies = randEnemy();
					enemyHealth = randEnemyHP();

					cout << "\t\t\t\tYou encountered: " << randEnemies << endl;
					cout << "\t\t\t\t\t    Enemy HP: " << enemyHealth << endl;

					loop++;

				}
				while (playerHealth > 0) {

					if (loop > 2) {
						cout << "\t\t\t\t\t" << randEnemies << endl;
						cout << "\t\t\t\t\t    Enemy HP: " << enemyHealth << endl;
					}


					// PLAYERS TURN


					cout << "\n\n\t\t\t\t\t    " << playerName << "'s HP: " << playerHealth << endl;

					cout << "\t\t\t1: Attack \t 2: Health Potion\t 3: RUN!\n\n" << endl;
					cout << "\t\t\t\t\tHealth Potions left:" << healthPotions << endl;
					cout << "What will you do?" << endl;
					cin >> playerChoice;


					while (playerChoiceNotValid == true) {
						if (playerChoiceNotValid == true && playerChoiceCounter == 1) {
							cout << "What will you do?" << endl;
							cin >> playerChoice;
							playerChoiceCounter = 0;
						}

						if (playerChoice == 1) {	// CHOICE 1

							playerDamage = playerDamageNum();
							if (critStrikeChance() == 1) {

								playerDamage = playerDamage * 2;
								enemyHealth = enemyHealth - playerDamage;
								cout << "You deal a crushing blow for " << playerDamage << " damage!" << endl;
								cout << "The enemy is now at " << enemyHealth << "HP!" << endl;

							}
							else if (critStrikeChance() == 0) {
								enemyHealth = enemyHealth - playerDamage;
								cout << "You did " << playerDamage << " damage!" << endl;
								cout << "The enemy is now at " << enemyHealth << "HP!" << endl;
							}
							playerChoiceNotValid = false;

						}
						else if (playerChoice == 2) {		// CHOICE 2

							if (playerHasHealthPotions == false && healthPotions > 0) {
								playerHasHealthPotions = true;
							}


							if (playerHasHealthPotions == false) {
								cout << "You dont have any more health potions!!!" << endl;
								playerChoiceCounter = 1;
								playerChoiceNotValid = true;
							}


							while (playerHasHealthPotions == true) {

								playerHealth = playerHealth + healthPotionsHeal;
								healthPotions = healthPotions - 1;
								cout << "You healed for " << healthPotionsHeal << " HP" << endl; // Make a random number in future instead of a constant
								playerChoiceNotValid = false;

								playerHasHealthPotions = false;


							}																	// current state: player uses all health potions and triggers
																								// the else if statement

						}
						else if (playerChoice == 3) {		// CHOICE 3
							cout << "You ran away from the fight!!" << endl; // ends fight and returns to town
							playerChoiceNotValid = false;
							inCombat = false;
							inTown = true;
							
							

						}
						else {
							cout << "You did not select a valid choice!" << endl;
							cout << "What will you do?" << endl;
							playerChoiceNotValid = true;
							cin >> playerChoice;
						}
					}

					// ENEMIES TURN
					playerChoiceNotValid = true;
					enemiesTurn = enemiesTurnNum();
					if (enemiesTurn == 1) {

						cout << "The enemy attacks wildly!" << endl;
						enemyDamage = (rand() % 35) + 20;				// enemy does a special attack for 20-25 dmg 
						cout << "The enemy did " << enemyDamage << "!" << endl;
						cout << "Your health is now " << playerHealth << "!!" << endl;
					}
					else {
						enemyDamage = enemyDamageNum();		// 


						if (critStrikeChance() == 1) {
							enemyDamage = enemyDamage * 2;

						}

						playerHealth = playerHealth - enemyDamage;
						cout << "The enemy did " << enemyDamage << "!" << endl;
						cout << "Your health is now " << playerHealth << "!!" << endl;
					}

					if (enemyHealth <= 0) {
						loop = 1;
						cout << "YOU DEFEATED " << randEnemies << " AND WON!!!!!" << endl;
						cout << "Would you like to go to town or continue in the dungeon?" << endl;
						cout << "1. Go to town     2. Continue in the dungeon" << endl;
						cin >> playerChoice;

						if (playerChoice == 1) {
							inCombat = false;
							inTown = true;
						} 
						else if (playerChoice == 2) {
							inCombat = true;
							inTown = false;
						}
					}


					
					
					

				}
			}
			
								// Town
			while (inTown) {
				playerHealth = 100;
				loopTown = 1;
				while (loopTown == 1) {
					cout << "Entering town...." << endl;
					loopTown++;
				}

				// add sleep
				while (playerChoiceNotValid == true) {
					cout << "Where do you want to go, or do you want to go to the dungeon?" << endl;
					cout << "1. Shop    2.BlackSmith   3. To dungeon\n\n";
					cin >> playerChoice;

					if (playerChoice == 1) {
						cout << "Welcome to the shop! What do you need today?" << endl;
						cout << "1. Potion - 50G - heals for 35 HP" << endl;
						cin >> playerChoice;
						playerChoiceNotValid = true;
						while (playerChoiceNotValid == true) {

							if (playerChoice == 1 && playerGold > 50) {
								playerChoiceNotValid = true;

								while (playerChoiceNotValid == true) {
									cout << "How many do you want to buy? " << endl;
									cin >> buyAmmount;

									if (playerGold > buyAmmount * 50) {
										healthPotions = healthPotions + buyAmmount;
										playerGold = playerGold - (buyAmmount * 50);

										cout << "You purchased " << buyAmmount << " health potions for " << buyAmmount * 50 << "gold." << endl;
										playerChoiceNotValid = false;
									}
									else if (playerGold < buyAmmount * 50) {
										cout << "You do not have " << buyAmmount * 50 << " gold!" << endl;
										playerChoiceNotValid = true;
									}
								}


							}
							else {
								cout << "You don't have enough money for that!" << endl;
							}
						}

						// add more items to shop like bandages etc

					}
					else if (playerChoice == 2) {
						cout << "Welcome to the blacksmith! My weapons and armour are made with the finest metal around! What can i get for you today?" << endl;
						cout << "";
					}
					else if (playerChoice == 3) {
						cout << "Entering dungeon!\n\n" << endl;
						playerChoiceNotValid = false;
						inCombat = true;
						inTown = false;
					}
					else {
						cout << "You must pick a valid choice!" << endl;
						playerChoiceNotValid = true;
					}
				}
				
				


			}
			if (playerHealth <= 0) {
				cout << "You ded" << endl;
				
			}


			

		}
		cout << "Thanks for playing!" << endl;



		return 0;
	}


string randEnemy() {
	string randEnemies;
	
	string enemies[3] = { "One boney mother fucker", "A 4chan white knight", "A wanna be dank 12 year old from /r/DankMemes" };


	randEnemies = enemies[rand() % 2];
	return randEnemies;
}
int randEnemyHP() {
	int enemyHP = (rand() % 200) + 100;
	return enemyHP;
}
int enemyDamageNum() {
	int enemyDamageNum = (rand() % 15) + 1;
	return enemyDamageNum;
}
int playerDamageNum() {
	int playerDamageNum = (rand() % 25) + 10;
	return playerDamageNum;
}
int enemiesTurnNum() {
	int enemiesTurnNum = (rand() % 6) + 1;
	return enemiesTurnNum;
}
int critStrikeChance() {
	int critStrikeChance = (rand() % 100) + 1;
	if (critStrikeChance > 1 && critStrikeChance <= 25) {
		return 1;
	}
	else {
		return 0;
	}
	

}
int enemyLootDrop() {
	int goldDropped = rand();
	


	return 0;
 }
