#include <stdio.h>
#include "menu.h"

void title_screen() {
    const char* lines[] = {
        "################################################",
        "##                                            ##",
        "##                                            ##",
        "##             American Soldier               ##",
        "##                 -V0.1-                     ##",
        "##                                            ##",
        "##                                            ##",
        "##                                            ##",
        "##            1.GAME START                    ##",
        "##            2.How TO Play                   ##",
        "##            3.EXIT                          ##",
        "##                                            ##",
        "################################################"
    };

    int i = 0;
    while (i < 13) {
        printf("%s\n", lines[i]);
        i++;
    }
}
