#ifndef GAME_MENU_H_
#define GAME_MENU_H_

#include "GameMenuItem.h"
#include <raylib.h>
#include <list>
#include <iostream>

#define DEBUG

using std::list;
using std::cout;
using std::cerr;
using std::endl;

class GameMenu {
public:
    GameMenu(Rectangle rc, Font font, int fontSize, int fontSpace, Color color, Color selectedColor) {
        m_rect.x = rc.x;
        m_rect.y = rc.y;
        m_rect.width = rc.width;
        m_rect.height = rc.height;

        m_font = font;
        m_fontSize = fontSize;
        m_fontSpace = fontSpace;

        m_menuItemColor = color;
        m_selectedMenuItemColor = selectedColor;

        m_menuItemIndex = 0;
    }

    inline void selectPrevMenuItem() {
        if(m_menuItems.size() == 0){
            return;
        }

        if(m_menuItemIndex > 0){
            m_menuItemIndex --;
        }
    }

    inline void selectNextMenuItem() {
        if(m_menuItems.size() == 0){
            return;
        }

        if(m_menuItemIndex +1 < m_menuItems.size()){
            m_menuItemIndex ++;
        }
    }

    inline void selectMenuItem(int menuItemIndex) {
        if(menuItemIndex > m_menuItems.size() || menuItemIndex < 0){
            return;
        }

        m_menuItemIndex = menuItemIndex;
    }

    inline int menuSelected() {
        if(m_menuItems.size() == 0){
            return -1;
        }
        return m_menuItemIndex;
    }

    GameMenuItem* addMenuItem(const char* text) {
        Vector2 textSize = MeasureTextEx(m_font, text, m_fontSize, m_fontSpace);

        TraceLog(LOG_WARNING, "===========X: %f, Y: %f==========", textSize.x, textSize.y) ;

        Rectangle menuItemRect;
        menuItemRect.x = 30 + m_rect.x;
        menuItemRect.y = m_rect.y + 30 + (textSize.y +30) * (m_menuItems.size());
        menuItemRect.width = textSize.x + 2;
        menuItemRect.height = textSize.y;

        auto menuItem = new GameMenuItem(this, text, menuItemRect);
        if(!menuItem){
            return nullptr;
        }

        m_menuItems.push_back(menuItem);

        return menuItem;
    }

    void removeMenuItem(GameMenuItem* menuItem) {
        m_menuItems.remove(menuItem);
    }

    void clean() {
        for(auto & menuItem : m_menuItems){
            menuItem->clean();
            delete menuItem;
        }
        m_menuItems.clear();
    }

    int selectByPoint(Vector2 mousePos);

    void draw();

private:
    int m_menuItemIndex;
    list<GameMenuItem*> m_menuItems;
    Rectangle m_rect;
    Font m_font;
    int m_fontSize;
    int m_fontSpace;
    Color m_menuItemColor;
    Color m_selectedMenuItemColor;

    friend class GameMenuItem;
};

#endif
