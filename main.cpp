/////////////////////////////////////
// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <typeinfo>

	



/////////////////////////////////////
// Game settings
const int rowsCount = 10;
const int columnsCount = 15;
int level = 0; 
int crystal = 0;
bool keyRed = false;
bool keyGreen = false;
bool keyBlue = false;

const unsigned char symbolHero = 2;
const unsigned char symbolWall = 177;
const unsigned char symbolBox = 254;
const unsigned char symbolExit = 176;
const unsigned char symbolExitRed = 176;
const unsigned char symbolExitGreen = 176;
const unsigned char symbolExitBlue = 176;
const unsigned char symbolMine = 15;
const unsigned char symbolCrystal = 4;
const unsigned char symbolKeyRed = 'R';
const unsigned char symbolKeyGreen = 'G';
const unsigned char symbolKeyBlue = 'B';
const int levelsCount = 9;

const unsigned char levelsData[levelsCount][rowsCount][columnsCount + 1] = {
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#  X1  #   X ##",
                                                                                    "# X ### X  #  #",
                                                                                    "#X X  X  ## X #",
                                                                                    "# X    ##  #  #",
                                                                                    "#######    # X#",
                                                                                    "#   X   XX #X #",
                                                                                    "#XXX # # X   ##",
                                                                                    "#  X #   X X  #",
                                                                                    "###############",
                                                                                },
                                                                                {
                                                                                    "#####2######   ",
                                                                                    "#          #   ",
                                                                                    "#  XXXX MMC#   ",
                                                                                    "#     X  M #   ",
                                                                                    "#    X   M #   ",
                                                                                    "#   X    M #   ",
                                                                                    "#  XXXX  M #   ",
                                                                                    "#        M1#   ",
                                                                                    "#       CC #   ",
                                                                                    "############   ",
                                                                                },
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#         1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
                                                                                ,
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#  RGB    1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
                                                                                ,
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#         1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
                                                                                ,
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#         1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
                                                                                ,
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#         1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
                                                                                ,
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#         1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
                                                                                ,
                                                                                {
                                                                                    "#####2#########",
                                                                                    "#             #",
                                                                                    "#  XXXX CCCC  #",
                                                                                    "#     X       #",
                                                                                    "#    X        #",
                                                                                    "#     X       #",
                                                                                    "#  XXXX       #",
                                                                                    "#         1   #",
                                                                                    "#             #",
                                                                                    "###############",
                                                                                }
};




/////////////////////////////////////
// Logics variables
HANDLE consoleHandle = 0;
bool isGameActive = true;
unsigned char levelData[rowsCount][columnsCount];
int heroRow = 0;
int heroColumn = 0;

