#ifndef __CHESS_ONLINE_FIGURES_KING_H__
#define __CHESS_ONLINE_FIGURES_KING_H__

#include "GameObject.h"

namespace Chess {

class King : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    King();

    QString getClassId() const override;
    QString getResource() const override;

    void initVisualObject(VisualObject *visualObject) override;
};

}

#endif //__CHESS_ONLINE_FIGURES_KING_H__
