// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

double  g_dElapsedTime;
double  g_dDeltaTime;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;
area *place[1];
trainer gamer;
int encounter = 0;


// Game specific variables here
SGameChar   g_sChar;
EGAMESTATES g_eGameState = EGAMESTATES::S_SPLASHSCREEN; // initial state

// Console object
Console g_Console(160, 80, "SP1 asciimon: the new begining");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    

    // sets the initial state for the game
    g_eGameState = EGAMESTATES::S_SPLASHSCREEN;

    g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2; // start pos
    g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Get all the console input events
//            This function sets up the keyboard and mouse input from the console.
//            We will need to reset all the keyboard status, because no events will be sent if no keys are pressed.
//
//            Remember to set the handlers for keyboard and mouse events.
//            The function prototype of the handler is a function that takes in a const reference to the event struct
//            and returns nothing. 
//            void pfKeyboardHandler(const KEY_EVENT_RECORD&);
//            void pfMouseHandlerconst MOUSE_EVENT_RECORD&);
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{
    // resets all the keyboard events
    memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
    // then call the console to detect input from user
    g_Console.readConsoleInput();    
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the keyboard input. Whenever there is a keyboard event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            The KEY_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any keyboard event in the Splashscreen state
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent - reference to a key event struct
// Output   : void
//--------------------------------------------------------------
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{    
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: gameplayKBHandler(keyboardEvent);// don't handle anything for the splash screen
        break;
    case EGAMESTATES::S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case EGAMESTATES::S_BATTLE: gameplayKBHandler(keyboardEvent);
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the mouse input. Whenever there is a mouse event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            For the mouse event, if the mouse is not moved, no event will be sent, hence you should not reset the mouse status.
//            However, if the mouse goes out of the window, you would not be able to know either. 
//
//            The MOUSE_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any mouse event in the Splashscreen state
//            
// Input    : const MOUSE_EVENT_RECORD& mouseEvent - reference to a mouse event struct
// Output   : void
//--------------------------------------------------------------
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{    
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case EGAMESTATES::S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the keyboard handler in the game state. Whenever there is a keyboard event in the game state, this function will be called.
//            
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case 0x31: key = K_ONE; break;
    case 0x32: key = K_TWO; break;
    case 0x33: key = K_THREE; break;
    case 0x57: key = K_UP; break;
    case 0x53: key = K_DOWN; break;
    case 0x41: key = K_LEFT; break; 
    case 0x44: key = K_RIGHT; break; 
    case 0x45: key = K_INTERACT; break;
    case 0x42: key = K_INVENTORY; break;
    case VK_ESCAPE: key = K_ESCAPE; break; 
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
    }    
}

//--------------------------------------------------------------
// Purpose  : This is the mouse handler in the game state. Whenever there is a mouse event in the game state, this function will be called.
//            
//            If mouse clicks are detected, the corresponding bit for that mouse button will be set.
//            mouse wheel, 
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    switch (g_eGameState)
    {
        case EGAMESTATES::S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case EGAMESTATES::S_GAME : updateGame(); // gameplay logic when we are in the game
            break;
        case EGAMESTATES::S_INVENTORY: updateInventory();
            break;
        case EGAMESTATES::S_STORAGE: updateStorage();
            break;
        case EGAMESTATES::S_BATTLE: updateBattle();
            break;
        case EGAMESTATES::S_MAP: updateMap();
            break;
    }
}


void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_skKeyEvent[K_INTERACT].keyReleased)
    {
        g_eGameState = EGAMESTATES::S_GAME;
        place[0] = new route_1;
    }
}

void updateGame()       // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                        // sound can be played here too.
}

void updateInventory()
{
    
}

void updateStorage()
{

}

/*void updateBattle()
{
    battle fight;
    if (g_skKeyEvent[K_ONE].keyReleased)
    {
        if (have move?)
        {
            do move
        }
    }
    else if(g_skKeyEvent[K_TWO].keyReleased)
    {
        if (have move?)
        {
            do move
        }
    }
    else if(g_skKeyEvent[K_THREE].keyReleased)
    {
        if (have move?)
        {
            do move
        }
    }
}*/

void updateMap()
{

}

