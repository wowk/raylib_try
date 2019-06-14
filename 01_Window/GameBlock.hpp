#ifndef GAME_BLOCK_H_
#define GAME_BLOCK_H_

#include <stdlib.h>

class GameBlock {
public:
    GameBlock(size_t size);
    void init(int type, int dir);
    void move(int x, int y);
    void draw(void);
    void nextType(void);
    void nextDir(void);
    void setPos(int x, int y);
    int d(int x, int y) const;
    int x() const {return m_x;}
    int y() const {return m_y;}

    enum Type {
        TYPE_A, TYPE_B, TYPE_C,
        TYPE_D, TYPE_E, TYPE_F,
        TYPE_G, TYPE_H, TYPE_MAX,
    };

    enum Dir {
        DIR_LEFT, DIR_DOWN,
        DIR_RIGHT, DIR_UP,
        DIR_MAX,
    };

private:
    int m_d[4][4];
    int m_type;
    int m_dir;
    int m_x, m_y;
    size_t m_size;
};

#endif
