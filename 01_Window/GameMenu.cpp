#include "GameMenu.h"


int GameMenu::selectByPoint(Vector2 mousePos)
{
    int index = 0;

    for(auto & menuItem : m_menuItems){
        if(menuItem->isMouseOver(mousePos)){
            selectMenuItem(index);
            return menuSelected();
        }
        index ++;
    }

    return -1;
}

void GameMenu::draw() {
    int count = 0;

    DrawRectangleRounded(m_rect, 0.1, 1, Color{12,23,45,100});

    for(auto & menuItem : m_menuItems){
        if(count == menuSelected()){
            menuItem->drawSelected();
        }else{
            menuItem->draw();
        }
        count ++;
    }
}
