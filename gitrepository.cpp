#include "gitrepository.h"

#include <QProcess>

static QStringList gitStatusArguments = (QStringList() << QStringLiteral("status") << QStringLiteral("--porcelain"));

GitRepository::GitRepository(QObject *parent) :
    Repository(parent)
{
    gitStatusProcess = new QProcess(this);
}

QString GitRepository::git(const QStringList &arguments)
{
    QProcess git;
    git.setWorkingDirectory(directory);
    git.start(QStringLiteral("git"), gitStatusArguments);
    if (!git.waitForStarted())
        throw QObject::tr("Git failed to start");
    if (!git.waitForFinished())
        throw QObject::tr("Git failed to finish");
    Log::info(git.readAllStandardError());
    return git.readAll();
}

void GitRepository::status()
{
    gitStatusProcess->setWorkingDirectory(path());
    gitStatusProcess->start(gitExecutable(), gitStatusArguments);
    connect(git, &QProcess::finished, this, &GitRepository::statusFinished);
}

void GitRepository::statusFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(exitCode == 0 && exitStatus == QProcess::NormalExit )
    {
        emit statusChanged();
    }
}
