// Implementation of the designed levels for the current iteration of the game.
#include "Levels.h"
#include "Utility.h"
#include "Enemies.h"
#include "Environment.h"
#include "Items.h"
#include "WindowsDisplay.h"

char spawnOptions(std::string environment, size_t paddH, size_t paddW,
				  strVect choices){
	// Display level screen in a particular way.
	clearScreen();
	displayCentredObject(environment, paddH, paddW);
	displayChoices(choices);
	return _getch();
}

void findItem(Character* player, Item* itm){
	// Find an item in a level after searching.
	clearScreen();
	if (!(player->charInv.checkForItem(itm->getName()))){
		displayCentredObject(itm->getAscii(), -5, 10);
		displayCentredText("You found a " + itm->getName(), -10, true);
		displayCentredText("Pick up item.", 2, false);
		displayCentredText("Leave item.", 3, false);

		char choice{char(_getch())};
		if (choice == '1')
			if(!player->charInv.pickItem(itm)){
				clearScreen();
				displayCentredText("Your inventory is full!", 0, false);
			}
	}
	else{
		displayCentredText("You find nothing!", 0, false);
		_getch();
	}
}

bool checkForCellGuard(strVect &choices, Character* guard){
	// Check if the cell guard is there in the cell level.
	if (std::find(choices.begin(), choices.end(), "Attack guard") !=
		choices.end() && guard->getHealth() > 0)
		return true;
	return false;
}

bool cellLevel(Character* player, Character* guard){
	// The cell level. Player is given a number of choices.
	// Display ASCII art and the choices in the centre of the screen.
	size_t waitCounter{0}, angry;
	strVect choices;
	choices = { "Search cell.", "Scream for help.", "Leave cell.", "Wait." };
	while (true){
		switch (spawnOptions(cellDoorOpen(), 14, 8, choices)){
		case '1': findItem(player, &Pen(3)); break;
		case '2': screamHelp(choices, guard); break;
		case '3': if (leaveCell(choices, guard)) return true; break;
		case '4': waitCounter++;  break;
		case '5': attackGuard(choices, player, guard, angry); break;
		default: break;
		}
		if (player->getHealth() <= 0) dead();
		if (waitCounter >= 10 && guard->getHealth() > 0) happyEnd(guard);
	}
	return false;
}

void screamHelp(strVect &cho, Character* guard){
	// The scream for help choice in the cell level.
	// Guard is alerted and comes. If guard already there, act confused.
	clearScreen();
	if (std::find(cho.begin(), cho.end(), "Attack guard") == cho.end()){

		displayCentredObject(guard->charAscii(false), 0, 0);
		displayCentredText(guard->lineAlerted(), 0, true);
		cho.push_back("Attack guard");
	}
	else if (guard->getHealth() > 0){
		displayCentredObject(guard->charAscii(false), 0, 0);
		displayCentredText(guard->lineConfused(), 0, true);
	}
	else
		displayCentredText("No one hears you.", 0, 0);
	_getch();
}

bool leaveCell(strVect &choices, Character* guard){
	// Leave cell choice in the cell level.
	// The user proceeds to next level if no guard is there.
	clearScreen();
	if (checkForCellGuard(choices, guard)){
		displayCentredObject(guard->charAscii(false), 0, 0);
		displayCentredText(guard->lineLeave(), 0, true);
		_getch();
		return false;
	}
	return true;
}

void attackGuard(strVect &choices, Character* player, Character* guard,
				 size_t &angry){
	// The attack guard choice in the cell level.
	// If guard was missed three times, the guard strikes back.
	clearScreen();
	if (checkForCellGuard(choices, guard))
		if (player->dealDamage(player->charInv["Pen"], guard) == 1)
			displayCentredText("You killed the guard with the pen!", 0, false);
		else{
			missSwing(guard);
			guardRiposte(guard, player, angry);
			angry++;
		}
	else if (guard->getHealth() < 0)
		displayCentredText(guard->charName() + " is already dead.", 0, false);
	_getch();
}

void guardRiposte(Character* guard, Character* player, size_t angry){
	// The guard strikes back at the player in the cell level.
	// The gurad might kill, miss or hit the player.
	if (angry >= 3){
		displayCentredText("The guard shoots at you!", 7, false);
		int guardAtk{guard->dealDamage(guard->charInv["Pistol"], player)};
		if (guardAtk == 1)
			displayCentredText("And kills you!", 8, false);
		else if (guardAtk == 0)
			displayCentredText("And hits you!", 8, false);
		else
			displayCentredText("And misses you!", 8, false);
	}
}

