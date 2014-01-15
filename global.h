#ifndef GLOBAL_H
#define GLOBAL_H

#include <QList>

class Repository;

class Global
{
public:
    static Global * globalInstance();

    QList<Repository *> repositories() const;

private:
    Global();
    static Global * m_globalInstance;
    QList<Repository *> m_repositories;
};

inline Global *Global::globalInstance()
{
    return m_globalInstance;
}

inline QList<Repository *> Global::repositories() const
{
    return m_repositories;
}

#endif // GLOBAL_H
