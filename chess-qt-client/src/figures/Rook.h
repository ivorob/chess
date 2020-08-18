#ifndef __CHESS_ONLINE_FIGURES_ROOK_H__
#define __CHESS_ONLINE_FIGURES_ROOK_H__

#include "GameObject.h"

namespace Chess {

class Rook : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    Rook();

    QString getClassId() const override;
    QString getResource() const override;

    void initVisualObject(VisualObject *visualObject) override;
};

}

#endif //__CHESS_ONLINE_FIGURES_ROOK_H__
