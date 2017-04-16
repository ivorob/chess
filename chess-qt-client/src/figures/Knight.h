#ifndef __CHESS_ONLINE_FIGURES_KNIGHT_H__
#define __CHESS_ONLINE_FIGURES_KNIGHT_H__

#include "GameObject.h"

namespace Chess {

class Knight : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    Knight();

    QString getClassId() const override;
    QString getResource() const override;

    void initVisualObject(VisualObject *visualObject) override;
};

}

#endif //__CHESS_ONLINE_FIGURES_KNIGHT_H__
