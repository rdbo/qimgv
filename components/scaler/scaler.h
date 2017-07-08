#ifndef SCALER_H
#define SCALER_H

#include <QObject>
#include <QtConcurrent>
#include <QMutex>
#include "components/cache/cache2.h"
#include "scalerrequest.h"
#include "scalerrunnable.h"

class Scaler : public QObject
{
    Q_OBJECT
public:
    explicit Scaler(Cache2 *_cache, QObject *parent = nullptr);

signals:
    void scalingFinished(QPixmap* result, ScalerRequest request);

public slots:
    void requestScaled(ScalerRequest req);

private slots:
    void onTaskFinish(QImage* scaled, ScalerRequest req);

private:
    ScalerRunnable *runnable;

    bool buffered, running;
    clock_t currentRequestTimestamp;
    ScalerRequest bufferedRequest;
    QMutex requestMutex;

    Cache2 *cache;

    void startRequest(ScalerRequest req);
};

#endif // SCALER_H
