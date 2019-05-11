#include "Enemies.h"

std::string Gman::charAscii(){
    return  "                                                  \n" \
			"                     `:/++:.                      \n" \
			"                    hMMMMMMMm`                    \n" \
			"                    NNmNNNNNM-                    \n" \
			"                   `mNNNNNMNM:                    \n" \
			"                   .NNMMNNMNN/                    \n" \
			"                    /mNMNMMMh`                    \n" \
			"                     +NMMMMN`                     \n" \
			"                    .oNNMMMm+`                    \n" \
			"                .:/hMMmNNNNNMNs/-.                \n" \
			"            :sdNMMMMMMNNMMNNMMMMMMNds.            \n" \
			"            mMMMMMMMMMMNMMNNMMMMMMMMMy            \n" \
			"           :MMMMMMMMMMMMMMNMMMMMMMMMMN`           \n" \
			"           +MMMMMMMMMMMMMMMMMMMMMMMMMM-           \n" \
			"           hMMMMMMMMMMMMMMMMMMMMMMMMMM/           \n" \
			"          `NMMMMMMMMMMMMMMMMMMMMMMMMMMo           \n" \
			"          .MMMMMMMMMMMMMMMMMMMMMMMMMMMh           \n" \
			"          /MMMMMMMMMMMMMMMMMMMMMMMMMMMm           \n" \
			"          oMMMMMMMMMMMMMMMMMMMMMMMMMMMN`          \n" \
			"          sMMMMMMMMMMMMMMMMMMMMMMMMMMMM-          \n" \
			"          dMMMMMMMMMMMMMMMMMMMMMMMMMMMM+          \n" \
			"         `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMs          \n" \
			"         -MMMMMMMMMMMMMMMMMMMMMMMMMMMMMh          \n" \
			"         +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMm          \n" \
			"         sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`         \n";
}

std::string Gman::lineIntro(){
    return "Rise and shine Mr. Freeman. Rise and shine. Not that I wish to " \
           "imply you have been sleeping on the job. No one is more deserving " \
           "of a rest and all the effort in the world would have gone to waste " \
           "until... well, let's just say your hour has come again.";
}

std::string Gman::lineIntro2(){
    return "Come on Mr. Freeman, time to try again.";
}

std::string Gman::lineFinal(){
    return "The right man in the wrong place can make all the difference " \
           "in the world... Mr. Freeman. Now enjoy some rest while I talk " \
		   "to your supervisor.";
}

std::string Gman::linePlayer(){
	return "You. Yes, you, the one controlling everything. I am talking to you. " \
		   "In the game folder you'll find and img.png file. " \
		   "Open it in paint, draw a digit in each box and save it.    I am waiting.";
}

std::string Guard::charAscii(bool boss){
	if (!boss)
		return  
		"                                                  \n"
		"                    .:+ossso+:`                   \n" \
		"                   /mhyysyyyhdy`                  \n" \
		"                  .dddhhdhhhhdds                  \n" \
		"                  dNMMMMMMMMNNMN/                 \n" \
		"                 .MMMMNNmNNNNNMMy                 \n" \
		"                 :MMNmmmshmNNmMMd                 \n" \
		"                 `mMNyyhsyhyydMMh                 \n" \
		"                  /NMhyydhyyhdMMo                 \n" \
		"                   -oydhddhhmdy+                  \n" \
		"                `    `hdmmddh:                    \n" \
		"             :dNNs++sooymmdyss/:/::ydh/           \n" \
		"            :dNMMNhymdmddhhdmdydmddMMMm/`         \n" \
		"          .+smmNMMhhhhddNMMNNdhhdyyMMMmso-        \n" \
		"         -ssyNMMMMNNNNNmNMNmmdNNmmNNMMdyss/       \n" \
		"         oyhhNNddmNNNNMMMMMNNMMMNmMMNMdhyhy-      \n" \
		"         yhddmmMMMMMMMNNMMNMMNMNdMMMMNdhdhy+      \n" \
		"        `dmmmmNNMNNMNMMNMMNNNNmNMMMMMNmmmddy      \n" \
		"        .dmmmmNNMNNNNNNNNMNNNNMNNNNMMNmmmmmh      \n" \
		"        -ddddmNMMMmNmNNMMNmNNNNNMNNNmsmmdddh`     \n" \
		"        /ddddd+MMMMMNNNMMMMNNNNNMNNM//dddhdh/     \n" \
		"       `yddddd`dNNNNNMMMMNNMNNNNMMMm  ydddhhy`    \n" \
		"       +hddddo oMNMMMMMMMNMMMMMMMMMo  .ddddhh/    \n" \
		"      `hhddmm. -MMMMMMNNNNNMMMMMMMM.   omdhhd+    \n" \
		"      :hdmmm+  /MMNNMMNMMNMMNNNNMMm    .mmmdd+    \n";
	else
		return
		"                                                 \n"
		"                     ```                         \n"
		"                 `....-----.                     \n"
		"                .//:-:/++++++.                   \n"
		"                :++oossoosssy/                   \n"
		"                -dmmyhNNmmdhho+:                 \n"
		"               +sdhNhmNhhhhMdsy.                 \n"
		"               -mdmh/ommmdmdhhy                  \n"
		"                `osyhhysssyyyd.                  \n"
		"                 :yyhhysyhhhs`                   \n"
		"                  yhdddhdhd:                     \n"
		"                  :hhhddmdd-                     \n"
		"                   :mmmmddho-.                   \n"
		"                `-sdddddddhdNm/                  \n"
		"         ```..-:hNNMNddmNNNNNMN+--.``            \n"
		"        `-----:+NNmmNMNMMNNNNMd+:::--:`          \n"
		"       `-::--:/oNmddmMMMmmmNNm+::::-::-.         \n"
		"       -://:-:+yNhhhmMMNddhmNdo///////:-`        \n"
		"       :/+/://+hdyyhNNMNhyyhNh+//////:::-        \n"
		"       /+/+///+mdyydMNMNyyydNho/////::::-        \n"
		"       /+/++/+oNdyhmMNNMhyydMho+//+/://:-.       \n"
		"       /oo++//oNmddNMNMMdyhhmho++++/+/::/-       \n"
		"       /+oso++sNmhdNNNNMdhhdmhso++oo+///::       \n"
		"       /+oss+oyMmdmMNMMMmhdmNyso+oss++///:`      \n"
		"                                                 \n"
		"           YOU FACE THE FINAL GUARD!             \n";

}

std::string Guard::lineAlerted(){
	return "Hey there! Stay where you are! I'll guard the door. ";
}

std::string Guard::lineConfused(){
	return "What are you doing? Did you see something?";
}

std::string Guard::lineLeave(){
	return "Sorry, but I cannot let you leave!";
}

std::string Guard::lineCooperation(){
	return "Thank you for your cooperation! I'll make sure to put in a good word!";
}

std::string Guard::lineKnife(){
	return "Do not bring a knife to a gun fight.";
}

std::string Guard::lineFinal(){
	return "Essentially... Essentially... Ess..." \
		   "What do we have here?";
}