/////////////////////////////////////
// Functions
void SetupSystem()
{
    srand(time(0));

    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Initialise()
{
    crystal = 0; // respoyn crystal zero new level
    // Load level
    for (int r = 0; r < rowsCount; r++)
    {
        for (int c = 0; c < columnsCount; c++)
        {
            unsigned char symbol = levelsData[level][r][c];

            switch (symbol)
            {
                // Wall
            case '#':
            {
                levelData[r][c] = symbolWall;
                break;
            }

            // Hero
            case '1':
            {
                levelData[r][c] = symbolHero;

                // Catch hero position
                heroRow = r;
                heroColumn = c;

                break;
            }

            // Exit
            case '2':
            {
                levelData[r][c] = symbolExit;
                break;
            }

            // Box
            case 'X':
            {
                levelData[r][c] = symbolBox;
                break;
            }

            // Mine
            case 'M':
            {
                levelData[r][c] = symbolMine;
                break;
            }

                // Crystal
            case 'C':
            {
                levelData[r][c] = symbolCrystal;
                break;
            }

               //RedKey
            case 'R':
            {
                levelData[r][c] = symbolKeyRed;
                break;
            }

            //GreenKey
            case 'G':
            {
                levelData[r][c] = symbolKeyGreen;
                break;
            }

            //BlueKey
            case 'B':
            {
                levelData[r][c] = symbolKeyBlue;
                break;
            }

            // Other symbols (like spaces)
            default:
            {
                levelData[r][c] = symbol;
                break;
            }
            }
        }
    }
}

void Render()
{
    // Move console cursor to (0,0)
    COORD cursorCoord;
    cursorCoord.X = 0;
    cursorCoord.Y = 0;
    SetConsoleCursorPosition(consoleHandle, cursorCoord);


    printf("\n\n\t");
    for (int r = 0; r < rowsCount; r++)
    {
        for (int c = 0; c < columnsCount; c++)
        {
            unsigned char symbol = levelData[r][c];

            switch (symbol)
            {
                // Walls - white
            case symbolWall:
            {
                SetConsoleTextAttribute(consoleHandle, 15);
                break;
            }
            // Hero - green
            case symbolHero:
            {
                SetConsoleTextAttribute(consoleHandle, 10);
                break;
            }
            // Boxes - yellow
            case symbolBox:
            {
                SetConsoleTextAttribute(consoleHandle, 14);
                break;
            }
            // Exit - red
            case symbolExit:
            {
                SetConsoleTextAttribute(consoleHandle, 12);
                break;
            }

            // Mine - red
            case symbolMine:
            {
                SetConsoleTextAttribute(consoleHandle, 12);
                break;
            }

            // Crystal - red
            case symbolCrystal:
            {
                SetConsoleTextAttribute(consoleHandle, 13);
                break;
            }

            // Key - red
            case symbolKeyRed:
            {
                SetConsoleTextAttribute(consoleHandle, 13);
                break;
            }

            // Key - green
            case symbolKeyGreen:
            {
                SetConsoleTextAttribute(consoleHandle, 2);
                break;
            }

            // Key - blue
            case symbolKeyBlue:
            {
                SetConsoleTextAttribute(consoleHandle, 1);
                break;
            }
            }

            printf("%c", symbol);
        }
        printf("\n\t");
    }
    printf("\n\t level = %i", level);
    printf("\n\t crystal = %i",crystal );
    SetConsoleTextAttribute(consoleHandle, 7);
    printf("\n\n\tUse AWSD to move ");
    SetConsoleTextAttribute(consoleHandle, 10);
    printf("Hero");
    SetConsoleTextAttribute(consoleHandle, 7);
    printf(". R - Restart level.");
}

void LogicExitCels()
{
    //level++;
    if (level >= levelsCount)
    {
        isGameActive = false;
    }
    switch (level)
    {
        // level 
    case 0:
    {
        level++;
        Initialise();
        break;
    }
    case 1:
    {
        level++;
        Initialise();
        break;
    }
    case 2:
    {
        if (crystal < 3)
        {
            break;
        }
        level++;
        Initialise();
        break;
    }
    case 3:
    {        
        level++;
        Initialise();
        break;
    }
    }

    //Initialise(); 
}

void MoveHeroTo(int row, int column)
{
    unsigned char destinationCell = levelData[row][column];
    bool canMoveToCell = false;


    switch (destinationCell)
    {
        // Empty cell
    case ' ':
    {
        canMoveToCell = true;
        break;
    }

    // Exit cell
    case symbolExit:
    {
        LogicExitCels();
        break;
    }

    // Mine cell
    case symbolMine:
    {    
        Initialise();
        break;
    }

    // Crystal cell
    case symbolCrystal:
    {
        canMoveToCell = true;
        crystal++;
        break;
    }

    // KeyRed cell 
    case symbolKeyRed:
    {
        canMoveToCell = true;
        keyRed = true;
        break;
    }

    // KeyGreen cell
    case symbolKeyGreen:
    {
        canMoveToCell = true;
        keyGreen = true;
        break;
    }

    // KeyBlue cell
    case symbolKeyBlue:
    {
        canMoveToCell = true;
        keyBlue = true;
        break;
    }

    // Box
    case symbolBox:
    {
        // Calculate hero move direction
        int heroDirectionR = row - heroRow;
        int heroDirectionC = column - heroColumn;

        // Check for empty space behind the box
        if (levelData[row + heroDirectionR][column + heroDirectionC] == ' ')
        {
            canMoveToCell = true;

            // Remove box symbol from previous position
            levelData[row][column] = ' ';

            // Set box symbol to new position
            levelData[row + heroDirectionR][column + heroDirectionC] = symbolBox;
        }

        break;
    }
    }


    if (canMoveToCell)
    {
        // Remove hero symbol from previous position
        levelData[heroRow][heroColumn] = ' ';

        // Set new hero position
        heroRow = row;
        heroColumn = column;

        // Set hero symbol to new position
        levelData[heroRow][heroColumn] = symbolHero;
    }
}


void Update()
{
    unsigned char inputChar = _getch();
    inputChar = tolower(inputChar);

    switch (inputChar)
    {
        // Up
    case 'w':
    {
        MoveHeroTo(heroRow - 1, heroColumn);
        break;
    }

    // Down
    case 's':
    {
        MoveHeroTo(heroRow + 1, heroColumn);
        break;
    }

    // Left
    case 'a':
    {
        MoveHeroTo(heroRow, heroColumn - 1);
        break;
    }

    // Right
    case 'd':
    {
        MoveHeroTo(heroRow, heroColumn + 1);
        break;
    }

    // Restart level
    case 'r':
    {
        Initialise();
        break;
    }
    }
}

void Shutdown()
{
    system("cls");
    printf("\n\tPress any key to continue...");
    _getch();
}



int main()
{
    SetupSystem();
    Initialise();

    do
    {
        Render();
        Update();
    } while (isGameActive);

    Shutdown();

    return 0;
}
