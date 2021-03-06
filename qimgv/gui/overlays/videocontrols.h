#pragma once

#include "gui/customwidgets/overlaywidget.h"
#include "settings.h"
#include <QPushButton>

namespace Ui {
class VideoControls;
}

enum PlaybackMode {
    PLAYBACK_ANIMATION,
    PLAYBACK_VIDEO
};

class VideoControls : public OverlayWidget
{
    Q_OBJECT

public:
    explicit VideoControls(FloatingWidgetContainer *parent = nullptr);
    ~VideoControls();

public slots:
    void setPlaybackDuration(int);
    void setPlaybackPosition(int);
    void onPlaybackPaused(bool);
    void onVideoMuted(bool);
    void setMode(PlaybackMode _mode);

signals:
    void pause();
    void seek(int pos);
    void seekRight();
    void seekLeft();
    void nextFrame();
    void prevFrame();

private slots:
    void readSettings();

private:
    Ui::VideoControls *ui;
    int lastPosition;
    PlaybackMode mode;
};
