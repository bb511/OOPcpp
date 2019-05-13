// Method implementation of all items in the adventure game.
#include "Items.h"
#include "Utility.h"

Crowbar::Crowbar(double successMultiplier):
    UtilityItem("Crowbar",
    "      ``.`                     \n"
    "   /ohdysshs/                  \n"
    "  +my/.   `/do                 \n"
    "  /:        /d:                \n"
    "             sd`               \n"
    "             -my               \n"
    "              sm+              \n"
    "              `dm.             \n"
    "               /mh             \n"
    "                :mdm`          \n"
    "                  omdh`        \n"
    "                   /hdh-       \n"
    "                    .yddy.     \n"
    "                     `ommd-    \n"
    "                        .+/`   \n",
    successMultiplier)
{}

size_t Crowbar::attack(double threshold){
    // Grant crowbar ability to deal damage.
    // Utility items cannot deal damage naturally.
    double roll{generateRandomNumber()};
    if(roll > threshold + 0.1){
        std::cout<<"You hit and deal 5 damage.\n";
        return 5;
    }
    std::cout<<"You miss and deal no damage.\n";
    return 0;
}

Pen::Pen(size_t damage):
    DamageItem("Pen",
	". == == == == == == == == == == == = ooooooo                      \n"
	"___, '    \\_________________________________________              \n"
	"/ / -/ dP /                           ////////////  ''--..._      \n"
	"|\\___\\ - \\  dP   \\                                    __..--'\n"
	"`---------------------------------''''''''''''''                  \n",
    damage)
{}

Knife::Knife(size_t damage):
    DamageItem("Knife",
	"	 ___________________________________ ______________________ \n"
	"\\                                  | (_)     (_)    (_)   \\    \n"
	" `.                                |  __________________   }   \n"
	"	`-..........................____|_(                  )_/    \n",
    damage)
{}

bool Knife::pryOpen(double threshold){
    // Grant Knife ability to unlock environment objects in the game.
    double roll{generateRandomNumber()};
    if(roll > threshold + 0.1)
        return true;
    return false;
}

Pistol::Pistol(size_t damage):
    DamageItem("Pistol",
	"+--^----------, --------, ---- - , --------^-, \n"
	"| || || || || | `------- - '     |          O  \n"
	"`+-------------------------- - ^---------- |   \n"
	"`\\_, -------- - , -------- - , --------------' \n"
	"/ XXXXXX / '|       /'                         \n"
	"/ XXXXXX / `\\ / '                              \n"
	"/ XXXXXX / `-------'                           \n"
	"/ XXXXXX /                                     \n"
	"/ XXXXXX /                                     \n"
	"(________(                                     \n"
	"`----- - ' ,                                   \n",
    damage)
{}


