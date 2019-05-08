#include "Enemies.h"

void Gman::showCharacter(){
    std::cout<<
    "                     `:/++:.                      \n"
    "                    hMMMMMMMm`                    \n"
    "                    NNmNNNNNM-                    \n"
    "                   `mNNNNNMNM:                    \n"
    "                   .NNMMNNMNN/                    \n"
    "                    /mNMNMMMh`                    \n"
    "                     +NMMMMN`                     \n"
    "                    .oNNMMMm+`                    \n"
    "                .:/hMMmNNNNNMNs/-.                \n"
    "            :sdNMMMMMMNNMMNNMMMMMMNds.            \n"
    "            mMMMMMMMMMMNMMNNMMMMMMMMMy            \n"
    "           :MMMMMMMMMMMMMMNMMMMMMMMMMN`           \n"
    "           +MMMMMMMMMMMMMMMMMMMMMMMMMM-           \n"
    "           hMMMMMMMMMMMMMMMMMMMMMMMMMM/           \n"
    "          `NMMMMMMMMMMMMMMMMMMMMMMMMMMo           \n"
    "          .MMMMMMMMMMMMMMMMMMMMMMMMMMMh           \n"
    "          /MMMMMMMMMMMMMMMMMMMMMMMMMMMm           \n"
    "          oMMMMMMMMMMMMMMMMMMMMMMMMMMMN`          \n"
    "          sMMMMMMMMMMMMMMMMMMMMMMMMMMMM-          \n"
    "          dMMMMMMMMMMMMMMMMMMMMMMMMMMMM+          \n"
    "         `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMs          \n"
    "         -MMMMMMMMMMMMMMMMMMMMMMMMMMMMMh          \n"
    "         +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMm          \n"
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
           "in the world, Mr. Freeman. Thank you for your service.";
}

void Guard::showCharacter(){
    std::cout<<
    "                    .:+ossso+:`                   \n"
    "                   /mhyysyyyhdy`                  \n"
    "                  .dddhhdhhhhdds                  \n"
    "                  dNMMMMMMMMNNMN/                 \n"
    "                 .MMMMNNmNNNNNMMy                 \n"
    "                 :MMNmmmshmNNmMMd                 \n"
    "                 `mMNyyhsyhyydMMh                 \n"
    "                  /NMhyydhyyhdMMo                 \n"
    "                   -oydhddhhmdy+                  \n"
    "                `    `hdmmddh:                    \n"
    "             :dNNs++sooymmdyss/:/::ydh/           \n"
    "            :dNMMNhymdmddhhdmdydmddMMMm/`         \n"
    "          .+smmNMMhhhhddNMMNNdhhdyyMMMmso-        \n"
    "         -ssyNMMMMNNNNNmNMNmmdNNmmNNMMdyss/       \n"
    "         oyhhNNddmNNNNMMMMMNNMMMNmMMNMdhyhy-      \n"
    "         yhddmmMMMMMMMNNMMNMMNMNdMMMMNdhdhy+      \n"
    "        `dmmmmNNMNNMNMMNMMNNNNmNMMMMMNmmmddy      \n"
    "        .dmmmmNNMNNNNNNNNMNNNNMNNNNMMNmmmmmh      \n"
    "        -ddddmNMMMmNmNNMMNmNNNNNMNNNmsmmdddh`     \n"
    "        /ddddd+MMMMMNNNMMMMNNNNNMNNM//dddhdh/     \n"
    "       `yddddd`dNNNNNMMMMNNMNNNNMMMm  ydddhhy`    \n"
    "       +hddddo oMNMMMMMMMNMMMMMMMMMo  .ddddhh/    \n"
    "      `hhddmm. -MMMMMMNNNNNMMMMMMMM.   omdhhd+    \n"
    "      :hdmmm+  /MMNNMMNMMNMMNNNNMMm    .mmmdd+    \n";
}
