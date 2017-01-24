#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //think of removing it from here
#include <stdio.h>
#include <stdlib.h>
#include "gamedefs.h"
#include "resources.h"
#include "tetromino.h"

static int scores, level;

static void DrawBackground()
{
	SDL_Rect src, dest;
	src.w = background->w;
	src.h = background->h;
	src.x = 0;
	src.y = 0;
	dest = src;
	SDL_BlitSurface(background, &src, screen, &dest);
}
static void DrawScores()
{
	SDL_Rect src, dest;
	int i, temp_scores, digit;
	temp_scores = scores;
  for(i=3;i>=0;i--)
	{
		digit = temp_scores % 10;
    temp_scores /= 10;
		src.w = FONT_WIDTH;
		src.h = FONT_HEIGHT;
		src.x = FONT_STARTX + digit * (FONT_WIDTH + FONT_SPACING);
		src.y = FONT_STARTY;
		dest.w = FONT_WIDTH;
		dest.h = FONT_HEIGHT;
		dest.x = SCORES_STARTX + i * (FONT_WIDTH + FONT_SPACING);
		dest.y = SCORES_STARTY;
		SDL_BlitSurface(gamedata, &src, screen, &dest);
	}
}
static void DrawLevel()
{
	SDL_Rect src, dest;
	int i, temp_level, digit;
  temp_level = level;
	for(i=1;i>=0;i--)
	{
		digit = temp_level % 10;
    temp_level /= 10;
		src.w = FONT_WIDTH;
		src.h = FONT_HEIGHT;
		src.x = FONT_STARTX + digit * (FONT_WIDTH + FONT_SPACING);
		src.y = FONT_STARTY;
		dest.w = FONT_WIDTH;
		dest.h = FONT_HEIGHT;
		dest.x = LEVEL_STARTX + i * (FONT_WIDTH + FONT_SPACING);
		dest.y = LEVEL_STARTY;
		SDL_BlitSurface(gamedata, &src, screen, &dest);
	}
	
}

static void PlayGame()
{
	int quit = 0;
	SDL_Event event;
	SDL_keysym keysym;
  InitalizePlayGrid();
  SpawnNewTetromino();
	while(quit == 0)
  {
    while(SDL_PollEvent(&event))
    {
			switch(event.type)
			{
				case SDL_KEYDOWN:
					keysym = event.key.keysym;
          switch(keysym.sym)
					{
						case SDLK_q:
							quit = 1;
							break;
						case SDLK_LEFT:
							MoveTetromino(LEFT);
							printf("Moving tetromino left\n");
							break;
						case SDLK_RIGHT:
							MoveTetromino(RIGHT);
							printf("Moving tetromino right\n");
							break;
						case SDLK_UP:
							//rotate between different shapes and rotations
							RotateTetromino();
							printf("Rotating tetromino\n");
							break;
						case SDLK_DOWN:
							//LandTetromino();
              MoveTetrominoDown();
							printf("Moving tetromino down\n");
							break;
						//temp logic below
            case SDLK_n:
							SpawnNewTetromino();
							printf("spawning new tetromino\n");
							break;
            case SDLK_i: //increment scores and levels
              level += 1;
              scores += 51;
              if(level >= 100)
                level = 0;
              if(scores >= 10000)
                scores = 0;
              break;
						default:
							break;
					}
					break;
        
        case SDL_QUIT:
          quit = 1;
          break;
          
				default:
					break;
			}
		}
	
		//draw stuff
		DrawBackground();
		DrawGridBlocks();
    DrawTetromino(); //current tetromino
    DrawNextTetromino();
    if(IfTetrominoLanded())
    {
      UpdatePlayGrid();
      if(!SpawnNewTetromino())
      {
        printf("Game over!\n");
        quit = 1;
      }
      printf("Tetromino landed\n");
    }
    
    DrawScores();
		DrawLevel();
		
		//DrawTetromino(); //next tetromino
    SDL_Flip(screen);
		
	}
}

int main(int argc, char **argv)
{
	//avoid compiler warnings
	argc++;
	argv++;
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
		printf("Unable to initialise SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);

	// Attempt to set game screen
	screen = SDL_SetVideoMode(GAME_WIDTH, GAME_HEIGHT, 16, SDL_DOUBLEBUF);
	if (screen == NULL)
    {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	//Set window caption
  SDL_WM_SetCaption("Freedom Blocks", "Dhruv Freedom Blocks");
	//load game graphics
	LoadGameGraphics();
  //initalize scores and level
  scores = 0;
  level = 1;
	//Play game
	PlayGame();
	//Free game data
	FreeGameGraphics();
	
	return 0;
}