void moveCharacter(area* place)
{    
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character
    if (g_skKeyEvent[K_UP].keyReleased)
    {
        if (place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) != '|' ||
            place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) != '-' ||
            place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) != '\\' ||
            place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) != '/')
        {
            if (place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) == ' ')
            {
                gamer.setPositionY(gamer.getPositionY() - 1);
            }
            else if(place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) == 'V')
            {
                gamer.setPositionY(gamer.getPositionY() - 1);
                if (rand() % 10 == 0)
                {
                    encounter = 1;
                    g_eGameState = EGAMESTATES::S_BATTLE;
                }
            }
            else if(place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) == 'T')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 2;
            }
            else if(place->readMap(gamer.getPositionY() - 1,gamer.getPositionX()) == 'G')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 3;
            }
        }
    }
    if (g_skKeyEvent[K_LEFT].keyReleased)
    {
        
         if (place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) != '|' ||
            place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) != '-' ||
            place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) != '\\' ||
            place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) != '/')
        {
            if (place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) == ' ')
            {
                gamer.setPositionX(gamer.getPositionX() - 1);
            }
            else if(place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) == 'V')
            {
                gamer.setPositionX(gamer.getPositionX() - 1);
                if (rand() % 10 == 0)
                {
                    g_eGameState = EGAMESTATES::S_BATTLE;
                    encounter = 1;
                }
            }
            else if(place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) == 'T')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 2;
            }
            else if(place->readMap(gamer.getPositionY(),gamer.getPositionX() - 1) == 'G')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 3;
            }
        }
    }
    if (g_skKeyEvent[K_DOWN].keyReleased)
    {
        
         if (place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) != '|' ||
            place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) != '-' ||
            place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) != '\\' ||
            place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) != '/')
        {
            if (place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) == ' ')
            {
                gamer.setPositionY(gamer.getPositionY() + 1);
            }
            else if(place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) == 'V')
            {
                gamer.setPositionY(gamer.getPositionY() + 1);
                if (rand() % 10 == 0)
                {
                    g_eGameState = EGAMESTATES::S_BATTLE;
                    encounter = 1;
                }
            }
            else if(place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) == 'T')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 2;
            }
            else if(place->readMap(gamer.getPositionY() + 1,gamer.getPositionX()) == 'G')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 3;
            }
        }
    }
    if (g_skKeyEvent[K_RIGHT].keyReleased)
    {

        
         if (place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) != '|' ||
            place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) != '-' ||
            place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) != '\\' ||
            place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) != '/')
        {
            if (place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) == ' ')
            {
                gamer.setPositionX(gamer.getPositionX() + 1);
            }
            else if(place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) == 'V')
            {
                gamer.setPositionX(gamer.getPositionX() + 1);
                if (rand() % 10 == 0)
                {
                    g_eGameState = EGAMESTATES::S_BATTLE;
                    encounter = 1;
                }
            }
            else if(place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) == 'T')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 2;
            }
            else if(place->readMap(gamer.getPositionY(),gamer.getPositionX() + 1) == 'G')
            {
                g_eGameState = EGAMESTATES::S_BATTLE;
                encounter = 3;
            }
        }
    }
    /*
    if (g_skKeyEvent[K_INVENTORY].keyReleased)
    {
        OPEN INVENTORY;
    }
    if (g_skKeyEvent[K_INTERACT].keyReleased)
    {
        g_sChar.m_bActive = !g_sChar.m_bActive;
    }
    */
   
}
void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[K_ESCAPE].keyReleased)
        g_bQuitGame = true;    
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: renderSplashScreen();
        break;
    case EGAMESTATES::S_GAME: renderGame();
        break;
    case EGAMESTATES::S_INVENTORY: renderInventory();
        break;
    case EGAMESTATES::S_BATTLE: renderBattle();
        break;
    case EGAMESTATES::S_MAP: renderMap();
        break;
    }
    //renderFramerate();      // renders debug information, frame rate, elapsed time, etc
    //renderInputEvents();    // renders status of input events
    //renderToScreen();       // dump the contents of the buffer to the screen, one frame worth of game
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x1F);
}
/*
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}
*/

void renderMove()
{
    COORD c;
    c.X = 0;
    for (int i = 0; i < 50; i++)
    {
        c.Y = i;
        std::string st = place[0]->readMap(i,0,110);
        g_Console.writeToBuffer(c,st,0x03);
    }
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c;
    c.X = 0;
    for (int i = 0; i < 50; i++)
    {
        c.Y = i;
        g_Console.writeToBuffer(c,"                                                                                                              ", 0x03);
    }
    c = g_Console.getConsoleSize();
    c.X = c.X / 2 - 8;
    c.Y = 5;
    g_Console.writeToBuffer(c,"ASCIIMON: TITLE", 0x03);
    c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 8;
    g_Console.writeToBuffer(c, "Press E to Start", 0x03);
    c.Y += 1;
    g_Console.writeToBuffer(c, "Press 'ESC' to quit", 0x03);
}



void renderGame()
{
    renderArea();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
}

void renderArea()
{
    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
    };
    COORD c;
    for (int i = 0; i < 21; ++i)
    {
        c.X = 0;
        c.Y = i;
        std::string st;
        for (int j = 0; j < 41; j++)
        {
            c.X = j;
            if (gamer.getPositionX() - 10 + i >= 0 && gamer.getPositionX() - 10 + i <= place[0]->getHeight() && gamer.getPositionY() - 20 >= 0 && gamer.getPositionY() + 20)
            {
                st = (place[0]->readMap(gamer.getPositionX() - 10 + i,gamer.getPositionY() - 20,gamer.getPositionY() + 20))[j];
                if (st == "V")
                {
                    colour(colors[5]);
                    g_Console.writeToBuffer(c,st,colors[1]);
                    //green 1
                }
                else if(st == "~")
                {
                    colour(colors[4]);
                    g_Console.writeToBuffer(c,st,colors[4]);
                    //blue 4 
                }
                else if(st == "/" || st == "\\" || st == "|" || st == "-" || st == "_")
                {
                    colour(colors[6]);
                    g_Console.writeToBuffer(c,st,colors[6]);
                    //brown 6
                }
            }
            
        }
    }
}

void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x0C;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0A;
    }
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
}
/*
void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {50, 2};
    std::ostringstream ss;
    std::string key;
    for (int i = 0; i < K_COUNT; ++i)
    {
        ss.str("");
        switch (i)
        {
        case K_UP: key = "UP";
            break;
        case K_DOWN: key = "DOWN";
            break;
        case K_LEFT: key = "LEFT";
            break;
        case K_RIGHT: key = "RIGHT";
            break;
        case K_SPACE: key = "SPACE";
            break;
        default: continue;
        }
        if (g_skKeyEvent[i].keyDown)
            ss << key << " pressed";
        else if (g_skKeyEvent[i].keyReleased)
            ss << key << " released";
        else
            ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
        g_Console.writeToBuffer(c, ss.str(), 0x17);
    }

    // mouse events    
    ss.str("");
    ss << "Mouse position (" << g_mouseEvent.mousePosition.X << ", " << g_mouseEvent.mousePosition.Y << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x59);
    ss.str("");
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            ss.str("Left Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;        
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:        
        break;
    }
    
}
*/


