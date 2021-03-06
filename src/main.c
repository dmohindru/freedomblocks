/* Author: 			Dhruv Mohindru
 * Date: 				10/02/17
 * Description:	This is a main file of game which controls all other modules
 */
#include <stdio.h>
#include <stdlib.h>
#include "gamedefs.h"
#include "resources.h"
#include "tetromino.h"

static int scores, level, game_state, hiscore, game_lines;

//Function to draw main play background
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
//Function to draw welcome screen background
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
//Function to draw Press A to continue sprite in welcome screen
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
//Function to draw Press A to continue sprite in tutorial screen
static void DrawPressAContinueTutorial()
{
	SDL_Rect src, dest;
	src.w = MESS_PRESSA_BIG_WIDTH;
	src.h = MESS_PRESSA_BIG_HEIGHT;
	src.x = MESS_PRESSA_BIG_STARTX;
	src.y = MESS_PRESSA_BIG_STARTY;
	dest.w = MESS_PRESSA_BIG_WIDTH;
	dest.h = MESS_PRESSA_BIG_HEIGHT;
	dest.x = TSCR_PRESSA_STARTX;
	dest.y = TSCR_PRESSA_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
//Function to draw Press B for tutorial sprite on welcome screen
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
//Function to draw confirm quit sprite on game play screen
static void DrawConfirmQuit()
{
	SDL_Rect src, dest;
	src.w = MESS_QUIT_WIDTH;
	src.h = MESS_QUIT_HEIGHT;
	src.x = MESS_QUIT_STARTX;
	src.y = MESS_QUIT_STARTY;
	dest.w = MESS_QUIT_WIDTH;
	dest.h = MESS_QUIT_HEIGHT;
	dest.x = GAME_QUIT_STARTX;
	dest.y = GAME_QUIT_STARTY;
	SDL_BlitSurface(messages, &src, screen, &dest);
}
//Function to draw You Win sprite on game play screen
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
//Function to draw Game Over sprite on game play screen
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
//Function to draw Paused sprite on game play screen
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
//Function to draw You got hi score sprite on game play screen
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
//Function to draw Press A sprite on game play screen
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
//Function to draw Tutorial background screen
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
//Function to draw Hi Score on game play screen
static void DrawHiScores()
{
	SDL_Rect src, dest;
	int i, temp_scores, digit;
	temp_scores = hiscore;
  for(i=SCORES_DIGITS-1;i>=0;i--)
	{
		digit = temp_scores % 10;
    temp_scores /= 10;
		src.w = FONT_WIDTH;
		src.h = FONT_HEIGHT;
		src.x = FONT_STARTX + digit * (FONT_WIDTH + FONT_SPACING);
		src.y = FONT_STARTY;
		dest.w = FONT_WIDTH;
		dest.h = FONT_HEIGHT;
		dest.x = HI_SCORES_STARTX + i * (FONT_WIDTH + FONT_SPACING);
		dest.y = HI_SCORES_STARTY;
		SDL_BlitSurface(gamedata, &src, screen, &dest);
	}
}
//Function to draw Score on game play screen
static void DrawScores()
{
	SDL_Rect src, dest;
	int i, temp_scores, digit;
	temp_scores = scores;
  for(i=SCORES_DIGITS-1;i>=0;i--)
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
//Function to draw lines on game play screen
static void DrawGameLines()
{
	SDL_Rect src, dest;
	int i, temp_scores, digit;
	temp_scores = game_lines;
  for(i=LINES_DIGITS-1;i>=0;i--)
	{
		digit = temp_scores % 10;
    temp_scores /= 10;
		src.w = FONT_WIDTH;
		src.h = FONT_HEIGHT;
		src.x = FONT_STARTX + digit * (FONT_WIDTH + FONT_SPACING);
		src.y = FONT_STARTY;
		dest.w = FONT_WIDTH;
		dest.h = FONT_HEIGHT;
		dest.x = LINES_STARTX + i * (FONT_WIDTH + FONT_SPACING);
		dest.y = LINES_STARTY;
		SDL_BlitSurface(gamedata, &src, screen, &dest);
	}
}
//Function to draw Level on game play screen
static void DrawLevel()
{
	SDL_Rect src, dest;
	int i, temp_level, digit;
  temp_level = level;
	for(i=LEVEL_DIGITS-1;i>=0;i--)
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
//Function to read hi scores from file
static int ReadHiScores()
{
  FILE *hi_score_file;
  int hi_scores = 0;
  //First read attempt to open existing file
  hi_score_file = fopen(HI_SCORE_FILE, "r");
  if(!hi_score_file) //if file does not exist then create one
  {
    hi_score_file = fopen(HI_SCORE_FILE, "w");
    if(!hi_score_file)
      printf("Hi Score data file creation failed\n");
    return 0; //return 0 hi scores
  }
  fscanf(hi_score_file, "%d", &hi_scores);
  fclose(hi_score_file);
  return hi_scores;
  
}
//Function to save hi scores to a file
static void SaveHiScores(int hi_scores)
{
  FILE *hi_score_file;
  //open file writing
  hi_score_file = fopen(HI_SCORE_FILE, "w");
  if(!hi_score_file) //if some error happend during opening of file
  {
    printf("Error opening hi score file!\n");
  }
  fprintf(hi_score_file, "%d", hi_scores);
  fclose(hi_score_file);
}
//Thread to update music
static int UpdateMusicThread(void *arg)
{
  arg++; // avoid compiler warning
  PlayMusic();
  return 0;
}
//Main game loop
static void PlayGame()
{
	int quit = 0, lines_cleared, level_lines = 0, 
      score_factor, timer_running, confirm_quit, game_end, new_tetromino;
  unsigned int previous_time, current_time, delay;
	SDL_Event event;
	SDL_keysym keysym;
  SDL_Thread *music_update_thread;
  timer_running = FALSE;
  game_end = FALSE;
  confirm_quit = FALSE;
  new_tetromino = FALSE;
  game_state = STATE_WELCOME;
  music_update_thread = SDL_CreateThread(UpdateMusicThread, NULL);
  if (music_update_thread == NULL) 
    printf("Unable to start music update thread.\n");

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
							if(game_state == STATE_WELCOME)
                quit = 1;
                break;
						case LEFT_BUTTON:
							if(timer_running && game_state == STATE_PLAY)
                MoveTetromino(LEFT);
                break;
						case RIGHT_BUTTON:
              if(timer_running && game_state == STATE_PLAY)
                MoveTetromino(RIGHT);
                break;
						case UP_BUTTON:
							if(timer_running && game_state == STATE_PLAY)
                RotateTetromino();
                break;
						case DOWN_BUTTON:
							if(timer_running && game_state == STATE_PLAY)
                LandTetromino();
                break;
            case A_BUTTON:
							if(game_state == STATE_WELCOME)
              {
                game_state = STATE_PLAY;
                timer_running = TRUE;
                game_end = FALSE;
                confirm_quit = FALSE;
                InitalizePlayGrid();
                SpawnNewTetromino();
                previous_time = SDL_GetTicks();
                scores = 0;
                level = 1;
                game_lines = 0; 
                delay = DELAY_START;
                hiscore = ReadHiScores();
               }
              else if(game_state == STATE_PLAY)
              {
                if(timer_running && !game_end && !confirm_quit)
                {
                  timer_running = FALSE;
                  StopMusic();
                }
                else if(!timer_running && !game_end && !confirm_quit)
                {
                  timer_running = TRUE;
                  previous_time = SDL_GetTicks();
                  StartMusic();
                }
                else if(!timer_running && game_end && !confirm_quit)
                {
                  game_state = STATE_WELCOME;
                }
                else if(!timer_running && !game_end && confirm_quit)
                {
                  game_state = STATE_WELCOME;
                  StartMusic();
                }
              }
              else if(game_state == STATE_TUTORIAL)
              {
                game_state = STATE_WELCOME;
              }
							break;
            case B_BUTTON:
              if(game_state == STATE_WELCOME)
              {
                game_state = STATE_TUTORIAL;
              }
              else if(game_state == STATE_PLAY)
              {
                if(timer_running && !game_end && !confirm_quit)
                {
                  timer_running = FALSE;
                  confirm_quit = TRUE;
                  StopMusic();
                }
                else if(!timer_running && !game_end && confirm_quit)
                {
                  timer_running = TRUE;
                  previous_time = SDL_GetTicks();
                  confirm_quit = FALSE;
                  StartMusic();
                }
              }
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
          if(IfTetrominoLanded() && !game_end)
          {
            UpdatePlayGrid();
            score_factor = SCORES_PER_LINE;
            //check for line cleared
            while((lines_cleared = LinesCleared()))
            {
              level_lines += lines_cleared;
              if(level_lines >= LEVEL_LINES)
              {
                level++;
                level_lines = level_lines - LEVEL_LINES;
                delay -= NEXT_LEVEL_TIME;
              }
              if(level >= MAX_LEVELS)
              {
                timer_running = FALSE;
                game_end = GAME_WIN_STATE;
              }
              scores += lines_cleared * score_factor;
              score_factor += SCORES_BONUS;
              game_lines += lines_cleared;
        
            }
            if(!SpawnNewTetromino())
            {
              timer_running = FALSE;
              game_end = GAME_OVER_STATE;
              
            }
            new_tetromino = TRUE; //attemp to spawn new tetromino has been made
          }
          
          if(new_tetromino)  //If new tetromino as spawned, dont move it
            new_tetromino = FALSE;
          else
            MoveTetrominoDown(); //else move it down
            
          previous_time = current_time;
        }
      }
      DrawBackground();
      DrawGridBlocks();
      DrawTetromino(); //current tetromino
      DrawNextTetromino();
      DrawScores();
      DrawLevel();
      DrawHiScores();
      DrawGameLines();
      DrawTetrominoStats();
      if(!timer_running && !game_end && !confirm_quit)
      {
        DrawPaused();
      }
      else if(!timer_running && game_end == GAME_OVER_STATE && !confirm_quit)
      {
				DrawGameOver();
				DrawPressA();
        if(scores > hiscore)
				{
					DrawYouGotHighScore();
					//Save Hi scores here
          SaveHiScores(scores);
				}
			}
			else if(!timer_running && game_end == GAME_WIN_STATE && !confirm_quit)
      {
				DrawYouWin();
				DrawPressA();
				if(scores > hiscore)
				{
					DrawYouGotHighScore();
					//Save Hi scores here
          SaveHiScores(scores);
				}
			}
			else if(!timer_running && !game_end && confirm_quit)
			{
				DrawConfirmQuit();
			}
      
		}
    else if(game_state == STATE_WELCOME)
    {
      DrawWelcomeBackground();
      DrawPressAContinue();
      DrawPressB();
    }
    else if(game_state == STATE_TUTORIAL)
    {
      DrawTutorialBackground();
      DrawPressAContinueTutorial();
    }
    SDL_Flip(screen);
	}
}
//The main function
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
	screen = SDL_SetVideoMode(GAME_WIDTH, GAME_HEIGHT, 16, SDL_DOUBLEBUF|SDL_FULLSCREEN);
	if (screen == NULL)
    {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	//Set window caption
  SDL_WM_SetCaption("Freedom Blocks", "Dhruv Freedom Blocks");
  SDL_ShowCursor(SDL_DISABLE);
	//load game graphics
	LoadGameGraphics();
  InitMusic();
  //Play game
	PlayGame();
	//Free game data
	FreeGameGraphics();
  CloseMusic();
	
	return 0;
}

