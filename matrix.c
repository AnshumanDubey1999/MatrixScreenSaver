#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#define LINESIZE 150
#define LINES 30



char** introFrame(char **frame){
	//printf("3\n");
	frame = (char**)malloc(sizeof(char)*15*151);
    frame[0]  = "            888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888            ";
    frame[1]  = "            8888888888888888888888888888888888888888888888888888888888 88  88 888888888888888888888888888888888888888888888888888888888888            ";
    frame[2]  = "                                                                  88   88  88 88__                                                                    ";
    frame[3]  = "                                                                  88   888888 88\"\"                                                                    ";
    frame[4]  = "                           .         .                            88   88  88 888888                                                                  ";
    frame[5]  = "                          ,8.       ,8.                   .8.    8888888 8888888888 8 888888888o.    8 8888 `8.`8888.      ,8'                        ";
    frame[6]  = "                         ,888.     ,888.                 .888.         8 8888       8 8888    `88.   8 8888  `8.`8888.    ,8'                         ";
    frame[7]  = "                        .`8888.   .`8888.               :88888.        8 8888       8 8888     `88   8 8888   `8.`8888.  ,8'                          ";
    frame[8]  = "                       ,8.`8888. ,8.`8888.             . `88888.       8 8888       8 8888     ,88   8 8888    `8.`8888.,8'                           ";
    frame[9]  = "                      ,8'8.`8888,8^8.`8888.           .8. `88888.      8 8888       8 8888.   ,88'   8 8888     `8.`88888'                            ";
    frame[10] = "                     ,8' `8.`8888' `8.`8888.         .8`8. `88888.     8 8888       8 888888888P'    8 8888     .88.`8888.                            ";
    frame[11] = "                    ,8'   `8.`88'   `8.`8888.       .8' `8. `88888.    8 8888       8 8888`8b        8 8888    .8'`8.`8888.                           ";
    frame[12] = "                   ,8'     `8.`'     `8.`8888.     .8'   `8. `88888.   8 8888       8 8888 `8b.      8 8888   .8'  `8.`8888.                          ";
    frame[13] = "                  ,8'       `8        `8.`8888.   .888888888. `88888.  8 8888       8 8888   `8b.    8 8888  .8'    `8.`8888.                         ";
    frame[14] = "                 ,8'         `         `8.`8888. .8'       `8. `88888. 8 8888       8 8888     `88.  8 8888 .8'      `8.`8888.                        ";
    return frame;
}

char** creditsFrame(char **frame){
	frame = (char**)malloc(sizeof(char)*16*150);
	frame[0] = "                     .o.                            oooo                                                                                              ";
	frame[1] = "                    .888.                           `888                                                                                              ";
	frame[2] = "                   .8\"888.     ooo. .oo.    .oooo.o  888 .oo.   oooo  oooo  ooo. .oo.  .oo.    .oooo.   ooo. .oo.                                     ";
	frame[3] = "                  .8' `888.    `888P\"Y88b  d88(  \"8  888P\"Y88b  `888  `888  `888P\"Y88bP\"Y88b  `P  )88b  `888P\"Y88b                                    ";
	frame[4] = "                 .88ooo8888.    888   888  `\"Y88b.   888   888   888   888   888   888   888   .oP\"888   888   888                                    ";
	frame[5] = "                .8'     `888.   888   888  o.  )88b  888   888   888   888   888   888   888  d8(  888   888   888                                    ";
	frame[6] = "               o88o     o8888o o888o o888o 8\"\"888P' o888o o888o  `V88V\"V8P' o888o o888o o888o `Y888\"\"8o o888o o888o                                   ";
	frame[7] = "                                                                            oooooooooo.                .o8                                            ";
	frame[8] = "                                                                            `888'   `Y8b              \"888                                            ";
	frame[9] = "                                                                             888      888 oooo  oooo   888oooo.   .ooooo.  oooo    ooo                ";
	frame[10] = "                                                                             888      888 `888  `888   d88' `88b d88' `88b  `88.  .8'                 ";
	frame[11] = "                                                                             888      888  888   888   888   888 888ooo888   `88..8'                  ";
	frame[12] = "                                                                             888     d88'  888   888   888   888 888    .o    `888'                   ";
	frame[13] = "                                                                            o888bood8P'    `V88V\"V8P'  `Y8bod8P' `Y8bod8P'     .8'                    ";
	frame[14] = "                                                                                                                           .o..P'                     ";
	frame[15] = "                                                                                                                           `Y8P'                      ";
	return frame;
}


char * newLine(char* lastLine, char* permanentLine, char* newLine, int density, int scarcity, int i) {
	int j;
	char character;
	for (int j = 0; j < LINESIZE; j++){
		srand(time(0) * i + character * j);                                         //To randomize the rand function with current time
		character = rand() % 93 + 33;
		if(permanentLine!=NULL && permanentLine[j] != ' '){
			newLine[j] = permanentLine[j];
		}
		else if (lastLine[j] == ' '){
			if (rand()%100 < (100-(density+scarcity)))
				newLine[j] = character;
			else
				newLine[j] = ' ';
		}
		else{
			if (rand() % 100 < density)
				newLine[j] = character;
			else
				newLine[j] = ' ';
		}
	}
	newLine[LINESIZE] = '\0';
	return newLine;
}

int main()
{
    system("title MATRIX");
    system("color 04");
    system("mode 150, 35");

    printf("Shall we begin?");
    scanf("%*c");
    printf("\n\n\n");
    char *s1, *s2;
    int i, j;
    char character = ' ';
    char **intro, **credit;
    intro = introFrame(intro);
    credit = creditsFrame(credit);
    //printf("1\n");

    s1 = (char*)malloc(sizeof(char)*151);
    s2 = (char*)malloc(sizeof(char)*151);
    strcpy(s1, intro[0]);
    //printf("2\n");
    for (i = 0; i < 15; ++i)
    {
    	s2 = newLine(s1, intro[i], s2, 2, 96, i);
        Sleep(200);
        printf("%s", s2);
        strcpy(s1,s2);
    }
    Sleep(500);

    for(i = 0; i < 20; i++)
    {
        s2 = newLine(s1, NULL, s2, 95, (10-i), i);
        Sleep(40);
        printf("%s", s2);
        strcpy(s1,s2);
    }
    //Constructing s1


    // createFrame(s1, frame);
    // printFrame(frame);

    //Constructing s2 based on s1

    for(i = 0; i < 9000; i++)
    {
        s2 = newLine(s1, NULL, s2, 85, 10, i);
        Sleep(40);
        printf("%s", s2);
        strcpy(s1,s2);
    }
    return 0;
}