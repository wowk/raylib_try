#ifndef GAME_PANEL_H_
#define GAME_PANEL_H_

#include <cstdlib>

class GameBlock;

class GamePanel {
public:
    GamePanel(int wsize, int hsize, int blksize);
    void draw(void);
    void add(const GameBlock*);
    bool collision(const GameBlock*);
    bool full(void);
    int wsize() {return m_wsize;}
    int hsize() {return m_hsize;}

private:
    int* m_panel;
    int m_x, m_y;
    int m_wsize, m_hsize;
    size_t m_size;
};

#endif
