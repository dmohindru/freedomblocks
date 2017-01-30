//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h> //think of removing it from here
#include <stdio.h>
#include <stdlib.h>
#include "gamedefs.h"
#include "resources.h"
#include "tetromino.h"

static int scores, level, game_state;

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
static void DrawWelcomeBackground()
{
	SDL_Rect src, dest;
	src.w = welcome->w;
	src.h = welcome->h;
	src.x = 0;
	src.y = 0;
	dest = src;
	SDL_BlitSurface(welcome, &src, screen, &dest);
}
static void DrawPressAContinue()
{
	SDL_Rect src, dest;
	src.w = MESS_PRESSA_BIG_WIDTH;
	src.h = MESS_PRESSA_BIG_HEIGHT;
	src.x = MESS_PRESSA_BIG_STARTX;
	src.y = MESS_PRESSA_BIG_STARTY;
	dest.w = MESS_PRESSA_BIG_WIDTH;
	dest.h = MESS_PRESSA_BIG_HEIGHT;
	dest.x = WSCR_PRESSA_STARTX;
	dest.y = WSCR_PRESSA_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
static void DrawPressB()
{
	SDL_Rect src, dest;
	src.w = MESS_PRESSB_WIDTH;
	src.h = MESS_PRESSB_HEIGHT;
	src.x = MESS_PRESSB_STARTX;
	src.y = MESS_PRESSB_STARTY;
	dest.w = MESS_PRESSB_WIDTH;
	dest.h = MESS_PRESSB_HEIGHT;
	dest.x = WSCR_PRESSB_STARTX;
	dest.y = WSCR_PRESSB_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
static void DrawConfirmQuit()
{
	SDL_Rect src, dest;
	src.w = MESS_QUIT_WIDTH;
	src.h = MESS_QUIT_HEIGHT;
	src.x = MESS_QUIT_STARTX;
	src.y = MESS_QUIT_STARTY;
	dest.w = MESS_QUIT_WIDTH;
	dest.h = MESS_QUIT_HEIGHT;
	dest.x = GAME_STATE_STARTX;
	dest.y = GAME_STATE_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
static void DrawYouWin()
{
	SDL_Rect src, dest;
	src.w = MESS_YOUWIN_WIDTH;
	src.h = MESS_YOUWIN_HEIGHT;
	src.x = MESS_YOUWIN_STARTX;
	src.y = MESS_YOUWIN_STARTY;
	dest.w = MESS_YOUWIN_WIDTH;
	dest.h = MESS_YOUWIN_HEIGHT;
	dest.x = GAME_STATE_STARTX;
	dest.y = GAME_STATE_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
static void DrawGameOver()
{
	SDL_Rect src, dest;
	src.w = MESS_GAMEOVER_WIDTH;
	src.h = MESS_GAMEOVER_HEIGHT;
	src.x = MESS_GAMEOVER_STARTX;
	src.y = MESS_GAMEOVER_STARTY;
	dest.w = MESS_GAMEOVER_WIDTH;
	dest.h = MESS_GAMEOVER_HEIGHT;
	dest.x = GAME_STATE_STARTX;
	dest.y = GAME_STATE_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
static void DrawPaused()
{
	SDL_Rect src, dest;
	src.w = MESS_PAUSED_WIDTH;
	src.h = MESS_PAUSED_HEIGHT;
	src.x = MESS_PAUSED_STARTX;
	src.y = MESS_PAUSED_STARTY;
	dest.w = MESS_PAUSED_WIDTH;
	dest.h = MESS_PAUSED_HEIGHT;
	dest.x = GAME_STATE_STARTX;
	dest.y = GAME_STATE_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
	
}
static void DrawYouGotHighScore()
{
	SDL_Rect src, dest;
	src.w = MESS_HISCORE_WIDTH;
	src.h = MESS_HISCORE_HEIGHT;
	src.x = MESS_HISCORE_STARTX;
	src.y = MESS_HISCORE_STARTY;
	dest.w = MESS_HISCORE_WIDTH;
	dest.h = MESS_HISCORE_HEIGHT;
	dest.x = HISCORE_STARTX;
	dest.y = HISCORE_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
	
}
static void DrawPressA()
{
	SDL_Rect src, dest;
	src.w = MESS_PRESSA_WIDTH;
	src.h = MESS_PRESSA_HEIGHT;
	src.x = MESS_PRESSA_STARTX;
	src.y = MESS_PRESSA_STARTY;
	dest.w = MESS_PRESSA_WIDTH;
	dest.h = MESS_PRESSA_HEIGHT;
	dest.x = PRESSA_STARTX;
	dest.y = PRESSA_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
static void DrawTutorialBackground()
{
	SDL_Rect src, dest;
	src.w = tutorial->w;
	src.h = tutorial->h;
	src.x = 0;
	src.y = 0;
	dest = src;
	SDL_BlitSurface(tutorial, &src, screen, &dest);
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
	int quit = 0, lines_cleared, level_lines = 0, 
      score_factor, timer_running;
	unsigned int previous_time, current_time, delay = 1000;
  SDL_Event event;
	SDL_keysym keysym;
  InitalizePlayGrid();
  SpawnNewTetromino();
  timer_running = TRUE;
  game_state = STATE_WELCOME;
  previous_time = SDL_GetTicks(); 
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
						case HOME_BUTTON:
							quit = 1;
							break;
						case LEFT_BUTTON:
							if(timer_running)
                MoveTetromino(LEFT);
							//printf("Moving tetromino left\n");
							break;
						case RIGHT_BUTTON:
              if(timer_running)
                MoveTetromino(RIGHT);
							//printf("Moving tetromino right\n");
							break;
						case UP_BUTTON:
							//rotate between different shapes and rotations
							if(timer_running)
                RotateTetromino();
							//printf("Rotating tetromino\n");
							break;
						case DOWN_BUTTON:
							if(timer_running)
                LandTetromino();
              //MoveTetrominoDown();
							//printf("Moving tetromino down\n");
							break;
						//temp logic below
            case A_BUTTON:
							if(timer_running)
              {
                timer_running = FALSE;
              }
              else
              {
                timer_running = TRUE;
                previous_time = SDL_GetTicks();
              }
              //SpawnNewTetromino();
							//printf("spawning new tetromino\n");
							break;
            case B_BUTTON: //increment scores and levels
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
    
	
		//Play game state
		if(game_state == STATE_PLAY)
    {
      if(timer_running)
      {
        current_time = SDL_GetTicks();
        if(current_time - previous_time >= delay)
        {
          MoveTetrominoDown();
          previous_time = current_time;
        }
      }
      DrawBackground();
      DrawGridBlocks();
      DrawTetromino(); //current tetromino
      DrawNextTetromino();
      if(IfTetrominoLanded())
      {
        UpdatePlayGrid();
        score_factor = 10;
        //check for line cleared
        while((lines_cleared = LinesCleared()))
        {
          printf("lines_cleared: %d\n", lines_cleared);
          level_lines += lines_cleared;
          printf("level_lines: %d\n", level_lines);
          if(level_lines >= 10)
          {
            level++;
            level_lines = level_lines - 10;
            delay -= NEXT_LEVEL_TIME;
          }
          if(level >= 10)
            printf("You win\n");
          scores += lines_cleared * score_factor;
          score_factor += 5;
        
        }
        if(!SpawnNewTetromino())
        {
          printf("Game over!\n");
          quit = 1;
        }
      }
    
      DrawScores();
      DrawLevel();
      if(!timer_running)
      {
        //SDL BILT Paused bitmap
      }
      
		}
    else if(game_state == STATE_WELCOME)
    {
      DrawWelcomeBackground();
      //DrawPressAContinue();
      //DrawPressB();
      //DrawConfirmQuit();
      //DrawYouWin();
      //DrawGameOver();
      DrawPaused();
      DrawYouGotHighScore();
      DrawPressA();
    }
    else if(game_state == STATE_TUTORIAL)
    {
      DrawTutorialBackground();
     
    }
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

