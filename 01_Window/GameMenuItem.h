#ifndef GAME_MENU_ITEM_H
#define GAME_MENU_ITEM_H


#include <raylib.h>

class GameMenu;

class GameMenuItem {
public:
    GameMenuItem(GameMenu* menu, const char* text, Rectangle rect) {
        m_menu = menu;
        m_text = text;
        m_rect.x = rect.x;
        m_rect.y = rect.y;
        m_rect.width  = rect.width;
        m_rect.height = rect.height;
    }

    bool isMouseOver(Vector2 point);

    void draw();
    void drawSelected();

    void clean();
private:
    const char* m_text;
    Rectangle m_rect;
    GameMenu* m_menu;
};

#endif
