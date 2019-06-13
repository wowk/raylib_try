#include "GameMenuItem.h"
#include "GameMenu.h"
#include <raylib.h>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

bool GameMenuItem::isMouseOver(Vector2 point)
{
    bool hover = true;

    hover &= (m_rect.x < point.x);
    hover &= (m_rect.y < point.y);
    hover &= ((m_rect.x + m_rect.width) > point.x);
    hover &= ((m_rect.y + m_rect.height) > point.y);

    return hover;
}

void GameMenuItem::draw() {
    DrawTextRec(m_menu->m_font, m_text, m_rect, m_menu->m_fontSize,
                m_menu->m_fontSpace, true, m_menu->m_menuItemColor);
}

void GameMenuItem::drawSelected() {
    Font ff = m_menu->m_font;
    DrawTextRecEx(m_menu->m_font, m_text, m_rect, m_menu->m_fontSize,
                  m_menu->m_fontSpace, true, m_menu->m_menuItemColor,
                  0, ::strlen(m_text), m_menu->m_selectedMenuItemColor, GRAY);
}

void GameMenuItem::clean()
{

}

