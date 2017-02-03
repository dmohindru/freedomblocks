#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <AL/alut.h>
#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>
#include "resources.h"
#include "gamedefs.h"

static char music_buffer[16384];
static OggVorbis_File vf;
static vorbis_info *vi;
static int current_section;
static ALuint source;


void LoadGameGraphics()
{
  //Load game background
	temp = IMG_Load(GAME_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load game play background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  background = SDL_DisplayFormat(temp);
	if (background == NULL)
  {
    printf("Unable to convert game play background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
	//Load game data
	temp = IMG_Load(GAME_DATA);
	if (temp == NULL)
  {
		printf("Unable to load game data file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  //set the color key
  SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
		  (Uint16) SDL_MapRGB(temp->format, COLORKEY_RED, 
                  COLORKEY_GREEN, COLORKEY_BLUE));
  //convert game data bitmap for fast animation
  gamedata = SDL_DisplayFormat(temp);
  if (gamedata == NULL)
  {
    printf("Unable to convert the gamedata bitmap\n");
    exit(EXIT_FAILURE);
  }
  // Free temp surface
  SDL_FreeSurface(temp);
  //Load Welcome screen
  temp = IMG_Load(WELCOME_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load Welcome background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  welcome = SDL_DisplayFormat(temp);
	if (welcome == NULL)
  {
    printf("Unable to convert welcome background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
  
  //Load Tutorial Background
  temp = IMG_Load(TUTORIAL_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load Tutorial background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  tutorial = SDL_DisplayFormat(temp);
	if (tutorial == NULL)
  {
    printf("Unable to convert tutorial background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
  
  //Load Messages bitmap
  temp = IMG_Load(MESSAGES_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load Message background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  //set the color key
  SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
		  (Uint16) SDL_MapRGB(temp->format, COLORKEY_RED, 
                  COLORKEY_GREEN, COLORKEY_BLUE));
  messages = SDL_DisplayFormat(temp);
	if (messages == NULL)
  {
    printf("Unable to convert messages background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
}

void FreeGameGraphics()
{
  SDL_FreeSurface(background);
  SDL_FreeSurface(gamedata);
  SDL_FreeSurface(welcome);
  SDL_FreeSurface(tutorial);
  SDL_FreeSurface(messages);
}

void InitMusic()
{
  FILE *fp = fopen(GAMEMUSIC, "rb");
  unsigned long pos, ret;
  int i;
  if(fp == NULL)
  {
    fprintf(stderr, "could not open file %s", GAMEMUSIC);
    exit(1);
  }

  if(ov_open_callbacks(fp, &vf, NULL, 0, OV_CALLBACKS_DEFAULT)<0)
  {
    fprintf(stderr, "input does not appear to be in an ogg bitstream");
    exit(1);
  }

  vi = ov_info(&vf, -1);

  alutInit (0, 0);
   
  ALuint buffers[16];
  alGenBuffers(16, buffers);

  alGenSources (1, &source);
   

  for(i = 0;i<16;++i)
  {
    pos = 0;

    while(pos < sizeof(music_buffer))
    {
      ret = ov_read(&vf, music_buffer+pos, sizeof(music_buffer)-pos, 0, 2, 1, &current_section);
      pos+=ret;
      if(ret == 0)
      {
        break;
      }
    }
   
    alBufferData(buffers[i], AL_FORMAT_STEREO16, music_buffer, pos, vi->rate);
   }
   alSourceQueueBuffers(source, 16, buffers);
   
   alSourcePlay(source);
}
void PlayMusic()
{
  ALuint released[16];
  ALint count;
  int i;
  unsigned long pos, ret;
  while(1)
  {
    alGetSourcei(source, AL_BUFFERS_PROCESSED, &count);
    alSourceUnqueueBuffers(source, count, released);
    for(i=0;i<count;++i)
    {
      pos = 0;
      while(pos < sizeof(music_buffer))
      {
        ret = ov_read(&vf, music_buffer+pos, sizeof(music_buffer)-pos, 0, 2, 1, &current_section);
        pos+=ret;
        if(ret == 0)
        {
          //rewind music file
          if(ov_raw_seek(&vf, 0))
          {
						printf("Unable to rewind music file\n");
						return;
					}
          //eof = 1;
          //break;
        }
      }
      alBufferData(released[i], AL_FORMAT_STEREO16, music_buffer, pos, vi->rate);
   
    }
    alSourceQueueBuffers(source, count, released);
    alutSleep(1/20.);
  }
}
void CloseMusic()
{
  if (music_enabled) {
	/* Stop music playback. */
	alSourceStop(music_source);

	/* Delete the buffer and the source. */
	alDeleteBuffers(NUM_BUFFERS, music_buffer);
	alDeleteSources(1, &music_source);
	alutExit();
	//free(buf);
	/* Close the music file, if one is open. */
	if (music_file_loaded) {
	    ov_clear(&music_file);
	    music_file_loaded = 0;
	}

	music_enabled = 0;
    }
}

