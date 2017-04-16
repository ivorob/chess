#ifndef __CHESS_ONLINE_WHITE_DECORATOR_H__
#define __CHESS_ONLINE_WHITE_DECORATOR_H__

#include "GameObject.h"

class WhiteDecorator : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    WhiteDecorator(GameObject *object);
    ~WhiteDecorator();

    QString getClassId() const override;
    QString getResource() const override;
private:
    void initVisualObject(VisualObject *visualObject) override;
private:
    GameObject *object;
};

#endif //__CHESS_ONLINE_WHITE_DECORATOR_H__
