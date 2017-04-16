#ifndef __CHESS_ONLINE_FIGURES_PAWN_H__
#define __CHESS_ONLINE_FIGURES_PAWN_H__

#include "GameObject.h"

namespace Chess {

class Pawn : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    Pawn();

    QString getClassId() const override;
    QString getResource() const override;

    void initVisualObject(VisualObject *visualObject) override;
};

}

#endif //__CHESS_ONLINE_FIGURES_PAWN_H__
