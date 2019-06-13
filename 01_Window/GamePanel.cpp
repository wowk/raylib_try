#include <GameBlock.hpp>
#include <GamePanel.hpp>
#include <cassert>
#include <cstring>
#include <raylib.h>


extern Color color(int v);

GamePanel::GamePanel(int wsize, int hsize, int blksize)
{
    assert(wsize > 0 && wsize < 100);
    assert(hsize > 0 && hsize < 100);

    m_wsize = wsize;
    m_hsize = hsize;
    m_size  = blksize;

    m_panel = new int[wsize*hsize];
    memset(m_panel, 0, wsize*hsize*sizeof(int));
}

void GamePanel::draw()
{
    Rectangle rect;

    rect.width = rect.height = m_size;
    for(unsigned i = 0 ; i < m_wsize ; i ++){
        rect.x = m_x + i*m_size;
        for(unsigned j = 0 ; j < m_hsize ; j ++){
            if(m_panel[i*m_wsize+j]){
                rect.y = m_y + i*m_size;
                DrawRectangleRounded(rect, 0.2, 1, color(m_panel[i*m_wsize+j]));
            }
        }
    }
}

void GamePanel::add(const GameBlock * g)
{
    int x, y;

    for(unsigned i = 0 ; i < 4 ; i ++){
        x = g->x() + i;
        for(unsigned j = 0 ; j < 4 ; j ++){
            if(!g->d(i, j)){
                continue;
            }
            y = g->y() + j;
            m_panel[x*m_wsize+y] = g->d(i, j);
        }
    }
}

bool GamePanel::collision(const GameBlock* g)
{
    int x, y;

    for(unsigned i = 0 ; i < 4 ; i ++){
        x = g->x() + i;
        for(unsigned j = 0 ; j < 4 ; j ++){
            y = g->y() + j;
            if(!g->d(i, j)){
                continue;
            }
            if(m_panel[x*m_wsize+y]){
                return true;
            }else if(y >= m_hsize){
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