void missSwing(Character* guard){
	// A guard misses a swing.
	displayCentredObject(guard->charAscii(false), 0, 0);
	displayCentredText(guard->lineConfused(), 0, true);
	displayCentredText("You missed.", 5, false);
}

bool corridorLevel(Character* player){
	// The corridor level. Same methodology as cell level (see above).
	size_t waitCounter{ 0 }; strVect choices;
	choices = { "Move forward.", "Go through ventilation unit.", "Wait." };
	while (true){
		switch (spawnOptions(corridor(), 0, 5, choices)){
			case '1': return true;
			case '2': ventInitial(); return true;
			case '3': waitCounter++;
			default: break;
		}
		if (waitCounter == 3) hearPatrol();
		if (waitCounter == 5) getCaughtEnd();
	}
	return false;
}

void hearPatrol(){
	// Hear a patrol if chose to wait in corridor level.
	clearScreen();
	displayCentredText("You hear some voices in the distance!", -5, true);
	_getch();
}

void ventInitial(){
	// Chose to go through vent in corridor level.
	clearScreen();
	displayCentredText("As you crawl through, you notice a locked exit.",
					   0, true);
	_getch();
	displayCentredText("You leave it for now and continue...", 1, true);
}

bool kitchenLevel(Character* player){
	// The kitchen level. Same methodology as cell level (see above).
	strVect choices;
	choices = {"Search kitchen.", "Go for 'EXIT' corridor."};
	while (true){
		switch (spawnOptions(kitchen(), -9, -3, choices)){
		case '1': findItem(player, &Knife(50)); break;
		case '2': kitchenLevelEpi(); return true;
		default: break;
		}
	}
	return false;
}

void kitchenLevelEpi(){
	// Epilogue after exiting the kitchen level.
	clearScreen();
	displayCentredText("You notice a strange man looking through the window.",
					   0, true);
	displayCentredText("Looking again... He's not there.", 2, true);
	displayCentredText("You immediately run for the exit.", 4, true);
	_getch();
}

bool finalLevel(Character* player, Character* guard){
	// The final level in the game, character has to fight final guard.
	strVect choices;
	choices = {"Try to fight."};
	displayCentredText(guard->lineFinal(), 2, true);
	_getch();
	spawnOptions(guard->charAscii(true), 0, 0, choices);
	finalShowdown(player, guard);
	return true;
}

void finalShowdown(Character* player, Character* guard){
	// The final showdown in the game. The guard kills the player if the player
	// is not equipped with the correct items.
	clearScreen();
	displayCentredObject(guard->charAscii(true), 0, 0);
	if (player->charInv.checkForItem("Knife")){
		displayCentredText(guard->lineKnife(), 2, true);
		_getch();
	}
	if (player->charInv.checkForItem("Pistol"))
		if (duelOfFaith(player, guard))
			bloodyEnd();
	clearScreen();
	displayCentredText("The guard shoots you. You die.", 5, false);
	_getch();
}

bool duelOfFaith(Character* player, Character* guard){
	// If the player has the pistol in the final showdown, the guard and the
	// player duel, only one of them walking alive.
	strVect choices;
	choices = { "Shoot guard.", "Wait." };
	while (player->getHealth() > 0 && guard->getHealth() > 0){
		if (spawnOptions(guard->charAscii(true), 0, 0, choices) == '1')
			player->dealDamage(player->charInv["Pistol"], guard);
		guard->dealDamage(guard->charInv["Pistol"], player);
		std::cout<<player->getHealth();
	}
	if (guard->getHealth() > 0)
		return false;
	else
		return true;
}

void gmanEpilogue(Character* gman){
	// Dialogue provided by gman if you die in final showdown.
	clearScreen();
	displayCentredObject(gman->charAscii(), 0, 0);
	displayCentredText(gman->lineFinal(), 1, true);
	_getch();
	clearScreen();
	displayCentredObject(gman->charAscii(), 0, 0);
	displayCentredText(gman->linePlayer(), 1, true);
	_getch();
}

void giveCrowbar(Character* player, Character* gman){
	// The gman gives a crowbar to the player.
	clearScreen();
	displayCentredObject(gman->charAscii(), 0, 0);
	displayCentredText("I see, well, here's a crowbar for Mr. Freeman then.",
						0, true);
	getCrowbar(player);
	_getch();
}

