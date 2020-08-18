#ifndef __CHESS_ONLINE_FIGURES_QUEEN_H__
#define __CHESS_ONLINE_FIGURES_QUEEN_H__

#include "GameObject.h"

namespace Chess {

class Queen : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    Queen();

    QString getClassId() const override;
    QString getResource() const override;

    void initVisualObject(VisualObject *visualObject) override;
};

}

#endif //__CHESS_ONLINE_FIGURES_QUEEN_H__
