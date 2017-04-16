#ifndef __CHESS_ONLINE_BLACK_DECORATOR_H__
#define __CHESS_ONLINE_BLACK_DECORATOR_H__

#include "GameObject.h"

class BlackDecorator : public GameObject {
    typedef GameObject::VisualObject VisualObject;
public:
    BlackDecorator(GameObject *object);
    ~BlackDecorator();

    QString getClassId() const override;
    QString getResource() const override;
private:
    void initVisualObject(VisualObject *visualObject) override;
private:
    GameObject *object;
};

#endif //__CHESS_ONLINE_BLACK_DECORATOR_H__
