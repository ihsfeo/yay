#pragma once

class position
{
private:
    int x;
    int y;

public:
    position();
    ~position();
    void setPositionX(int x);
    void setPositionY(int y);
    int getPositionX(void);
    int getPositionY(void);
};
