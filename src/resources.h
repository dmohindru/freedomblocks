#ifndef RESOURCES_H
#define RESOURCES_H

#define GAME_BACKGROUND 	"../graphics/background.png" //Play Background file
#define GAME_DATA			    "../graphics/data.png" //Graphics data file
#define WELCOME_BACKGROUND  "../graphics/welcome.png" //Welcome Background file
#define TUTORIAL_BACKGROUND "../graphics/tutorial.png" //Tutorial Background file
#define MESSAGES_BACKGROUND "../graphics/messages.png" //Messages data file

#define COLORKEY_RED        0 //Color key red component
#define COLORKEY_GREEN      0 //Color key green component
#define COLORKEY_BLUE       0 //Color key blue component

#define COLORKEY_MESS_RED    0 //Color key red component
#define COLORKEY_MESS_GREEN  0 //Color key green component
#define COLORKEY_MESS_BLUE   255 //Color key blue component

void LoadGameGraphics();
void FreeGameGraphics();

#endif
