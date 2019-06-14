#include <GameBlock.hpp>
#include <GamePanel.hpp>
#include <cassert>
#include <cstring>
#include <raylib.h>
#include <iostream>

using namespace std;


extern Color color(int v);

GamePanel::GamePanel(int wsize, int hsize, int blksize)
{
    assert(wsize > 0 && wsize < 100);
    assert(hsize > 0 && hsize < 100);

    m_wsize = wsize;
    m_hsize = hsize;
    m_size  = blksize;

    m_x = m_y = 0;

    m_panel = new int[wsize*hsize];
    memset(m_panel, 0, wsize*hsize*sizeof(int));
}

void GamePanel::draw()
{
    Rectangle rect;

    rect.width = rect.height = m_size;
    for(unsigned i = 0 ; i < m_hsize ; i ++){
        rect.y = (m_y + i)*m_size;
        for(unsigned j = 0 ; j < m_wsize ; j ++){
            cout << m_panel[i*m_wsize+j] << " ";
            if(m_panel[i*m_wsize+j]){
                rect.x = (m_x + j)*m_size;
                DrawRectangleRounded(rect, 0.2, 1, color(m_panel[i*m_wsize+j]));
            }
        }
        cout << endl;
    }
}

void GamePanel::add(const GameBlock * g)
{
    int x, y;

    for(unsigned i = 0 ; i < 4 ; i ++){
        x = g->x() + i;
        for(unsigned j = 0 ; j < 4 ; j ++){
            cout << "X: " << x << ", Y: " << y << endl;
            if(!g->d(i, j)){
                continue;
            }
            y = g->y() + j;
            m_panel[y*m_wsize+x] = g->d(i, j);
        }
    }
}

bool GamePanel::collision(const GameBlock* g)
{
    int x, y;

    for(unsigned i = 0 ; i < 4 ; i ++){
        x = g->x() + i;
        for(unsigned j = 0 ; j < 4 ; j ++){
            if(!g->d(i, j)){
                continue;
            }
            y = g->y() + j;
            if(m_panel[y*m_wsize+x]){
                cout << "Collision at <" << x << ", " << y << endl;
                return true;
            }else if(y >= m_hsize){
                cout << "Collision at <" << x << ", " << y << endl;
                return true;
            }
        }
    }

    return false;
}

bool GamePanel::full()
{
    for(int i = 0 ; i < m_wsize ; i ++){
        if(m_panel[i]){
            return true;
        }
    }

    return false;
}
