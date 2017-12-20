#ifndef OPENBITENGINE_H
#define OPENBITENGINE_H

#include <QObject>

class OpenBitEngine : public QObject
{
    Q_OBJECT
public:
    explicit OpenBitEngine(QObject *parent = nullptr);

signals:

public slots:
};

#endif // OPENBITENGINE_H