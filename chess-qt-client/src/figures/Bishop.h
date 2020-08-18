#ifndef __CHESS_ONLINE_FIGURES_BISHOP_H__
#define __CHESS_ONLINE_FIGURES_BISHOP_H__

#include "GameObject.h"

namespace Chess {

class Bishop : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    Bishop();

    QString getClassId() const override;
    QString getResource() const override;

    void initVisualObject(VisualObject *visualObject) override;
};

}

#endif //__CHESS_ONLINE_FIGURES_BISHOP_H__
