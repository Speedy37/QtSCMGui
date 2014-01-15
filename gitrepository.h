#ifndef GITREPOSITORY_H
#define GITREPOSITORY_H

#include "repository.h"
#include <QProcess>

class GitRepository : public Repository
{
    Q_OBJECT
public:
    explicit GitRepository(QObject *parent = 0);
    virtual void status() Q_DECL_OVERRIDE;
signals:
public slots:

private slots:
    void statusFinished(int exitCode, QProcess::ExitStatus exitStatus);
private:
    QProcess * gitStatusProcess;
};

#endif // GITREPOSITORY_H