void getCrowbar(Character* player){
	// The player receives a crowbar. The pen is dropped.
	clearScreen();
	Crowbar bar(3.5);
	displayCentredObject(bar.getAscii(), 0, 0);
	displayCentredText("You obtained a crowbar!", 0, true);
	if (player->charInv.checkForItem("Pen"))
		player->charInv.dropItem("Pen");
	player->charInv.pickItem(&bar);
	_getch();
}


bool lockerLevel(Character* player, std::string lockerCode){
	// The locker level, same methodology as the cell level.
	// The locker code is set by the player by using the neural network.
	// The crowbar option is added if the player has the crowbar in inventory.
	strVect choices;
	choices = {"Open locker with code.", "Go to exit."};
	if(player->charInv.checkForItem("Crowbar"))
		choices.push_back("Open locker with crowbar.");
	while (true){
		switch (spawnOptions(locker(), 10, 11, choices)){
		case '1': openCode(player, lockerCode); break;
		case '2': if (goExit(player)) return true; break;
		case '3': openCrowbar(player); break;
		default: break;
		}
	}
	return false;
}

void openCode(Character* player, std::string code){
	// Open the locker with the code option.
	clearScreen();
	size_t k{ 0 };
	if(!player->charInv.checkForItem("Pistol")){
		displayCentredObject(locker(), 10, 11);
		displayCentredText("Please input code: ", 0, false);
		for (size_t i = 0; i < 3; i++)
			if (_getch() == code[i]) k++;
		if (k == 3) getGun(player);
	}
}

void openCrowbar(Character* player){
	// Open the locker with thte crowbar option.
	clearScreen();
	if(!player->charInv.checkForItem("Pistol")){
		displayCentredObject(locker(), 10, 11);
		if(player->bruteOpen(player->charInv["Crowbar"] ,0.5)){
			displayCentredText("You break through the lock!", 0, false);
			_getch();
			getGun(player);
		}
		else{

		}
	}
}

void getGun(Character* player){
	// The player gets the gun from the locker.
	// The knife is dropped if in the inventory.
	clearScreen();
	Pistol pist(100);
	displayCentredObject(pist.getAscii(), 0, 10);
	displayCentredText("You find a gun!", 0, false);
	displayCentredText("[ENTER] Pick up.", 2, false);
	if(player->charInv.checkForItem("Knife"))
		player->charInv.dropItem("Knife");
	player->charInv.pickItem(&pist);
	_getch();
}

bool goExit(Character* player){
	// The player exits the locker room.
	if(player->charInv.checkForItem("Pistol"))
		return true;
	else{
		clearScreen();
		displayCentredText("Hmm... I should open this locker, Freeman thought.",
							0, true);
	}
	return false;
}

bool checkNumbers(std::string code, Character* gman){
	// Check if the numbers read by the neural network are correct.
	char choice;
	clearScreen();
	displayCentredObject(gman->charAscii(), 0, 0);
	displayCentredText("Are your digits: " + code + " ? (y/n)", 1, true);
	choice = _getch();
	if (choice == 'y')
		return true;
	return false;
}


void breakEnd(){
	// The crowbar breaks ending.
	displayCentredText("You try to break through the lock.", 0, true);
	displayCentredText("Your crowbar breaks instead...", 1, true);
	clearScreen();
	displayCentredText("You lost...", 1, true);
	exit(1);
}
void happyEnd(Character* guard){
	// The player waits at the beginning of the game and gets rewarded for
	// their good deeds.
	clearScreen();
	displayCentredObject(guard->charAscii(false), 0, 0);
	displayCentredText(guard->lineCooperation(), 0, true);
	_getch();
	clearScreen();
	displayCentredText("You won the game! Congrats!", 0, true);
	_getch();
	exit(1);
}

void dead(){
	// The player dies by damage.
	clearScreen();
	displayCentredText("You died... Game over.", 0, true);
	_getch();
	exit(1);
}

void getCaughtEnd(){
	// The player gets caught in the corridor level.
	clearScreen();
	displayCentredText("You waited too long and got caught by a patrol unit!",
						-5, true);
	displayCentredText("You lost the game! :(", 1, false);
	_getch();
	exit(1);
}

void bloodyEnd(){
	// The player kills the final boss, but nothing good comes out of it.
	clearScreen();
	displayCentredText("You make your bloody escape.", 2, true);
	displayCentredText("Almost... The guard draws his last breath...", 3, true);
	displayCentredText("and finally he shoots you in the back.", 4, true);
	displayCentredText("You die.", 5, true);
	displayCentredText("You should have waited at the start...", 5, true);
	_getch();
	exit(1);
}

