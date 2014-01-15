#include "file.h"

File::File(Repository *parent) :
    QObject(parent), m_repository(parent)
{
}
