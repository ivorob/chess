#ifndef __CHESS_ONLINE_GAME_OBJECT_H__
#define __CHESS_ONLINE_GAME_OBJECT_H__

#include <QGraphicsItem>

class GameObject {
public:
    typedef QGraphicsItem VisualObject;
    typedef uint32_t objectId;
public:
    GameObject();
    virtual ~GameObject();

    virtual QString getClassId() const = 0;
    virtual QString getResource() const =  0;

    void setId(objectId id);
    objectId getId() const;

    VisualObject *obtainVisualObject();
    virtual void initVisualObject(VisualObject *object) = 0;
private:
    objectId id;
    VisualObject *visualObject;
};

#endif //__CHESS_ONLINE_GAME_OBJECT_H__
