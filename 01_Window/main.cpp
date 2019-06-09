#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <cstring>
#include <raylib.h>
#include <GameMenu.h>
#include <GameMenuItem.h>


using namespace std;

class Director {

};

class GameScene {
public:
    virtual bool init() = 0;
    virtual void update(float delta) = 0;
    virtual void draw() = 0;
    virtual void clean() {}
};

class GameMenuScene : public GameScene {
public:
    bool init() {
        const char* textMenuItemStart    = "New Game";
        const char* textMenuItemSettings = "Settings";
        const char* textMenuItemExit     = "Exit";

        Font font = GetFontDefault();
        Rectangle menuRect = {100, 100, 400, 600};

        m_menu = new GameMenu(menuRect, font, 44, 2, YELLOW, Color{255, 127, 0, 128});
        if(!m_menu){
            return false;
        }

        m_menu->addMenuItem(textMenuItemStart);
        m_menu->addMenuItem(textMenuItemSettings);
        m_menu->addMenuItem(textMenuItemExit);

        return true;
    }

    void update(float delta) {
        if(IsKeyPressed(KEY_DOWN)){
            m_menu->selectNextMenuItem();
        }else if(IsKeyPressed(KEY_UP)){
            m_menu->selectPrevMenuItem();
        }

        Vector2 mousePos = GetMousePosition();
        int menuItemIndex = m_menu->selectByPoint(mousePos);
        if(menuItemIndex < 0){
            menuItemIndex = m_menu->menuSelected();
        }

        if(menuItemIndex == 2){
            if(IsKeyPressed(KEY_ENTER) || IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                CloseWindow();
            };
        }
    }

    void draw() {
        m_menu->draw();
    }

    void clean() {
        m_menu->clean();
    }
private:
    Rectangle m_menuRect;
    GameMenu* m_menu;
};

class Game {
public:
    enum Status {
        START,
        PLAYING,
        PASUE,
    };

public:
    void pushScene(GameScene* scene);
    GameScene* popScene(GameScene* scene);

private:
    Status m_status;
    stack<GameScene*> m_sceneStack;
};


int main(int argc, char* argv[])
{
    InitWindow(800, 800, "Tetris");

    Font font = GetFontDefault();

    enum {
        START,
        PAUSING,
        PAUSE,
    } game_status;
    game_status = START;

    GameMenuScene* menuScene = new GameMenuScene();

    menuScene->init();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if(IsKeyDown(KEY_ESCAPE)){
            break;
        }

        if(game_status == START) {
            menuScene->update(GetFrameTime());
        }

        BeginDrawing();
        ClearBackground(Color{29, 12, 23});

        menuScene->draw();

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
