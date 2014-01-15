#ifndef FILE_H
#define FILE_H

#include <QObject>

class Repository;

class File : public QObject
{
    Q_OBJECT
public:
    explicit File(Repository *parent);

    enum Status
    {
        Unmodified,
        Modified,
        Added,
        Deleted,
        Renamed,
        Copied,
        Updated
    };

    Status indexStatus() const;
    Status workingTreeStatus()const;

    bool isUntracked() const;
    bool isIgnored() const;

    QString statusDescription() const;
    QString filename() const;
    QString directory() const;
    QString path() const;
    QString previousPath() const;

    Repository* repository() const;

    //TODO : Design diff, commit, stage, ... interfaces
private:
    Repository m_repository;
    QString m_path, m_previousPath;
    Status m_indexStatus, m_workingTreeStatus;
};

#endif // FILE_H
