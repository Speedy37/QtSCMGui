#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>

class File;

class Repository : public QObject
{
    Q_OBJECT
public:
    explicit Repository(QObject *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QString path() const;
    void setPath(const QString &path);

    QList<File *> files() const;

    bool isBookmarked() const;
    void setBookmarked(bool bookmarked = true);

    virtual void log() = 0;
    virtual void status() = 0;
    virtual void pull() = 0;
    virtual void push() = 0;
    virtual void merge() = 0;
    virtual void commit() = 0;
    virtual void branch();
    virtual void tag() = 0;
    virtual void discard() = 0;
    virtual void stash() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void checkout() = 0;

signals:
    void bookmarkChanged(bool bookmarked);
    void statusChanged();

public slots:

private:
    QString m_name, m_path;
    bool m_bookmarked;
};

inline QString Repository::name() const
{
    return m_name;
}

inline void Repository::setName(const QString &name)
{
    m_name = name;
}

inline QString Repository::path() const
{
    return m_path;
}

inline void Repository::setPath(const QString &path)
{
    m_path = path;
}

inline bool Repository::isBookmarked() const
{
    return m_bookmarked;
}

inline void Repository::setBookmarked(bool bookmarked)
{
    m_bookmarked = bookmarked;
    emit bookmarkChanged(bookmarked);
}

#endif // REPOSITORY_H
